#include "entidades.h"
#include "dominios.h"
#include "../sources/dominios.cpp"


#include <list>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include "../sources/database.db.sql"
#include "../headers/entidades.h"
#include "sqlite3.h"            // Incluir cabe�alho da biblioteca SQLite.

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
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
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
             nomeBancoDados = "testedb.db";                             // Nome do banco de dados.
        }
        void executar();
};

//---------------------------------------------------------------------------
// Classe ComandoLerMatricula.

class ComandoLerMatricula:public ComandoSQL {
public:
        ComandoLerMatricula(Matricula);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoVisualizarDesenvolvedor.

class ComandoVisualizarDesenvolvedor:public ComandoSQL {
public:
        ComandoVisualizarDesenvolvedor(Matricula);
        Desenvolvedor getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoCadastrarDesenvolvedor

class ComandoCadastrarDesenvolvedor:public ComandoSQL {
public:
        ComandoCadastrarDesenvolvedor(Desenvolvedor);
};

//---------------------------------------------------------------------------
//Classe ComandoEditarDesenvolvedor

class ComandoEditarDesenvolvedor:public ComandoSQL {
public:
        ComandoEditarDesenvolvedor(Desenvolvedor);
};

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarDesenvolvedor

class ComandoDescadastrarDesenvolvedor:public ComandoSQL {
public:
        ComandoDescadastrarDesenvolvedor(Matricula);
};
//---------------------------------------------------------------------------
// Classe ComandoLerCodigo

class ComandoLerCodigo: public ComandoSQL {
public:
        ComandoLerCodigo(Codigo);
        string getResultado();
};

//---------------------------------------------------------------------------
// Classe ComandoVisualizarTeste

class ComandoVisualizarTeste: public ComandoSQL {
public:
        ComandoVisualizarTeste(Codigo);
        Codigo getResultado();
};
//---------------------------------------------------------------------------
// Classe ComandoCadastrarTeste
class ComandoCadastrarTeste:public ComandoSQL {
public:
        ComandoCadastrarTeste(Teste);
};
//---------------------------------------------------------------------------
// Classe ComandoEditarTeste
class ComandoEditarTeste:public ComandoSQL {
public:
        ComandoEditarTeste(Teste);
};
//---------------------------------------------------------------------------
// Classe ComandoDescadastrarTeste
class ComandoDescadastrarTeste:public ComandoSQL {
public:
        ComandoDescadastrarTeste(Codigo);
};
//---------------------------------------------------------------------------
// Classe ComandoVisualizarCasoDeTeste
class ComandoVisualizarCasoDeTeste: public ComandoSQL {
public:
        ComandoVisualizarCasoDeTeste(Codigo);
        Codigo getResultado();
};
//---------------------------------------------------------------------------
// Classe ComandoCadastrarCasoDeTeste
class ComandoCadastrarCasoDeTeste:public ComandoSQL {
public:
        ComandoCadastrarCasoDeTeste(CasoDeTeste);
};
//---------------------------------------------------------------------------
// Classe ComandoEditarCasoDeTeste
class ComandoEditarCasoDeTeste:public ComandoSQL {
public:
        ComandoEditarCasoDeTeste(CasoDeTeste);
};
//---------------------------------------------------------------------------
// Classe ComandoDescadastrarTeste
class ComandoDescadastrarCasoDeTeste:public ComandoSQL {
public:
        ComandoDescadastrarCasoDeTeste(Codigo);
};