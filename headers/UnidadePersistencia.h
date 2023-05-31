#include "entidades.h"
#include "dominios.h"
#include "../sources/dominios.cpp"


#include <list>

#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
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
// Declara��o da classe ComandoSQL.

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
// Declara��o da classe ComandoLerSenha.

class ComandoLerMatricula:public ComandoSQL {
public:
        ComandoLerMatricula(Matricula);
        string getResultado();
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarAluno.

class ComandoVisualizarDesenvolvedor:public ComandoSQL {
public:
        ComandoVisualizarDesenvolvedor(Matricula);
        Desenvolvedor getResultado();
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoCadastrarAluno.

class ComandoCadastrarDesenvolvedor:public ComandoSQL {
public:
        ComandoCadastrarDesenvolvedor(Desenvolvedor);
};

//---------------------------------------------------------------------------
//Classe ComandoAtualizarAluno.

class ComandoEditarDesenvolvedor:public ComandoSQL {
public:
        ComandoEditarDesenvolvedor(Desenvolvedor);
};

//---------------------------------------------------------------------------
// Declara��o da classe ComandoRemoverAluno.

class ComandoDescadastrarDesenvolvedor:public ComandoSQL {
public:
        ComandoDescadastrarDesenvolvedor(Matricula);
};

