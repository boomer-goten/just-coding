#include <stdio.h>

void sum(int a, int b);
void razn(int a, int b);
void proizved(int a, int b);
void chast(int a, int b);

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
        sum(a, b);
        razn(a, b);
        proizved(a, b);
        if (b != 0) {
            chast(a, b);
        } else {
            printf("n/a\n");
        }
    } else {
        printf("n/a\n");
    }
    return 0;
}

void sum(int a, int b) {
    printf("%d ", a+b);
}

void razn(int a, int b) {
    printf("%d ", a-b);
}

void proizved(int a, int b) {
    printf("%d ", a*b);
}

void chast(int a, int b) {
    int k;
    k = (double)a/(double)b;
    printf("%d", k);
}
