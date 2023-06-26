#ifndef COMANDOS_SERVICOS_H_INCLUDED
#define COMANDOS_SERVICOS_H_INCLUDED

// #include <conio.h>
// #include <stdio.h>

#include "dominios.h"
#include "entidades.h"
#include "sqlite3.h"

using namespace std;

//---------------------------------------------------------------------------
// Declara��o da classe EErroPersistencia.

class EErroPersistencia {
   private:
    string mensagem;

   public:
    EErroPersistencia(string);
    string what();
};

class ElementoResultado {
   private:
    string nomeColuna;
    string valorColuna;

   public:
    void setNomeColuna(const string &);
    string getNomeColuna() const;
    void setValorColuna(const string &);
    string getValorColuna() const;
};

//---------------------------------------------------------------------------
// Classe ComandoSQL.

class ComandoSQL {
   private:
    const char *nomeBancoDados;
    sqlite3 *bd;
    char *mensagem;
    int rc;
    void conectar();
    void desconectar();
    static int callback(void *, int, char **, char **);

   protected:
    static list<ElementoResultado> listaResultado;
    string comandoSQL;

   public:
    ComandoSQL() {
        nomeBancoDados = "database.db";  // Nome do banco de dados.
    }
    ComandoSQL *Comandosql;
    void executar();
};
//---------------------------------------------------------------------------
// Classe ComandoLerSenha
class ComandoLerSenha : public ComandoSQL {
   private:
   public:
    ComandoLerSenha(Matricula);
    string getResultado();
};

//---------------------------------------------------------------------------
// Classe ComandoLerMatricula.

class ComandoLerMatricula : public ComandoSQL {
   private:
   public:
    ComandoLerMatricula(Matricula);
    string getResultado();
};

//---------------------------------------------------------------------------
// Classe ComandoVisualizarDesenvolvedor.

class ComandoVisualizarDesenvolvedor : public ComandoSQL {
   public:
    ComandoVisualizarDesenvolvedor(Matricula);
    Desenvolvedor getResultado();
};

//---------------------------------------------------------------------------
// Classe ComandoCadastrarDesenvolvedor

class ComandoCadastrarDesenvolvedor : public ComandoSQL {
   public:
    ComandoCadastrarDesenvolvedor(Desenvolvedor);
};

//---------------------------------------------------------------------------
// Classe ComandoEditarDesenvolvedor

class ComandoEditarDesenvolvedor : public ComandoSQL {
   public:
    ComandoEditarDesenvolvedor(Desenvolvedor);
};

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarDesenvolvedor

class ComandoDescadastrarDesenvolvedor : public ComandoSQL {
   public:
    ComandoDescadastrarDesenvolvedor(Matricula);
};
//---------------------------------------------------------------------------
// Classe ComandoLerCodigo

class ComandoLerCodigo : public ComandoSQL {
   public:
    ComandoLerCodigo(Codigo);
    string getResultado();
};

//---------------------------------------------------------------------------
// Classe ComandoListarTeste
class ComandoListarTeste : public ComandoSQL {
   public:
    ComandoListarTeste(Matricula);
    vector<Teste> getLista();
};
//---------------------------------------------------------------------------
// Classe ComandoVisualizarTeste

class ComandoVisualizarTeste : public ComandoSQL {
   public:
    ComandoVisualizarTeste(Codigo);
    Codigo getResultado();
};
//---------------------------------------------------------------------------
// Classe ComandoCadastrarTeste
class ComandoCadastrarTeste : public ComandoSQL {
   public:
    ComandoCadastrarTeste(Teste);
};
//---------------------------------------------------------------------------
// Classe ComandoEditarTeste
class ComandoEditarTeste : public ComandoSQL {
   public:
    ComandoEditarTeste(Teste);
};
//---------------------------------------------------------------------------
// Classe ComandoDescadastrarTeste
class ComandoDescadastrarTeste : public ComandoSQL {
   public:
    ComandoDescadastrarTeste(Codigo);
};
//---------------------------------------------------------------------------
// Classe ComandoVisualizarCasoDeTeste
class ComandoVisualizarCasoDeTeste : public ComandoSQL {
   public:
    ComandoVisualizarCasoDeTeste(Codigo);
    Codigo getResultado();
};
//---------------------------------------------------------------------------
// Classe ComandoCadastrarCasoDeTeste
class ComandoCadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoCadastrarCasoDeTeste(CasoDeTeste);
};
//---------------------------------------------------------------------------
// Classe ComandoEditarCasoDeTeste
class ComandoEditarCasoDeTeste : public ComandoSQL {
   public:
    ComandoEditarCasoDeTeste(CasoDeTeste);
};
//---------------------------------------------------------------------------
// Classe ComandoListarCasoDeTeste

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarTeste
class ComandoDescadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoDescadastrarCasoDeTeste(Codigo);
};

#endif  // COMANDOS_SERVICOS_H_INCLUDED