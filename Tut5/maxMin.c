#include <stdio.h>
#include <stdlib.h>

// a number is stable iff it has at least one 0-digit.
int isStable(int nr) {
    int flag = 0;
    do {
        int digit = nr % 10;
        if (digit == 0) {
            flag = 1;
        }
        nr /= 10;
    } while (nr > 0);

    return flag;
}

int findMinDigit(int nr) {
    int min = 10;
    do {
        int digit = nr % 10;
        if (digit < min) {
            min = digit;
        }
        nr /= 10;
    } while (nr > 0);
    return min;
}

int findMaxDigit(int nr) {
    int max = -1;
    do {
        int digit = nr % 10;
        if (digit > max) {
            max = digit;
        }
        nr /= 10;
    } while (nr > 0);
    return max;
}

int replaceDigitByD(int nr, int max, int d) {
    int result = 0;
    int pow10 = 1;
    do {
        int digit = nr % 10;
        if (digit == max) {
            result = d * pow10 + result;
        } else {
            result = digit * pow10 + result;
        }
        nr /= 10;
        pow10 *= 10;
    } while (nr > 0);
    return result;
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);

    int cnt = 0;
    while (!isStable(n)) {
        int min = findMinDigit(n);
        int max = findMaxDigit(n);
        int d = max - min;

        cnt += 1;
        n = replaceDigitByD(n, max, d);
    }

    printf("%d %d\n", n, cnt);
}