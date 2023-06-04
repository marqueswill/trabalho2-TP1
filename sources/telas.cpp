#include "../headers/telas.h"
#include "../headers/entidades.h"
#include "../headers/comandos.h"
#include "comandos.cpp"
#include "../headers/dominios.h"
#include "dominios.cpp"
#include "entidades.cpp"
using namespace std;
void Tela::apresentar(string generica){
    getmaxyx(stdscr, linha, coluna);
    clear();                                         // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", generica);  // Imprime mensagem.
    noecho();                                        // Desabilita eco.                                       // Leitura de caracter digitado.
    echo(); 
}

void Tela_Inicial::selecionar_servicos_inicial(){
    getmaxyx(stdscr, linha, coluna);  // Armazena quantidade de linhas e colunas.
        clear();                                            // Limpa janela.
        mvprintw(linha / 4, coluna / 4, "%s", texto1);      // Imprime nome do campo.
        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);  // Imprime nome do campo.
        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);  // Imprime nome do campo.

        noecho();
        campo = getch() - 48;  // Leitura do campo de entrada e conversão de ASCII.
        echo();
}


void Tela_Inicial::selecionar_servicos_logado(){
    getmaxyx(stdscr, linha, coluna);                         // Apresenta tela de seleção de serviço.
    clear();                                            // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto6);      // Imprime nome do campo.
                        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto7);  // Imprime nome do campo.
                        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto8);  // Imprime nome do campo.
                        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto9);  // Imprime nome do campo.

                        noecho();
                        campo = getch() - 48;  // Leitura do campo de entrada e conversão de ASCII.
                        echo();
}

void Tela_Apresentacao_Desenvolvedor::cadastrar_desenvolvedor(Desenvolvedor *dev){
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
desenvolvedor.setNome(nome);
}