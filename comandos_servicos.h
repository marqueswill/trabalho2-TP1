#ifndef COMANDOS_SERVICOS_H_INCLUDED
#define COMANDOS_SERVICOS_H_INCLUDED
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include <list>

#include "dominios.h"
#include "entidades.h"
#include "sqlite3.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
class EErroPersistencia {
   private:
    string mensagem;

   public:
    EErroPersistencia(string);
    string what();
};

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

inline string ElementoResultado::getNomeColuna() const {
    return nomeColuna;
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
        // criartabelas();
    }
    void criartabelas();
    void executar();
};

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
class ComandoSQLContarTeste : public ComandoSQL {
   public:
    ComandoSQLContarTeste(Matricula);
    int getResultado();
};
class ComandoSQLAutenticarTeste : public ComandoSQL {
   public:
    ComandoSQLAutenticarTeste(Matricula);
    list<string> getResultado();
};
class ComandoSQLAutenticarCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLAutenticarCasoDeTeste(Matricula);
    ComandoSQLAutenticarCasoDeTeste(Codigo);
    list<string> getResultado();
};
// class ComandoSQLAutenticarAssociacoesTeste: public ComandoSQL{
//     public:
//     ComandoSQLAutenticarAssociacoesTeste(Matricula);
//     string getResultado();
// };
class ComandoSQLContarCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLContarCasoDeTeste(Codigo);
    ComandoSQLContarCasoDeTeste(Matricula);
    int getResultado();
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
class ComandoSQLDeletarTeste : public ComandoSQL {
   public:
    ComandoSQLDeletarTeste(Matricula);
};
class ComandoSQLListarTeste : public ComandoSQL {
   public:
    ComandoSQLListarTeste(Codigo);
    list<Codigo> getResultado();
};

//----------------------------------------------------------------------------------------------------------------------
class ComandoSQLListarCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLListarCasoDeTeste(Codigo);
    list<Codigo> getResultado();
};
class ComandoSQLDeletarCasoDeTeste : public ComandoSQL {
   public:
    ComandoSQLDeletarCasoDeTeste(Codigo);
    ComandoSQLDeletarCasoDeTeste(Matricula);
};
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
