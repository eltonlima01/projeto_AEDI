#include"estrutura.h"


void escrever_arquivo_usuario(struct usuario user){
    FILE *arquivo = fopen("usuarios.txt", "wt");
    fprintf(arquivo, "Nome: %s\nNome de usuario: %s\nE-mail: %s\nSenha: %s", user.nome, user.username, user.email, user.senha);
    fclose(arquivo);
}

struct usuario *ler_arquivo_usuario(int *quantidade){
    struct usuario *vetor = (struct usuario *)malloc(sizeof(struct usuario) * 999);
    FILE *arquivo = fopen("usuarios.txt", "rt");
    int i = 0;
    char leitor[100];
    for(fscanf(arquivo, "Nome: % [^\n]\n", leitor); arquivo != EOF; i++){
        strcpy(vetor[i].nome, leitor);
        fscanf(arquivo, "Nome de usuario: %[^\n]\n", leitor);
        strcpy(vetor[i].username, leitor);

    }
    quantidade = i;
    fclose(arquivo);
}

