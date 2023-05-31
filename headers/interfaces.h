#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declarações adiantadas
class ISAutenticacao;
class ISDesenvolvedor;
class ISTeste;
class ISCasoDeTeste;

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de apresentação.

class IAInicializacao {
   public:
    virtual void executar() = 0;
    virtual void setCtrlIAAutenticacao(IAAutenticacao *) = 0;
    virtual void setCtrlIADesenvolvedor(IADesenvolvedor *) = 0;
    virtual void setCtrlIATeste(IATeste *) = 0;
    virtual ~IAInicializacao(){};
};

class IAAutenticacao {
   public:
};

class IADesenvolvedor {
   public:
    virtual void cadastrar() = 0;
    virtual void executar(Matricula) = 0;
    virtual ~IADesenvolvedor() {}
};

class IATeste {
   public:
    virtual void executar(Matricula) = 0;
    virtual void setCtrlISTeste(ISTeste *) = 0;
    virtual ~IATeste(){};
};

class IACasoDeTeste {
   public:
    virtual void executar(Matricula) = 0;
    virtual void setCtrlISTeste(ISCasoDeTeste *) = 0;
    virtual ~IACasoDeTeste(){};
};

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de serviço.

class ISAutenticacao {
};

class ISDesenvolvedor {
   public:
    virtual void visualizar(Desenvolvedor *) = 0;
    virtual void cadastrar(Desenvolvedor) = 0;
    virtual void editar(Desenvolvedor) = 0;
    virtual void descadastrar(Matricula) = 0;
    virtual ~ISDesenvolvedor() {}
};
class ISTeste {
   public:
    virtual bool visualizar(Teste *) = 0;
    virtual bool cadastrar(Teste) = 0;
    virtual bool editar(Teste) = 0;
    virtual bool descadastrar(Codigo) = 0;
    virtual ~ISTeste(){};
};

class ISCasoDeTeste {
   public:
    virtual bool visualizar(CasoDeTeste *) = 0;
    virtual bool cadastrar(CasoDeTeste) = 0;
    virtual bool editar(CasoDeTeste) = 0;
    virtual bool descadastrar(Codigo) = 0;
    virtual ~ISCasoDeTeste(){};
};

#endif  // INTERFACES_H_INCLUDED