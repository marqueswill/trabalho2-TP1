#ifndef COMANDOS_SERVICOS_H_INCLUDED
#define COMANDOS_SERVICOS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "sqlite3.h"

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
        nomeBancoDados = "testedb.db";  // Nome default para um banco de dados.
    }
    void executar();
};

//--------------------------------------------------------------------------------------------
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
   private:
    vector<string> tabelas = {"testes", "casodetestes"};

   public:
    ComandoLerCodigo(Codigo, int);  // informar de qual banco
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

//--------------------------------------------------------------------------------------------
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

class ComandoDescadastrarCasoDeTeste : public ComandoSQL {
   public:
    ComandoDescadastrarCasoDeTeste(Codigo);
};

#endif  // COMANDOS_SERVICOS_H_INCLUDED