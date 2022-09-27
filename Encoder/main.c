#include <stdlib.h>
#include <stdio.h>

void record();
void read();
void encode();

int main() {
    char *file[9999];

    read(file);

    encode(file);

    record(file);

    printf("[3] - Program Finished\n");
    
    return 0;
}

void record(char *text) {
    FILE *file; 

    file = fopen("./encoded_files/0.txt", "w");
    if(file == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(file, "%s", text);
    printf("[2] - Encoded File Recorded!\n");

    fclose(file);
}

void read(char *text) {
    FILE *file;

    file = fopen("./decoded_files/0.txt", "r");
    if(file == NULL) {
        printf("Error!");
        exit(1);
    }

    fscanf(file, "%s", text);
    printf("[0] - File Readed!\n");

    fclose(file);
}

void encode(char *text) {
    char encodedLetters[38] = " qwertyuiopasdfghjklzxcvbnm0897645312";
    char letters[38] =        " abcdefghijklmnopqrstuvwxyz1234567890";
    int i, j;

    for(i = 0; text[i] != '\0'; i++){
        for(j = 0; letters[j] != '\0'; j++) {
            if(text[i] == letters[j]) {
                text[i] = encodedLetters[j];
                break;
            }
        }
    }

    printf("[1] - File Encoded!\n");
}