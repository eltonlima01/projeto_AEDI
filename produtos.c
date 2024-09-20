#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void produtos(){
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
}
