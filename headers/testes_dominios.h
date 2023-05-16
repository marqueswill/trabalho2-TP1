#ifndef TESTES_DOMINIOS_H_INCLUDED
#define TESTES_DOMINIOS_H_INCLUDED

#include <iomanip>
#include <iostream>
#include <string>

#include "dominios.h"

using namespace std;

//---------------------------------------------------------------------
class TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

   protected:
    bool estado;

    Dominios *dominios;

    virtual void setUp() = 0;
    virtual void tearDown() = 0;
    virtual void testarValorValido() = 0;
    virtual void testarValorInvalido() = 0;

   public:
    const static bool SUCESSO = true;
    const static bool FALHA = false;
    bool run();
    void showResult(bool, string);
};

inline bool TUDominios::run() {
    setUp();
    testarValorValido();
    testarValorInvalido();
    tearDown();
    return estado;
}

inline void TUDominios::showResult(bool result, string nome_dominio) {
    string resultado = result ? "\033[32mSUCESSO\033[0m" : "\033[31mFALHA\033[0m";
    cout << setw(16) << left << setfill('.') << nome_dominio << resultado << endl;
}

//---------------------------------------------------------------------
// Teste Unitário  Classe
class TUClasse : public TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Classe *classe;

    void setUp();
    void tearDown();
    void testarValorValido();
    void testarValorInvalido();
};

//---------------------------------------------------------------------
// Teste Unitário Codigo - 221006351
class TUCodigo : public TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Codigo *codigo;

    void setUp();
    void tearDown();
    void testarValorValido();
    void testarValorInvalido();
};

//---------------------------------------------------------------------
// Teste Unitário Data
class TUData : public TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Data *data;

    void setUp();
    void tearDown();
    void testarValorValido();
    void testarValorInvalido();
};

//---------------------------------------------------------------------
// Teste Unitário Matricula
class TUMatricula : public TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Matricula *matricula;

    void setUp();
    void tearDown();
    void testarValorValido();
    void testarValorInvalido();
};

//---------------------------------------------------------------------
// Teste Unitário  Resultado
class TUResultado : public TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Resultado *resultado;

    void setUp();
    void tearDown();
    void testarValorValido();
    void testarValorInvalido();
};

//---------------------------------------------------------------------
// Teste Unitário Senha
class TUSenha : public TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Senha *senha;

    void setUp();
    void tearDown();
    void testarValorValido();
    void testarValorInvalido();
};

//---------------------------------------------------------------------};
// Teste Unitário Telefone
class TUTelefone : public TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Telefone *telefone;

    void setUp();
    void tearDown();
    void testarValorValido();
    void testarValorInvalido();
};

//---------------------------------------------------------------------
// Teste Unitário  Texto
class TUTexto : public TUDominios {
   private:
    const static string VALOR_VALIDO;
    const static string VALOR_INVALIDO;

    Texto *texto;

    void setUp();
    void tearDown();
    void testarValorValido();
    void testarValorInvalido();
};

#endif  // TESTES_DOMINIOS_H_INCLUDED
