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

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de apresentação.

class IAInicializacao {
   public:
    virtual void executar() = 0;
    virtual void setCtrlIAAutenticacao(IAAutenticacao *) = 0;    // Método para estabelecer ligação com a controladora na camada de apresentação.
    virtual void setCtrlIADesenvolvedor(IADesenvolvedor *) = 0;  // Método para estabelecer ligação com a controladora na camada de apresentação.
    virtual void setCtrlIATeste(IATeste *) = 0;                  // Método para estabelecer ligação com a controladora na camada de apresentação.
    virtual ~IAInicializacao(){};
};

class IAAutenticacao {
   public:
};

class IADesenvolvedor {
};

class IATeste {
   public:
    virtual void executar(Matricula) = 0;        // Método por meio do qual é solicitado o serviço.
    virtual void setCtrlISTeste(ISTeste *) = 0;  // Método para estabelecer ligação com a controladora na camada de serviço.
    virtual ~IATeste(){};                        // Método destrutor virtual.
};

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de serviço.

class ISAutenticacao {
};

class ISDesenvolvedor {
};

class ISTeste {
   public:
    virtual bool visualizar(Teste *) = 0;
    virtual bool cadastrar(Teste) = 0;
    virtual bool editar(Teste) = 0;
    virtual bool visualizar(CasoDeTeste *) = 0;
    virtual bool cadastrar(CasoDeTeste) = 0;
    virtual bool editar(CasoDeTeste) = 0;
    virtual bool descadastrar(Codigo) = 0;  // Desambiguidade feita na implementação das controladoras
    virtual ~ISTeste(){};
};

#endif  // INTERFACES_H_INCLUDED