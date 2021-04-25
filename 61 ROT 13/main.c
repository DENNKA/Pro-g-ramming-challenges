#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc > 1) {
        for (int word = 1; word < argc; word++) {
            for (int i = 0; i < strlen(argv[word]); i++) {
                int c = argv[word][i];
                // if first 13 letter {c + 13} else if last 13 letter {c - 13} else {c}
                printf("%c", c >= 65 && c < 65 + 13 || c >= 97 && c < 97 + 13 ? c + 13 :
                c >= 65 + 13 && c < 65 + 13 + 13 || c >= 97 + 13 && c < 97 + 13 + 13 ? c - 13 : c);
            }
            printf(" ");
        }
    } else printf("No input");
    printf("\n");
}
