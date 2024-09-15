#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void limparbuffer()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF &&
           ch != '\n')
        ;
}
struct usuario
{
    char nome[99], username[99], email[99], senha[99];
};
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