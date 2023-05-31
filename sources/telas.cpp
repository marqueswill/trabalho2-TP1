#include "../headers/telas.h"

void TelaMensagem::apresentar(string mensagem) {
    getmaxyx(stdscr, linha, coluna);
    initscr();

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", mensagem);
    noecho();
    getch();
    echo();

    endwin();
}

void TelaInicial::apresentar(int *campo) {
    // Mensagens a serem apresentadas na tela inicial
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Acessar sistema.";
    string texto3 = "2 - Cadastrar desenvolvedor.";
    string texto4 = "3 - Encerrar execução do sistema.";

    getmaxyx(stdscr, linha, coluna);
    initscr();

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);

    noecho();
    *campo = getch() - 48;
    echo();

    endwin();
}

void TelaUsuarioLogado::apresentar(int *campo) {
    // Mensagens a serem apresentadas na tela de usuário logado.
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Selecionar serviços relacionados a desenvolvedor.";
    string texto3 = "2 - Selecionar serviços relacionados a teste.";
    string texto4 = "3 - Selecionar serviços relacionados a caso de teste.";
    string texto5 = "4 - Encerrar sessão.";

    getmaxyx(stdscr, linha, coluna);
    initscr();

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);

    noecho();
    *campo = getch() - 48;
    echo();

    endwin();
}