#include<stdio.h>
#include<stdlib.h>

int wordHasPairs(char word[], int len) {
    for (int i = 1 ; i < len ; ++ i) {
        if (word[i] == word[i - 1]) {
            return 1;
        }
    }
    return 0;
}

void removeFirstPair(char word[], int *plen) {
    int pairPosition = 0;
    for (int i = 1 ; i < (*plen) ; ++ i) {
        if (word[i] == word[i - 1]) {
            pairPosition = i;
            break;
        }
    }

    for (int i = pairPosition + 1 ; i < (*plen) ; ++ i) {
        word[i - 2] = word[i];
    }

    (*plen) -= 2;
}

int main(int argc, char *argv[]) {
    char ch;
    char word[25];
    int len = 0;
    while ((ch = getchar()) != EOF) {
        word[len] = ch;
        len ++;
    }

    while (len >= 2 && wordHasPairs(word, len)) {
        int pairPosition = 0;
        for (int i = 1 ; i < len ; ++ i) {
            if (word[i] == word[i - 1]) {
                pairPosition = i;
                break;
            }
        }

        for (int i = pairPosition + 1 ; i < len ; ++ i) {
            word[i - 2] = word[i];
        }
        len -= 2;
    }

    if (len == 0) {
        printf("###\n");
    } else {
        for (int i = 0 ; i < len ; ++ i) {
            printf("%c", word[i]);
        }
        printf("\n");
    }
    return 0;
}
