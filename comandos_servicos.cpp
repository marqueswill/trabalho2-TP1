#include "comandos_servicos.h"

EErroPersistencia::EErroPersistencia(string mensagem) {
    this->mensagem = mensagem;
}

 string EErroPersistencia::what() {
    return mensagem;
}

void ElementoResultado::setNomeColuna(const string &nomeColuna) {
    this->nomeColuna = nomeColuna;
}

 void ElementoResultado::setValorColuna(const string &valorColuna) {
    this->valorColuna = valorColuna;
}
void ComandoSQL::conectar() {
    rc = sqlite3_open(nomeBancoDados, &bd);
    if (rc != SQLITE_OK)
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() {
    rc = sqlite3_close(bd);
    if (rc != SQLITE_OK)
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna) {
    NotUsed = 0;
    ElementoResultado elemento;
    int i;
    for (i = 0; i < argc; i++) {
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i] : "NULL");
        listaResultado.push_front(elemento);
    }
    return 0;
}

void ComandoSQL::executar() {
    conectar();
    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if (rc != SQLITE_OK) {
        printf("%s", mensagem);
        printf("%s", comandoSQL.c_str());
        printf("%d", callback);
        getch();
        sqlite3_free(mensagem);
        desconectar();
        throw EErroPersistencia("Erro na execucao do comando SQL");
    }
    desconectar();
}
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
        return "NULL";
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
        return "NULL";
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
        return "NULL";
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
        return "NULL";
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
    Texto nome;
    Matricula matricula;
    Senha senha;
    Telefone telefone;
    for (int i = 0; i < 4; i++) {
        if (listaResultado.empty()) {
            throw EErroPersistencia("Lista de resultados vazia.");
        }

        resultado = listaResultado.back();  // obtem último elemento
        listaResultado.pop_back();          // retira ele da lista

        switch (i) {
            case 3:
                telefone.setValor(resultado.getValorColuna());
                break;
            case 2:
                senha.setValor(resultado.getValorColuna());
                break;
            case 1:
                matricula.setValor(resultado.getValorColuna());
                break;
            case 0:
                nome.setValor(resultado.getValorColuna());
                break;
        }
    }
    desenvolvedor.setNome(nome);
    desenvolvedor.setMatricula(matricula);
    desenvolvedor.setSenha(senha);
    desenvolvedor.setTelefone(telefone);
    return desenvolvedor;
}

ComandoSQLCadastrarDesenvolvedor::ComandoSQLCadastrarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comandoSQL = "INSERT INTO desenvolvedores(nome,matricula,senha,telefone) VALUES (";
    comandoSQL += "'" + desenvolvedor.getNome().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getMatricula().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getSenha().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getTelefone().getValor() + "'";
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
    comandoSQL += "DELETE FROM testes WHERE matricula = ";

}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLContarCasoDeTeste::ComandoSQLContarCasoDeTeste(Codigo codigo){
    comandoSQL = "COUNT from casodetestes where codigo = ";
    comandoSQL += codigo.getValor();
}
int ComandoSQLContarCasoDeTeste::getResultado(){

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
    Texto nome;
    Codigo codigo;
    Classe classe;

    for (int i = 0; i < 3; i++) {
        resultado = listaResultado.back();  // obtem último elemento
        listaResultado.pop_back();          // retira ele da lista

        switch (i) {
            case 2:
                classe.setValor(resultado.getValorColuna());
                break;
            case 1:
                codigo.setValor(resultado.getValorColuna());
                break;
            case 0:
                nome.setValor(resultado.getValorColuna());
                break;
        }
    }
    teste.setClasse(classe);
    teste.setCodigo(codigo);
    teste.setNome(nome);
    return teste;
}

ComandoSQLCadastrarTeste::ComandoSQLCadastrarTeste(Teste teste) {
    comandoSQL = "INSERT INTO testes(nome,codigo,classe) VALUES (";
    comandoSQL += "'" + teste.getNome().getValor() + "', ";
    comandoSQL += "'" + teste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + teste.getClasse().getValor() + "' ";
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
    Texto nome;
    Codigo codigo;
    Data data;
    Texto acao;
    Texto resposta;
    Resultado resultados;
    for (int i = 0; i < 5; i++) {
        resultado = listaResultado.back();  // obtem último elemento
        listaResultado.pop_back();          // retira ele da lista

        switch (i) {
            case 5:
                resultados.setValor(resultado.getValorColuna());
                break;
            case 4:
                resposta.setValor(resultado.getValorColuna());
                break;
            case 3:
                acao.setValor(resultado.getValorColuna());
                break;
            case 2:
                data.setValor(resultado.getValorColuna());
                break;
            case 1:
                codigo.setValor(resultado.getValorColuna());
                break;
            case 0:
                nome.setValor(resultado.getValorColuna());
                break;
        }
        casoDeTeste.setAcao(acao);
        casoDeTeste.setCodigo(codigo);
        casoDeTeste.setData(data);
        casoDeTeste.setNome(nome);
        casoDeTeste.setResposta(resposta);
        casoDeTeste.setResultado(resultados);
        return casoDeTeste;
    }
}

ComandoSQLCadastrarCasoDeTeste::ComandoSQLCadastrarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "INSERT INTO casodetestes(nome,codigo,data,acao,resposta,resultado) VALUES (";
    comandoSQL += "'" + casoDeTeste.getNome().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getData().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getAcao().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getResposta().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getResultado().getValor() + "' ";
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
