#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* Kristade Swain here. This project reads a file of text and generates a cipher of the file. A cipher is simply a secret or disguised way of writing the text. We disguise the text by shifting it to the right (or left) and also incrementing (or
decrementing) the letters and digits in the text.*/

void functI(char* word) {
        for(int a = 0; a < strlen(word); a++) {
                if (isalpha(word[a])) {
                        if (word[a] == 'z') word[a] = 'a';
                        else if (word[a] == 'Z') word[a] = 'A';
                        else word[a] = word[a] + 1;
                }
                else if (isdigit(word[a])) {
                        if (word[a] == '9') word[a] = '0';
                        else word[a] = word[a] + 1;
                }
        }
        return;
}
void functD(char* word) {
        for (int a = 0; a < strlen(word); a++) {
                if (isalpha(word[a])) {
                        if (word[a] == 'a') word[a] = 'z';
						else if (word[a] == 'A') word[a] = 'Z';
                        else word[a] = word[a] - 1;
                }
                else if (isdigit(word[a])) {
                        if (word[a] == '0') word[a] = '9';
                        else word[a] = word[a] - 1;
                }
        }
        return;
}
void functL(char* word) {
        int b = strlen(word);
        char term = word[0];
        for (int a = 0; a < b-1; a++)
                word[a] = word[a + 1];
        word[b-1] = term;
        return;
}
void functR(char* word) {
        int b = strlen(word);
        char term = word[b-1];
        for (int a = b-1; a > 0 && a < b; a--)
                word[a] = word[a - 1];
        word[0] = term;
        return;
}
int main(int argc, char *argv[]) {
        FILE *file = fopen(argv[1], "r");
        char word[50] = "";
	char *cipher;
        cipher = argv[2];

        if (file == NULL) {
                printf("Error: %s does not exist.", argv[1]);
                exit(-1);
        }

        fscanf(file, "%s", word);

        while (!feof(file)) {
                for(int a = 0; a < strlen(cipher); a++) {
                        if (cipher[a] == 'I') functI(word);
                        if (cipher[a] == 'D') functD(word);
                        if (cipher[a] == 'L') functL(word);
                        if (cipher[a] == 'R') functR(word);
                        if (cipher[a] != 'I' && cipher[a] != 'D' && cipher[a] != 'L' && cipher[a] != 'R') {
                                printf("Error: the command is invalid.");
                                exit (-1);
                        }
                }
                printf("%s\n", word);
                fscanf(file, "%s", word);
        }
        fclose(file);
        return 0;
}
