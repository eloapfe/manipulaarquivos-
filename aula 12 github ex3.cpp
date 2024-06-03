#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo_entrada, *arquivo_saida;
    char caractere;

    // Abre o arquivo de entrada para leitura
    arquivo_entrada = fopen("entrada.txt", "r");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return EXIT_FAILURE;
    }

    // Abre o arquivo de saída para escrita
    arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        fclose(arquivo_entrada);
        return EXIT_FAILURE;
    }

    // Lê cada caractere do arquivo de entrada e escreve no arquivo de saída se não for espaço ou quebra de linha
    while ((caractere = fgetc(arquivo_entrada)) != EOF) {
        if (caractere != ' ' && caractere != '\n') {
            fputc(caractere, arquivo_saida);
        }
    }

    // Fecha os arquivos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Espaços em branco e quebras de linha removidos com sucesso!\n");

    return EXIT_SUCCESS;
}

