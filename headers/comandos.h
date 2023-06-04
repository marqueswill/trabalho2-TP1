#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "telas.h"

//--------------------------------------------------------------------------------------------
class CmdIAAutenticacao {
   public:
    virtual void executar(ISTeste*) = 0;
    virtual ~CmdIAAutenticacao() {}
};
//--------------------------------------------------------------------------------------------
class CmdIADev {
    protected:
    bool resultado;
    Desenvolvedor dev;
    Matricula matricula;
    Telefone telefone;
    Senha senha;
    TelaDesenvolvedor TelaDev;
   public:
    virtual void executar(ISTeste*) = 0;
    virtual ~CmdIADev() {}
};
class CmdIADevCadastrar: public CmdIADev{
public:
void executar(ISDesenvolvedor*);
};
class CmdIADevVisualizar: public CmdIADev{
public:
void executar(ISDesenvolvedor*);
};
class CmdIADevEditar: public CmdIADev{
    public:
    void executar(ISDesenvolvedor*);
};
class CmdIaDevDescadastrar: public CmdIADev{
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
    CasoDeTeste casodeteste;
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

#endif  // COMANDOS_H_INCLUDED