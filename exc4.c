#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "address.h"

struct address *create_address(const char *entrada) {
    struct address *novo_endereco = (struct address*) malloc(sizeof(struct address));
    
    if (novo_endereco == NULL) return NULL;

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

struct user *create_user(const char *entrada) {
    struct user *novo_usuario = (struct user*) malloc(sizeof(struct user));
    
    if (novo_usuario == NULL) return NULL;

    const char *sep1 = strchr(entrada, '#');
    const char *sep2 = strchr(sep1 + 1, '#');

    int tam_nome = sep1 - entrada;

    novo_usuario->name = (char*) malloc((tam_nome + 1) * sizeof(char));
    
    if (novo_usuario->name != NULL) {
        strncpy(novo_usuario->name, entrada, tam_nome);
        novo_usuario->name[tam_nome] = '\0';
    }

    novo_usuario->idade = atoi(sep1 + 1);
    novo_usuario->addr = create_address(sep2 + 1);

    if (novo_usuario->addr == NULL) {
        free(novo_usuario->name);
        free(novo_usuario);
        return NULL;
    }

    return novo_usuario;
}

void free_user(struct user *usuario) {
    if (usuario != NULL) {
        free(usuario->name);
        free_address(usuario->addr);
        free(usuario);
    }
}

struct user **create_user_database(int n) {
    struct user **banco_dados = (struct user**) malloc(n * sizeof(struct user*));
    
    if (banco_dados == NULL) return NULL;

    char buffer[512];

    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", buffer);
        
        banco_dados[i] = create_user(buffer);

        if (banco_dados[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free_user(banco_dados[j]);
            }
            free(banco_dados);
            return NULL;
        }
    }

    return banco_dados;
}

void free_user_database(struct user **banco_dados, int n) {
    if (banco_dados != NULL) {
        for (int i = 0; i < n; i++) {
            free_user(banco_dados[i]);
        }
        free(banco_dados);
    }
}