#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED

#include <iomanip>
#include <iostream>

#include "entidades.h"
using namespace std;

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
    void showResult(bool, string);
};

inline bool TUEntidades::run() {
    setUp();
    testarValorValido();
    tearDown();
    return estado;
}

inline void TUEntidades::showResult(bool result, string nome_dominio) {
    string resultado = result ? "\033[32mSUCESSO\033[0m" : "\033[31mFALHA\033[0m";
    cout << setw(16) << left << setfill('.') << nome_dominio << resultado << endl;
}

//---------------------------------------------------------------------
// Teste Unitário Desenvolvedor

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

//---------------------------------------------------------------------
// Teste Unitário Teste
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
//---------------------------------------------------------------------
// Teste Unitário CasoDeTeste

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
    CasoDeTeste *casodeteste;
};
#endif  // TESTES_ENTIDADES_H_INCLUDED