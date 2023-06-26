#ifndef COMANDOS_SERVICOS_H_INCLUDED
#define COMANDOS_SERVICOS_H_INCLUDED

// #include <conio.h>

#include "../sources/database.db.sql"
#include "../sources/dominios.cpp"
#include "dominios.h"
#include "entidades.h"
// #include <conio.h>

using namespace std;

//--------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------
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

inline string ElementoResultado::getValorColuna() const {
    return valorColuna;
}

inline void ElementoResultado::setValorColuna(const string &valorColuna) {
    this->valorColuna = valorColuna;
}

//--------------------------------------------------------------------------------------------
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
        nomeBancoDados = "testedb.db";  // Nome do banco de dados.
    }
    void executar();
};

//---------------------------------------------------------------------------
class ComandoLerSenha : public ComandoSQL {
   public:
    ComandoLerSenha(Matricula);
    string getResultado();
};

class ComandoLerMatricula : public ComandoSQL {
   public:
    ComandoLerMatricula(Matricula);
    string getResultado();
};

class ComandoLerCodigo : public ComandoSQL {
   public:
    ComandoLerCodigo(Codigo);
    string getResultado();
};

//--------------------------------------------------------------------------------------------
class ComandoVisualizarDesenvolvedor : public ComandoSQL {
   public:
    ComandoVisualizarDesenvolvedor(Matricula);
    Desenvolvedor getResultado();
};

class ComandoCadastrarDesenvolvedor : public ComandoSQL {
   public:
    ComandoCadastrarDesenvolvedor(Desenvolvedor);
};

class ComandoEditarDesenvolvedor : public ComandoSQL {
   public:
    ComandoEditarDesenvolvedor(Desenvolvedor);
};

class ComandoDescadastrarDesenvolvedor : public ComandoSQL {
   public:
    ComandoDescadastrarDesenvolvedor(Matricula);
};

class ComandoLerCodigo : public ComandoSQL {
   public:
    ComandoLerCodigo(Codigo);
    string getResultado();
};

//---------------------------------------------------------------------------
// Classe ComandoVisualizarTeste

class ComandoVisualizarTeste : public ComandoSQL {
   public:
    ComandoVisualizarTeste(Codigo);
    Codigo getResultado();
};

class ComandoCadastrarTeste : public ComandoSQL {
   public:
    ComandoCadastrarTeste(Teste);
};

class ComandoEditarTeste : public ComandoSQL {
   public:
    ComandoEditarTeste(Teste);
};

class ComandoDescadastrarTeste : public ComandoSQL {
   public:
    ComandoDescadastrarTeste(Codigo);
};

class ComandoListarTeste : public ComandoSQL {
   public:
    ComandoListarTeste(Matricula);
    vector<Teste> getLista();
};

//--------------------------------------------------------------------------------------------
class ComandoVisualizarCasoDeTeste : public ComandoSQL {
   public:
    ComandoVisualizarCasoDeTeste(Codigo);
    Codigo getResultado();
};

class ComandoCadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoCadastrarCasoDeTeste(CasoDeTeste);
};

class ComandoEditarCasoDeTeste : public ComandoSQL {
   public:
    ComandoEditarCasoDeTeste(CasoDeTeste);
};
//---------------------------------------------------------------------------
// Classe ComandoDescadastrarTeste
class ComandoDescadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoDescadastrarCasoDeTeste(Codigo);
};

class ComandoListarCasoDeTeste : public ComandoSQL {
   public:
    ComandoListarCasoDeTeste(Matricula);
    vector<CasoDeTeste> getLista();
};

#endif  // COMANDOS_SERVICOS_H_INCLUDED