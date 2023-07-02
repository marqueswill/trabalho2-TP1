#ifndef TESTES_DOMINIOS_H_INCLUDED
#define TESTES_DOMINIOS_H_INCLUDED

#include "dominios.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
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
};

inline bool TUDominios::run() {
    setUp();
    testarValorValido();
    testarValorInvalido();
    tearDown();
    return estado;
}

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------};
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

//----------------------------------------------------------------------------------------------------------------------
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
