#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "address.h"

struct user *create_user(const char *entrada) {
    struct user *novo_usuario = (struct user*) malloc(sizeof(struct user));

    const char *sep1 = strchr(entrada, '#');
    const char *sep2 = strchr(sep1 + 1, '#');

    int tam_nome = sep1 - entrada;

    novo_usuario->name = (char*) malloc((tam_nome + 1) * sizeof(char));
    strncpy(novo_usuario->name, entrada, tam_nome);
    novo_usuario->name[tam_nome] = '\0';

    novo_usuario->idade = atoi(sep1 + 1);

    novo_usuario->addr = create_address(sep2 + 1);

    return novo_usuario;
}

void free_user(struct user *usuario) {
    if (usuario != NULL) {
        free(usuario->name);
        free_address(usuario->addr);
        free(usuario);
    }
}