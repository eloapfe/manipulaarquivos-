#include <stdio.h>
#include <stdlib.h>

#define SHIFT 3 // O deslocamento usado para a cifra de substitui��o

int main() {
    FILE *entrada, *saida;
    char caractere;

    // Abre o arquivo de entrada para leitura
    entrada = fopen("arquivo_original.txt", "r");
    if (entrada == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        return EXIT_FAILURE;
    }

    // Abre o arquivo de sa�da para escrita
    saida = fopen("arquivo_criptografado.txt", "w");
    if (saida == NULL) {
        perror("Erro ao criar arquivo de sa�da");
        fclose(entrada);
        return EXIT_FAILURE;
    }

    // Criptografa o conte�do do arquivo de entrada e escreve no arquivo de sa�da
    while ((caractere = fgetc(entrada)) != EOF) {
        // Verifica se o caractere � uma letra min�scula
        if (caractere >= 'a' && caractere <= 'z') {
            // Aplica a cifra de substitui��o
            caractere = 'a' + (caractere - 'a' + SHIFT) % 26;
        }
        // Escreve o caractere criptografado no arquivo de sa�da
        fputc(caractere, saida);
    }

    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);

    printf("Conte�do criptografado salvo em 'arquivo_criptografado.txt'\n");

    return EXIT_SUCCESS;
}

