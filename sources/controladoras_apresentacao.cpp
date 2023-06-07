#include "../headers/controladoras_apresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CtrlIAInicializacao::executar() {
    Matricula matricula;
    int campo1, campo2;  // Campo de entrada.

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        TelaInicial telaInicial;
        telaInicial.apresentar(&campo1);

        switch (campo1) {
            case AUTENTICAR:
                if (ctrlIAAutenticacao->autenticar(&matricula)) {  // Solicita autenticação.

                    bool apresentar = true;  // Controle de laço.
                    while (apresentar) {     // Apresenta tela de seleção de serviço.

                        TelaUsuarioLogado telaUsuarioLogado;
                        telaUsuarioLogado.apresentar(&campo2);  // Pergunta e define o serviço.

                        switch (campo2) {
                            case DESENVOLVEDOR:
                                ctrlIADesenvolvedor->executar(matricula);  // Solicita serviço de desenvolvedor.
                                break;                                     //
                            case TESTE:                                    //
                                ctrlIATeste->executar(matricula);          // Solicita serviço de teste.
                                break;                                     //
                            case CASODETESTE:                              //
                                ctrlIACasoDeTeste->executar(matricula);    // Solicita serviço de casodeteste.
                                break;
                            case VOLTAR:
                                apresentar = false;
                                break;
                            default:
                                TelaMensagem telaMensagem;
                                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                                break;
                        }
                    }
                } else {
                    TelaMensagem telaMensagem;
                    telaMensagem.apresentar("Falha na autenticacao. Pressione qualquer tecla para continuar.");
                }
                break;

            case CADASTRAR:                        // Solicitação de cadastro de desenvolvedor.
                ctrlIADesenvolvedor->cadastrar();  // Abre a tela de cadastro.
                break;

            case SAIR:
                apresentar = false;  // Encerra o programa.
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

//--------------------------------------------------------------------------------------------
// bool CtrlIAAutenticacao::autenticar(Matricula *) {
// }

//--------------------------------------------------------------------------------------------
void CtrlIADesenvolvedor::cadastrar() {
    CmdIADesenvolvedor *comando;

    Desenvolvedor desenvolvedor;

    TelaDesenvolvedor telaDesenvolvedor;
    initscr();
    telaDesenvolvedor.apresentar(&desenvolvedor);
}

void CtrlIADesenvolvedor::executar(Matricula) {
    TelaDesenvolvedor telaDesenvolvedor;
    int opcao;
    initscr();
    telaDesenvolvedor.apresentar(&opcao);
    bool apresentar = true;
    while (apresentar) {
        switch (opcao) {
            case CADASTRAR:
                comando = new CmdIADesenvolvedorCadastrar();
                comando->executar(ctrlISDesenvolvedor);
                delete comando;
                break;

            case EDITAR:
                comando = new CmdIADesenvolvedorEditar();
                comando->executar(ctrlISDesenvolvedor);
                delete comando;
                break;
            case VISUALIZAR:
                comando = new CmdIADesenvolvedorVisualizar();
                comando->executar(ctrlISDesenvolvedor);
                delete comando;
                break;
            case DESCADASTRAR:
                comando = new CmdIADesenvolvedorDescadastrar();
                comando->executar(ctrlISDesenvolvedor);
                delete comando;
                break;

            case RETORNAR:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
}

//--------------------------------------------------------------------------------------------
void CtrlIATeste::executar(Matricula matricula) {
    int opcao;  // Campo de entrada.

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        TelaTeste telaTeste;
        telaTeste.selecionar(&opcao);

        switch (opcao) {
            case VISUALIZAR:
                comando = new CmdIATesteVisualizar();
                comando->executar(ctrlISTeste);
                delete comando;
                break;

            case CADASTRAR:
                comando = new CmdIATesteCadastrar();
                comando->executar(ctrlISTeste);
                delete comando;
                break;

            case EDITAR:
                comando = new CmdIATesteEditar();
                comando->executar(ctrlISTeste);
                delete comando;
                break;

            case DESCADASTRAR:
                comando = new CmdIATesteDescadastrar();
                comando->executar(ctrlISTeste);
                delete comando;
                break;

            case RETORNAR:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

//--------------------------------------------------------------------------------------------
void CtrlIACasoDeTeste::executar(Matricula) {
    CmdIACasoDeTeste *comando;
    int opcao;  // Campo de entrada.

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
                comando = new CmdIACasoDeTesteCadastrar();
                comando->executar(ctrlISCasoDeTeste);
                delete comando;
                break;

            case EDITAR:
                comando = new CmdIACasoDeTesteEditar();
                comando->executar(ctrlISCasoDeTeste);
                delete comando;
                break;

            case DESCADASTRAR:
                comando = new CmdIACasoDeTesteDescadastrar();
                comando->executar(ctrlISCasoDeTeste);
                delete comando;
                break;

            case RETORNAR:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    };
}