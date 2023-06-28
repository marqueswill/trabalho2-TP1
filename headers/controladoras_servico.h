#ifndef CONTROLADORAS_SERVICO_H_INCLUDED
#define CONTROLADORAS_SERVICO_H_INCLUDED

#include "comandos_servico.h"
#include "interfaces.h"

//----------------------------------------------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de serviços e implementações de métodos inline.

class CtrlISAutenticacao : public ISAutenticacao {
   public:
    bool autenticar(Matricula, Senha);
};

//----------------------------------------------------------------------------------------------------------------------
class CtrlISDesenvolvedor : public ISDesenvolvedor {
   public:
    bool visualizar(Desenvolvedor *);
    bool cadastrar(Desenvolvedor);
    bool editar(Desenvolvedor);
    bool descadastrar(Matricula);
};

//----------------------------------------------------------------------------------------------------------------------
class CtrlISTeste : public ISTeste {
   public:
    bool visualizar(Teste *);
    bool cadastrar(Teste);
    bool editar(Teste);
    bool descadastrar(Codigo);
};

class CtrlISCasoDeTeste : public ISCasoDeTeste {
   public:
    bool visualizar(CasoDeTeste *);
    bool cadastrar(CasoDeTeste);
    bool editar(CasoDeTeste);
    bool descadastrar(Codigo);
};

#endif  // CONTROLADORAS_SERVICO_H_INCLUDED