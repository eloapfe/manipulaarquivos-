#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo1, *arquivo2, *arquivo_saida;
    char linha[100];

    // Abre os arquivos de entrada
    arquivo1 = fopen("arquivo1.txt", "r");
    arquivo2 = fopen("arquivo2.txt", "r");
    if (arquivo1 == NULL || arquivo2 == NULL) {
        perror("Erro ao abrir arquivo");
        return EXIT_FAILURE;
    }

    // Abre o arquivo de saída
    arquivo_saida = fopen("arquivo_saida.txt", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao criar arquivo de saída");
        return EXIT_FAILURE;
    }

    // Lê e escreve alternadamente as linhas dos arquivos de entrada no arquivo de saída
    while (fgets(linha, sizeof(linha), arquivo1) != NULL || fgets(linha, sizeof(linha), arquivo2) != NULL) {
        if (linha[0] != '\0') // Verifica se a linha lida não está vazia
            fputs(linha, arquivo_saida);

        if (fgets(linha, sizeof(linha), arquivo2) != NULL) // Lê a próxima linha do arquivo 2
            fputs(linha, arquivo_saida);
    }

    // Fecha os arquivos
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo_saida);

    printf("Arquivos mesclados com sucesso!\n");

    return EXIT_SUCCESS;
}

