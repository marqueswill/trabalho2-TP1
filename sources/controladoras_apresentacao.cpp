#include "../headers/controladoras_apresentacao.h"

#include "../headers/comandos.h"
#include "../headers/telas.h"

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CtrlIAInicializacao::executar() {
    initscr();  // Iniciar curses.

    Matricula matricula;
    int campo, opcao;        // Campo de entrada.
    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        TelaInicial telaInicial;
        telaInicial.apresentar(&campo);

        switch (campo) {
            case AUTENTICAR:
                if (ctrlIAAutenticacao->autenticar(&matricula)) {  // Solicita autenticação.

                    bool apresentar = true;  // Controle de laço.
                    while (apresentar) {     // Apresenta tela de seleção de serviço.

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
                                telaMensagem.apresentar("Opção inválida. Pressione qualquer teclar para retornar.");
                                break;
                        }
                    }
                } else {
                    TelaMensagem telaMensagem;
                    telaMensagem.apresentar("Falha na autenticacao. Pressione qualquer teclar para retornar.");
                }
                break;

            case CADASTRAR:                        // Solicitação de cadastro de desenvolvedor.
                ctrlIADesenvolvedor->cadastrar();  // Abre a tela de cadastro.
                break;

            case SAIR:
                apresentar = false;  // Encerra o programa.
                break;
        }
    }
    return;
};

//--------------------------------------------------------------------------------------------
bool CtrlIAAutenticacao::autenticar(Matricula *) {
}

//--------------------------------------------------------------------------------------------
void CtrlIADesenvolvedor::cadastrar() {
}

void CtrlIADesenvolvedor::executar(Matricula) {
}

//--------------------------------------------------------------------------------------------
void CtrlIATeste::executar(Matricula) {
    int opcao;  // Campo de entrada.
    CmdIATeste *comando;

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        TelaTeste telaTeste;
        telaTeste.apresentar(&opcao);

        switch (opcao) {
            case VISUALIZAR:
                comando = new CmdIATesteVisualizar();
                comando->executar(ctrlISTeste);
                delete comando;
                break;

            case CADASTRAR:
                comando = new CmdIATesteCadastrar;
                comando->executar(ctrlISTeste);
                delete comando;
                break;

            case EDITAR:
                comando = new CmdIATesteEditar;
                comando->executar(ctrlISTeste);
                delete comando;
                break;

            case DESCADASTRAR:
                comando = new CmdIATesteDescadastrar;
                comando->executar(ctrlISTeste);
                delete comando;
                break;

            case RETORNAR:
                apresentar = false;
                break;
        }
    }
    return;
};

//--------------------------------------------------------------------------------------------
void CtrlIACasoDeTeste::executar(Matricula) {
    int opcao;  // Campo de entrada.
    CmdIACasoDeTeste *comando;

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        TelaCasoDeTeste telaCasoDeTeste;
        telaCasoDeTeste.apresentar(&opcao);

        switch (opcao) {
            case VISUALIZAR:
                comando = new CmdIACasoDeTesteVisualizar();
                comando->executar(ctrlISCasoDeTeste);
                delete comando;
                break;

            case CADASTRAR:
                comando = new CmdIACasoDeTesteCadastrar;
                comando->executar(ctrlISCasoDeTeste);
                delete comando;
                break;

            case EDITAR:
                comando = new CmdIACasoDeTesteEditar;
                comando->executar(ctrlISCasoDeTeste);
                delete comando;
                break;

            case DESCADASTRAR:
                comando = new CmdIACasoDeTesteDescadastrar;
                comando->executar(ctrlISCasoDeTeste);
                delete comando;
                break;

            case RETORNAR:
                apresentar = false;
                break;
        }
    };
    return;
}