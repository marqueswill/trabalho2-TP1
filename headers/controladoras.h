#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
//-----------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de apresentação e implementações de métodos inline.

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

inline void CtrlIAInicializacao::setCtrlIAAutenticacao(IAAutenticacao *ctrlIAAutenticacao) {
    this->ctrlIAAutenticacao = ctrlIAAutenticacao;
}

inline void CtrlIAInicializacao::setCtrlIADesenvolvedor(IADesenvolvedor *ctrlIADesenvolvedor) {
    this->ctrlIADesenvolvedor = ctrlIADesenvolvedor;
}

inline void CtrlIAInicializacao::setCtrlIATeste(IATeste *ctrlIATeste) {
    this->ctrlIATeste = ctrlIATeste;
}

//-----------------------------------------------------------------------------------

class CtrlIAAutenticacao : IAAutenticacao {
};

//-----------------------------------------------------------------------------------

class cntrlIADesenvolvedor: public IADesenvolvedor{
private:
ISDesenvolvedor *cntrlISDesenvolvedor;
Matricula matricula;
public:
Matricula *matricula;
Desenvolvedor *desenvolvedor;
void cadastrar() throw(runtime_error);
void executar(Matricula);
~cntrlIADesenvolvedor();
};

//-----------------------------------------------------------------------------------
class CtrlIATeste : IATeste {
   private:
    ISTeste *ctrlISTeste;  // referência para servidor

   public:
    void executar(Matricula);
    void setCtrlISTeste(ISTeste *);
};

inline void CtrlIATeste::setCtrlISTeste(ISTeste *ctrlISTeste) {
    this->ctrlISTeste = ctrlISTeste;
}

//-----------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de serviços e implementações de métodos inline.

class CtrlISAutenticacao : ISAutenticacao {
};

//-----------------------------------------------------------------------------------
class cntrlISDesenvolvedor: public ISDesenvolvedor{
public:
const static unsigned int max = 5;
const static unsigned int cadastrar_dev = 1;
const static unsigned int descadastrar_dev = 2;
const static unsigned int visualizar_dev = 3;
const static unsigned int editar_dev = 4;
bool cadastrar(Desenvolvedor);
bool descadastrar(Matricula);
bool visualizar(Desenvolvedor *);
bool editar(Desenvolvedor);
cntrlISDesenvolvedor();
};
//-----------------------------------------------------------------------------------
class CtrlISTeste : ISTeste {
   public:
    bool visualizar(Teste *);
    bool cadastrar(Teste);
    bool editar(Teste);
    bool descadastrar(Codigo);
};

//-----------------------------------------------------------------------------------
class CtrlISCasoDeTeste : ISTeste {
   public:
    bool visualizar(CasoDeTeste *);
    bool cadastrar(CasoDeTeste);
    bool editar(CasoDeTeste);
    bool descadastrar(Codigo);
};

#endif  /// CONTROLADORAS_H_INCLUDED