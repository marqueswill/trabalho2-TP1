#include <conio.h>
#include <cstdlib>
#include "../headers/curses.h"
#include <iostream>
#include <string>
using namespace std;
#include "../headers/entidades.h"
#include "../headers/dominios.h"
#include "dominios.cpp"

class cntrlIADesenvolvedor{
private:

Matricula matricula;
public:
Matricula *matricula2;
Desenvolvedor *desenvolvedor;
void cadastrar();
void executar(Matricula);
~cntrlIADesenvolvedor();
};

void cntrlIADesenvolvedor::cadastrar(){
char texto1[] = "Por favor, preencha os espaços com os seus dados:";
char texto2[] = "Nome       :";
char texto3[] = "Matricula  :";
char texto4[] = "Telefone   :";
char texto5[] = "Senha      :";
char texto6[] = "O formato dos dados é inválido. Tecle algo.";
char texto7[] = "O cadastramento foi executado com sucesso. Tecle algo.";
char texto8[] = "O cadastramento falhou. Tecle algo";
char campo1[80], campo2[80], campo3[80];
char campo4[80], campo5[80], campo6[80];
char campo7[80], campo8[80];



int linha, coluna;
getmaxyx(stdscr, linha, coluna);
clear();
mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // L� valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                                // Imprime nome do campo.
    getstr(campo5);        

Texto nome;
Matricula matricula;
Telefone telefone;
Senha senha;

nome.setValor(string(campo1));
matricula.setValor(string(campo2));
telefone.setValor(string(campo3));
senha.setValor(string(campo4));


Desenvolvedor desenvolvedor;
desenvolvedor.setNome(nome);
desenvolvedor.setMatricula(matricula);
desenvolvedor.setTelefone(telefone);
desenvolvedor.setSenha(senha);
}

int main(){
    cntrlIADesenvolvedor controladoradev;
    controladoradev.cadastrar();
    return 0;
}
