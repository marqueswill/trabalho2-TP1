#include "../headers/builders.h"

CtrlIAInicializacao *BuilderSistema::construir() {
    ctrlIAInicializacao = new CtrlIAInicializacao();

    ctrlIAAutenticacao = new CtrlIAAutenticacao();
    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlIATeste = new CtrlIATeste();
    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();

    ctrlISAutenticacao = new StubISAutenticacao();
    ctrlISDesenvolvedor = new StubISDesenvolvedor();
    ctrlISTeste = new StubISTeste();
    ctrlISCasoDeTeste = new StubISCasoDeTeste();

    ctrlIAInicializacao->setCtrlIAAutenticacao(ctrlIAAutenticacao);
    ctrlIAInicializacao->setCtrlIADesenvolvedor(ctrlIADesenvolvedor);
    ctrlIAInicializacao->setCtrlIATeste(ctrlIATeste);
    ctrlIAInicializacao->setCtrlIACasoDeTeste(ctrlIACasoDeTeste);

    ctrlIAAutenticacao->setCtrlISAutenticacao(ctrlISAutenticacao);
    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(ctrlISDesenvolvedor);
    ctrlIATeste->setCtrlISTeste(ctrlISTeste);
    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(ctrlISCasoDeTeste);

    return ctrlIAInicializacao;
}

void BuilderSistema::executar() {
    ctrlIAInicializacao = new CtrlIAInicializacao();
    ctrlIAAutenticacao = new CtrlIAAutenticacao();
    ctrlIADesenvolvedor = new CtrlIADesenvolvedor();
    ctrlIATeste = new CtrlIATeste();
    ctrlIACasoDeTeste = new CtrlIACasoDeTeste();

    ctrlISAutenticacao = new StubISAutenticacao();
    ctrlISDesenvolvedor = new StubISDesenvolvedor();
    ctrlISTeste = new StubISTeste();
    ctrlISCasoDeTeste = new StubISCasoDeTeste();

    ctrlIAAutenticacao->setCtrlISAutenticacao(ctrlISAutenticacao);
    ctrlIADesenvolvedor->setCtrlISDesenvolvedor(ctrlISDesenvolvedor);
    ctrlIATeste->setCtrlISTeste(ctrlISTeste);
    ctrlIACasoDeTeste->setCtrlISCasoDeTeste(ctrlISCasoDeTeste);

    ctrlIAInicializacao->setCtrlIAAutenticacao(ctrlIAAutenticacao);
    ctrlIAInicializacao->setCtrlIADesenvolvedor(ctrlIADesenvolvedor);
    ctrlIAInicializacao->setCtrlIATeste(ctrlIATeste);
    ctrlIAInicializacao->setCtrlIACasoDeTeste(ctrlIACasoDeTeste);

    ctrlIAInicializacao->executar();
    delete ctrlIAInicializacao;
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
