#include <stdio.h>

int fibonachi(int n);

int main() {
    char c;
    int n = 0;
    int status = 0;
    while (((c = getchar()) != EOF) && (c != '\t') && (c != '\n')) {
        if ((c >= 48) && (c <= 57)) {
                n = 10*n+c - '0'; 
        } else { 
            status = 1;
        }
    }
    if (status == 0) {
        printf("%d", fibonachi(n));
    } else {
        printf("n/a");
    }
}

int fibonachi(int n) {
    int chislo;
    if (n <= 1) {
        chislo = n;
    } else {
    chislo = fibonachi(n-1) + fibonachi(n-2);
    }
    return chislo;
}
