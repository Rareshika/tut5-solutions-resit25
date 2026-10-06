#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int speedLimit, driverSpeed;
    scanf("%d%d", &speedLimit, &driverSpeed);

    double r = (double)driverSpeed / speedLimit;
    if (r <= 1.0) {
        printf("LEGAL\n");
        return 0;
    }
    if (r <= 1.2) {
        printf("MINOR\n");
        return 0;
    }
    if (r <= 1.5) {
        printf("MAJOR\n");
        return 0;
    }
    printf("SEVERE\n");
    return 0;
}
