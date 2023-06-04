#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//--------------------------------------------------------------------------------------------
class TelaMensagem {
   public:
    void apresentar(string);
};

//--------------------------------------------------------------------------------------------
class TelaInicial {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(int *);  // Método que retorna a opção escolhida.
};

//--------------------------------------------------------------------------------------------
class TelaUsuarioLogado {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(int *);
};

//--------------------------------------------------------------------------------------------
class TelaAutenticacao {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(Matricula *, Senha *);
};

//--------------------------------------------------------------------------------------------
class TelaDesenvolvedor {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(int *);
    void cadastrar(Desenvolvedor *);
};

//--------------------------------------------------------------------------------------------
class TelaTeste {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(int *);
    void visualizar(Teste *);
    void cadastrar(Teste *);
    void editar(Teste *);
    void descadastrar(Teste *);
};

//--------------------------------------------------------------------------------------------
class TelaCasoDeTeste {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(int *);
    void visualizar(CasoDeTeste *);
    void cadastrar(CasoDeTeste *);
    void editar(CasoDeTeste *);
    void descadastrar(CasoDeTeste *);
};

#endif  // TELAS_H_INCLUDED