#ifndef COMANDOS_SERVICOS_H_INCLUDED
#define COMANDOS_SERVICOS_H_INCLUDED

// #include <conio.h>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#include "dominios.h"
#include "entidades.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
class EErroPersistencia {
   private:
    string mensagem;

   public:
    EErroPersistencia(string);
    string what();
};

inline EErroPersistencia::EErroPersistencia(string mensagem) {
    this->mensagem = mensagem;
}

inline string EErroPersistencia::what() {
    return mensagem;
}

//----------------------------------------------------------------------------------------------------------------------
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

inline void ElementoResultado::setNomeColuna(const string &nomeColuna) {
    this->nomeColuna = nomeColuna;
}

inline string ElementoResultado::getNomeColuna() const {
    return nomeColuna;
}

inline void ElementoResultado::setValorColuna(const string &valorColuna) {
    this->valorColuna = valorColuna;
}

inline string ElementoResultado::getValorColuna() const {
    return valorColuna;
}

//----------------------------------------------------------------------------------------------------------------------
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
        nomeBancoDados = "database.db";
    }
    void executar();
};

inline void ComandoSQL::conectar() {
    rc = sqlite3_open(nomeBancoDados, &bd);
    if (rc != SQLITE_OK)
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

inline void ComandoSQL::desconectar() {
    rc = sqlite3_close(bd);
    if (rc != SQLITE_OK)
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

inline int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna) {
    NotUsed = 0;
    ElementoResultado elemento;
    int i;
    for (i = 0; i < argc; i++) {
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i] : "NULL");
        listaResultado.push_front(elemento);
    }
    return 0;
}

inline void ComandoSQL::executar() {
    conectar();
    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if (rc != SQLITE_OK) {
        sqlite3_free(mensagem);
        desconectar();
        throw EErroPersistencia("Erro na execucao do comando SQL");
    }
    desconectar();
}

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLLerSenha : public ComandoSQL {
   private:
   public:
    ComandoSQLLerSenha(Matricula);
    string getResultado();
};

class ComandoSQLLerMatricula : public ComandoSQL {
   private:
   public:
    ComandoSQLLerMatricula(Matricula);
    string getResultado();
};

class ComandoSQLLerCodigoTeste : public ComandoSQL {
   public:
    ComandoSQLLerCodigoTeste(Codigo);
    string getResultado();
};

class ComandoSQLLerCodigoCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLLerCodigoCasoDeTeste(Codigo);
    string getResultado();
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLVisualizarDesenvolvedor : public ComandoSQL {
   public:
    ComandoSQLVisualizarDesenvolvedor(Matricula);
    Desenvolvedor getResultado();
};

class ComandoSQLCadastrarDesenvolvedor : public ComandoSQL {
   public:
    ComandoSQLCadastrarDesenvolvedor(Desenvolvedor);
};

class ComandoSQLEditarDesenvolvedor : public ComandoSQL {
   public:
    ComandoSQLEditarDesenvolvedor(Desenvolvedor);
};

class ComandoSQLDescadastrarDesenvolvedor : public ComandoSQL {
   public:
    ComandoSQLDescadastrarDesenvolvedor(Matricula);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLListarTeste : public ComandoSQL {
   public:
    ComandoSQLListarTeste(Matricula);
    vector<Teste> getLista();
};

class ComandoSQLVisualizarTeste : public ComandoSQL {
   public:
    ComandoSQLVisualizarTeste(Codigo);
    Teste getResultado();
};

class ComandoSQLCadastrarTeste : public ComandoSQL {
   public:
    ComandoSQLCadastrarTeste(Teste);
};

class ComandoSQLEditarTeste : public ComandoSQL {
   public:
    ComandoSQLEditarTeste(Teste);
};

class ComandoSQLDescadastrarTeste : public ComandoSQL {
   public:
    ComandoSQLDescadastrarTeste(Codigo);
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLVisualizarCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLVisualizarCasoDeTeste(Codigo);
    CasoDeTeste getResultado();
};

class ComandoSQLCadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLCadastrarCasoDeTeste(CasoDeTeste);
};

class ComandoSQLEditarCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLEditarCasoDeTeste(CasoDeTeste);
};

class ComandoSQLDescadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLDescadastrarCasoDeTeste(Codigo);
};

#endif  // COMANDOS_SERVICOS_H_INCLUDED