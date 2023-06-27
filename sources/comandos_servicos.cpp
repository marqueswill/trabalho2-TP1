#include "../headers/comandos_servicos.h"

//----------------------------------------------------------------------------------------------------------------------
list<ElementoResultado> ComandoSQL::listaResultado;

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerSenha::ComandoSQLLerSenha(Matricula matricula) {
    comandoSQL = "SELECT senha FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

string ComandoSQLLerSenha::getResultado() {
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

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerMatricula::ComandoSQLLerMatricula(Matricula matricula) {
    comandoSQL = "SELECT matricula FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

string ComandoSQLLerMatricula::getResultado() {
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

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerCodigoTeste::ComandoSQLLerCodigoTeste(Codigo codigo) {
    comandoSQL = "SELECT codigo FROM testes WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

string ComandoSQLLerCodigoTeste::getResultado() {
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

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerCodigoCasoDeTeste::ComandoSQLLerCodigoCasoDeTeste(Codigo codigo) {
    //comandoSQL = "SELECT codigotestes FROM casodetestes WHERE codigo = ";
    comandoSQL = "SELECT codigo FROM casodetestes WHERE codigotestes = ";
    comandoSQL += codigo.getValor();
}

string ComandoSQLLerCodigoCasoDeTeste::getResultado() {
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

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLVisualizarDesenvolvedor::ComandoSQLVisualizarDesenvolvedor(Matricula matricula) {
    comandoSQL = "SELECT * FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

Desenvolvedor ComandoSQLVisualizarDesenvolvedor::getResultado() {
    ElementoResultado resultado;
    Desenvolvedor desenvolvedor;

    for (int i = 0; i < 4; i++) {
        if (listaResultado.empty()) {
            throw EErroPersistencia("Lista de resultados vazia.");
        }

        resultado = listaResultado.back();  // obtem último elemento
        listaResultado.pop_back();          // retira ele da lista

        switch (i) {
            case 3:
                desenvolvedor.setNome(Texto(resultado.getValorColuna()));
                break;
            case 2:
                desenvolvedor.setMatricula(Matricula(resultado.getValorColuna()));
                break;
            case 1:
                desenvolvedor.setSenha(Senha(resultado.getValorColuna()));
                break;
            case 0:
                desenvolvedor.setTelefone(Telefone(resultado.getValorColuna()));
                break;
        }
    }

    return desenvolvedor;
}

ComandoSQLCadastrarDesenvolvedor::ComandoSQLCadastrarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comandoSQL = "INSERT INTO desenvolvedores(nome,matricula,senha,telefone) VALUES (";
    comandoSQL += "'" + desenvolvedor.getNome().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getMatricula().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getSenha().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getTelefone().getValor() + "', ";
    comandoSQL += ")";
}

ComandoSQLEditarDesenvolvedor::ComandoSQLEditarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comandoSQL = "UPDATE desenvolvedores ";
    comandoSQL += "SET nome = '" + desenvolvedor.getNome().getValor();
    comandoSQL += "', senha = '" + desenvolvedor.getSenha().getValor();
    comandoSQL += "', telefone = '" + desenvolvedor.getTelefone().getValor();
    comandoSQL += "' WHERE matricula = " + desenvolvedor.getMatricula().getValor();
}

ComandoSQLDescadastrarDesenvolvedor::ComandoSQLDescadastrarDesenvolvedor(Matricula matricula) {
    comandoSQL = "DELETE FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLVisualizarTeste::ComandoSQLVisualizarTeste(Codigo codigo) {
    comandoSQL = "SELECT * from testes INNER JOIN desenvolvedores on testes.matricula = desenvolvedores.matricula WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

Teste ComandoSQLVisualizarTeste::getResultado() {
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    ElementoResultado resultado;
    Teste teste;

    for (int i = 0; i < 3; i++) {
        resultado = listaResultado.back();  // obtem último elemento
        listaResultado.pop_back();          // retira ele da lista

        switch (i) {
            case 2:
                teste.setNome(Texto(resultado.getValorColuna()));
                break;
            case 1:
                teste.setCodigo(Codigo(resultado.getValorColuna()));
                break;
            case 0:
                teste.setClasse(Classe(resultado.getValorColuna()));
                break;
        }
    }

    return teste;
}

ComandoSQLCadastrarTeste::ComandoSQLCadastrarTeste(Teste teste) {
    comandoSQL = "INSERT INTO testes(nome,codigo,classe) VALUES (";
    comandoSQL += "'" + teste.getNome().getValor() + "', ";
    comandoSQL += "'" + teste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + teste.getClasse().getValor() + "', ";
    comandoSQL += ")";
}

ComandoSQLEditarTeste::ComandoSQLEditarTeste(Teste teste) {
    comandoSQL = "UPDATE testes ";
    comandoSQL += "SET nome = '" + teste.getNome().getValor();
    comandoSQL += "', classe = '" + teste.getClasse().getValor();
    comandoSQL += "' WHERE codigo = " + teste.getCodigo().getValor();
}

ComandoSQLDescadastrarTeste::ComandoSQLDescadastrarTeste(Codigo codigo) {
    comandoSQL += "DELETE FROM casodetestes WHERE codigotestes = ";
    comandoSQL += codigo.getValor();
    comandoSQL = "DELETE FROM testes WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLVisualizarCasoDeTeste::ComandoSQLVisualizarCasoDeTeste(Codigo codigo) {
    comandoSQL = "SELECT * from casodetestes INNER JOIN testes on casodetestes.codigo = testes.codigo  WHERE codigotestes = ";
    comandoSQL += codigo.getValor();
}

CasoDeTeste ComandoSQLVisualizarCasoDeTeste::getResultado() {
    if (listaResultado.empty()) {
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    ElementoResultado resultado;
    CasoDeTeste casoDeTeste;

    for (int i = 0; i < 3; i++) {
        resultado = listaResultado.back();  // obtem último elemento
        listaResultado.pop_back();          // retira ele da lista

        switch (i) {
            case 5:
                casoDeTeste.setNome(Texto(resultado.getValorColuna()));
                break;
            case 4:
                casoDeTeste.setCodigo(Codigo(resultado.getValorColuna()));
                break;
            case 3:
                casoDeTeste.setData(Data(resultado.getValorColuna()));
                break;
            case 2:
                casoDeTeste.setAcao(Texto(resultado.getValorColuna()));
                break;
            case 1:
                casoDeTeste.setResposta(Texto(resultado.getValorColuna()));
                break;
            case 0:
                casoDeTeste.setResultado(Resultado(resultado.getValorColuna()));
                break;
        }

        return casoDeTeste;
    }
}

ComandoSQLCadastrarCasoDeTeste::ComandoSQLCadastrarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "INSERT INTO casodetestes(nome,codigo,data,acao,resposta,resultado) VALUES (";
    comandoSQL += "'" + casoDeTeste.getNome().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getData().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getAcao().getValor();
    comandoSQL += "'" + casoDeTeste.getResposta().getValor();
    comandoSQL += "'" + casoDeTeste.getResultado().getValor();
    comandoSQL += ")";
}

ComandoSQLEditarCasoDeTeste::ComandoSQLEditarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "UPDATE casodetestes ";
    comandoSQL += "SET nome = '" + casoDeTeste.getNome().getValor();
    comandoSQL += "', senha = '" + casoDeTeste.getData().getValor();
    comandoSQL += "', telefone = '" + casoDeTeste.getData().getValor();
    comandoSQL += "', acao = '" + casoDeTeste.getAcao().getValor();
    comandoSQL += "', resposta = '" + casoDeTeste.getResposta().getValor();
    comandoSQL += "', resultado = '" + casoDeTeste.getResultado().getValor();
    comandoSQL += "' WHERE codigotestes = " + casoDeTeste.getCodigo().getValor();
}

ComandoSQLDescadastrarCasoDeTeste::ComandoSQLDescadastrarCasoDeTeste(Codigo codigo) {
    comandoSQL = "DELETE FROM casodetestes WHERE codigotestes = ";
    comandoSQL += codigo.getValor();
}