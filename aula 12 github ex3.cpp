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

    // Abre o arquivo de sa�da para escrita
    arquivo_saida = fopen("saida.txt", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao criar o arquivo de sa�da");
        fclose(arquivo_entrada);
        return EXIT_FAILURE;
    }

    // L� cada caractere do arquivo de entrada e escreve no arquivo de sa�da se n�o for espa�o ou quebra de linha
    while ((caractere = fgetc(arquivo_entrada)) != EOF) {
        if (caractere != ' ' && caractere != '\n') {
            fputc(caractere, arquivo_saida);
        }
    }

    // Fecha os arquivos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Espa�os em branco e quebras de linha removidos com sucesso!\n");

    return EXIT_SUCCESS;
}

