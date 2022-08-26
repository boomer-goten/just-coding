#include <stdio.h>
#include <math.h>

void funct(long double x);

int main() {
    char c;
    int tochka = 0;
    long double x = 0;
    int status = 0;
    int i = 1;
    int tmp;
    while (((c = getchar()) != EOF) && (c != '\t') && (c != '\n')) {
        if ((c >= 48) && (c <= 57)) {
            if (tochka == 0) {
                x = 10*x+c - '0'; 
            }
            if (tochka == 1) {
                tmp = c - '0';
                x = x+(tmp/(10*i));
            } 
        } else if (c == '.') {
            tochka++;
        } else status = 2;
        if (tochka >= 2) {
            status = 3;
        }
    }
    if (status == 0) {
        funct(x);
    } else {
        printf("n/a");
    }
}

void funct(long double x) {
    double z;
    z = 7 * pow(10,-3) * pow(x,4) + (((22.8 * pow(x,(1. / 3)) - 1 * pow(10,3)) * x + 3) / (x * x/2)) - x * pow(10+x,2/x) - 1.01; 
    printf("%.1lf", z);
}