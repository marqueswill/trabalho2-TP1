#include "../headers/telas.h"
using namespace std;

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

void Tela_Inicial::falha_autenticacao(){
    getmaxyx(stdscr, linha, coluna);
    clear();                                         // Limpa janela.
    mvprintw(linha / 4, coluna / 4, "%s", texto10);  // Imprime mensagem.
    noecho();                                        // Desabilita eco.
    getch();                                         // Leitura de caracter digitado.
    echo(); 
}