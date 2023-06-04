#include "../headers/telas.h"
#include "../headers/dominios.h"
#include "../headers/entidades.h"

//--------------------------------------------------------------------------------------------
void TelaMensagem::apresentar(string mensagem) {
    int linha, coluna;
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

    int linha, coluna;
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

    int linha, coluna;
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
void TelaTeste::apresentar(int *campo) {
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Visualizar teste.";
    string texto3 = "2 - Cadastrar teste.";
    string texto4 = "3 - Editar teste.";
    string texto5 = "4 - Descadastrar teste.";
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

void TelaTeste::visualizar(Teste *teste) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código: ";

    string codigoTeste;

    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);
    initscr();
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);

    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
    noecho();
    codigoTeste = getch() - 48;
    echo();

    endwin();

    Codigo codigo;
    codigo.setValor(codigoTeste);
    teste->setCodigo(codigo);
}

void TelaTeste::cadastrar(Teste *teste) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Código : ";
    string texto3 = "Classe : ";

    Codigo codigo;
    Classe classe;
    string codigoTeste;
    string classeTeste;

    int linha, coluna;
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

    codigo.setValor(codigoTeste);
    classe.setValor(classeTeste);
    teste->setCodigo(codigo);
    teste->setClasse(classe);
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

    Codigo codigo;
    codigo.setValor(codigoCasoDeTeste);
    casodeteste->setCodigo(codigo);
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
}

void TelaCasoDeTeste::editar(CasoDeTeste *casodeteste) {
    TelaCasoDeTeste telaCasoDeTeste;
    telaCasoDeTeste.cadastrar(casodeteste);  // Chama tela para usuário informar dados do novo caso de teste.
}

void TelaCasoDeTeste::descadastrar(CasoDeTeste *casodeteste) {
    TelaCasoDeTeste telaCasoDeTeste;
    telaCasoDeTeste.visualizar(casodeteste);  // Chama tela para usuário informar o código do caso de teste.
}

void TelaDesenvolvedor::apresentar(Desenvolvedor *dev){
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
echo();
endwin();
Texto name;
Matricula registernumber;
Telefone telephone;
Senha password; 
name.setValor(campo1);
registernumber.setValor(campo2);
telephone.setValor(campo3);
password.setValor(campo4);
dev.setNome(name);
dev.setMatricula(registernumber);
dev.setTelefone(telephone);
dev.setSenha(password);
}

void TelaDesenvolvedor::apresentar(int *opcao){
     char texto1[] = "Selecione o servico desejado : ";
    char texto2[] = "1- Cadastrar novo desenvolvedor";
    char texto3[] = "2- Editar dados de desenvolvedor";
    char texto4[] = "3- Visualizar dados de desenvolvedor";
    char texto5[] = "4- Descadastrar desenvolvedor";
    int campo;
    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);
    initscr();
    echo();
        clear();
        mvprintw(linha/4, coluna/4, "%s", texto1);
        mvprintw(linha/4 + 2, coluna/4, "%s", texto2);
        mvprintw(linha/4 + 4, coluna/4, "%s", texto3);
        mvprintw(linha/4 + 8, coluna/4, "%s", texto4);
        mvprintw(linha/4 + 16, coluna/4,"%s",texto5);
        scanw("%d", &opcao)
        noecho();
        campo = getch() - 48;
        echo();
        endwin();
    }