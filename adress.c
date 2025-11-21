#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"

struct address *create_address(const char *entrada) {
    struct address *novo_endereco = (struct address*) malloc(sizeof(struct address));

    const char *sep1 = strchr(entrada, '|');
    const char *sep2 = strchr(sep1 + 1, '|');

    int tam_linha = sep1 - entrada;

    novo_endereco->line = (char*) malloc((tam_linha + 1) * sizeof(char));
    
    if (novo_endereco->line != NULL) {
        strncpy(novo_endereco->line, entrada, tam_linha);
        novo_endereco->line[tam_linha] = '\0';
    }

    novo_endereco->number = atoi(sep1 + 1);
    novo_endereco->zipcode = atoi(sep2 + 1);

    return novo_endereco;
}

void free_address(struct address *endereco) {
    if (endereco != NULL) {
        free(endereco->line);
        free(endereco);
    }
}