#include "../headers/telas.h"

#include "../headers/dominios.h"
#include "../headers/entidades.h"

//--------------------------------------------------------------------------------------------
void TelaMensagem::apresentar(string mensagem) {
    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", mensagem.c_str());

    echo();
    getch();
    noecho();
}

//--------------------------------------------------------------------------------------------
void TelaInicial::apresentar(int *campo) {
    // Mensagens a serem apresentadas na tela inicial
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Acessar sistema.";
    string texto3 = "2 - Cadastrar desenvolvedor.";
    string texto4 = "3 - Encerrar execução do sistema.";
    string texto5 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());

    noecho();
    *campo = getch() - 48;
    echo();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaUsuarioLogado::apresentar(int *campo) {
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Selecionar serviços relacionados a desenvolvedor.";
    string texto3 = "2 - Selecionar serviços relacionados a teste.";
    string texto4 = "3 - Selecionar serviços relacionados a caso de teste.";
    string texto5 = "4 - Encerrar sessão.";
    string texto6 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaDesenvolvedor::apresentar(int *campo) {
    string texto1 = "Selecione o servico desejado : ";
    string texto2 = "1 - Visualizar dados de desenvolvedor";
    string texto3 = "2 - Editar dados de desenvolvedor";
    string texto4 = "3 - Descadastrar desenvolvedor";
    string texto5 = "4 - Encerrar sessão.";
    string texto6 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

void TelaDesenvolvedor::apresentar(Desenvolvedor *desenvolvedor) {
    string texto1 = "Por favor, preencha os espaços com os seus dados:";
    string texto2 = "Nome      : ";
    string texto3 = "Matricula : ";
    string texto4 = "Telefone  : ";
    string texto5 = "Senha     : ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    echo();
    getstr(nomeDesenvolvedor);
    noecho();

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    echo();
    getstr(matriculaDesenvolvedor);
    noecho();

    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    echo();
    getstr(telefoneDesenvolvedor);
    noecho();

    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    echo();
    getstr(senhaDesenvolvedor);
    noecho();

    desenvolvedor->setNome(nome);

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaTeste::apresentar(int *campo) {
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Visualizar teste.";
    string texto3 = "2 - Cadastrar teste.";
    string texto4 = "3 - Editar teste.";
    string texto5 = "4 - Descadastrar teste.";
    string texto6 = "5 - Encerrar sessão.";
    string texto7 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto7.c_str());

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

void TelaTeste::apresentar(Codigo *codigo) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código : ";

    string texto3 = "Código informado inválido. Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    echo();
    getstr(codigoTeste);
    noecho();

    try {
        codigo->setValor(codigoTeste);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", texto3.c_str());
        echo();
        getch();
        noecho();
    };

    endwin();
}

void TelaTeste::apresentar(Teste *teste) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código : ";
    string texto3 = "Nome   : ";
    string texto4 = "Classe : ";

    string texto5 = "Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    echo();
    getstr(codigoTeste);
    noecho();

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    echo();
    getstr(nomeTeste);
    noecho();

    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    echo();
    getstr(classeTeste);
    noecho();

    try {
        codigo.setValor(codigoTeste);
        nome.setValor(nomeTeste);
        classe.setValor(classeTeste);
        teste->setCodigo(codigo);
        teste->setNome(nome);
        teste->setClasse(classe);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 5, coluna / 4, "%s", texto5.c_str());
        echo();
        getch();
        noecho();
    };

    endwin();
}

void TelaTeste::apresentar(Teste teste) {
    string texto1 = "Valores atuais do teste: ";
    string texto2 = "Código : ";
    string texto3 = "Nome   : ";
    string texto4 = "Classe : ";

    string texto5 = "Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    texto2 += teste.getCodigo().getValor();
    texto3 += teste.getNome().getValor();
    texto4 += teste.getClasse().getValor();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());

    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto5.c_str());
    echo();
    getch();
    noecho();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaCasoDeTeste::apresentar(int *campo) {
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Visualizar caso de teste.";
    string texto3 = "2 - Cadastrar caso de teste.";
    string texto4 = "3 - Editar caso de teste.";
    string texto5 = "4 - Descadastrar caso de teste.";
    string texto6 = "5 - Encerrar sessão.";
    string texto7 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto7.c_str());

    noecho();
    *campo = getch() - 48;
    echo();

    endwin();
}

void TelaCasoDeTeste::apresentar(Codigo *codigo) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código : ";

    string texto3 = "Código informado inválido. Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2.c_str());
    echo();
    getstr(codigoCasoDeTeste);
    noecho();

    try {
        codigo->setValor(codigoCasoDeTeste);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3.c_str());
        echo();
        getch();
        noecho();
    };

    endwin();
}

void TelaCasoDeTeste::apresentar(CasoDeTeste *casodeteste) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código    : ";
    string texto3 = "Nome      : ";
    string texto4 = "Data      : ";
    string texto5 = "Ação      : ";
    string texto6 = "Resposta  : ";
    string texto7 = "Resultado : ";

    string texto8 = "Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    echo();
    getstr(codigoCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    echo();
    getstr(nomeCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    echo();
    getstr(dataCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    echo();
    getstr(acaoCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());
    echo();
    getstr(respostaCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto7.c_str());
    echo();
    getstr(resultadoCasoDeTeste);
    noecho();

    try {
        codigo.setValor(codigoCasoDeTeste);
        data.setValor(dataCasoDeTeste);
        acao.setValor(acaoCasoDeTeste);
        resposta.setValor(respostaCasoDeTeste);
        resultado.setValor(resultadoCasoDeTeste);
        casodeteste->setCodigo(codigo);
        casodeteste->setData(data);
        casodeteste->setAcao(acao);
        casodeteste->setResposta(resposta);
        casodeteste->setResultado(resultado);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 8, coluna / 4, "%s", texto8.c_str());
    };

    endwin();
}

void TelaCasoDeTeste::apresentar(CasoDeTeste casodeteste) {
    string texto1 = "Valores atuais do teste: ";
    string texto2 = "Código    : ";
    string texto3 = "Nome      : ";
    string texto4 = "Data      : ";
    string texto5 = "Ação      : ";
    string texto6 = "Resposta  : ";
    string texto7 = "Resultado : ";

    string texto8 = "Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    texto2 += casodeteste.getCodigo().getValor();
    texto3 += casodeteste.getNome().getValor();
    texto4 += casodeteste.getData().getValor();
    texto5 += casodeteste.getAcao().getValor();
    texto6 += casodeteste.getResposta().getValor();
    texto7 += casodeteste.getResultado().getValor();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto7.c_str());

    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto8.c_str());

    echo();
    getch();
    noecho();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaDepuracao::apresentar(int *campo) {
    string texto1 = "Selecione tipo de teste a ser executado : ";
    string texto2 = "1 - Executar testes unitários.";
    string texto3 = "2 - Executar testes de integração.";
    string texto4 = "3 - Executar testes fumaça.";
    string texto5 = "4 - Executar testes sistema.";
    string texto6 = "5 - Encerrar depuração.";
    string texto7 = "Digite a opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto7.c_str());

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

void TelaTestesUnitarios::apresentar(int *campo) {
    string texto1 = "Selecione unidades de teste: ";
    string texto2 = "1 - Executar testes domínios.";
    string texto3 = "2 - Executar testes entidades.";
    string texto4 = "3 - Executar testes modulos.";
    string texto5 = "4 - Retornar.";
    string texto6 = "Digite a opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}