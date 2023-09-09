#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define READ_BUF 10

size_t ft_strlen_c(const char *s);
extern size_t ft_strlen(const char *s);

char *ft_strcpy_c(char *dst, const char *src);
extern char *ft_strcpy(char *dst, const char *src);

int ft_strcmp_c(const char *s1, const char *s2);
extern int ft_strcmp(const char *s1, const char *s2);

extern ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
extern ssize_t ft_read(int fildes, const void *buf, size_t nbyte);


int main(void)
{
    printf("---- ft_strlen ---\n");
    const char *s = "Hello World";
    printf("o:  %lu\n", strlen(s));
    printf("c:  %lu\n", ft_strlen_c(s));
    printf("a:  %lu\n", ft_strlen(s));

    printf("\n---- ft_strcpy ---\n");
    const char *s1 = "Hello World in strcpy";
    char dst[256];
    printf("o:  %s | %s\n", strcpy(dst, s1), dst);
    printf("c:  %s | %s\n", ft_strcpy_c(dst, s1), dst);
    printf("a:  %s | %s\n", ft_strcpy(dst, s1), dst);

    printf("\n---- ft_strcmp ---\n");
    const char *s2 = "Hello";
    const char *s3 = "meep";
    const char *s4 = "Hello World but longer";
    printf("o:  %d, %d, %d, %d\n", strcmp(s,s), strcmp(s, s2), strcmp(s, s3), strcmp(s, s4));
    printf("c:  %d, %d, %d, %d\n", ft_strcmp_c(s,s), ft_strcmp_c(s, s2), ft_strcmp_c(s, s3), ft_strcmp_c(s, s4));
 	printf("a:  %d, %d, %d, %d\n", ft_strcmp(s,s), ft_strcmp(s, s2), ft_strcmp(s, s3), ft_strcmp(s, s4));


    printf("\n---- ft_write ---\n");
    write(1, "a:  ", 4);
    printf("    len = %d, errno = %d\n", (int)ft_write(1, s, 11), errno);
    write(1, "o:  ", 4);
    printf("    len = %d, errno = %d\n", (int)write(1, s, 11), errno);
    printf("a:  len = %d, errno = %d\n", (int)ft_write(3, s, 11), errno);
    printf("o:  len = %d, errno = %d\n", (int)write(3, s, 11), errno);
    printf("a:  len = %d, errno = %d\n", (int)ft_write(1, 0x0, 11), errno);
    printf("o:  len = %d, errno = %d\n", (int)write(1, 0x0, 11), errno);
    printf("a:  len = %d, errno = %d\n", (int)ft_write(1, s, -1), errno);
    printf("o:  len = %d, errno = %d\n", (int)write(1, s, -1), errno);

    printf("\n---- ft_read ---\n");
    char buf[READ_BUF];
    int fildes = open("./ft_strlen.s", O_RDONLY);
    bzero(buf, READ_BUF);
    write(1, "a:  ", 5);
    printf("len = %d\n", (int)ft_read(fildes, buf, READ_BUF - 1));
    printf("->BUFFER\n%s\n", buf);
    close(fildes);

    fildes = open("./ft_strlen.s", O_RDONLY);
    bzero(buf, READ_BUF);
    write(1, "\no:  ", 5);
    printf("len = %d\n", (int)read(fildes, buf, READ_BUF - 1));
    printf("->BUFFER\n%s\n", buf);
    close(fildes);
    

    bzero(buf, READ_BUF);
    fildes = open("./ft_strlen.s", O_RDONLY);
    printf("a:  len = %d, errno = %d\n", (int)ft_read(3, buf, 1), errno);
    printf("o:  len = %d, errno = %d\n", (int)read(3, buf, 1), errno);
    printf("a:  len = %d, errno = %d\n", (int)ft_read(fildes, NULL, 1), errno);
    printf("o:  len = %d, errno = %d\n", (int)read(fildes, NULL, 1), errno);
    printf("a:  len = %d, errno = %d\n", (int)ft_read(fildes, buf, -1), errno);
    printf("o:  len = %d, errno = %d\n", (int)read(fildes, buf, -1), errno);
    close(fildes);
    return EXIT_SUCCESS;
}

size_t ft_strlen_c(const char *s) {
    
    size_t i = 0;

    while (*(s+i) != 0) {
        i++;
    }

    return (i);
}

char *ft_strcpy_c(char *dst, const char *src) {
    size_t i = 0;

    while (src[i] != 0) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return dst;
}

int ft_strcmp_c(const char *s1, const char *s2) {
    size_t i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == 0 || s2[i] ==  0) {                //-> if these lines ar not present we have a bus error
            return 0;
        }
        i++;
    }
    return (s1[i] - s2[i]);
}
