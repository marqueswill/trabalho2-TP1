#ifndef CONTROLADORAS_SERVICO_H_INCLUDED
#define CONTROLADORAS_SERVICO_H_INCLUDED

#include <cstdlib>
#include <iostream>
#include <string>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//-----------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de serviços e implementações de métodos inline.

class CtrlMSAutenticacao : public ISAutenticacao {
};

//-----------------------------------------------------------------------------------
class CtrlMSDesenvolvedor : public ISDesenvolvedor {
   public:
    TelaMensagem telaMsg;
    TelaDesenvolvedor telaDesenvolvedor;
    const static int MAX = 4;
    const static int VISUALIZAR = 1;
    const static int EDITAR = 2;
    const static int DESCADASTRAR = 3;

    bool visualizar(Desenvolvedor*);
    bool editar(Desenvolvedor);
    bool descadastrar(Matricula);
};

//-----------------------------------------------------------------------------------
class CtrlMSTeste : public ISTeste {
   public:
    bool visualizar(Teste *);
    bool cadastrar(Teste);
    bool editar(Teste);
    bool descadastrar(Codigo);
};

class CtrlMSCasoDeTeste : public ISCasoDeTeste {
   public:
    bool visualizar(CasoDeTeste *);
    bool cadastrar(CasoDeTeste);
    bool editar(CasoDeTeste);
    bool descadastrar(Codigo);
};

#endif CONTROLADORAS_SERVICO_H_INCLUDED