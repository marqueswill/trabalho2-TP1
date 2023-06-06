#include "../headers/controladoras_apresentacao.h"

#include "../headers/comandos.h"
#include "../headers/telas.h"

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CtrlIAInicializacao::executar() {
    Matricula matricula;
    int campo, opcao;  // Campo de entrada.

    bool apresentar = true;  // Controle de laço.
    while (apresentar) {     // Apresenta tela inicial.

        TelaInicial telaInicial;
        telaInicial.apresentar(&campo);

        switch (campo) {
            case AUTENTICAR:
                if (ctrlIAAutenticacao->autenticar(&matricula)) {  // Solicita autenticação.

                    bool apresentar = true;  // Controle de laço.
                    while (apresentar) {     // Apresenta tela de seleção de serviço.

                        TelaUsuarioLogado telaUsuarioLogado;
                        telaUsuarioLogado.apresentar(&opcao);  // Pergunta e define o serviço.

                        switch (opcao) {
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
        }
    }
};

//--------------------------------------------------------------------------------------------
// bool CtrlIAAutenticacao::autenticar(Matricula *) {
// }

//--------------------------------------------------------------------------------------------
void CtrlIADesenvolvedor::cadastrar() {
Desenvolvedor *Dev;
Dev = new Desenvolvedor();
TelaDesenvolvedor TelaDev;
initscr();
TelaDev.apresentar(Dev);
delete Dev;
}

void CtrlIADesenvolvedor::executar(Matricula) {
    TelaDesenvolvedor TelaDev;
    int opcao;
    initscr();
    TelaDev.apresentar(&opcao);
    switch(opcao){
        case cadastro:
        case editar:
        case visualizar:
        case descadastrar:

    }

}

//--------------------------------------------------------------------------------------------
void CtrlIATeste::executar(Matricula matricula) {
    int opcao;  // Campo de entrada.

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