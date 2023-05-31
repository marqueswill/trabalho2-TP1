#ifndef CONTROLADORAS_APRESENTACAO_H_INCLUDED
#define CONTROLADORAS_APRESENTACAO_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <string>

#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//-----------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de apresentação e implementações de métodos inline.

class CtrlMAInicializacao : public IAInicializacao {
   private:
    Matricula matricula;

    IAAutenticacao *ctrlMAAutenticacao;
    IADesenvolvedor *ctrlMADesenvolvedor;
    IATeste *ctrlMATeste;
    IACasoDeTeste *ctrlMACasoDeTeste;

   public:
    void executar();
    void setCtrlMAAutenticacao(IAAutenticacao *);
    void setCtrlMADesenvolvedor(IADesenvolvedor *);
    void setCtrlMATeste(IATeste *);
    void setCtrlMACasoDeTeste(IACasoDeTeste *);
};

inline void CtrlMAInicializacao::setCtrlMAAutenticacao(IAAutenticacao *ctrlMAAutenticacao) {
    this->ctrlMAAutenticacao = ctrlMAAutenticacao;
}

inline void CtrlMAInicializacao::setCtrlMADesenvolvedor(IADesenvolvedor *ctrlMADesenvolvedor) {
    this->ctrlMADesenvolvedor = ctrlMADesenvolvedor;
}

inline void CtrlMAInicializacao::setCtrlMATeste(IATeste *ctrlMATeste) {
    this->ctrlMATeste = ctrlMATeste;
}

inline void CtrlMAInicializacao::setCtrlMACasoDeTeste(IACasoDeTeste *ctrlMACasoDeTeste) {
    this->ctrlMACasoDeTeste = ctrlMACasoDeTeste;
}

//-----------------------------------------------------------------------------------

class CtrlMAAutenticacao : public IAAutenticacao {
};

//-----------------------------------------------------------------------------------
class CtrlMADesenvolvedor : public IADesenvolvedor {
};

//-----------------------------------------------------------------------------------
class CtrlMATeste : public IATeste {
   private:
    ISTeste *ctrlMSTeste;

   public:
    void executar(Matricula);
    void setCtrlMSTeste(ISTeste *);
};

inline void CtrlMATeste::setCtrlMSTeste(ISTeste *ctrlMSTeste) {
    this->ctrlMSTeste = ctrlMSTeste;
}

//-----------------------------------------------------------------------------------
class CtrlMACasoDeTeste : public IACasoDeTeste {
   private:
    ISCasoDeTeste *ctrlMSCasoDeTeste;

   public:
    void executar(Matricula);
    void setCtrlMSCasoDeTeste(ISCasoDeTeste *);
};

inline void CtrlMACasoDeTeste::setCtrlMSCasoDeTeste(ISCasoDeTeste *ctrlMSCasoDeTeste) {
    this->ctrlMSCasoDeTeste = ctrlMSCasoDeTeste;
}

#endif  // CONTROLADORAS_APRESENTACAO_H_INCLUDED