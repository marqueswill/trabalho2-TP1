#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

// Mudar o include quando for compilar
//#include <ncurses.h>
 #include "curses.h"

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
    void selecionar(int *);  // Método que retorna a opção escolhida.
};

//--------------------------------------------------------------------------------------------
class TelaUsuarioLogado : public Telas {
   public:
    void selecionar(int *);
};

//--------------------------------------------------------------------------------------------
class TelaAutenticacao : public Telas {
   private:
    char matriculaAutenticacao[100] = "";
    char senhaAutenticacao[100] = "";
   public:
    void autenticar(Matricula *, Senha *);
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
    void selecionar(int *);
    void mostrar(Desenvolvedor);
    void visualizar(Desenvolvedor *);
    void descadastrar(Matricula *);
    void cadastrar(Desenvolvedor *);
    void editar(Desenvolvedor *);
};

//--------------------------------------------------------------------------------------------
class TelaTeste : public Telas {
   private:
    Codigo codigo;
    Texto nome;
    Classe classe;

    char codigoTeste[100] = "";
    char nomeTeste[100] = "";
    char classeTeste[100] = "";

   public:
    void mostrar(Teste);          // mostrar valores
    void selecionar(int *);       // tela de seleção
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
    void mostrar(CasoDeTeste);       // mostrar valores
    void selecionar(int *);          // tela de seleção
    void visualizar(CasoDeTeste *);  // obter codigo
    void cadastrar(CasoDeTeste *);   // defnir  valores teste
    void editar(CasoDeTeste *);      // definir novos valores
    void descadastrar(Codigo *);     // definir codigo
};

//--------------------------------------------------------------------------------------------
class TelaDepuracao : public Telas {
   public:
    void selecionar(int *);
};

class TelaTestesUnitarios : public Telas {
   public:
    void selecionar(int *);
};

class TelaTestesModulos : public Telas {
   public:
    void selecionar(int *);
};

class TelaTestesIntegracao : public Telas {
   public:
    void selecionar(int *);
};

#endif  // TELAS_H_INCLUDED
