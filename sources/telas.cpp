#include "../headers/telas.h"

#include "../headers/dominios.h"
#include "../headers/entidades.h"

//--------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------
void TelaUsuarioLogado::apresentar(int *campo) {
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

//--------------------------------------------------------------------------------------------
void TelaDesenvolvedor::cadastrar(Desenvolvedor *desenvolvedor) {
    char texto1[] = "Preencha os seguintes campos: ";
    char texto2[] = "Matricula  :";
    char texto3[] = "Nome       :";
    char texto4[] = "Telefone   :";
    char texto5[] = "Senha      :";
    char texto6[] = "O formato dos dados é inválido. Tecle algo.";
    char texto7[] = "O cadastramento foi executado com sucesso. Tecle algo.";
    char texto8[] = "O cadastramento falhou. Tecle algo";

    Matricula matricula;
    Texto nome;
    Telefone telefone;
    Senha senha;

    char matriculaDesenvolvedor[80];
    char nomeDesenvolvedor[80];
    char telefoneDesenvolvedor[80];
    char senhaDesenvolvedor[80];

    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    getstr(matriculaDesenvolvedor);

    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    getstr(nomeDesenvolvedor);

    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);
    getstr(telefoneDesenvolvedor);

    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);
    getstr(senhaDesenvolvedor);

    echo();
    endwin();

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
        telaMensagem.apresentar("Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.");
    }
}

void TelaDesenvolvedor::apresentar(int *campo) {
    char texto1[] = "Selecione o servico desejado : ";
    char texto2[] = "1 - Visualizar dados de desenvolvedor";
    char texto3[] = "2 - Editar dados de desenvolvedor";
    char texto4[] = "3 - Descadastrar desenvolvedor";
    char texto5[] = "4 - Encerrar sessão.";

    getmaxyx(stdscr, linha, coluna);
    initscr();
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto5);

    echo();
    scanw("%d", &campo);
    noecho();

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

    getmaxyx(stdscr, linha, coluna);

    initscr();

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6);

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

void TelaTeste::visualizar(Teste *teste) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código: ";

    Codigo codigo;

    string codigoTeste;

    getmaxyx(stdscr, linha, coluna);
    initscr();
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    noecho();
    codigoTeste = getch() - 48;
    echo();

    endwin();

    try {
        codigo.setValor(codigoTeste);
        teste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        telaMensagem.apresentar("Código informado inválido. Pressione qualquer tecla para continuar.");
    };
}

void TelaTeste::cadastrar(Teste *teste) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código : ";
    string texto3 = "Classe : ";

    Codigo codigo;
    Classe classe;

    string codigoTeste;
    string classeTeste;


    getmaxyx(stdscr, linha, coluna);
    initscr();
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    noecho();
    codigoTeste = getch() - 48;
    echo();

    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    noecho();
    classeTeste = getch() - 48;
    echo();

    endwin();

    try {
        codigo.setValor(codigoTeste);
        classe.setValor(classeTeste);
        teste->setCodigo(codigo);
        teste->setClasse(classe);  // Solicita dados do teste ao usuário. .
    } catch (invalid_argument &exp) {
        telaMensagem.apresentar("Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.");
    };
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
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Visualizar caso de teste.";
    string texto3 = "2 - Cadastrar caso de teste.";
    string texto4 = "3 - Editar caso de teste.";
    string texto5 = "4 - Descadastrar caso de teste.";
    string texto6 = "5 - Encerrar sessão.";

    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);
    initscr();
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6);

    noecho();
    *campo = getch() - 48;
    echo();
    endwin();
}

void TelaCasoDeTeste::visualizar(CasoDeTeste *casodeteste) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código: ";

    string codigoCasoDeTeste;

    Codigo codigo;

    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);
    initscr();
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    noecho();
    codigoCasoDeTeste = getch() - 48;
    echo();

    endwin();

    try {
        codigo.setValor(codigoCasoDeTeste);
        casodeteste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        telaMensagem.apresentar("Código informado inválido. Pressione qualquer tecla para continuar.");
    };
}

void TelaCasoDeTeste::cadastrar(CasoDeTeste *casodeteste) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código    : ";
    string texto3 = "Data      : ";
    string texto4 = "Ação      : ";
    string texto5 = "Resposta  : ";
    string texto6 = "Resultado : ";

    Codigo codigo;
    Data data;
    Texto acao;
    Texto resposta;
    Resultado resultado;

    string codigoCasoDeTeste;
    string dataCasoDeTeste;
    string acaoCasoDeTeste;
    string respostaCasoDeTeste;
    string resultadoCasoDeTeste;

    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);
    initscr();
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    noecho();
    codigoCasoDeTeste = getch() - 48;
    echo();

    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
    noecho();
    dataCasoDeTeste = getch() - 48;
    echo();

    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto3);
    noecho();
    acaoCasoDeTeste = getch() - 48;
    echo();

    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto3);
    noecho();
    respostaCasoDeTeste = getch() - 48;
    echo();

    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto3);
    noecho();
    resultadoCasoDeTeste = getch() - 48;
    echo();

    endwin();

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
        telaMensagem.apresentar("Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.");
    };
}

void TelaCasoDeTeste::editar(CasoDeTeste *casodeteste) {
    TelaCasoDeTeste telaCasoDeTeste;
    telaCasoDeTeste.cadastrar(casodeteste);  // Chama tela para usuário informar dados do novo caso de teste.
}

void TelaCasoDeTeste::descadastrar(CasoDeTeste *casodeteste) {
    TelaCasoDeTeste telaCasoDeTeste;
    telaCasoDeTeste.visualizar(casodeteste);  // Chama tela para usuário informar o código do caso de teste.
}

void Tela_Servico_Desenvolvedor::descadastrar(Matricula *matricula){
    initscr();
    char teste[20];
    getmaxyx(stdscr,linha,coluna);
    char texto[]="Escolha um numero de matricula para descadastrar";
    clear();
    mvprintw(linha/4,coluna/4, "%s", texto);
    getstr(teste);
    string m(teste);
    try{
        matricula->setValor(m);
    }
    catch(invalid_argument & exp){
        char texto2[] = "A matrícula digitada é inválida. Tente novamente.";
        clear();
        mvprintw(linha/4,coluna/4,"%s", texto2);
        return;
    }
}
