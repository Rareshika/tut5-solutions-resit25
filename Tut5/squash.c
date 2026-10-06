#include <stdio.h>
#include <stdlib.h>

int arr[10015];

int sumOfSquaredDigits(int nr, int m) {
    int sum = 0;
    do {
        int digit = nr % 10;
        sum += (digit * digit) % m;
        nr /= 10;
    } while (nr > 0);

    return sum;
}

int main(int argc, char* argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);

    int step = 1;
    if (n >= m) {
        n = sumOfSquaredDigits(n, m);
    }

    while (arr[n] == 0) {
        arr[n] = step;
        n = sumOfSquaredDigits(n, m);
        step++;
    }
    printf("%d\n", step - arr[n]);

    return 0;
}
