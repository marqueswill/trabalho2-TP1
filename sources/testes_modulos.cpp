#include "../headers/testes_modulos.h"

//----------------------------------------------------------------------------------------------------------------------
void TUIAAutenticacao::executar() {
    IAAutenticacao *ctrlIAAutenticacao;
    StubISAutenticacao *stubISAutenticacao;

    ctrlIAAutenticacao = new CtrlIAAutenticacao();
    stubISAutenticacao = new StubISAutenticacao();

    ctrlIAAutenticacao->setCtrlISAutenticacao(stubISAutenticacao);

    Matricula matricula;
    TelaMensagem telaMensagem;

    if (ctrlIAAutenticacao->executar(&matricula)) {
        telaMensagem.apresentar("Sucesso na autenticacao.");
    } else {
        telaMensagem.apresentar("Erro de autenticacao.");
    }

    delete ctrlIAAutenticacao;
    delete stubISAutenticacao;
}

//----------------------------------------------------------------------------------------------------------------------
void TUIADesenvolvedor::executar() {
    IADesenvolvedor *ctrlIADesenvolvedor;
    StubISDesenvolvedor *stubISDesenvolvedor;

    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    stubISDesenvolvedor = new StubISDesenvolvedor();

    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(stubISDesenvolvedor);

    Matricula matricula;
    matricula.setValor("1234567");
    ctrlIADesenvolvedor->executar(matricula);

    delete ctrlIADesenvolvedor;
    delete stubISDesenvolvedor;
}

//----------------------------------------------------------------------------------------------------------------------
void TUIATeste::executar() {
    IATeste *ctrlIATeste;
    StubISTeste *stubISTeste;

    ctrlIATeste = new CtrlIATeste();
    stubISTeste = new StubISTeste();

    ctrlIATeste->setCtrlISTeste(stubISTeste);

    Matricula matricula;
    ctrlIATeste->executar(matricula);

    delete ctrlIATeste;
    delete stubISTeste;
}

//----------------------------------------------------------------------------------------------------------------------
void TUIACasoDeTeste::executar() {
    IACasoDeTeste *ctrlIACasoDeTeste;
    StubISCasoDeTeste *stubISCasoDeTeste;

    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();
    stubISCasoDeTeste = new StubISCasoDeTeste();

    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(stubISCasoDeTeste);

    Matricula matricula;
    ctrlIACasoDeTeste->executar(matricula);

    delete ctrlIACasoDeTeste;
    delete stubISCasoDeTeste;
}