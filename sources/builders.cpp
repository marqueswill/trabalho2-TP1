#include "../headers/builders.h"

CtrlIAInicializacao *BuilderSistema::construir() {
    ctrlIAInicializacao = new CtrlIAInicializacao();
    ctrlIAAutenticacao = new CtrlIAAutenticacao();
    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlIATeste = new CtrlIATeste();
    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();

    ctrlISAutenticacao = new CtrlISAutenticacao();
    ctrlISDesenvolvedor = new CtrlISDesenvolvedor();
    ctrlISTeste = new CtrlISTeste();
    ctrlISCasoDeTeste = new CtrlISCasoDeTeste();

    ctrlIAAutenticacao->setCtrlISAutenticacao(ctrlISAutenticacao);
    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(ctrlISDesenvolvedor);
    ctrlIATeste->setCtrlISTeste(ctrlISTeste);
    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(ctrlISCasoDeTeste);

    ctrlIAInicializacao->setCtrlIAAutenticacao(ctrlIAAutenticacao);
    ctrlIAInicializacao->setCtrlIADesenvolvedor(ctrlIADesenvolvedor);
    ctrlIAInicializacao->setCtrlIATeste(ctrlIATeste);
    ctrlIAInicializacao->setCtrlIACasoDeTeste(ctrlIACasoDeTeste);

    return ctrlIAInicializacao;
}

BuilderSistema::~BuilderSistema() {
    delete ctrlIAInicializacao;
    delete ctrlIAAutenticacao;
    delete ctrlIADesenvolvedor;
    delete ctrlIATeste;
    delete ctrlIACasoDeTeste;
    delete ctrlISAutenticacao;
    delete ctrlISDesenvolvedor;
    delete ctrlISTeste;
    delete ctrlISCasoDeTeste;
}
