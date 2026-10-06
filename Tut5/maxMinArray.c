#include<stdio.h>
#include<stdlib.h>

int arr[100];

// a number is stable only if it has 0 as a digit
int isStable(int len) {
    for (int i = 0 ; i < len ; ++ i) {
        int digit = arr[i];
        if (digit == 0) {
            return 1;
        }
    }
    return 0;
}

int findMaxDigit(int len) {
    int max = 0;
    for (int i = 0 ; i < len ; ++ i) {
        int digit = arr[i];
        if (digit > max) {
            max = digit;
        }
    }
    return max;
}

int findMinDigit(int len) {
    int min = 9;
    for (int i = 0 ; i < len ; ++ i) {
        int digit = arr[i];
        if (digit < min) {
            min = digit;
        }
    }
    return min;
}

void replaceDigitByD(int len, int max, int d) {
    for (int i = 0 ; i < len ; ++ i) {
        int digit = arr[i];
        if (digit == max) {
            arr[i] = d;
        }
    }
}

// 582
// 562
// 542
// 342
// 322
// 122
// 111
// 000

// 909
// 909

// 000203
void printNumber(int len) {
    int i = 0;
    while (i < len && arr[i] == 0) {
        i ++;
    }

    if (i == len) {
        printf("0");
        return;
    }

    while(i < len) {
        printf("%d", arr[i]);
        i ++;
    }
}

int main(int argc, char *argv[]) {
    char ch;
    int len = 0;
    while((ch = getchar()) != EOF) { // '2'
        // character ch which will be our digit
        // ch = '1', '7'
        int digit = ch - '0'; // '2' -> 2(int)
        arr[len] = digit; // add the integer digit to our array
        len ++; // increase its length
    }

    int steps = 0;
    while (!isStable(len)) {
        int max = findMaxDigit(len);
        int min = findMinDigit(len);
        int d = max - min;

        steps ++;
        replaceDigitByD(len, max, d);
    }

    printNumber(len);
    printf(" %d\n", steps);
    return 0;
}
