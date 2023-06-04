#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//--------------------------------------------------------------------------------------------
class Tela{
    public:
    void apresentar(string generica);
    // Mensagens a serem apresentadas na tela de usuário logado.
    int campo;                        // Campo de entrada.
    int linha, coluna;              // Dados sobre tamanho da tela.
};

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