#include"estrutura.h"
#include"usuarios.c"


void limparbuffer()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF &&
           ch != '\n')
        ;
}


int qtduser = 0;
int main()
{
    setlocale(LC_ALL, "portuguese");
    int validaruser(char *str, struct usuario user[], int n);
    int logar(char *userlogin, char *senha, struct usuario user[], int n);
    int n = 3;
    struct usuario *user = malloc(n * sizeof(struct usuario));
    char nome[99], usuario[99], email[99], senha[99], loginuser[99], loginsenha[99];
    int z;
    do
    {
        puts("1 - Entrar;\n2 - Cadastrar;\n0 - Sair.");
        scanf("%i", &z);
        switch (z)
        {
            // LOGIN
        case 1: // Variáveis temporárias para o login
            puts("User:");
            scanf("%s", loginuser);
            puts("Senha:");
            scanf("%s", loginsenha);
            if (logar(loginuser, loginsenha, user, qtduser) != 0)
            {
                // Deu certo
            }
            else
            {
                puts("E-mail ou senha inválidos!");
            }
            break;
            // CADASTRO
        case 2:
            puts("Digite o seu nome:");
            scanf(" %99[^\n]", nome);
            limparbuffer();
            puts("Crie um nome de usuário:");
            scanf("%s", usuario);
            limparbuffer();
            while(validaruser(usuario, user, qtduser) != 0)
            {
                puts("Nome de usuário inválido!");
                puts("Crie um nome de usuário:");
                scanf("%s", usuario);
            };
            puts("Digite o seu e-mail:");
            scanf("%s", email);
            limparbuffer();
            if (validaremail(email, user, qtduser) != 0)
            {
                puts("E-mail inválido!");
            }
            puts("Crie uma senha:");
            scanf("%s", senha);
            limparbuffer();
            strcpy(user[qtduser].username, usuario);
            strcpy(user[qtduser].email, email);
            strcpy(user[qtduser].senha, senha);
            strcpy(user[qtduser].nome, nome);
            qtduser++;
            if (qtduser > n)
            {
                n = n + 3;
                user = realloc(user, n * sizeof(struct usuario));
            }
            break;
            // SAIR
        case 0:
            puts("Sai");
            break;
        default:
            puts("Entrada inválida");
        }
    } while (z != 0);
    return 0;
}
// FUNÇÃO PARA CADASTRAR USUÁRIO
int validaruser(char *str, struct usuario user[], int n)
{
    int jaexiste = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(user[i].username, str) == 0)
        {
            return jaexiste + 1;
        }
    }
    return jaexiste;
}
int validaremail(char *str, struct usuario user[], int n)
{
    // falta ajeitar a questao do arroba
    int jaexiste = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(user[i].email, str) == 0)
        {
            return jaexiste + 1;
        }
    }
    return jaexiste;
}
int logar(char *userlogin, char *senha, struct usuario user[], int n)
{
    int validado = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(user[i].email, userlogin) == 0 || strcmp(user[i].senha, senha))
        {
            return validado + 1;
        }
    }
    return validado;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct produto {
    char nome[99];
    float preco;
};

void limparbuffer() {
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n') ;
}

int qtdprodutos = 0;

void listarProdutos(struct produto *produtos, int qtd) {
    if (qtd == 0) {
        puts("Nenhum produto cadastrado.");
        return;
    }
    puts("Lista de Produtos:");
    for (int i = 0; i < qtd; i++) {
        printf("%d - Nome: %s, Preço: %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }
}

void cadastrarProduto(struct produto *produtos, int *qtd) {
    char nome[99];
    float preco;

    puts("Digite o nome do produto:");
    scanf(" %99[^\n]", nome);
    limparbuffer();
    
    puts("Digite o preço do produto:");
    scanf("%f", &preco);
    limparbuffer();

    strcpy(produtos[*qtd].nome, nome);
    produtos[*qtd].preco = preco;
    (*qtd)++;
}

void editarProduto(struct produto *produtos, int qtd) {
    int index;
    listarProdutos(produtos, qtd);
    puts("Digite o número do produto que deseja editar:");
    scanf("%d", &index);
    limparbuffer();

    if (index < 1 || index > qtd) {
        puts("Produto inválido.");
        return;
    }

    index--;

    char nome[99];
    float preco;
    puts("Digite o novo nome do produto:");
    scanf(" %99[^\n]", nome);
    limparbuffer();
    
    puts("Digite o novo preço do produto:");
    scanf("%f", &preco);
    limparbuffer();

    strcpy(produtos[index].nome, nome);
    produtos[index].preco = preco;
}

void excluirProduto(struct produto *produtos, int *qtd) {
    int index;
    listarProdutos(produtos, *qtd);
    puts("Digite o número do produto que deseja excluir:");
    scanf("%d", &index);
    limparbuffer();

    if (index < 1 || index > *qtd) {
        puts("Produto inválido.");
        return;
    }

    index--;

    for (int i = index; i < *qtd - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    (*qtd)--;
    puts("Produto excluído com sucesso.");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int n = 3;
    struct produto *produtos = malloc(n * sizeof(struct produto));
    int z;

    do {
        puts("1 - Cadastrar Produto;\n2 - Editar Produto;\n3 - Excluir Produto;\n4 - Listar Produtos;\n0 - Sair.");
        scanf("%i", &z);
        limparbuffer();
        switch (z) {
            case 1:
                if (qtdprodutos >= n) {
                    n += 3;
                    produtos = realloc(produtos, n * sizeof(struct produto));
                }
                cadastrarProduto(produtos, &qtdprodutos);
                break;
            case 2:
                editarProduto(produtos, qtdprodutos);
                break;
            case 3:
                excluirProduto(produtos, &qtdprodutos);
                break;
            case 4:
                listarProdutos(produtos, qtdprodutos);
                break;
            case 0:
                puts("Saindo...");
                break;
            default:
                puts("Entrada inválida");
        }
    } while (z != 0);

    free(produtos);
    return 0;
}
