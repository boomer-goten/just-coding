#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main()
{
    int n, data[NMAX];
    input(data, n);
    squaring(data, n);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    int status = 0;
    char c;
    int x;
    int stat = scanf("%d", n);
        if 
    for(int *p = a; p - a < *n; p++) {
        while (((c = getchar()) != EOF) && (c != '\t') && (c != '\n')) {
            if (c == ' ') {
                break;
            }
            if ((c >= 48) && (c <= 57)) {
                x =10*x+c - '0'; 
            } else {
                status = 2;
            }
        }
        p[p-a] = x;
    }
}

void output(int *a, int n)
{
    //NOTHING
}

void squaring(int *a, int n)
{
    //NOTHING
}


