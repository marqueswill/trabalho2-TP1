#include "../headers/controladoras_apresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CtrlMAInicializacao::executar() {
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

        // Tela inicial
        clear();                                            // Limpa janela.
        mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);  // Imprime nome do campo.
        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);  // Imprime nome do campo.
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);  // Imprime nome do campo.
        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);  // Imprime nome do campo.

        noecho();
        campo = getch() - 48;  // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch (campo) {
            case 1:
                if (ctrlMAAutenticacao->autenticar(&matricula)) {  // Solicita autenticação.
                    bool apresentar = true;                        // Controle de laço.
                    while (apresentar) {                           // Apresenta tela de seleção de serviço.

                        // Tela de usuário logado
                        clear();                                            // Limpa janela.
                        mvprintw(linha / 4 + 0, coluna / 4, "%s", texto6);  // Imprime nome do campo.
                        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto7);  // Imprime nome do campo.
                        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto8);  // Imprime nome do campo.
                        mvprintw(linha / 4 + 6, coluna / 4, "%s", texto9);  // Imprime nome do campo.

                        noecho();
                        campo = getch() - 48;  // Leitura do campo de entrada e conversão de ASCII.
                        echo();

                        switch (campo) {
                            case 1:
                                ctrlMADesenvolvedor->executar(matricula);  // Solicita serviço de desenvolvedor.
                                break;                                     //
                            case 2:                                        //
                                ctrlMATeste->executar(matricula);          // Solicita serviço de teste.
                                break;                                     //
                            case 3:                                        //
                                ctrlMACasoDeTeste->executar(matricula);    // Solicita serviço de casodeteste.
                                break;
                            case 4:
                                apresentar = false;
                                break;
                        }
                    }
                } else {
                    // Falha na autenticação, reinicia o loop
                    clear();                                             // Limpa janela.
                    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto10);  // Imprime mensagem.
                    noecho();                                            // Desabilita eco.
                    getch();                                             // Leitura de caracter digitado.
                    echo();                                              // Habilita eco.
                }
                break;

            case 2:                                // Solicitação de cadastro de desenvolvedor.
                ctrlMADesenvolvedor->cadastrar();  // Abre a tela de cadastro.
                break;

            case 3:
                apresentar = false;  // Encerra o programa.
                break;
        }
    }
    return;
};

//--------------------------------------------------------------------------------------------
CtrlMADesenvolvedor::CtrlMADesenvolvedor() {
}

void CtrlMADesenvolvedor::cadastrar() {
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

    // Tela cadastramento
    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);   // Imprime nome do campo.
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);   // Imprime nome do campo.
    getstr(campo1);                                      // Lê valor do campo.
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);   // Imprime nome do campo.
    getstr(campo2);                                      // Lê valor do campo.
    mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4);   // Imprime nome do campo.
    getstr(campo3);                                      // Lê valor do campo.
    mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5);   // Imprime nome do campo.
    getstr(campo4);                                      // Lê valor do campo.
    mvprintw(linha / 4 + 10, coluna / 4, "%s", texto6);  // Imprime nome do campo.
    getstr(campo5);

    try {
        nome.setValor(string(campo1));
        matricula.setValor(string(campo2));
        telefone.setValor(string(campo3));
        senha.setValor(string(campo4));
    } catch (invalid_argument &exp) {
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

void CtrlMADesenvolvedor::executar(Matricula) {
    char texto1[] = "Selecione o servico desejado : ";
    char texto2[] = "1 - Cadastrar novo desenvolvedor";
    char texto3[] = "2 - Editar dados de desenvolvedor";
    char texto4[] = "3 - Visualizar dados de desenvolvedor";
    char texto5[] = "4 - Descadastrar desenvolvedor";
    int campo;
    int linha, coluna;
    getmaxyx(stdscr, linha, coluna);
    bool apresentar = true;
    echo();
    while (apresentar) {
        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1);
        mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2);
        mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3);
        noecho();
        campo = getch() - 48;
        echo();
        switch (campo) {
            // case 1:
            // break;
            case 2:
                apresentar = false;
                break;
        }
    }
}

//--------------------------------------------------------------------------------------------
void CtrlMATeste::executar(Matricula){

};

//--------------------------------------------------------------------------------------------
void CtrlMACasoDeTeste::executar(Matricula){

};