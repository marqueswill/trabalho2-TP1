#ifndef COMANDOS_APRESENTACAO_H_INCLUDED
#define COMANDOS_APRESENTACAO_H_INCLUDED

#include "interfaces.h"
#include "telas.h"

//--------------------------------------------------------------------------------------------
class CmdIAAutenticacao {
   protected:
    bool resultado;
    Matricula *matricula;
    Senha senha;
    TelaAutenticacao telaAutenticacao;
    
   public:
    virtual void executar(ISAutenticacao*) = 0;
    virtual ~CmdIAAutenticacao() {}
};
class CmdIAutenticacaoAutenticar : public CmdIAAutenticacao {
    public:
    void executar(ISDesenvolvedor*);
};

//--------------------------------------------------------------------------------------------
class CmdIADesenvolvedor {
   protected:
    bool resultado;
    Desenvolvedor desenvolvedor;
    Matricula matricula;
    TelaDesenvolvedor telaDesenvolvedor;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISDesenvolvedor*) = 0;
    virtual ~CmdIADesenvolvedor() {}
};

class CmdIADesenvolvedorCadastrar : public CmdIADesenvolvedor {
   public:
    void executar(ISDesenvolvedor*);
};

class CmdIADesenvolvedorVisualizar : public CmdIADesenvolvedor {
   public:
    void executar(ISDesenvolvedor*);
};

class CmdIADesenvolvedorEditar : public CmdIADesenvolvedor {
   public:
    void executar(ISDesenvolvedor*);
};

class CmdIADesenvolvedorDescadastrar : public CmdIADesenvolvedor {
   public:
    void executar(ISDesenvolvedor*);
};

//--------------------------------------------------------------------------------------------
class CmdIATeste {
   protected:
    bool resultado;
    Teste teste;
    Codigo codigo;
    TelaTeste telaTeste;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISTeste*) = 0;
    virtual ~CmdIATeste() {}
};

class CmdIATesteVisualizar : public CmdIATeste {
   public:
    void executar(ISTeste*);
};

class CmdIATesteCadastrar : public CmdIATeste {
    void executar(ISTeste*);
};

class CmdIATesteEditar : public CmdIATeste {
    void executar(ISTeste*);
};

class CmdIATesteDescadastrar : public CmdIATeste {
    void executar(ISTeste*);
};

//--------------------------------------------------------------------------------------------
class CmdIACasoDeTeste {
   protected:
    bool resultado;
    CasoDeTeste casoDeTeste;
    Codigo codigo;
    TelaCasoDeTeste telaCasoDeTeste;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISCasoDeTeste*) = 0;
    virtual ~CmdIACasoDeTeste() {}
};

class CmdIACasoDeTesteVisualizar : public CmdIACasoDeTeste {
    void executar(ISCasoDeTeste*);
};

class CmdIACasoDeTesteCadastrar : public CmdIACasoDeTeste {
    void executar(ISCasoDeTeste*);
};

class CmdIACasoDeTesteEditar : public CmdIACasoDeTeste {
    void executar(ISCasoDeTeste*);
};

class CmdIACasoDeTesteDescadastrar : public CmdIACasoDeTeste {
    void executar(ISCasoDeTeste*);
};

#endif  // COMANDOS_APRESENTACAO_H_INCLUDED
