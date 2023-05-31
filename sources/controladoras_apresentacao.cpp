#include "../headers/controladoras_apresentacao.h"

#include "../headers/telas.h"

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CtrlIAInicializacao::executar() {
    initscr();  // Iniciar curses.

    int campo, opcao;        // Campo de entrada.
    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        // Tela inicial
        //
        TelaInicial telaInicial;
        telaInicial.apresentar(&campo);

        switch (campo) {
            case 1:
                if (ctrlIAAutenticacao->autenticar(&matricula)) {  // Solicita autenticação.
                    bool apresentar = true;                        // Controle de laço.
                    while (apresentar) {                           // Apresenta tela de seleção de serviço.

                        TelaUsuarioLogado telaUsuarioLogado;   // Tela de serviços após login.
                        telaUsuarioLogado.apresentar(&opcao);  // Pergunta e define o serviço.

                        switch (opcao) {
                            case 1:
                                ctrlIADesenvolvedor->executar(matricula);  // Solicita serviço de desenvolvedor.
                                break;                                     //
                            case 2:                                        //
                                ctrlIATeste->executar(matricula);          // Solicita serviço de teste.
                                break;                                     //
                            case 3:                                        //
                                ctrlIACasoDeTeste->executar(matricula);    // Solicita serviço de casodeteste.
                                break;
                            case 4:
                                apresentar = false;
                                break;
                            default:
                                TelaMensagem telaMensagem;  // Tela de serviços após login.
                                telaMensagem.apresentar("Serviço inválido.");
                                break;
                        }
                    }
                } else {
                    TelaMensagem telaMensagem;
                    telaMensagem.apresentar("Falha de autenticação.");
                }
                break;

            case 2:                                // Solicitação de cadastro de desenvolvedor.
                ctrlIADesenvolvedor->cadastrar();  // Abre a tela de cadastro.
                break;

            case 3:
                apresentar = false;  // Encerra o programa.
                break;
        }
    }
    return;
};

//--------------------------------------------------------------------------------------------
void CtrlIADesenvolvedor::cadastrar() {
}

void CtrlIADesenvolvedor::executar(Matricula) {
}

//--------------------------------------------------------------------------------------------
void CtrlIATeste::executar(Matricula){

};

//--------------------------------------------------------------------------------------------
void CtrlIACasoDeTeste::executar(Matricula){

};