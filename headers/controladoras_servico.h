#ifndef CONTROLADORAS_SERVICO_H_INCLUDED
#define CONTROLADORAS_SERVICO_H_INCLUDED

#include "interfaces.h"
#include "comandos_servicos.h"
//-----------------------------------------------------------------------------------
// Declarações de classes controladoras da camada de serviços e implementações de métodos inline.

class CtrlMSAutenticacao : public ISAutenticacao {
};

//-----------------------------------------------------------------------------------
class CtrlMSDesenvolvedor : public ISDesenvolvedor {
   private:
   ComandoCadastrarDesenvolvedor comandoCadastrar;
   ComandoEditarDesenvolvedor comandoEditar;
   ComandoVisualizarDesenvolvedor comandoVisualizar;
   ComandoDescadastrarDesenvolvedor comandoDescadastrar;
   public:
    bool visualizar(Desenvolvedor *);
    bool cadastrar(Desenvolvedor);
    bool editar(Desenvolvedor);
    bool descadastrar(Matricula);
};

//-----------------------------------------------------------------------------------
class CtrlMSTeste : public ISTeste {
   private:
   ComandoCadastrarTeste comandoCadastrar;
   ComandoEditarTeste comandoEditar;
   ComandoVisualizarTeste comandoVisualizar;
   ComandoDescadastrarTeste comandoDescadastrar;
   public:
    bool visualizar(Teste *);
    bool cadastrar(Teste);
    bool editar(Teste);
    bool descadastrar(Codigo);
};

class CtrlMSCasoDeTeste : public ISCasoDeTeste {
   private:
   ComandoCadastrarCasoDeTeste comandoCadastrar;
   ComandoEditarCasoDeTeste comandoEditar;
   ComandoVisualizarCasoDeTeste comandoVisualizar;
   ComandoDescadastrarCasoDeTeste comandoDescadastrar;
   public:
    bool visualizar(CasoDeTeste *);
    bool cadastrar(CasoDeTeste);
    bool editar(CasoDeTeste);
    bool descadastrar(Codigo);
};

#endif  // CONTROLADORAS_SERVICO_H_INCLUDED