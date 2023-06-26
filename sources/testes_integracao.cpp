#include "../headers/testes_integracao.h"

//--------------------------------------------------------------------------------------------
void ::executar() {
    IAAutenticacao *ctrlIAAutenticacao;
    IADesenvolvedor *ctrlIADesenvolvedor;
    IATeste *ctrlIATeste;
    IACasoDeTeste *ctrlIACasoDeTeste;

    CtrlMSAutenticacao *ctrlMSAutenticacao;
    CtrlMSDesenvolvedor *ctrlMSDesenvolvedor;
    CtrlMSTeste *ctrlMSTeste;
    CtrlMSCasoDeTeste *ctrlMSCasoDeTeste;

    CtrlIAInicializacao ctrlIAInicializacao;
    ctrlIAAutenticacao = new CtrlIAAutenticacao();
    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlIATeste = new CtrlIATeste();
    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();

    ctrlMSAutenticacao = new CtrlMSAutenticacao();
    ctrlMSDesenvolvedor = new CtrlMSDesenvolvedor();
    ctrlMSTeste = new CtrlMSTeste();
    ctrlMSCasoDeTeste = new CtrlMSCasoDeTeste();

    ctrlIAAutenticacao->setCtrlISAutenticacao(ctrlMSAutenticacao);
    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(ctrlMSDesenvolvedor);
    ctrlIATeste->setCtrlISTeste(ctrlMSTeste);
    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(ctrlMSCasoDeTeste);

    ctrlIAInicializacao.setCtrlIAAutenticacao(ctrlIAAutenticacao);
    ctrlIAInicializacao.setCtrlIADesenvolvedor(ctrlIADesenvolvedor);
    ctrlIAInicializacao.setCtrlIATeste(ctrlIATeste);
    ctrlIAInicializacao.setCtrlIACasoDeTeste(ctrlIACasoDeTeste);

    ctrlIAInicializacao.executar();
}