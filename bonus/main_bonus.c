#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_atoi_base(char *str, char *base);
int is_white_space(char c);

int main()
{
    printf("%d\n", ft_atoi_base(" --+--+ABF", "0123456789ABCDEF"));
    return 0;
}

/*
 * checks for \t, \n, \v, \f, \r, ''
 */
int is_white_space(char c) {
    if ((c >= 9 && c <= 13) || c == 32) {
        return 1;
    }
    return 0;
}

/*
 *  Checks if base contains:
 *      fewer than 2 elemts
 *      +, - or whitespaces
 *      double char
 *
 *  Returns 0 on failure, len_base on success
 */ 
int check_base(char *base) {
    size_t i = 0;
    char char_val[93] = {0};      //93 printable characters
    
    while (base[i]) {
        char c = base[i];

        if (is_white_space(c) || c == '+' || c == '-' || char_val[c - 33] == 1) {
            return (0);
        }
        char_val[c - 33] = 1;
        i++;
    }
    if (i < 2) {
        return (0);
    }
    return i; 
}


/*
 * returns index of char c in base if found, -1 if not  
 *
 */ 
int is_in_base(char c, char *base) {
    int i = 0;
    while (base[i]) {
        if (base[i] == c) {
            return i;
        }       
        i++;
    }
    return -1;
}

/*
 * ft_atoi 
 * string can start with arbitrary nb of whitespaces
 * arbitrary nb of + -
 * followed by any nb in base x
 * stop when one of those rules is not followed anymore
 * Not take care of overflow
 *
 * Invalid arguments : base size 0, 1 or NULL
 * Base has twice the same char
 * Base contains + - or whitespaces
 *
 */ 
int ft_atoi_base(char *str, char *base) {
    int i = 0;
    char sign = 1;
    int acc = 0;
    int decimal_value = 0;
    int len_base;
     
    len_base = check_base(base);
    if(!len_base) {
        return (0);
    }
    while(is_white_space(str[i])) {
        i++;
    }
    while (str[i] == '+' || str[i] == '-') {
       if (str[i] == '-') {
            sign *= -1;
       } 
       i++;
    }
    while(str[i]) {
        decimal_value = is_in_base(str[i], base);
        if (decimal_value == -1) {
            break;
        }
        acc = acc * len_base + decimal_value;
        i++;
    }
    return (acc);
}
