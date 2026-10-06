#include <stdio.h>
#include <stdlib.h>

int arr[10025];

int haveSeenNumberBefore(int len, int x) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] == x) {
            return 1;
        }
    }
    return 0;
}

int squashFunction(int x, int m) {
    int sum = 0;
    do {
        int digit = x % 10;
        sum += (digit * digit) % m;
        x /= 10;
    } while (x > 0);

    return sum;
}

int main(int argc, char* argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);

    arr[0] = n;
    int len = 1;
    while (!haveSeenNumberBefore(len - 1, arr[len - 1])) {
        arr[len] = squashFunction(arr[len - 1], m);
        len++;
    }

    int target = arr[len - 1], targetPos = -1;
    for (int i = 0; i < len; ++i) {
        if (arr[i] == target) {
            targetPos = i;
            break;
        }
    }
    printf("%d\n", len - targetPos - 1);
    return 0;
}
