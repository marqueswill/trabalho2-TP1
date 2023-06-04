#include "../headers/telas.h"

#include "../headers/dominios.h"
#include "../headers/entidades.h"

//--------------------------------------------------------------------------------------------
void TelaMensagem::apresentar(string mensagem) {
    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", mensagem);

    echo();
    getch();
    noecho();
}

//--------------------------------------------------------------------------------------------
void TelaInicial::apresentar(int *campo) {
    // Mensagens a serem apresentadas na tela inicial
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Acessar sistema.";
    char texto3[] = "2 - Cadastrar desenvolvedor.";
    char texto4[] = "3 - Encerrar execução do sistema.";
    char texto5[] = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);

    noecho();
    *campo = getch() - 48;
    echo();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaUsuarioLogado::apresentar(int *campo) {
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Selecionar serviços relacionados a desenvolvedor.";
    char texto3[] = "2 - Selecionar serviços relacionados a teste.";
    char texto4[] = "3 - Selecionar serviços relacionados a caso de teste.";
    char texto5[] = "4 - Encerrar sessão.";
    char texto6[] = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6);

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaDesenvolvedor::cadastrar(Desenvolvedor *desenvolvedor) {
    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Matricula :";
    char texto3[] = "Nome      :";
    char texto4[] = "Telefone  :";
    char texto5[] = "Senha     :";

    char texto6[] = "Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    echo();
    getstr(matriculaDesenvolvedor);
    noecho();

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    echo();
    getstr(nomeDesenvolvedor);
    noecho();

    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);
    echo();
    getstr(telefoneDesenvolvedor);
    noecho();

    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
    echo();
    getstr(senhaDesenvolvedor);
    noecho();

    try {
        matricula.setValor(matriculaDesenvolvedor);
        nome.setValor(nomeDesenvolvedor);
        telefone.setValor(telefoneDesenvolvedor);
        senha.setValor(senhaDesenvolvedor);
        desenvolvedor->setMatricula(matricula);
        desenvolvedor->setNome(nome);
        desenvolvedor->setTelefone(telefone);
        desenvolvedor->setSenha(senha);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto6);
        echo();
        getch();
        noecho();
    }

    endwin();
}

void TelaDesenvolvedor::apresentar(int *campo) {
    char texto1[] = "Selecione o servico desejado : ";
    char texto2[] = "1 - Visualizar dados de desenvolvedor";
    char texto3[] = "2 - Editar dados de desenvolvedor";
    char texto4[] = "3 - Descadastrar desenvolvedor";
    char texto5[] = "4 - Encerrar sessão.";
    char texto6[] = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6);

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaTeste::apresentar(int *campo) {
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Visualizar teste.";
    char texto3[] = "2 - Cadastrar teste.";
    char texto4[] = "3 - Editar teste.";
    char texto5[] = "4 - Descadastrar teste.";
    char texto6[] = "5 - Encerrar sessão.";
    char texto7[] = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6);
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto7);

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

void TelaTeste::visualizar(Teste *teste) {
    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Código : ";

    char texto3[] = "Código informado inválido. Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    echo();
    getstr(codigoTeste);
    noecho();

    try {
        codigo.setValor(codigoTeste);
        teste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", texto3);
        echo();
        getch();
        noecho();
    };

    endwin();
}

void TelaTeste::cadastrar(Teste *teste) {
    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Código : ";
    char texto3[] = "Nome   : ";
    char texto4[] = "Classe : ";

    char texto5[] = "Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    echo();
    getstr(codigoTeste);
    noecho();

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    echo();
    getstr(nomeTeste);
    noecho();

    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);
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
        mvprintw(linha / 4 + 5, coluna / 4, "%s", texto5);
        echo();
        getch();
        noecho();
    };

    endwin();
}

void TelaTeste::editar(Teste *teste) {
    TelaTeste telaTeste;
    telaTeste.cadastrar(teste);  // Chama tela para usuário informar dados do novo teste.
}

void TelaTeste::descadastrar(Teste *teste) {
    TelaTeste telaTeste;
    telaTeste.visualizar(teste);  // Chama tela para usuário informar o código do teste.
}

//--------------------------------------------------------------------------------------------
void TelaCasoDeTeste::apresentar(int *campo) {
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Visualizar caso de teste.";
    char texto3[] = "2 - Cadastrar caso de teste.";
    char texto4[] = "3 - Editar caso de teste.";
    char texto5[] = "4 - Descadastrar caso de teste.";
    char texto6[] = "5 - Encerrar sessão.";
    char texto7[] = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6);
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto7);

    noecho();
    *campo = getch() - 48;
    echo();

    endwin();
}

void TelaCasoDeTeste::visualizar(CasoDeTeste *casodeteste) {
    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Código: ";

    char texto3[] = "Código informado inválido. Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    echo();
    getstr(codigoCasoDeTeste);
    noecho();

    try {
        codigo.setValor(codigoCasoDeTeste);
        casodeteste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
        echo();
        getch();
        noecho();
    };

    endwin();
}

void TelaCasoDeTeste::cadastrar(CasoDeTeste *casodeteste) {
    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Código    : ";
    char texto3[] = "Nome      : ";
    char texto4[] = "Data      : ";
    char texto5[] = "Ação      : ";
    char texto6[] = "Resposta  : ";
    char texto7[] = "Resultado : ";

    char texto8[] = "Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2);
    echo();
    getstr(codigoCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3);
    echo();
    getstr(nomeCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4);
    echo();
    getstr(dataCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5);
    echo();
    getstr(acaoCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6);
    echo();
    getstr(respostaCasoDeTeste);
    noecho();

    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto7);
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
        mvprintw(linha / 4 + 8, coluna / 4, "%s", texto8);
    };

    endwin();
}

void TelaCasoDeTeste::editar(CasoDeTeste *casodeteste) {
    TelaCasoDeTeste telaCasoDeTeste;
    telaCasoDeTeste.cadastrar(casodeteste);  // Chama tela para usuário informar dados do novo caso de teste.
}

void TelaCasoDeTeste::descadastrar(CasoDeTeste *casodeteste) {
    TelaCasoDeTeste telaCasoDeTeste;
    telaCasoDeTeste.visualizar(casodeteste);  // Chama tela para usuário informar o código do caso de teste.
}