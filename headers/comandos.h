#include <iostream>
#include <telas.h>
#include "controladoras.h"

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
class CmdIADesenvolvedor {
   protected:
    bool resultado;
    Desenvolvedor desenvolvedor;
    Matricula matricula;
    Telefone telefone;
    Senha senha;
    TelaDesenvolvedor elaDesenvolvedor;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISTeste*) = 0;
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
;
class Comandos_Desenvolvedor{
    public:
    Texto nome;
    Matricula matricula;
    Telefone telefone;
    Senha senha;
    void Cadastrar_Desenvolvedor(Desenvolvedor*,string, string, string, string);
};
#endif  // COMANDOS_H_INCLUDED