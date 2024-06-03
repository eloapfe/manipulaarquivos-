#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo_entrada, *arquivo_saida;
    char caractere, prox_caractere;

    // Abre o arquivo de entrada
    arquivo_entrada = fopen("codigo_fonte.c", "r");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        return EXIT_FAILURE;
    }

    // Abre o arquivo de sa�da
    arquivo_saida = fopen("codigo_sem_comentarios.c", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao criar arquivo de sa�da");
        fclose(arquivo_entrada);
        return EXIT_FAILURE;
    }

    // Remove os coment�rios do arquivo de entrada e salva no arquivo de sa�da
    while ((caractere = fgetc(arquivo_entrada)) != EOF) {
        if (caractere == '/') {
            prox_caractere = fgetc(arquivo_entrada);
            if (prox_caractere == '/') {
                // Coment�rio de linha, ignora tudo at� o fim da linha
                while ((caractere = fgetc(arquivo_entrada)) != '\n' && caractere != EOF) {}
            } else if (prox_caractere == '*') {
                // Coment�rio de bloco, ignora tudo at� encontrar '*/'
                while ((caractere = fgetc(arquivo_entrada)) != EOF) {
                    if (caractere == '*') {
                        prox_caractere = fgetc(arquivo_entrada);
                        if (prox_caractere == '/') {
                            break;
                        }
                    }
                }
            } else {
                // N�o � um coment�rio, ent�o volta para o caractere '/'
                fputc(caractere, arquivo_saida);
                fputc(prox_caractere, arquivo_saida);
            }
        } else {
            fputc(caractere, arquivo_saida);
        }
    }

    // Fecha os arquivos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Coment�rios removidos com sucesso!\n");

    return EXIT_SUCCESS;
}

