#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


size_t ft_strlenC(const char *s);
extern size_t _ft_strlen(const char *s);

char *ft_strcpyC(char *dst, const char *src);
extern char *_ft_strcpy(char *dst, const char *src);

int main(int argc, char *argv[])
{
    char *s = "Hello World";
    printf("%lu\n", strlen(s));
    printf("%lu\n", ft_strlenC(s));
    printf("%lu\n", _ft_strlen(s));


    s = "Hello World in strcpy";
    char dst[256];
    printf("%s | %s\n", strcpy(dst, s), dst);
    printf("%s | %s\n", ft_strcpyC(dst, s), dst);
    printf("%s | %s\n", _ft_strcpy(dst, s), dst);
    return EXIT_SUCCESS;
}

size_t ft_strlenC(const char *s) {
    
    size_t i = 0;

    while (*(s+i) != 0) {
        i++;
    }

    return (i);
}

char *ft_strcpyC(char *dst, const char *src) {
    size_t i = 0;

    while (src[i] != 0) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return dst;
}
