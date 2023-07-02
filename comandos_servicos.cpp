#include "comandos_servicos.h"
#include <iostream>
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
    comandoSQL = "SELECT senha FROM desenvolvedores WHERE matricula = '";
    comandoSQL += matricula.getValor();
    comandoSQL += "'";
}

string ComandoSQLLerSenha::getResultado() {
    ElementoResultado resultado;
    string senha;
    if (listaResultado.empty()){
        return "NULL";
    }

    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();
    listaResultado.clear();
    return senha;
}

ComandoSQLAutenticarTeste::ComandoSQLAutenticarTeste(Matricula matricula){
    comandoSQL = "SELECT codigo FROM testes WHERE matricula = '";
    comandoSQL += matricula.getValor();
    comandoSQL += "'";
}
list <string> ComandoSQLAutenticarTeste::getResultado() {
    ElementoResultado resultado;
    list <string> lista;
    if (listaResultado.empty()){
        return lista;
    }

    while(!listaResultado.empty()){
        resultado = listaResultado.back();
        listaResultado.pop_back();
        lista.push_back(resultado.getValorColuna());
    }
    listaResultado.clear();
    return lista;
}


ComandoSQLAutenticarCasoDeTeste::ComandoSQLAutenticarCasoDeTeste(Codigo codigotestes){
    comandoSQL = "SELECT codigo FROM casodetestes WHERE codigotestes = '";
    comandoSQL += codigotestes.getValor();
    comandoSQL += "'";
}

ComandoSQLAutenticarCasoDeTeste::ComandoSQLAutenticarCasoDeTeste(Matricula matricula){
    comandoSQL = "SELECT codigo FROM casodetestes WHERE matricula = '";
    comandoSQL += matricula.getValor();
    comandoSQL += "'";
}
list <string> ComandoSQLAutenticarCasoDeTeste::getResultado() {
    ElementoResultado resultado;
    list <string> lista;
    if (listaResultado.empty()){
        return lista;
    }

    while(!listaResultado.empty()){
        resultado = listaResultado.back();
        listaResultado.pop_back();
        lista.push_back(resultado.getValorColuna());
    }
    listaResultado.clear();
    return lista;
}


//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerMatricula::ComandoSQLLerMatricula(Matricula matricula) {
    comandoSQL = "SELECT matricula FROM desenvolvedores WHERE matricula = '";
    comandoSQL += matricula.getValor();
    comandoSQL += "'";
}

