#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <string>

#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//-----------------------------------------------------------------------------------
// Declarações de classes controladoras e implementações de métodos.

class CtrlIAInicializacao : IAInicializacao {
   private:
    Matricula matricula;

    IAAutenticacao *ctrlIAAutenticacao;    // referência para servidor
    IADesenvolvedor *ctrlIADesenvolvedor;  // referência para servidor
    IATeste *ctrlIATeste;                  // referência para servidor

   public:
    void executar();
    void setCtrlIAAutenticacao(IAAutenticacao *);
    void setCtrlIADesenvolvedor(IADesenvolvedor *);
    void setCtrlIATeste(IATeste *);
};

inline void CtrlIAInicializacao::setCtrlIAAutenticacao(IAAutenticacao *ctrl) {
    ctrlIAAutenticacao = ctrl;
}

inline void CtrlIAInicializacao::setCtrlIADesenvolvedor(IADesenvolvedor *ctrl) {
    ctrlIADesenvolvedor = ctrl;
}

inline void CtrlIAInicializacao::setCtrlIATeste(IATeste *ctrl) {
    ctrlIATeste = ctrl;
}

//-----------------------------------------------------------------------------------

class CtrlIAAutenticacao : IAAutenticacao {
};

//-----------------------------------------------------------------------------------
class CtrlIADesenvolvedor : IADesenvolvedor {
};

//-----------------------------------------------------------------------------------
class CtrlIATeste : IATeste {
   private:
    ISTeste *ctrlISTeste;  // referência para servidor

   public:
    void executar(Matricula);
    void setCtrlISTeste(ISTeste *);
};

inline void CtrlIATeste::setCtrlISTeste(ISTeste *ctrl) {
    ctrlISTeste = ctrl;
}

//-----------------------------------------------------------------------------------
// Declarações de classes controladoras e implementações de métodos.
class CtrlISAutenticacao : ISAutenticacao {
};

//-----------------------------------------------------------------------------------
class CtrlISDesenvolvedor : ISDesenvolvedor {
};

//-----------------------------------------------------------------------------------
class CtrlISTeste : ISTeste {
};

#endif  // CONTROLADORAS_H_INCLUDED