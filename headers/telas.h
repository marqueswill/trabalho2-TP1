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
    // Mensagens a serem apresentadas na tela de usuário logado.
    int campo;                        // Campo de entrada.
    int linha, coluna;            // Dados sobre tamanho da tela.
};

class TelaMensagem: public Tela {
   public:
    void apresentar(string);
};

//--------------------------------------------------------------------------------------------
class TelaInicial: public Tela {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(int *);  // Método que retorna a opção escolhida.
};

//--------------------------------------------------------------------------------------------
class TelaUsuarioLogado: public Tela {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(int *);
};

//--------------------------------------------------------------------------------------------
class TelaAutenticacao: public Tela {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(Matricula *, Senha *);
};

//--------------------------------------------------------------------------------------------
class TelaDesenvolvedor: public Tela {
   private:
    TelaMensagem telaMensagem;

   public:
    void apresentar(int *);
    void cadastrar(Desenvolvedor *);
};

//--------------------------------------------------------------------------------------------
class TelaTeste: public Tela {
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
class TelaCasoDeTeste: public Tela {
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

#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
using namespace std;
class Tela{
    public:
    void apresentar(string generica);
    // Mensagens a serem apresentadas na tela de usuário logado.
    int campo;                        // Campo de entrada.
    int linha, coluna;              // Dados sobre tamanho da tela.
};
class Tela_Inicial: public Tela{
    public:
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Acessar sistema.";
    string texto3 = "2 - Cadastrar desenvolvedor.";
    string texto4 = "3 - Encerrar execução do sistema.";
    string texto10 = "Falha na autenticacao. Digite algo para continuar.";
    void selecionar_servicos_inicial();
    void selecionar_servicos_logado();
};

class Tela_Apresentacao_Desenvolvedor: public Tela{
    public:
    void cadastrar_desenvolvedor(Desenvolvedor *desenvolvedor);
    void executar_desenvolvedor();
};

class Tela_Servico_Desenvolvedor: public Tela{
    public:
    string texto5 = "Selecione um dos servicos : ";
    string texto6 = "1 - Selecionar serviços relacionados a desenvolvedor.";
    string texto7 = "2 - Selecionar serviços relacionados a teste.";
    string texto8 = "3 - Selecionar serviços relacionados a caso de teste.";
    string texto9 = "4 - Encerrar sessão.";
}