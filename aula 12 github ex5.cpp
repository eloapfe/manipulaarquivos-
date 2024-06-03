#include <stdio.h>
#include <stdlib.h>

#define SHIFT 3 // O deslocamento usado para a cifra de substituição

int main() {
    FILE *entrada, *saida;
    char caractere;

    // Abre o arquivo de entrada para leitura
    entrada = fopen("arquivo_original.txt", "r");
    if (entrada == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        return EXIT_FAILURE;
    }

    // Abre o arquivo de saída para escrita
    saida = fopen("arquivo_criptografado.txt", "w");
    if (saida == NULL) {
        perror("Erro ao criar arquivo de saída");
        fclose(entrada);
        return EXIT_FAILURE;
    }

    // Criptografa o conteúdo do arquivo de entrada e escreve no arquivo de saída
    while ((caractere = fgetc(entrada)) != EOF) {
        // Verifica se o caractere é uma letra minúscula
        if (caractere >= 'a' && caractere <= 'z') {
            // Aplica a cifra de substituição
            caractere = 'a' + (caractere - 'a' + SHIFT) % 26;
        }
        // Escreve o caractere criptografado no arquivo de saída
        fputc(caractere, saida);
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Conteúdo criptografado salvo em 'arquivo_criptografado.txt'\n");

    return EXIT_SUCCESS;
}

