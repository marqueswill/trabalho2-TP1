#include "../headers/testes_dominios.h"

using namespace std;

//---------------------------------------------------------------------
// IMPLEMENTAÇÃO DO TESTE DE CLASSE - 221006389

const string TUClasse::VALOR_VALIDO = "FUMACA";
const string TUClasse::VALOR_INVALIDO = "fumaca";

void TUClasse::setUp() {
    classe = new Classe();
    estado = SUCESSO;
}

void TUClasse::tearDown() {
    delete classe;
}

void TUClasse::testarValorValido() {
    try {
        classe->setValor(VALOR_VALIDO);
        if (classe->getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUClasse::testarValorInvalido() {
    try {
        classe->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument &excecao) {
        if (classe->getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

//---------------------------------------------------------------------
// IMPLEMENTAÇÃO DO TESTE DO CÓDIGO - 221006351

const string TUCodigo::VALOR_VALIDO = "UnB231";
const string TUCodigo::VALOR_INVALIDO = "123ABC";

void TUCodigo::setUp() {
    codigo = new Codigo();
    estado = SUCESSO;
}
void TUCodigo::tearDown() {
    delete codigo;
}

void TUCodigo::testarValorValido() {
    try {
        codigo->setValor(VALOR_VALIDO);
        if (codigo->getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUCodigo::testarValorInvalido() {
    try {
        codigo->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument &excecao) {
        if (codigo->getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

//---------------------------------------------------------------------
// IMPLEMENTAÇÃO DO TESTE DO DATA - 221020940

const string TUData::VALOR_VALIDO = "29/FEV/2020";
const string TUData::VALOR_INVALIDO = "29/FEV/2021";

void TUData::setUp() {
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown() {
    delete data;
}

void TUData::testarValorValido() {
    try {
        data->setValor(VALOR_VALIDO);
        if (data->getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUData::testarValorInvalido() {
    try {
        data->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument &excecao) {
        if (data->getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

//---------------------------------------------------------------------
// IMPLEMENTAÇÃO DO TESTE DA MATRÍCULA - 221006351

const string TUMatricula::VALOR_VALIDO = "1234567";
const string TUMatricula::VALOR_INVALIDO = "1234568";

void TUMatricula::setUp() {
    matricula = new Matricula();
    estado = SUCESSO;
}

void TUMatricula::tearDown() {
    delete matricula;
}

void TUMatricula::testarValorValido() {
    try {
        matricula->setValor(VALOR_VALIDO);
        if (matricula->getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUMatricula::testarValorInvalido() {
    try {
        matricula->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument &excecao) {
        if (matricula->getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

//---------------------------------------------------------------------
// IMPLEMENTAÇÃO DO TESTE DE RESULTADO - 221006389

const string TUResultado::VALOR_VALIDO = "APROVADO";
const string TUResultado::VALOR_INVALIDO = "aprovado";

void TUResultado::setUp() {
    resultado = new Resultado();
    estado = SUCESSO;
}

void TUResultado::tearDown() {
    delete resultado;
}

void TUResultado::testarValorValido() {
    try {
        resultado->setValor(VALOR_VALIDO);
        if (resultado->getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUResultado::testarValorInvalido() {
    try {
        resultado->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument &excecao) {
        if (resultado->getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

//---------------------------------------------------------------------
// IMPLEMENTAÇÃO DO TESTE DA SENHA - 221020940

const string TUSenha::VALOR_VALIDO = "w1Ly4n";
const string TUSenha::VALOR_INVALIDO = "minhasenha123";

void TUSenha::setUp() {
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown() {
    delete senha;
}

void TUSenha::testarValorValido() {
    try {
        senha->setValor(VALOR_VALIDO);
        if (senha->getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUSenha::testarValorInvalido() {
    try {
        senha->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument &excecao) {
        if (senha->getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

//---------------------------------------------------------------------
// IMPLEMENTAÇÃO DO TESTE DO TELEFONE - 221020940

const string TUTelefone::VALOR_VALIDO = "+123456789012345";
const string TUTelefone::VALOR_INVALIDO = "1234567";

void TUTelefone::setUp() {
    telefone = new Telefone();
    estado = SUCESSO;
}

void TUTelefone::tearDown() {
    delete telefone;
}

void TUTelefone::testarValorValido() {
    try {
        telefone->setValor(VALOR_VALIDO);
        if (telefone->getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUTelefone::testarValorInvalido() {
    try {
        telefone->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument &excecao) {
        if (telefone->getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}

//---------------------------------------------------------------------
// IMPLEMENTAÇÃO DO TESTE DE TEXTO - 221020940

const string TUTexto::VALOR_VALIDO = "TP1 - JLW 2023";
const string TUTexto::VALOR_INVALIDO = "abc123";

void TUTexto::setUp() {
    texto = new Texto();
    estado = SUCESSO;
}

void TUTexto::tearDown() {
    delete texto;
}

void TUTexto::testarValorValido() {
    try {
        texto->setValor(VALOR_VALIDO);
        if (texto->getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &excecao) {
        estado = FALHA;
    }
}

void TUTexto::testarValorInvalido() {
    try {
        texto->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (invalid_argument &excecao) {
        if (texto->getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}