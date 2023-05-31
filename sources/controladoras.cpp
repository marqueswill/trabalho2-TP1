#include "../headers/controladoras.h"
#include "UnidadePersistencia.cpp"
using namespace std;
//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CtrlIAInicializacao::executar() {
    // Mensagens a serem apresentadas na tela inicial.
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Acessar sistema.";
    string texto3 = "2 - Cadastrar desenvolvedor.";
    string texto4 = "3 - Encerrar execução do sistema.";

    // Mensagens a serem apresentadas na tela de usuário logado.
    string texto5 = "Selecione um dos servicos : ";
    string texto6 = "1 - Selecionar serviços relacionados a desenvolvedor.";
    string texto7 = "2 - Selecionar serviços relacionados a teste.";
    string texto8 = "3 - Selecionar serviços relacionados a caso de teste.";
    string texto9 = "4 - Encerrar sessão.";

    string texto10 = "Falha na autenticacao. Digite algo para continuar.";

    int campo;                        // Campo de entrada.
    int linha, coluna;                // Dados sobre tamanho da tela.
    getmaxyx(stdscr, linha, coluna);  // Armazena quantidade de linhas e colunas.

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        clear();                                            // Limpa janela.
        mvprintw(linha / 4, coluna / 4, "%s", texto1);      // Imprime nome do campo.
        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);  // Imprime nome do campo.
        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);  // Imprime nome do campo.

        noecho();
        campo = getch() - 48;  // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch (campo) {
            case 1:
                if (ctrlIAAutenticacao->autenticar(matricula*)) {  // Solicita autenticação.
                    bool apresentar = true;                        // Controle de laço.
                    while (apresentar) {                           // Apresenta tela de seleção de serviço.

                        clear();                                            // Limpa janela.
                        mvprintw(linha / 4, coluna / 4, "%s", texto6);      // Imprime nome do campo.
                        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto7);  // Imprime nome do campo.
                        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto8);  // Imprime nome do campo.
                        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto9);  // Imprime nome do campo.

                        noecho();
                        campo = getch() - 48;  // Leitura do campo de entrada e conversão de ASCII.
                        echo();

                        switch (campo) {
                            case 1:
                                ctrlIADesenvolvedor->executar(matricula);  // Solicita serviço de desenvolvedor.
                                break;                                     //
                            case 2:                                        //
                                ctrlIATeste->executar(matricula);          // Solicita serviço de teste.
                                break;
                            case 3:
                                apresentar = false;
                                break;
                        }
                    }
                } else {
                    clear();                                         // Limpa janela.
                    mvprintw(linha / 4, coluna / 4, "%s", texto10);  // Imprime mensagem.
                    noecho();                                        // Desabilita eco.
                    getch();                                         // Leitura de caracter digitado.
                    echo();                                          // Habilita eco.
                }
                break;

            case 2:  // Solicitação de cadastro de desenvolvedor.
                ctrlIADesenvolvedor->cadastrar();
                break;

            case 3:
                apresentar = false;
                break;
        }
    }
    return;
};
cntrlIADesenvolvedor::cntrlIADesenvolvedor(){

}

void cntrlIADesenvolvedor::cadastrar(){
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

Texto nome;
Matricula matricula;
Telefone telefone;
Senha senha;

int linha, coluna;
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

try{
    nome.setValor(string(campo1));
    matricula.setValor(string(campo2));
    telefone.setValor(string(campo3));
    senha.setValor(string(campo4));
}
catch(invalid_argument &exp){
    cout << texto6 << endl;
    getchar();
    return;
}

Desenvolvedor desenvolvedor;
desenvolvedor.setNome(nome);
desenvolvedor.setMatricula(matricula);
desenvolvedor.setTelefone(telefone);
desenvolvedor.setSenha(senha);
}
void cntrlIADesenvolvedor::executar(Matricula){
    char texto1[] = "Selecione o servico desejado : ";
    char texto2[] = "1- Cadastrar novo desenvolvedor";
    char texto3[] = "2- Editar dados de desenvolvedor";
    char texto4[] = "3- Visualizar dados de desenvolvedor";
    char texto5[] = "5- Descadastrar desenvolvedor";
    int campo;
    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);
    bool apresentar = true;
    echo();
    while(apresentar){
        clear();
        mvprintw(linha/4, coluna/4, "%s", texto1);
        mvprintw(linha/4 + 2, coluna/4, "%s", texto2);
        mvprintw(linha/4+4, coluna/4, "%s", texto3);
        noecho();
        campo = getch() - 48;
        echo();
        switch(campo){
            //case 1:
            //break; 
            case 2: apresentar = false;
            break;
        }
    }
}
void cntrlISDesenvolvedor::descadastrar(){
char teste[20];
Matricula matricula;
int linha, coluna;
getmaxyx(stdscr,linha,coluna);
char texto[] = "Escolha um número de matrícula para descadastrar uma conta";
clear();
mvprintw(linha/4,coluna/4,"%s", texto);
getstr(teste);
string m(teste);
try{
    matricula.setValor(m);
}
catch (invalid_argument & exp){
    char texto2[] = "A matrícula digitada é inválida. Tente novamente";
    clear();
    mvprintw(linha/4,coluna/4,"%s", texto2);
    return;
}

ComandoDescadastrarDesenvolvedor comando(matricula);

try{
    comando.executar();
}
catch(EErroPersistencia exp){
     char texto3[] = "Houve erro de acesso ao banco de dados. Tente novamente";
    clear();
    mvprintw(linha/4,coluna/4,"%s", texto3);
    return;
}

char texto4[] = "A operação foi efetuada com sucesso. Tecle algo";
clear();
mvprintw(linha/4,coluna/4,"%s", texto4);

noecho();
getch();
echo();
}

//------------------------------------------------------------------------------------------
void CtrlIATeste::executar(Matricula matricula){
};