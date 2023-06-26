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
void TIDesenvolvedor::executar() {
    IADesenvolvedor *ctrlIADesenvolvedor;
    ISDesenvolvedor *ctrlISDesenvolvedor;

    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlISDesenvolvedor = new CtrlISDesenvolvedor();

    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(ctrlISDesenvolvedor);

    Matricula matricula;
    ctrlIADesenvolvedor->executar(matricula);

    delete ctrlIADesenvolvedor;
    delete ctrlISDesenvolvedor;
}

//--------------------------------------------------------------------------------------------
void TITeste::executar() {
    CtrlIATeste *ctrlIATeste;
    CtrlISTeste *ctrlISTeste;

    ctrlIATeste = new CtrlIATeste();
    ctrlISTeste = new CtrlISTeste();

    ctrlIATeste->setCtrlISTeste(ctrlISTeste);

    Matricula matricula;
    ctrlIATeste->executar(matricula);

    delete ctrlIATeste;
    delete ctrlISTeste;
}

//--------------------------------------------------------------------------------------------
void TICasoDeTeste::executar() {
    CtrlIACasoDeTeste *ctrlIACasoDeTeste;
    CtrlISCasoDeTeste *ctrlISCasoDeTeste;

    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();
    ctrlISCasoDeTeste = new CtrlISCasoDeTeste();

    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(ctrlISCasoDeTeste);

    Matricula matricula;
    ctrlIACasoDeTeste->executar(matricula);

    delete ctrlIACasoDeTeste;
    delete ctrlISCasoDeTeste;
}