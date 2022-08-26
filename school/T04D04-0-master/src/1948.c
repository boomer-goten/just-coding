#include <stdio.h>

int del(int i, int x);
int prostoe(int chislo);

int main() {
    char c;
    double x = 0;
    int status = 0;
    int tmp;
    int max = -1;
    while (((c = getchar()) != EOF) && (c != '\t') && (c != '\n')) {
        if ((c >= 48) && (c <= 57)) {
                x = 10*x+c - '0'; 
        } else if (c == '-') {
            continue; 
        } else { 
            status = 1;
        }
    }
    if (x == 1) {
        status = 2;
    }
    if (status == 0) {
        for (int i = x; i >= 1; i--) {
            tmp = del(i,x);
            if (tmp != 0) {
                if (prostoe(tmp) > -1) {
                    max = prostoe(tmp);
                }
            }
        }
        printf("%d\n", max);
    } else {
        printf("n/a");
    }
}

int del(int i, int x) {
    int delitel = 0;
    while (x > 0) {
        x = x - i;
        delitel++;
    }
    if (x != 0) {
        delitel = 0;
    }
    return delitel;
}

int prostoe(int chislo) {
    int delit;
    int chet = 0;
    for (int j = 1; j <= chislo; j++) {
        int x = chislo;
        delit = del(j,x);
        if (delit != 0) {
            chet++;
        }
    }
    if (chet != 2) {
        chislo = -1;
    }
    return chislo;
}
