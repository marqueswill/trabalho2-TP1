#include <iostream>
#include "../headers/controladoras.h"
#include "../headers/dominios.h"
#include "../headers/entidades.h"
#include <string>
using namespace std;

cntrlIADesenvolvedor::cntrlIADesenvolvedor(){

}

void cntrlIADesenvolvedor::Cadastrar(){
char texto1[] = "Por favor, preencha os espaços com os seus dados:";
char texto2[] = "Nome       :";
char texto3[] = "Matricula  :";
char texto4[] = "Telefone   :";
char texto5[] = "Senha      :";
char texto6[] = "O formato dos dados é inválido. Tecle algo.";
char texto7[] = "O cadastramento foi executado com sucesso. Tecle algo.";
char texto8[] = "O cadastramento falhou. Tecle algo";
char campo1[50], campo2[50], campo3[50];
char campo4[50], campo5[50], campo6[50];
char campo7[50], campo8[50];

Texto nome;
Matricula matricula;
Telefone telefone;
Senha senha;

//CLR_SCR;

cout << texto1 << endl;
cout << texto2 << " ";
cin.getline(campo1, sizeof(campo1));

cout << "Valor lido" << campo1 << " ";

cout << texto3 << " ";
cin >> campo2;
cout << texto4 << " ";
cin >> campo3;
cout << texto5 << " ";
cin >> campo4;
cout << texto6 << " ";
cin >> campo5;

try{
    nome.setValor(string(campo1));
    matricula.setValor(string(campo2));
    telefone.setValor(string(campo3));
    senha.setValor(string(campo4));
}
catch(invalid_argument &exp){
    cout << texto6 << endl;
    getchar();
    return;
}

Desenvolvedor desenvolvedor;
desenvolvedor.setNome(nome);
desenvolvedor.setMatricula(matricula);
desenvolvedor.setTelefone(telefone);
desenvolvedor.setSenha(senha);


}

void cntrlIADesenvolvedor::Executar(Matricula){

}

cntrlISDesenvolvedor::cntrlISDesenvolvedor(){

}

bool cntrlISDesenvolvedor::Cadastrar(Desenvolvedor){

}
bool cntrlISDesenvolvedor::Visualizar(Desenvolvedor *){

}

bool cntrlISDesenvolvedor::Editar(Desenvolvedor){

}
