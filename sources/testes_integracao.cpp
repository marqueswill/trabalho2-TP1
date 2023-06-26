#include "../headers/testes_integracao.h"

//--------------------------------------------------------------------------------------------
void TIApresentacao::executar() {
    IAAutenticacao *ctrlIAAutenticacao;
    IADesenvolvedor *ctrlIADesenvolvedor;
    IATeste *ctrlIATeste;
    IACasoDeTeste *ctrlIACasoDeTeste;

    StubISAutenticacao *stubISAutenticacao;
    StubISDesenvolvedor *stubISDesenvolvedor;
    StubISTeste *stubISTeste;
    StubISCasoDeTeste *stubISCasoDeTeste;

    CtrlIAInicializacao ctrlIAInicializacao;
    ctrlIAAutenticacao = new CtrlIAAutenticacao();
    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlIATeste = new CtrlIATeste();
    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();

    stubISAutenticacao = new StubISAutenticacao();
    stubISDesenvolvedor = new StubISDesenvolvedor();
    stubISTeste = new StubISTeste();
    stubISCasoDeTeste = new StubISCasoDeTeste();

    ctrlIAAutenticacao->setCtrlISAutenticacao(stubISAutenticacao);
    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(stubISDesenvolvedor);
    ctrlIATeste->setCtrlISTeste(stubISTeste);
    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(stubISCasoDeTeste);

    ctrlIAInicializacao.setCtrlIAAutenticacao(ctrlIAAutenticacao);
    ctrlIAInicializacao.setCtrlIADesenvolvedor(ctrlIADesenvolvedor);
    ctrlIAInicializacao.setCtrlIATeste(ctrlIATeste);
    ctrlIAInicializacao.setCtrlIACasoDeTeste(ctrlIACasoDeTeste);

    ctrlIAInicializacao.executar();
}

//--------------------------------------------------------------------------------------------
void TISubDesenvolvedor::executar() {
    IADesenvolvedor *ctrlIADesenvolvedor;
    ISDesenvolvedor *ctrlMSDesenvolvedor;

    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlMSDesenvolvedor = new CtrlMSDesenvolvedor();

    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(ctrlMSDesenvolvedor);

    Matricula matricula;
    ctrlIADesenvolvedor->executar(matricula);

    delete ctrlIADesenvolvedor;
    delete ctrlMSDesenvolvedor;
}

//--------------------------------------------------------------------------------------------
void TISubTeste::executar() {
    CtrlIATeste *ctrlIATeste;
    CtrlMSTeste *ctrlMSTeste;

    ctrlIATeste = new CtrlIATeste();
    ctrlMSTeste = new CtrlMSTeste();

    ctrlIATeste->setCtrlISTeste(ctrlMSTeste);

    Matricula matricula;
    ctrlIATeste->executar(matricula);

    delete ctrlIATeste;
    delete ctrlMSTeste;
}

//--------------------------------------------------------------------------------------------
void TISubCasoDeTeste::executar() {
    CtrlIACasoDeTeste *ctrlIACasoDeTeste;
    CtrlMSCasoDeTeste *ctrlMSCasoDeTeste;

    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();
    ctrlMSCasoDeTeste = new CtrlMSCasoDeTeste();

    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(ctrlMSCasoDeTeste);

    Matricula matricula;
    ctrlIACasoDeTeste->executar(matricula);

    delete ctrlIACasoDeTeste;
    delete ctrlMSCasoDeTeste;
}