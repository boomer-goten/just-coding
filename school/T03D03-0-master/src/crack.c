#include <stdio.h>

void krug(double a, double b);

int main() {
    char c;
    int tochka = 0;
    int space = 0;
    double tmp;
    double x = 0;
    double y = 0;
    double z = 0;
    int status = 0;
    int i = 1;
    while (((c = getchar()) != EOF) && (c != '\t') && (c != '\n')) {
        if ((c >= 48) && (c <= 57)) {
            if (tochka == 0) {
                z = 10*z+c - '0';
            }
            if (tochka == 1) {
                tmp = c - '0';
                z = z+(tmp/(10*i));
                i++;
            }
        } else if (c == ' ') {
            space++;
            x = z;
            z = 0;
            i = 1;
            tochka = 0;
        } else if (c == '.') {
            tochka++;
        } else {
            status = 2;
        }
        if (space >= 2) {
            status = 3;
        }
        y = z;
    }
    if (status == 0) {
        krug(x, y);
    } else {
        printf("n/a");
    }
}

void krug(double x, double y) {
    if (x*x+y*y < 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }
}
