#include <locale.h>

#include <iomanip>
#include <iostream>

#include "../headers/drivers.h"
#include "dominios.cpp"
#include "drivers.cpp"
#include "entidades.cpp"
#include "testes_dominios.cpp"
#include "testes_entidades.cpp"

#define TESTE ;

using namespace std;

int main() {
#ifdef TESTE;
    // Criar tela seleção de teste
    char texto1[] = "Selecione teste a ser executado : ";
    char texto2[] = "1 - Executar testes domínios.";
    char texto3[] = "2 - Executar testes entidades.";
    char texto4[] = "3 - Encerrar execução do sistema.";
    char texto5[] = "Digite a opção: ";

    int linha, coluna;
    int campo;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);

    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);

    echo();
    campo = getch() - 48;
    noecho();

    DriverTestesDominios testesDominios;
    DriverTestesEntidades testesEntidades;

    switch (campo) {
        case 1:
            testesDominios.executar();
            break;
        case 2:
            testesEntidades.executar();
            break;
        default:
            break;
    }

    endwin();

#endif  // TESTE

    return 0;
}
