#include <stdio.h>

int main() {
    char c;
    int i = 1;
    int chislo = 0;
    while (((c = getchar()) != '\n') && (c != '\t')) {
        //c = c - '0';
        if (i % 2 == 1) {
            chislo = (c - '0') * 10;
        } else if (i % 2 == 0) {
            chislo += c - '0';
            c = (char)chislo;
            printf("%c", c);
        }
        i++;
    }
}