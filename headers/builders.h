#ifndef BUILDERS_H_INCLUDED
#define BUILDERS_H_INCLUDED

#include "controladoras_apresentacao.h"
#include "controladoras_servico.h"
#include "stubs.h"

class BuilderSistema {
   private:
    CtrlIAInicializacao *ctrlIAInicializacao;

    IAAutenticacao *ctrlIAAutenticacao;
    IADesenvolvedor *ctrlIADesenvolvedor;
    IATeste *ctrlIATeste;
    IACasoDeTeste *ctrlIACasoDeTeste;

    StubISAutenticacao *ctrlISAutenticacao;
    StubISDesenvolvedor *ctrlISDesenvolvedor;
    StubISTeste *ctrlISTeste;
    StubISCasoDeTeste *ctrlISCasoDeTeste;

   public:
    CtrlIAInicializacao *construir();
    void executar();
    ~BuilderSistema();
};

#endif  // BUILDERS_H_INCLUDED