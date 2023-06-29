#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED

#include "entidades.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------
class TUEntidades {
   private:
    virtual void setUp() = 0;
    virtual void tearDown() = 0;
    virtual void testarValorValido() = 0;

   protected:
    int estado;

   public:
    const static int SUCESSO = true;
    const static int FALHA = false;
    bool run();
};

inline bool TUEntidades::run() {
    setUp();
    testarValorValido();
    tearDown();
    return estado;
}

//----------------------------------------------------------------------------------------------------------------------
class TUDesenvolvedor : public TUEntidades {
   private:
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_MATRICULA;
    const static string VALOR_VALIDO_SENHA;
    const static string VALOR_VALIDO_TELEFONE;
    void setUp();
    void tearDown();
    void testarValorValido();
    Desenvolvedor *desenvolvedor;
};

//----------------------------------------------------------------------------------------------------------------------
class TUTeste : public TUEntidades {
   private:
    const static string VALOR_VALIDO_CODIGO;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_CLASSE;
    void setUp();
    void tearDown();
    void testarValorValido();
    Teste *teste;
};

//----------------------------------------------------------------------------------------------------------------------
class TUCasoDeTeste : public TUEntidades {
   private:
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_DATA;
    const static string VALOR_VALIDO_ACAO;
    const static string VALOR_VALIDO_RESPOSTA;
    const static string VALOR_VALIDO_RESULTADO;
    void setUp();
    void tearDown();
    void testarValorValido();
    CasoDeTeste *casoDeTeste;
};

#endif  // TESTES_ENTIDADES_H_INCLUDED