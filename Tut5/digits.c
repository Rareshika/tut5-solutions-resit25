#include<stdio.h>
#include<stdlib.h>

int digitCounter[10], number[30];

void countDigits(int len) {
    for (int digit = 0 ; digit <= 9 ; ++ digit) {
        digitCounter[digit] = 0;
    }

    for (int i = 0 ; i < len ; ++ i) {
        int digit = number[i];
        digitCounter[digit] += 1;
    }
}

void updateNumber(int *plen) {
    (*plen) = 0;
    for (int digit = 0 ; digit <= 9 ; ++ digit) {
        if (digitCounter[digit] == 0) {
            continue;
        }

        number[(*plen)] = digitCounter[digit];
        number[(*plen) + 1] = digit;
        (*plen) += 2;
    }
}

int main(int argc, char *argv[]) {
    char ch;
    int len = 0;
    while ((ch = getchar()) != ' ') {
        number[len] = (ch - '0');
        len += 1;
    }
    int s;
    scanf("%d", &s);

    while (s > 0) {
        countDigits(len);
        updateNumber(&len);
        s --;
    }

    for (int i = 0 ; i < len ; ++ i) {
        printf("%d", number[i]);
    }
    printf("\n");
    
    return 0;
}
