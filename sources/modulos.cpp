#include "../headers/modulos.h"

//--------------------------------------------------------------------------------------------
void MADesenvolvedor::executar() {
    CtrlIADesenvolvedor *ctrlIADesenvolvedor;
    CtrlMSDesenvolvedor *ctrlMSDesenvolvedor;

    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlMSDesenvolvedor = new CtrlMSDesenvolvedor();

    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(ctrlMSDesenvolvedor);

    Matricula matricula;
    ctrlIADesenvolvedor->executar(matricula);

    delete ctrlIADesenvolvedor;
    delete ctrlMSDesenvolvedor;
}

//--------------------------------------------------------------------------------------------
void MATeste::executar() {
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
void MACasoDeTeste::executar() {
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