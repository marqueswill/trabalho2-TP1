#include "../headers/testes_modulos.h"

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