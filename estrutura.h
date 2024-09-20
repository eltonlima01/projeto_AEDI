#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct usuario
{
    char nome[99], username[99], email[99], senha[99];
};

int validaruser(char *str, struct usuario user[], int n);
int validaremail(char *str, struct usuario user[], int n);
int logar(char *userlogin, char *senha, struct usuario user[], int n);
