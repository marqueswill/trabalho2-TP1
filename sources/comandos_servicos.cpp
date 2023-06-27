#include "../headers/comandos_servicos.h"

#include "database.db"
#include "database.db.sql"
//---------------------------------------------------------------------------
list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
ComandoISLerSenha::ComandoISLerSenha(Matricula matricula) {
    comandoSQL = "SELECT senha FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

string ComandoISLerSenha::getResultado() {
    ElementoResultado resultado;
    string senha;

    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();

    return senha;
}

//---------------------------------------------------------------------------
ComandoISLerMatricula::ComandoISLerMatricula(Matricula matricula) {
    comandoSQL = "SELECT matricula FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

string ComandoISLerMatricula::getResultado() {
    ElementoResultado resultado;
    string matricula;

    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia.");
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    matricula = resultado.getValorColuna();

    return matricula;
}

//---------------------------------------------------------------------------
ComandoISLerCodigoTeste::ComandoISLerCodigoTeste(Codigo codigo) {
    comandoSQL = "SELECT codigo FROM testes WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

string ComandoISLerCodigoTeste::getResultado() {
    ElementoResultado resultado;
    string codigo;

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    ;
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo = resultado.getValorColuna();

    return codigo;
}

//---------------------------------------------------------------------------
ComandoISLerCodigoCasoDeTeste::ComandoISLerCodigoCasoDeTeste(Codigo codigo) {
    comandoSQL = "SELECT codigo FROM casodetestes WHERE codigo2 = ";
    comandoSQL += codigo.getValor();
}

string ComandoISLerCodigoCasoDeTeste::getResultado() {
    ElementoResultado resultado;
    string codigo;

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    ;
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo = resultado.getValorColuna();

    return codigo;
}

//---------------------------------------------------------------------------
ComandoISVisualizarDesenvolvedor::ComandoISVisualizarDesenvolvedor(Matricula matricula) {
    comandoSQL = "SELECT * FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

Desenvolvedor ComandoISVisualizarDesenvolvedor::getResultado() {
    ElementoResultado resultado;
    Desenvolvedor desenvolvedor;

    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    for (int i = 0; i < 4; i++) {
        resultado = listaResultado.back();  // obtem último elemento
        listaResultado.pop_back();          // retira ele da lista

        switch (i) {
            case 0:
                desenvolvedor.setTelefone(Telefone(resultado.getValorColuna()));
                break;
            case 1:
                desenvolvedor.setSenha(Senha(resultado.getValorColuna()));
                break;
            case 2:
                desenvolvedor.setMatricula(Matricula(resultado.getValorColuna()));
                break;
            case 3:
                desenvolvedor.setNome(Texto(resultado.getValorColuna()));
                break;
        }
    }

    return desenvolvedor;
}

ComandoISCadastrarDesenvolvedor::ComandoISCadastrarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comandoSQL = "INSERT INTO desenvolvedores(nome,matricula,senha,telefone) VALUES (";
    comandoSQL += "'" + desenvolvedor.getNome().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getMatricula().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getSenha().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getTelefone().getValor() + "', ";
    comandoSQL += ")";
}

ComandoISEditarDesenvolvedor::ComandoISEditarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comandoSQL = "UPDATE desenvolvedores ";
    comandoSQL += "SET nome = '" + desenvolvedor.getNome().getValor();
    comandoSQL += "', senha = '" + desenvolvedor.getSenha().getValor();
    comandoSQL += "', telefone = '" + desenvolvedor.getTelefone().getValor();
    comandoSQL += "' WHERE matricula = " + desenvolvedor.getMatricula().getValor();
}

ComandoISDescadastrarDesenvolvedor::ComandoISDescadastrarDesenvolvedor(Matricula matricula) {
    comandoSQL = "DELETE FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

//---------------------------------------------------------------------------
ComandoISVisualizarTeste::ComandoISVisualizarTeste(Codigo codigo) {
    comandoSQL = "SELECT * from testes INNER JOIN desenvolvedores on testes.matricula = desenvolvedores.matricula WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

Codigo ComandoISVisualizarTeste::getResultado() {
    ElementoResultado resultado;
    Teste teste;

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    teste.setNome(Texto(resultado.getValorColuna()));

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    teste.setClasse(Classe(resultado.getValorColuna()));
}

ComandoISCadastrarTeste::ComandoISCadastrarTeste(Teste teste) {
    comandoSQL = "INSERT INTO testes(nome,codigo,classe) VALUES (";
    comandoSQL += "'" + teste.getNome().getValor() + "', ";
    comandoSQL += "'" + teste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + teste.getClasse().getValor() + "', ";
    comandoSQL += ")";
}

ComandoISEditarTeste::ComandoISEditarTeste(Teste teste) {
    comandoSQL = "UPDATE testes ";
    comandoSQL += "SET nome = '" + teste.getNome().getValor();
    comandoSQL += "', classe = '" + teste.getClasse().getValor();
    comandoSQL += "' WHERE codigo = " + teste.getCodigo().getValor();
}

ComandoISDescadastrarTeste::ComandoISDescadastrarTeste(Codigo codigo) {
    comandoSQL += "DELETE FROM casodetestes WHERE codigotestes = ";
    comandoSQL += codigo.getValor();
    comandoSQL = "DELETE FROM testes WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

//---------------------------------------------------------------------------
ComandoISVisualizarCasoDeTeste::ComandoISVisualizarCasoDeTeste(Codigo codigo) {
    comandoSQL = "SELECT * from casodetestes INNER JOIN testes on casodetestes.codigo = testes.codigo  WHERE codigo2 = ";
    comandoSQL += codigo.getValor();
}

Codigo ComandoISVisualizarTeste::getResultado() {
    ElementoResultado resultado;
    CasoDeTeste casoDeTeste;

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setNome(Texto(resultado.getValorColuna()));

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setData(Data(resultado.getValorColuna()));

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setAcao(Texto(resultado.getValorColuna()));

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setResposta(Texto(resultado.getValorColuna()));

    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setResultado(Resultado(resultado.getValorColuna()));
}

ComandoISCadastrarCasoDeTeste::ComandoISCadastrarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "INSERT INTO casodetestes(nome,codigo2,data,acao,resposta,resultado) VALUES (";
    comandoSQL += "'" + casoDeTeste.getNome().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getData().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getAcao().getValor();
    comandoSQL += "'" + casoDeTeste.getResposta().getValor();
    comandoSQL += "'" + casoDeTeste.getResultado().getValor();
    comandoSQL += ")";
}

ComandoISEditarCasoDeTeste::ComandoISEditarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "UPDATE casodetestes ";
    comandoSQL += "SET nome = '" + casoDeTeste.getNome().getValor();
    comandoSQL += "', senha = '" + casoDeTeste.getData().getValor();
    comandoSQL += "', telefone = '" + casoDeTeste.getData().getValor();
    comandoSQL += "', acao = '" + casoDeTeste.getAcao().getValor();
    comandoSQL += "', resposta = '" + casoDeTeste.getResposta().getValor();
    comandoSQL += "', resultado = '" + casoDeTeste.getResultado().getValor();
    comandoSQL += "' WHERE codigo2 = " + casoDeTeste.getCodigo().getValor();
}

ComandoISDescadastrarCasoDeTeste::ComandoISDescadastrarCasoDeTeste(Codigo codigo) {
    comandoSQL = "DELETE FROM casodetestes WHERE codigo2 = ";
    comandoSQL += codigo.getValor();
}