#ifndef COMANDOS_SERVICOS_H_INCLUDED
#define COMANDOS_SERVICOS_H_INCLUDED

// #include <conio.h>
// #include <stdio.h>

#include "dominios.h"
#include "entidades.h"
#include "sqlite3.h"

using namespace std;

//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
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

inline void ElementoResultado::setValorColuna(const string &valorColuna) {
    this->valorColuna = valorColuna;
}

//---------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
class ComandoISLerSenha : public ComandoSQL {
   private:
   public:
    ComandoISLerSenha(Matricula);
    string getResultado();
};

class ComandoISLerMatricula : public ComandoSQL {
   private:
   public:
    ComandoISLerMatricula(Matricula);
    string getResultado();
};

class ComandoISLerCodigoTeste : public ComandoSQL {
   public:
    ComandoISLerCodigoTeste(Codigo);
    string getResultado();
};

class ComandoISLerCodigoCasoDeTeste : public ComandoSQL {
   public:
    ComandoISLerCodigoCasoDeTeste(Codigo);
    string getResultado();
};

//---------------------------------------------------------------------------
class ComandoISVisualizarDesenvolvedor : public ComandoSQL {
   public:
    ComandoISVisualizarDesenvolvedor(Matricula);
    Desenvolvedor getResultado();
};

class ComandoISCadastrarDesenvolvedor : public ComandoSQL {
   public:
    ComandoISCadastrarDesenvolvedor(Desenvolvedor);
};

class ComandoISEditarDesenvolvedor : public ComandoSQL {
   public:
    ComandoISEditarDesenvolvedor(Desenvolvedor);
};

class ComandoISDescadastrarDesenvolvedor : public ComandoSQL {
   public:
    ComandoISDescadastrarDesenvolvedor(Matricula);
};

//---------------------------------------------------------------------------
class ComandoISListarTeste : public ComandoSQL {
   public:
    ComandoISListarTeste(Matricula);
    vector<Teste> getLista();
};

class ComandoISVisualizarTeste : public ComandoSQL {
   public:
    ComandoISVisualizarTeste(Codigo);
    Codigo getResultado();
};

class ComandoISCadastrarTeste : public ComandoSQL {
   public:
    ComandoISCadastrarTeste(Teste);
};

class ComandoISEditarTeste : public ComandoSQL {
   public:
    ComandoISEditarTeste(Teste);
};

class ComandoISDescadastrarTeste : public ComandoSQL {
   public:
    ComandoISDescadastrarTeste(Codigo);
};

//---------------------------------------------------------------------------
class ComandoISVisualizarCasoDeTeste : public ComandoSQL {
   public:
    ComandoISVisualizarCasoDeTeste(Codigo);
    Codigo getResultado();
};

class ComandoISCadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoISCadastrarCasoDeTeste(CasoDeTeste);
};

class ComandoISEditarCasoDeTeste : public ComandoSQL {
   public:
    ComandoISEditarCasoDeTeste(CasoDeTeste);
};

class ComandoISDescadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoISDescadastrarCasoDeTeste(Codigo);
};

#endif  // COMANDOS_SERVICOS_H_INCLUDED