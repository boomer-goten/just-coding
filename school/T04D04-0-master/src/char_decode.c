#include <stdio.h>

void vascii();
void izascii();

int main() {
    char c;
    int status = 0;
    if (((c = getchar()) != '\n') && (c != '\t')) {
        if ((c >= 48) && (c <= 49)) {
            c = c - '0';
        } else {
            status = 1;
        }
    }
    if (status == 0) {
        switch (c) {
            case 0:
                vascii();
            break;
            case 1:
                izascii();
            break;
            default:
                status = 2;
                printf("n/a");
            break;
        }
    }
}

void vascii() {
    char d;
    char slovo[100];
    int i = 0;
    int j = 0;
    int status = 0;
    fflush(stdin);
    while (((d = getchar()) != EOF) && (d != '\t')) {
        if ((d == '\n') && (i != 0)) {
            if (slovo[j-1] == ' ') {
                status = 2;
            }
            break;
        }
        if ((i % 2 == 0) && (d != '\n')) {
            if (d != ' ') {
                status = 1;
            } else {
                slovo[j] = ' ';
                j++;
            }
        }
        if (i % 2 != 0) {
            if (d % 16 <= 9) {
                slovo[j] = (d / 16) + 48;
                slovo[j+1] = (d % 16) + 48;
                j += 2;
            } else if (d % 16 >= 9) {
                slovo[j] = (d / 16) + 48;
                slovo[j+1] = 65 + ((d % 16) - 10);
                j += 2;
            } 
        }
        i++;
    }
    if (status == 0) {
        for (int z = 0; z <= (j-1); z++) {
            printf("%c", slovo[z]);
        }
    } else {
        printf("n/a");
    }
}

void izascii() {
    char d;
    char slovo[30];
    int i = 0;
    int j = 0;
    int status = 0;
    int chislo;
    fflush(stdin);
    while (((d = getchar()) != EOF) && (d != '\t')) {
        if ((d == '\n') && (i != 0)) {
            if (slovo[j-1] == ' ') {
                status = 2;
            }
            break;
        }
        if ((i % 3 == 0) && (d != '\n')) {
            if (d != ' ') {
                status = 1;
            } else {
                slovo[j] = ' ';
                j++;
                chislo = 0;
            }
        }
        if (i % 3 == 1) {
            chislo = (d - '0') * 10;
        } else if ((i % 3 == 2) && (d >= 48) && (d <= 57)) {
            chislo += d - '0';
            chislo += 24;
            slovo[j] = (char)chislo;
            j++;
        } else if ((i % 3 == 2) && ((d < 48) || (d > 57))) {
            chislo += d - '0';
            chislo += 17;
            slovo[j] = (char)chislo;
            j++;
        }
        i++;
    }
    if (status == 0) {
        for (int z = 0; z <= (j-1); z++) {
            printf("%c", slovo[z]);
        }
    } else {
        printf("n/a");
    }
}
