#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include <ncurses.h>

#include "interfaces.h"

class TelaMensagem;

//--------------------------------------------------------------------------------------------
class Telas {
   public:
    int campo;
    int linha, coluna;
};

//--------------------------------------------------------------------------------------------
class TelaMensagem : public Telas {
   public:
    void apresentar(string);
};

//--------------------------------------------------------------------------------------------
class TelaInicial : public Telas {
   public:
    void apresentar(int *);  // Método que retorna a opção escolhida.
};

//--------------------------------------------------------------------------------------------
class TelaUsuarioLogado : public Telas {
   public:
    void apresentar(int *);
};

//--------------------------------------------------------------------------------------------
class TelaAutenticacao : public Telas {
   public:
    void apresentar(Matricula *, Senha *);
};

//--------------------------------------------------------------------------------------------
class TelaDesenvolvedor : public Telas {
   private:
    Matricula matricula;
    Texto nome;
    Telefone telefone;
    Senha senha;

    char matriculaDesenvolvedor[100] = "";
    char nomeDesenvolvedor[100] = "";
    char telefoneDesenvolvedor[100] = "";
    char senhaDesenvolvedor[100] = "";

   public:
    void apresentar(int *);
    void apresentar(Desenvolvedor *);
    void apresentar(Matricula *);
};

//--------------------------------------------------------------------------------------------
class TelaTeste : public Telas {
   private:
    Codigo codigo;
    Texto nome;
    Classe classe;

    char valorGenerico[100] = "";
    char codigoTeste[100] = "";
    char nomeTeste[100] = "";
    char classeTeste[100] = "";

   public:
    void selecionar(int *);
    void mostrar(Teste);          // mostrar valores
    void visualizar(Teste *);     // obter codigo
    void cadastrar(Teste *);      // defnir  valores teste
    void editar(Teste *);         // definir novos valores
    void descadastrar(Codigo *);  // definir codigo
};

//--------------------------------------------------------------------------------------------
class TelaCasoDeTeste : public Telas {
   private:
    Codigo codigo;
    Texto nome;
    Data data;
    Texto acao;
    Texto resposta;
    Resultado resultado;

    char codigoCasoDeTeste[100] = "";
    char nomeCasoDeTeste[100] = "";
    char dataCasoDeTeste[100] = "";
    char acaoCasoDeTeste[100] = "";
    char respostaCasoDeTeste[100] = "";
    char resultadoCasoDeTeste[100] = "";

   public:
    void selecionar(int *);
    void mostrar(CasoDeTeste);       // mostrar valores
    void visualizar(CasoDeTeste *);  // obter codigo
    void cadastrar(CasoDeTeste *);   // defnir  valores teste
    void editar(CasoDeTeste *);      // definir novos valores
    void descadastrar(Codigo *);     // definir codigo
};

//--------------------------------------------------------------------------------------------
class TelaDepuracao : public Telas {
   private:
   public:
    void selecionar(int *);
};

class TelaTestesUnitarios : public Telas {
   private:
   public:
    void selecionar(int *);
};
#endif  // TELAS_H_INCLUDED