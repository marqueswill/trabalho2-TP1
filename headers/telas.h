#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//--------------------------------------------------------------------------------------------
class Telas {
   protected:
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

    char matriculaDesenvolvedor[80];
    char nomeDesenvolvedor[80];
    char telefoneDesenvolvedor[80];
    char senhaDesenvolvedor[80];

   public:
    void apresentar(int *);
    void cadastrar(Desenvolvedor *);
};

//--------------------------------------------------------------------------------------------
class TelaTeste : public Telas {
   private:
    Codigo codigo;
    Texto nome;
    Classe classe;

    char codigoTeste[100];
    char nomeTeste[100];
    char classeTeste[100];

   public:
    void apresentar(int *);
    void visualizar(Teste *);
    void cadastrar(Teste *);
    void editar(Teste *);
    void descadastrar(Teste *);
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

    char codigoCasoDeTeste[100];
    char nomeCasoDeTeste[100];
    char dataCasoDeTeste[100];
    char acaoCasoDeTeste[100];
    char respostaCasoDeTeste[100];
    char resultadoCasoDeTeste[100];

   public:
    void apresentar(int *);
    void visualizar(CasoDeTeste *);
    void cadastrar(CasoDeTeste *);
    void editar(CasoDeTeste *);
    void descadastrar(CasoDeTeste *);
};

class Tela_Servico_Desenvolvedor: public Tela{
    public:
    string texto5 = "Selecione um dos servicos : ";
    string texto6 = "1 - Selecionar serviços relacionados a desenvolvedor.";
    string texto7 = "2 - Selecionar serviços relacionados a teste.";
    string texto8 = "3 - Selecionar serviços relacionados a caso de teste.";
    string texto9 = "4 - Encerrar sessão.";
    void descadastrar(Matricula *);
};

#endif  // TELAS_H_INCLUDED