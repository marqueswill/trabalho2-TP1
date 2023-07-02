#ifndef BUILDERS_H_INCLUDED
#define BUILDERS_H_INCLUDED

#include "controladoras_apresentacao.h"

class BuilderSistema {
   private:
    CtrlIAInicializacao *ctrlIAInicializacao;

    IAAutenticacao *ctrlIAAutenticacao;
    IADesenvolvedor *ctrlIADesenvolvedor;
    IATeste *ctrlIATeste;
    IACasoDeTeste *ctrlIACasoDeTeste;

    CtrlISAutenticacao *ctrlISAutenticacao;
    CtrlISDesenvolvedor *ctrlISDesenvolvedor;
    CtrlISTeste *ctrlISTeste;
    CtrlISCasoDeTeste *ctrlISCasoDeTeste;

   public:
    CtrlIAInicializacao *construir();
    ~BuilderSistema();
};

#endif  // BUILDERS_H_INCLUDED
