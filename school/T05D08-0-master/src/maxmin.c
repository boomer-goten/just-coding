#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Find a max & min probabilities */
int main()
{
    int x = 0, y = 0, z = 0;
    char c;
    int space = 0;
    int status;
    while (((c = getchar()) != EOF) && (c != '\t') && (c != '\n')) {
        if ((c >= 48) && (c <= 57)) {
            if (space == 0) {
                x =10*x+c - '0'; 
            }
            if (space == 1) {
                y =10*y+c - '0';
            }
            if (space == 2) {
                z =10*z+c - '0';
            } 
        } else if (c == ' ') {
            space++;
        } else status = 2;
        if (space >= 3) {
            status = 3;
        }
    }
    int maxim, minim;
    int *max = &maxim; 
    int *min = &minim;
    maxmin(x, y, z, max, min);
    if (status == 0) {
        printf("%d %d", *max, *min);
    } else {
        printf("n/a");
    }
    return 0;
}


/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min)
{
    *max = *min = prob1;
    
    if(prob2 > *max)
        *max = prob2;
    if(prob2 < *min)
        *min = prob2;
    
    if(prob3 > *max)
        *max = prob3;
    if(prob3 < *min)
        *min = prob3;    
}

