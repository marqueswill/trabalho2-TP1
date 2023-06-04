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

class CtrlIAInicializacao : public IAInicializacao {
   private:
    IAAutenticacao *ctrlIAAutenticacao;
    IADesenvolvedor *ctrlIADesenvolvedor;
    IATeste *ctrlIATeste;
    IACasoDeTeste *ctrlIACasoDeTeste;

    const static int AUTENTICAR = 1;
    const static int CADASTRAR = 2;
    const static int SAIR = 3;

   public:
    void executar();
    void setCtrlIAAutenticacao(IAAutenticacao *);
    void setCtrlIADesenvolvedor(IADesenvolvedor *);
    void setCtrlIATeste(IATeste *);
    void setCtrlIACasoDeTeste(IACasoDeTeste *);
};

inline void CtrlIAInicializacao::setCtrlIAAutenticacao(IAAutenticacao *ctrlIAAutenticacao) {
    this->ctrlIAAutenticacao = ctrlIAAutenticacao;
}

inline void CtrlIAInicializacao::setCtrlIADesenvolvedor(IADesenvolvedor *ctrlIADesenvolvedor) {
    this->ctrlIADesenvolvedor = ctrlIADesenvolvedor;
}

inline void CtrlIAInicializacao::setCtrlIATeste(IATeste *ctrlIATeste) {
    this->ctrlIATeste = ctrlIATeste;
}

inline void CtrlIAInicializacao::setCtrlIACasoDeTeste(IACasoDeTeste *ctrlIACasoDeTeste) {
    this->ctrlIACasoDeTeste = ctrlIACasoDeTeste;
}

//-----------------------------------------------------------------------------------

class CtrlIAAutenticacao : public IAAutenticacao {
   private:
   public:
    bool autenticar(Matricula *);
};

//-----------------------------------------------------------------------------------
class CtrlIADesenvolvedor : public IADesenvolvedor {
   private:
   const static int cadastro = 1;
   const static int editar = 2;
   const static int visualizar = 3;
   const static int descadastrar = 4;
   ISDesenvolvedor *ctrlISDesenvolvedor;

   public:
    void cadastrar();
    void executar(Matricula);
};

//-----------------------------------------------------------------------------------
class CtrlIATeste : public IATeste {
   private:
    ISTeste *ctrlISTeste;
    const static int VISUALIZAR = 1;
    const static int CADASTRAR = 2;
    const static int EDITAR = 3;
    const static int DESCADASTRAR = 4;
    const static int RETORNAR = 5;

   public:
    void executar(Matricula);
    void setCtrlISTeste(ISTeste *);
};

inline void CtrlIATeste::setCtrlISTeste(ISTeste *ctrlISTeste) {
    this->ctrlISTeste = ctrlISTeste;
}

//-----------------------------------------------------------------------------------
class CtrlIACasoDeTeste : public IACasoDeTeste {
   private:
    ISCasoDeTeste *ctrlISCasoDeTeste;
    const static int VISUALIZAR = 1;
    const static int CADASTRAR = 2;
    const static int EDITAR = 3;
    const static int DESCADASTRAR = 4;
    const static int RETORNAR = 5;

   public:
    void executar(Matricula);
    void setCtrlISCasoDeTeste(ISCasoDeTeste *);
};

inline void CtrlIACasoDeTeste::setCtrlISCasoDeTeste(ISCasoDeTeste *ctrlISCasoDeTeste) {
    this->ctrlISCasoDeTeste = ctrlISCasoDeTeste;
}

#endif  // CONTROLADORAS_APRESENTACAO_H_INCLUDED