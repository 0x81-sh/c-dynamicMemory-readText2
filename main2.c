#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *insertText2(char *msg);

int main () {
    char* string = insertText2("Enter string: ");
    //printf("String entered: %s", string);

    return 0;
}

char *insertText2(char *msg) {
    int buffer = 3, len = 0;
    char *text = (char*)malloc(buffer * sizeof(char)), lastChar, *temp = (char*)malloc(buffer * sizeof(char));

    printf(msg);
    *text = '\0';
    do {
        fgets(temp, buffer - 1, stdin);
        lastChar = *(temp + (strlen(temp)-1));
        strcat(text, temp);
        len += buffer;
        text = (char*)realloc(text, (len * sizeof(char)) + (buffer * sizeof(char)));
        if (!text) {
            printf("Error occured!\a");
            return NULL;
        }
    }while(lastChar != '\n' );

    printf("Current length: %d, should be %d", len, strlen(text));

    return text;
}