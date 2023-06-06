#include "../headers/drivers.h"

//--------------------------------------------------------------------------------------------
void Drivers::showResult(bool resultado, string nome, int l) {
    string texto1 = "SUCESSO";
    string texto2 = "FALHA";

    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);

    int linha_atual = linha / 4 + l;

    texto1 = nome + string(16 - nome.length(), '.') + texto1;
    texto2 = nome + string(16 - nome.length(), '.') + texto2;

    if (resultado) {
        mvprintw(linha_atual, coluna / 4, "%s", texto1.c_str());
    } else {
        mvprintw(linha_atual, coluna / 4, "%s", texto2.c_str());
    }
}

//--------------------------------------------------------------------------------------------
void DriverDepuracao::executar() {
    DriverTestesUnitarios testesUnitarios;

    int campo;

    bool apresentar = true;
    while (apresentar) {
        TelaDepuracao telaDepuracao;
        telaDepuracao.apresentar(&campo);

        switch (campo) {
            case TESTE_UNITARIO:
                testesUnitarios.executar();
                break;
            case TESTE_INTEGRACAO:
                break;
            case TESTE_FUMACA:
                break;
            case TESTE_SISTEMA:
                break;
            case SAIR:
                apresentar = false;
                break;
            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
}

//--------------------------------------------------------------------------------------------
void DriverTestesUnitarios::executar() {
    DriverTestesDominios testesDominios;
    DriverTestesEntidades testesEntidades;

    int campo;

    bool apresentar = true;
    while (apresentar) {
        TelaTestesUnitarios telaTestesUnitarios;
        telaTestesUnitarios.apresentar(&campo);

        switch (campo) {
            case DOMINIOS:
                testesDominios.executar();
                break;
            case ENTIDADES:
                testesEntidades.executar();
                break;
            case MODULOS:
                break;
            case SAIR:
                apresentar = false;
                break;
            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
}

//--------------------------------------------------------------------------------------------
void DriverTestesDominios::executar() {
    int linha, coluna;
    string title = "DOMINIOS";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", title.c_str());
    showResult(testeClasse.run(), "Classe", 1);
    showResult(testeCodigo.run(), "Codigo", 2);
    showResult(testeData.run(), "Data", 3);
    showResult(testeMatricula.run(), "Matricula", 4);
    showResult(testeResultado.run(), "Resultado", 5);
    showResult(testeSenha.run(), "Senha", 6);
    showResult(testeTelefone.run(), "Telefone", 7);
    showResult(testeTexto.run(), "Texto", 8);

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
    showResult(testeDesenvolvedor.run(), "Desenvolvedor", 1);
    showResult(testeTeste.run(), "Teste", 2);
    showResult(testeCasoDeTeste.run(), "CasoDeTeste", 3);

    mvprintw(linha / 4 + 9, coluna / 4, "%s", "");
    echo();
    getch();
    noecho();

    endwin();
}