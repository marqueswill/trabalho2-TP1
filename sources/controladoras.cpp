#include "../headers/controladoras.h"

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

//--------------------------------------------------------------------------------------------
