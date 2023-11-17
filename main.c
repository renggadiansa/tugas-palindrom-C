#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char input[100]);

int main() {

    char input[100];
    printf("Masukkan input: ");
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    printf("Kalimat asli: %s\n", input);

    char reversedInput[100];
    strcpy(reversedInput, input);
    reverseString(reversedInput);

    printf("Kalimat setelah di reverse: %s\n", reversedInput);

    char inputTanpaSpasi[100];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(input[i])) {
            inputTanpaSpasi[j++] = tolower(input[i]);
        }
    }
    inputTanpaSpasi[j] = '\0';

    char reversedInputTanpaSpasi[100];
    strcpy(reversedInputTanpaSpasi, inputTanpaSpasi);
    reverseString(reversedInputTanpaSpasi);

    int hasil = strcmp(inputTanpaSpasi, reversedInputTanpaSpasi);

    if (hasil == 0) {
        printf("String palindrom\n");
    } else {
        printf("String bukan palindrom\n");
    }

    return 0;
}

void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
