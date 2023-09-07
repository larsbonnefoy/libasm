#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


size_t ft_strlen_c(const char *s);
extern size_t _ft_strlen(const char *s);

char *ft_strcpy_c(char *dst, const char *src);
extern char *_ft_strcpy(char *dst, const char *src);

int ft_strcmp_c(const char *s1, const char *s2);

int main(int argc, char *argv[])
{
    const char *s = "Hello World";
    printf("%lu\n", strlen(s));
    printf("%lu\n", ft_strlen_c(s));
    printf("%lu\n", _ft_strlen(s));


    const char *s1 = "Hello World in strcpy";
    char dst[256];
    printf("%s | %s\n", strcpy(dst, s1), dst);
    printf("%s | %s\n", ft_strcpy_c(dst, s1), dst);
    printf("%s | %s\n", _ft_strcpy(dst, s1), dst);

    const char *s2 = "Hello World";
    const char *s3 = "meep";
    const char *s4 = "Hello World but not the same";
    printf("%d, %d, %d, %d\n", strcmp(s,s), strcmp(s, s2), strcmp(s, s3), strcmp(s, s4));
    printf("%d, %d, %d, %d\n", ft_strcmp_c(s,s), ft_strcmp_c(s, s2), ft_strcmp_c(s, s3), ft_strcmp_c(s, s4));
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
