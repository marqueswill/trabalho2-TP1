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