string ComandoSQLLerMatricula::getResultado() {
    ElementoResultado resultado;
    string matricula;

    if (listaResultado.empty()){
        return "NULL";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    matricula = resultado.getValorColuna();
    listaResultado.clear();
    return matricula;
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerCodigoTeste::ComandoSQLLerCodigoTeste(Codigo codigo) {
    comandoSQL = "SELECT codigo FROM testes WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}

string ComandoSQLLerCodigoTeste::getResultado() {
    ElementoResultado resultado;
    string codigo;

    if (listaResultado.empty())
        return "NULL";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo = resultado.getValorColuna();
    listaResultado.clear();
    return codigo;
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLLerCodigoCasoDeTeste::ComandoSQLLerCodigoCasoDeTeste(Codigo codigo) {
    comandoSQL = "SELECT codigo FROM casodetestes WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}

string ComandoSQLLerCodigoCasoDeTeste::getResultado() {
    ElementoResultado resultado;
    string codigo;

    if (listaResultado.empty())
        return "NULL";
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo = resultado.getValorColuna();
    listaResultado.clear();
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
    listaResultado.clear();
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

}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLContarCasoDeTeste::ComandoSQLContarCasoDeTeste(Matricula matricula){
    comandoSQL = "SELECT COUNT(codigo) from casodetestes where matricula = '";
    comandoSQL += matricula.getValor();
    comandoSQL += "'";
}
//-----------------------------------------------------------------------------------------------------------------------


ComandoSQLContarTeste::ComandoSQLContarTeste(Matricula matricula){
    comandoSQL = "SELECT COUNT(codigo) from testes where matricula = '";
    comandoSQL += matricula.getValor();
    comandoSQL += "'";
}
int ComandoSQLContarTeste::getResultado(){
    if (listaResultado.empty()) {
        return 0;
    }

    ElementoResultado resultado;
    resultado = listaResultado.back();
    listaResultado.pop_back();
    string v = resultado.getValorColuna();
    int valor = stoi(v);
    listaResultado.clear();
    return valor;
}
ComandoSQLListarTeste::ComandoSQLListarTeste(Codigo codigo){
    comandoSQL = "SELECT codigo from testes where matricula = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}
list <Codigo> ComandoSQLListarTeste::getResultado(){
    list <Codigo> testes;
    Codigo codigo;
    if (listaResultado.empty()) {
        return testes;
    }

    ElementoResultado resultado;
    for(int i = 0; i <10; i++){
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo.setValor(resultado.getValorColuna());
    testes.push_back(codigo);
    }
    listaResultado.clear();
    return testes;

    }
ComandoSQLListarCasoDeTeste::ComandoSQLListarCasoDeTeste(Codigo codigo){
    comandoSQL = "SELECT codigo from casodetestes where codigotestes = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}
list <Codigo> ComandoSQLListarCasoDeTeste::getResultado(){
    list <Codigo> casosdeteste;
    Codigo codigo;
    if (listaResultado.empty()) {
        return casosdeteste;
    }

    ElementoResultado resultado;
    for(int i = 0; i <10; i++){
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo.setValor(resultado.getValorColuna());
    casosdeteste.push_back(codigo);
    }
    listaResultado.clear();
    return casosdeteste;

    }


ComandoSQLContarCasoDeTeste::ComandoSQLContarCasoDeTeste(Codigo codigo){
    comandoSQL = "SELECT COUNT(codigo) from casodetestes where codigotestes = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}
//-----------------------------------------------------------------------------------------------------------------------
int ComandoSQLContarCasoDeTeste::getResultado(){
    if (listaResultado.empty()) {
       return 0;
    }

    ElementoResultado resultado;
    resultado = listaResultado.back();
    listaResultado.pop_back();
    string v = resultado.getValorColuna();
    int valor = stoi(v);
    listaResultado.clear();
    return valor;
}
//----------------------------------------------------------------------------------------------------------------------
ComandoSQLVisualizarTeste::ComandoSQLVisualizarTeste(Codigo codigo) {
    comandoSQL = "SELECT * from testes WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
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
    listaResultado.clear();
    return teste;
}

ComandoSQLCadastrarTeste::ComandoSQLCadastrarTeste(Teste teste) {
    comandoSQL = "INSERT INTO testes(nome,codigo,classe, matricula) VALUES (";
    comandoSQL += "'" + teste.getNome().getValor() + "', ";
    comandoSQL += "'" + teste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + teste.getClasse().getValor() + "', ";
    comandoSQL += "'" + teste.getMatricula().getValor() + "'";
    comandoSQL += ")";
}

ComandoSQLEditarTeste::ComandoSQLEditarTeste(Teste teste) {
    comandoSQL = "UPDATE testes ";
    comandoSQL += "SET nome = '" + teste.getNome().getValor();
    comandoSQL += "', classe = '" + teste.getClasse().getValor();
    comandoSQL += "' WHERE codigo = '" + teste.getCodigo().getValor();
    comandoSQL += "'";
}

ComandoSQLDescadastrarTeste::ComandoSQLDescadastrarTeste(Codigo codigo) {
    comandoSQL = "DELETE FROM testes WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}

//----------------------------------------------------------------------------------------------------------------------
ComandoSQLVisualizarCasoDeTeste::ComandoSQLVisualizarCasoDeTeste(Codigo codigo) {
    comandoSQL = "SELECT * from casodetestes WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
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
    Codigo codigotestes;
    Matricula matricula;
    for (int i = 0; i < 7; i++) {
        resultado = listaResultado.back();  // obtem último elemento
        listaResultado.pop_back();          // retira ele da lista
        switch (i) {
            case 7:
                matricula.setValor(resultado.getValorColuna());
                break;
            case 6:
                codigotestes.setValor(resultado.getValorColuna());
                break;
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
    }
        casoDeTeste.setAcao(acao);
        casoDeTeste.setCodigo(codigo);
        casoDeTeste.setData(data);
        casoDeTeste.setNome(nome);
        casoDeTeste.setResposta(resposta);
        casoDeTeste.setResultado(resultados);
        casoDeTeste.setCodigoTestes(codigotestes);
        casoDeTeste.setMatricula(matricula);
        listaResultado.clear();
        return casoDeTeste;

}

ComandoSQLCadastrarCasoDeTeste::ComandoSQLCadastrarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "INSERT INTO casodetestes(nome,codigo,data,acao,resposta,resultado, codigotestes, matricula) VALUES (";
    comandoSQL += "'" + casoDeTeste.getNome().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getData().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getAcao().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getResposta().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getResultado().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getCodigoTestes().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getMatricula().getValor() + "'";
    comandoSQL += ")";
}

ComandoSQLEditarCasoDeTeste::ComandoSQLEditarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "UPDATE casodetestes ";
    comandoSQL += "SET nome = '" + casoDeTeste.getNome().getValor();
    comandoSQL += "', data = '" + casoDeTeste.getData().getValor();
    comandoSQL += "', acao = '" + casoDeTeste.getAcao().getValor();
    comandoSQL += "', resposta = '" + casoDeTeste.getResposta().getValor();
    comandoSQL += "', resultado = '" + casoDeTeste.getResultado().getValor();
    comandoSQL += "' WHERE codigo = '" + casoDeTeste.getCodigo().getValor();
    comandoSQL += "'";
}

ComandoSQLDescadastrarCasoDeTeste::ComandoSQLDescadastrarCasoDeTeste(Codigo codigo) {
    comandoSQL = "DELETE FROM casodetestes WHERE codigo = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}
ComandoSQLDeletarCasoDeTeste::ComandoSQLDeletarCasoDeTeste(Codigo codigo){
    comandoSQL = "DELETE FROM casodetestes WHERE codigotestes = '";
    comandoSQL += codigo.getValor();
    comandoSQL += "'";
}
ComandoSQLDeletarTeste::ComandoSQLDeletarTeste(Matricula matricula){
    comandoSQL = "DELETE FROM testes WHERE matricula = '";
    comandoSQL += matricula.getValor();
    comandoSQL += "'";
}
ComandoSQLDeletarCasoDeTeste::ComandoSQLDeletarCasoDeTeste(Matricula matricula){
    comandoSQL = "DELETE FROM casodetestes WHERE matricula = '";
    comandoSQL += matricula.getValor();
    comandoSQL += "'";
}

