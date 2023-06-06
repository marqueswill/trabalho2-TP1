#include <locale.h>

#include <iomanip>
#include <iostream>

#include "../headers/dominios.h"
#include "../headers/entidades.h"
#include "../headers/testes_dominios.h"
#include "../headers/testes_entidades.h"
#include "dominios.cpp"
#include "entidades.cpp"
#include "testes_dominios.cpp"
#include "testes_entidades.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    cout << "DOMINIOS" << endl;
    TUClasse teste_classe;

    TUCodigo teste_codigo;

    TUData teste_data;

    TUMatricula teste_matricula;

    TUResultado teste_resultado;

    TUSenha teste_senha;

    TUTelefone teste_telefone;

    TUTexto teste_texto;

    cout << "\nENTIDADES" << endl;
    TUDesenvolvedor teste_desenvolvedor;

    TUTeste teste_teste;

    TUCasoDeTeste teste_casodeteste;

    return 0;
}
