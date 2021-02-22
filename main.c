#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define DEBUG_INFO 1

bool containsNewline (char *, int);
char* readText2 (int, char *);

int main() {
    char *out = readText2(10, "Enter string: ");
    printf("\nRead text: %s", out);

    return 0;
}

bool containsNewline (char *str, int length) {
    bool nL = false;
    for (int i = 0; i < length; i++) {
        if (*(str + i) == '\n') nL = true;
    }

    return nL;
}

char* readText2 (int steps, char* msg) {
    steps++;
    int currentLength = 0;
    char *out = (char*) malloc(steps * sizeof(char));
    printf("%s", msg);

    char tempStr[steps + 1];
    while (!containsNewline(tempStr, steps)) {
        fgets(tempStr, steps, stdin);
        currentLength += (steps - 1);

        out = (char*) realloc(out, (currentLength * sizeof(char)) + 1);
        if (currentLength - steps + 1 == 0) {
            strcpy(out, tempStr);
            continue;
        }
        strcat(out, tempStr);
    }

    if (DEBUG_INFO) {
        printf("Debug info:\n");
        printf("String usage: %.2f%% [Memory: %d bytes, actual string length: %d bytes]\n", (float) strlen(out) / (float) currentLength * 100, currentLength * sizeof(char), strlen(out) * sizeof(char));
    }

    return out;
}
