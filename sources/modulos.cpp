#include "../headers/modulos.h"

//--------------------------------------------------------------------------------------------
void MADesenvolvedor::executar() {
    CtrlIADesenvolvedor *ctrlIADesenvolvedor;
    CtrlMSDesenvolvedor *ctrlMSDesenvolvedor;

    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlMSDesenvolvedor = new CtrlMSDesenvolvedor();

    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(stubISDesenvolvedor);

    Matricula matricula;
    ctrlIADesenvolvedor->executar(matricula);

    delete ctrlIADesenvolvedor;
    delete stubISDesenvolvedor;
}

//--------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------
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