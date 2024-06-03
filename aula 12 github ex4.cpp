#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int is_separator(char c) {
    return c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.' || c == ';' || c == ':' || c == '!' || c == '?' || c == '"';
}

void remove_punctuation(char *word) {
    int len = strlen(word);
    if (len == 0) return;

    while (is_separator(word[len - 1])) {
        word[len - 1] = '\0';
        len--;
    }
}

int main() {
    FILE *input_file;
    FILE *output_file;
    char word[MAX_WORD_LENGTH];
    WordFrequency word_freq[MAX_WORDS];
    int num_words = 0;

    // Abre o arquivo de entrada
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        return EXIT_FAILURE;
    }

    // Conta a frequência de cada palavra
    while (fscanf(input_file, "%s", word) != EOF) {
        remove_punctuation(word);

        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, word_freq[i].word) == 0) {
                word_freq[i].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (num_words < MAX_WORDS) {
                strcpy(word_freq[num_words].word, word);
                word_freq[num_words].frequency = 1;
                num_words++;
            } else {
                printf("Número máximo de palavras excedido.\n");
                return EXIT_FAILURE;
            }
        }
    }

    fclose(input_file);

    // Abre o arquivo de saída
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Erro ao criar arquivo de saída");
        return EXIT_FAILURE;
    }

    // Escreve a frequência de cada palavra no arquivo de saída
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s: %d\n", word_freq[i].word, word_freq[i].frequency);
    }

    fclose(output_file);

    printf("Frequência das palavras contada e salva em 'output.txt'\n");

    return EXIT_SUCCESS;
}

