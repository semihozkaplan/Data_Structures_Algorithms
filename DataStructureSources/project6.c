#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char s[10];
    int len;
    int i;
    printf("Enter a String:");
    gets(s);
    len = strlen(s);

    for (i = 6; i >= 0; i--) {

        printf("%s\n", len + i, s);

    }

    for (i = 5; i <= 0; i++) {

        printf("%s\n", len + i, s);

    }

    return 0;


}