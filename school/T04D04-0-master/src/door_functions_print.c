#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double anezi(double x);
double bernuli(double x);
double giperbola(double x);
void sort(double *mass);
void aneziprint(double *mass);
void bernuliprint(double *mass);
void giperbolaprint(double *mass);

int main() {
    double x, tmp;
    double *an = (double *)malloc(42 * sizeof(double));
    double *ber = (double *)calloc(42, sizeof(double));
    double *gip = (double *)malloc(42 * sizeof(double));
    for (int i = 0; i <= 41; i++) {
        tmp = i * 2 * M_PI / 41;
        x = M_PI*(-1)+tmp;
        an[i] = anezi(x);
        ber[i] = bernuli(x);
        gip[i] = giperbola(x);
    }
    sort(an);
    sort(ber);
    sort(gip);
    aneziprint(an);
    bernuliprint(ber);
    giperbolaprint(gip);
    free(an);
    free(ber);
    free(gip);
}

double anezi(double x) {
    double ordinata;
    ordinata = (1 / (x*x + 1 ));
    return ordinata;
}

double bernuli(double x) {
    double ordinata;
    ordinata = sqrt(sqrt(1 + 4*x*x*1) - x*x - 1);
    if (sqrt(1 + 4*x*x*1) - x*x - 1 <= 0) {
        ordinata = 0;
    }
    return ordinata;
}

double giperbola(double x) {
    double ordinata;
    ordinata = (1 / (x*x));
    return ordinata; 
}

void sort(double *mass) {
    for(int i = 0 ; i < 40; i++) { 
       for(int j = 0 ; j < 40 - i; j++) {  
           if(mass[j] < mass[j+1]) {           
              double tmp = mass[j];
              mass[j] = mass[j+1] ;
              mass[j+1] = tmp; 
           }
        }
    }
}

void aneziprint(double *mass) {
    double ordinata, ordinata_tmp;
    for (int i = 0; i <= 41; i += 2) {
        ordinata = mass[i];
        for (double abscis = M_PI * (-1); abscis <= M_PI; abscis += 2 * M_PI / 41) {
            ordinata_tmp = (1 / (abscis*abscis + 1));
            if (fabs(abscis - M_PI) < pow(10,-6)) {
                if (fabs(ordinata_tmp - ordinata) < pow(10,-6)) {
                    printf("*\n");
                } else {
                    printf(" \n");
                }
            } else {
                if (fabs(ordinata_tmp - ordinata) < pow(10,-6)) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } 
        }
    }
}

void bernuliprint(double *mass) {
    double abscis, ordinata, ordinata_tmp;
    for (int i = 0; i <= 41; i+=2) {
        ordinata = mass[i];
        for (abscis = M_PI * (-1); abscis <= M_PI; abscis += 2 * M_PI / 41) {
            ordinata_tmp = sqrt(sqrt(1 + 4*abscis*abscis*1) - abscis*abscis - 1);
            if (fabs(abscis - M_PI) < pow(10,-6)) {
                if (fabs(ordinata_tmp - ordinata) < pow(10,-6)) {
                    printf("*\n");
                } else {
                    printf(" \n");
                }
            } else {
                if (fabs(ordinata_tmp - ordinata) < pow(10,-6)) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
    }
}

void giperbolaprint(double *mass) {
    double abscis, ordinata, ordinata_tmp;
    for (int i = 0; i <= 41; i+=2) {
        ordinata = mass[i];
        for (abscis = M_PI * (-1); abscis <= M_PI; abscis += 2 * M_PI / 41) {
            ordinata_tmp = (1 / (abscis*abscis));
            if (fabs(abscis - M_PI) < pow(10,-6)) {
                if (fabs(ordinata_tmp - ordinata) < pow(10,-6)) {
                    printf("*\n");
                } else {
                    printf(" \n");
                }
            } else {
                if (fabs(ordinata_tmp - ordinata) < pow(10,-6)) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
    }
}
