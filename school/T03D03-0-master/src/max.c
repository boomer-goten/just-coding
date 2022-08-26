#include <stdio.h>

void max(int a, int b);

int main() {
    char c;
    int space = 0;
    int a = 0;
    int b = 0;
    int status = 0;
    while (((c = getchar()) != EOF) && (c != '\t') && (c != '\n')) {
        if ((c >= 48) && (c <= 57)) {
            if (space == 0) {
                a =10*a+c - '0'; 
            }
            if (space == 1) {
                b =10*b+c - '0';
            } 
        } else if (c == ' ') {
            space++;
        } else status = 2;
        if (space >= 2) {
            status = 3;
        }
    }
    if (status == 0) {
        max(a,b);
    } else {
        printf("n/a");
    }
}

void max(int a, int b) {
    if (a > b) {
        printf("%d", a);
    } else {
        printf("%d", b);
    }
}
