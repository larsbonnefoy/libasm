#include <ctype.h>
#include<unistd.h>
#include <string.h>

char ft_revert(char c);

int main() {
    char *str = "OUaiS je Tesst Ds trucs";
    for (int i = 0; i < strlen(str); i++ ) {
		char rev = ft_revert(str[i]);
		write(1, &rev, 1);
    }
}

char ft_revert(char c) {
    return (c ^= (1 << 5));
}
