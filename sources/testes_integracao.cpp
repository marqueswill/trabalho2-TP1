#include "../headers/testes_integracao.h"

//--------------------------------------------------------------------------------------------
void TIApresentacao::executar() {
    IADesenvolvedor *ctrlIADesenvolvedor;
    IATeste *ctrlIATeste;
    IACasoDeTeste *ctrlIACasoDeTeste;

    StubISDesenvolvedor *stubISDesenvolvedor;
    StubISTeste *stubISTeste;
    StubISCasoDeTeste *stubISCasoDeTeste;

    CtrlIAInicializacao ctrlIAInicializacao;

    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlIATeste = new CtrlIATeste();
    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();

    stubISDesenvolvedor = new StubISDesenvolvedor();
    stubISTeste = new StubISTeste();
    stubISCasoDeTeste = new StubISCasoDeTeste();

    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(stubISDesenvolvedor);
    ctrlIATeste->setCtrlISTeste(stubISTeste);
    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(stubISCasoDeTeste);

    ctrlIAInicializacao.setCtrlIAAutenticacao(ctrlIAAu)

        Matricula matricula;
}