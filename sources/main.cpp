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
    teste_classe.showResult(teste_classe.run(), "Classe");

    TUCodigo teste_codigo;
    teste_codigo.showResult(teste_codigo.run(), "Codigo");

    TUData teste_data;
    teste_data.showResult(teste_data.run(), "Data");

    TUMatricula teste_matricula;
    teste_matricula.showResult(teste_matricula.run(), "Matricula");

    TUResultado teste_resultado;
    teste_resultado.showResult(teste_resultado.run(), "Resultado");

    TUSenha teste_senha;
    teste_senha.showResult(teste_senha.run(), "Senha");

    TUTelefone teste_telefone;
    teste_telefone.showResult(teste_telefone.run(), "Telefone");

    TUTexto teste_texto;
    teste_texto.showResult(teste_texto.run(), "Texto");

    cout << "\nENTIDADES" << endl;
    TUDesenvolvedor teste_desenvolvedor;
    teste_desenvolvedor.showResult(teste_desenvolvedor.run(), "Desenvolvedor");

    TUTeste teste_teste;
    teste_teste.showResult(teste_teste.run(), "Teste");

    TUCasoDeTeste teste_casodeteste;
    teste_casodeteste.showResult(teste_casodeteste.run(), "CasoDeTeste");

    return 0;
}
