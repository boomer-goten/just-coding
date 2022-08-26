#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

void anezi(double x);
void bernuli(double x);
void giperbola(double x);

int main() {
    double x, tmp;
    for (double i = 0; i <= 41; i++) {
        tmp = i * 2 * M_PI / 41;
        x = M_PI*(-1)+tmp;
        if (x < 0) {
            printf("%.7lf | ", x);
        } else {
            printf(" %.7lf | ", x);
        }
        anezi(x);
        bernuli(x);
        giperbola(x);
    }
}

void anezi(double x) {
    double ordinata;
    ordinata = (1 / (x*x + 1 ));
    printf("%.7lf | ", ordinata); 
}

void bernuli(double x) {
    double ordinata;
    ordinata = sqrt(sqrt(1 + 4*x*x*1) - x*x - 1);
    if (sqrt(1 + 4*x*x*1) - x*x - 1 >= 0) {
        printf("%.7lf | ", ordinata);
    } else {
        printf("    -     | ");
    }
}

void giperbola(double x) {
    double ordinata;
    ordinata = (1 / (x*x));
    printf("%.7lf\n", ordinata); 
}