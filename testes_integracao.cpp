#include "testes_integracao.h"

//----------------------------------------------------------------------------------------------------------------------
void TIApresentacao::executar() {
    IAAutenticacao *ctrlIAAutenticacao;
    IADesenvolvedor *ctrlIADesenvolvedor;
    IATeste *ctrlIATeste;
    IACasoDeTeste *ctrlIACasoDeTeste;

    CtrlISAutenticacao *ctrlISAutenticacao;
    CtrlISDesenvolvedor *ctrlISDesenvolvedor;
    CtrlISTeste *ctrlISTeste;
    CtrlISCasoDeTeste *ctrlISCasoDeTeste;

    CtrlIAInicializacao ctrlIAInicializacao;
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

    ctrlIAInicializacao.setCtrlIAAutenticacao(ctrlIAAutenticacao);
    ctrlIAInicializacao.setCtrlIADesenvolvedor(ctrlIADesenvolvedor);
    ctrlIAInicializacao.setCtrlIATeste(ctrlIATeste);
    ctrlIAInicializacao.setCtrlIACasoDeTeste(ctrlIACasoDeTeste);

    ctrlIAInicializacao.executar();
}
void TIAutenticacao::executar(){
    IAAutenticacao *ctrlIAAutenticacao;
    ISAutenticacao *ctrlISAutenticacao;

    ctrlIAAutenticacao = new CtrlIAAutenticacao();
    ctrlISAutenticacao = new CtrlISAutenticacao();

    ctrlIAAutenticacao->setCtrlISAutenticacao(ctrlISAutenticacao);
    Matricula *matricula;
    matricula = new Matricula();
    ctrlIAAutenticacao->executar(matricula);
    delete ctrlIAAutenticacao;
    delete ctrlISAutenticacao;
    delete matricula;
}
//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
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
