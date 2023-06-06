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

void TelaDesenvolvedor::apresentar(Desenvolvedor *desenvolvedor) {
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
    mvprintw(linha / 4, coluna / 4, "%s", texto1);       // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);   // Imprime nome do campo.
    getstr(campo1);                                      // L� valor do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);   // Imprime nome do campo.
    getstr(campo2);                                      // L� valor do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);   // Imprime nome do campo.
    getstr(campo3);                                      // L� valor do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);   // Imprime nome do campo.
    getstr(campo4);                                      // L� valor do campo.
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6);  // Imprime nome do campo.
    getstr(campo5);
    Texto nome;
    Matricula matricula;
    Telefone telefone;
    Senha senha;
    desenvolvedor->setNome(nome);
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

void TelaTeste::apresentar(Codigo *codigo) {
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
        codigo->setValor(codigoTeste);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", texto3);
        echo();
        getch();
        noecho();
    };

    endwin();
}

void TelaTeste::apresentar(Teste *teste) {
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

void TelaCasoDeTeste::apresentar(Codigo *codigo) {
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
        codigo->setValor(codigoCasoDeTeste);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
        echo();
        getch();
        noecho();
    };

    endwin();
}

void TelaCasoDeTeste::apresentar(CasoDeTeste *casodeteste) {
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

//--------------------------------------------------------------------------------------------
void TelaDepuracao::apresentar(int *campo) {
    char texto1[] = "Selecione tipo de teste a ser executado : ";
    char texto2[] = "1 - Executar testes unitários.";
    char texto3[] = "2 - Executar testes de integração.";
    char texto4[] = "3 - Executar testes fumaça.";
    char texto5[] = "4 - Executar testes sistema.";
    char texto6[] = "5 - Encerrar depuração.";
    char texto7[] = "Digite a opção: ";

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

void TelaTestesUnitarios::apresentar(int *campo) {
    char texto1[] = "Selecione unidades de teste: ";
    char texto2[] = "1 - Executar testes domínios.";
    char texto3[] = "2 - Executar testes entidades.";
    char texto4[] = "3 - Executar testes modulos.";
    char texto5[] = "4 - Encerrar depuração.";
    char texto6[] = "Digite a opção: ";

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