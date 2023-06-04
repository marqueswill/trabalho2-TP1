#include "../headers/comandos.h"
void Comandos_Desenvolvedor::Cadastrar_Desenvolvedor(Desenvolvedor *obj, string n, string m, string t, string s){   
    matricula.setValor(m);
    nome.setValor(n);
    telefone.setValor(t);
    senha.setValor(s);
    obj->setNome(nome);
    obj->setMatricula(matricula);
    obj->setSenha(senha);
    obj->setTelefone(telefone);
}