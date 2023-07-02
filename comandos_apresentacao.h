#ifndef COMANDOS_APRESENTACAO_H_INCLUDED
#define COMANDOS_APRESENTACAO_H_INCLUDED

#include "controladoras_servicos.h"
#include "interfaces.h"
#include "telas.h"

//----------------------------------------------------------------------------------------------------------------------
class ComandoIAAutenticacao {
   protected:
    bool resultado;
    Matricula *matricula;
    Senha senha;
    TelaAutenticacao telaAutenticacao;

   public:
    virtual bool executar(ISAutenticacao *) = 0;
    virtual ~ComandoIAAutenticacao(){};
};

class ComandoIAAutenticacaoAutenticar : public ComandoIAAutenticacao {
   public:
    ComandoIAAutenticacaoAutenticar(Matricula *matricula) {
        this->matricula = matricula;
    };
    bool executar(ISAutenticacao *);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoIADesenvolvedor {
   protected:
    bool resultado;
    Desenvolvedor desenvolvedor;
    Matricula matricula;
    Senha senha;
    Telefone telefone;
    Texto nome;
    TelaDesenvolvedor telaDesenvolvedor;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISDesenvolvedor *) = 0;
};

class ComandoIADesenvolvedorCadastrar : public ComandoIADesenvolvedor {
   public:
    void executar(ISDesenvolvedor *);
};

class ComandoIADesenvolvedorVisualizar : public ComandoIADesenvolvedor {
   public:
    ComandoIADesenvolvedorVisualizar(Matricula matricula) {
        this->matricula = matricula;
    }
    void executar(ISDesenvolvedor *);
};

class ComandoIADesenvolvedorEditar : public ComandoIADesenvolvedor {
   public:
    ComandoIADesenvolvedorEditar(Matricula matricula) {
        this->matricula = matricula;
        this->nome = nome;
        this->senha = senha;
        this->telefone = telefone;
    }
    void executar(ISDesenvolvedor *);
};

class ComandoIADesenvolvedorDescadastrar : public ComandoIADesenvolvedor {
   public:
    ComandoIADesenvolvedorDescadastrar(Matricula matricula) {
        this->matricula = matricula;
    }
    void executar(ISDesenvolvedor *);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoIATeste {
   protected:
    bool resultado;
    Teste teste;
    Codigo codigo;
    Matricula matricula;
    Classe classe;
    Texto nome;
    TelaTeste telaTeste;
    TelaMensagem telaMensagem;

   public:
    virtual void executar(ISTeste *) = 0;
    virtual ~ComandoIATeste() {}
};
//
class ComandoIATesteVisualizar : public ComandoIATeste {
   public:
    ComandoIATesteVisualizar(Matricula matricula) {
        this->matricula = matricula;
    }
    void executar(ISTeste *);
};

class ComandoIATesteCadastrar : public ComandoIATeste {
    public:
    ComandoIATesteCadastrar(Matricula matricula){
        this->matricula = matricula;
    }
    void executar(ISTeste *);

};

class ComandoIATesteEditar : public ComandoIATeste {
    public:
    ComandoIATesteEditar(Matricula matricula){
        this->matricula = matricula;
    }
    void executar(ISTeste *);
};

class ComandoIATesteDescadastrar : public ComandoIATeste {
    public:
    ComandoIATesteDescadastrar(Matricula matricula){
        this->matricula = matricula;
    }
    void executar(ISTeste *);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoIACasoDeTeste {
   protected:
    bool resultado;
    CasoDeTeste casoDeTeste;
    Codigo codigo;
    Codigo codigotestes;
    TelaCasoDeTeste telaCasoDeTeste;
    TelaMensagem telaMensagem;
    Matricula matricula;

   public:
    virtual void executar(ISCasoDeTeste *) = 0;
    virtual ~ComandoIACasoDeTeste() {}
};

class ComandoIACasoDeTesteVisualizar : public ComandoIACasoDeTeste {
    public:
    ComandoIACasoDeTesteVisualizar(Matricula matricula){
        this->matricula = matricula;
    }
    void executar(ISCasoDeTeste *);
};

class ComandoIACasoDeTesteCadastrar : public ComandoIACasoDeTeste {
    public:
    ComandoIACasoDeTesteCadastrar(Matricula matricula){
        this->matricula = matricula;
    }

    void executar(ISCasoDeTeste *);
};

class ComandoIACasoDeTesteEditar : public ComandoIACasoDeTeste {
    public:
    ComandoIACasoDeTesteEditar(Matricula matricula){
        this->matricula = matricula;
    }
    void executar(ISCasoDeTeste *);
};

class ComandoIACasoDeTesteDescadastrar : public ComandoIACasoDeTeste {
    public:
    ComandoIACasoDeTesteDescadastrar(Matricula matricula){
        this->matricula = matricula;
    }
    void executar(ISCasoDeTeste *);
};

#endif  // COMANDOS_APRESENTACAO_H_INCLUDED
