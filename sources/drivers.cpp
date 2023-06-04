#include "../headers/drivers.h"

//--------------------------------------------------------------------------------------------
void Drivers::showResult(bool resultado, string nome) {
    string texto1 = "SUCESSO";
    string texto2 = "FALHA";

    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);

    static int linha_atual = linha / 4 + 1;

    texto1 = nome + string(16 - nome.length(), '.') + texto1;
    texto2 = nome + string(16 - nome.length(), '.') + texto2;

    if (resultado) {
        mvprintw(linha_atual, coluna / 4, "%s", texto1.c_str());
    } else {
        mvprintw(linha_atual, coluna / 4, "%s", texto2.c_str());
    }

    linha_atual++;
}

//--------------------------------------------------------------------------------------------
void DriverTestesDominios::executar() {
    int linha, coluna;
    string title = "DOMINIOS";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", title.c_str());
    showResult(testeClasse.run(), "Classe");
    showResult(testeCodigo.run(), "Codigo");
    showResult(testeData.run(), "Data");
    showResult(testeMatricula.run(), "Matricula");
    showResult(testeResultado.run(), "Resultado");
    showResult(testeSenha.run(), "Senha");
    showResult(testeTelefone.run(), "Telefone");
    showResult(testeTexto.run(), "Texto");

    mvprintw(linha / 4 + 9, coluna / 4, "%s", "");
    echo();
    getch();
    noecho();

    endwin();
}

//--------------------------------------------------------------------------------------------
void DriverTestesEntidades::executar() {
    int linha, coluna;
    string title = "ENTIDADES";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", title.c_str());
    showResult(testeDesenvolvedor.run(), "Desenvolvedor");
    showResult(testeTeste.run(), "Teste");
    showResult(testeCasoDeTeste.run(), "CasoDeTeste");

    mvprintw(linha / 4 + 9, coluna / 4, "%s", "");
    echo();
    getch();
    noecho();

    endwin();
}