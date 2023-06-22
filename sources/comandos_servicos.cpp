#include "../headers/comandos_servicos.h"

//-------------------------------------------------------------------------------------------------------------
// Atributo estatico.

list<ElementoResultado> ComandoSQL::listaResultado;

//--------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------
ComandoLerSenha::ComandoLerSenha(Matricula matricula) {
    comandoSQL = "SELECT senha FROM alunos WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

string ComandoLerSenha::getResultado() {
    ElementoResultado resultado;
    string senha;

    // Remover senha;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha = resultado.getValorColuna();

    return senha;
}

//--------------------------------------------------------------------------------------------
ComandoLerMatricula::ComandoLerMatricula(Matricula matricula) {
    comandoSQL = "SELECT matricula FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

string ComandoLerMatricula::getResultado() {
    ElementoResultado resultado;
    string matricula;

    // Remover matricula;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    matricula = resultado.getValorColuna();

    return matricula;
}
//--------------------------------------------------------------------------------------------
ComandoLerCodigo::ComandoLerCodigo(Codigo codigo) {
    comandoSQL = "SELECT codigo FROM testes WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

string ComandoLerCodigo::getResultado() {
    ElementoResultado resultado;
    string codigo;

    // Remover matricula;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigo = resultado.getValorColuna();

    return codigo;
}

//--------------------------------------------------------------------------------------------
ComandoVisualizarDesenvolvedor::ComandoVisualizarDesenvolvedor(Matricula matricula) {
    comandoSQL = "SELECT * FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

Desenvolvedor ComandoVisualizarDesenvolvedor::getResultado() {
    ElementoResultado resultado;
    Desenvolvedor desenvolvedor;
    // Remover nome;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    desenvolvedor.setNome(Texto(resultado.getValorColuna()));

    // Remover matricula;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    desenvolvedor.setMatricula(Matricula(resultado.getValorColuna()));

    // Remover senha;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    desenvolvedor.setSenha(Senha(resultado.getValorColuna()));

    // Remover telefone;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    desenvolvedor.setTelefone(Telefone(resultado.getValorColuna()));

    return desenvolvedor;
}

ComandoCadastrarDesenvolvedor::ComandoCadastrarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comandoSQL = "INSERT INTO desenvolvedores VALUES (";
    comandoSQL += "'" + desenvolvedor.getNome().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getMatricula().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getSenha().getValor() + "', ";
    comandoSQL += "'" + desenvolvedor.getTelefone().getValor() + "', ";
}

ComandoDescadastrarDesenvolvedor::ComandoDescadastrarDesenvolvedor(Matricula matricula) {
    comandoSQL = "DELETE FROM desenvolvedores WHERE matricula = ";
    comandoSQL += matricula.getValor();
}

ComandoEditarDesenvolvedor::ComandoEditarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comandoSQL = "UPDATE desenvolvedores ";
    comandoSQL += "SET nome = '" + desenvolvedor.getNome().getValor();
    comandoSQL += "', senha = '" + desenvolvedor.getSenha().getValor();
    comandoSQL += "', telefone = '" + desenvolvedor.getTelefone().getValor();
    comandoSQL += "' WHERE matricula = " + desenvolvedor.getMatricula().getValor();
}

//--------------------------------------------------------------------------------------------
ComandoVisualizarTeste::ComandoVisualizarTeste(Codigo codigo) {
    comandoSQL = "SELECT * from testes where codigo = ";
    comandoSQL += codigo.getValor();
}

Codigo ComandoVisualizarTeste::getResultado() {
    ElementoResultado resultado;
    Teste teste;

    // Remover nome;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    teste.setNome(Texto(resultado.getValorColuna()));

    // Remover classe;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    teste.setClasse(Classe(resultado.getValorColuna()));
}

ComandoCadastrarTeste::ComandoCadastrarTeste(Teste teste) {
    comandoSQL = "INSERT INTO testes VALUES (";
    comandoSQL += "'" + teste.getNome().getValor() + "', ";
    comandoSQL += "'" + teste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + teste.getClasse().getValor() + "', ";
}

ComandoEditarTeste::ComandoEditarTeste(Teste teste) {
    comandoSQL = "UPDATE testes ";
    comandoSQL += "SET nome = '" + teste.getNome().getValor();
    comandoSQL += "', classe = '" + teste.getClasse().getValor();
    comandoSQL += "' WHERE codigo = " + teste.getCodigo().getValor();
}

ComandoDescadastrarTeste::ComandoDescadastrarTeste(Codigo codigo) {
    comandoSQL = "DELETE FROM testes WHERE codigo = ";
    comandoSQL += codigo.getValor();
}

//--------------------------------------------------------------------------------------------
ComandoVisualizarCasoDeTeste::ComandoVisualizarCasoDeTeste(Codigo codigo) {
    comandoSQL = "SELECT * from casodetestes where codigo = ";
    comandoSQL += codigo.getValor();
}

Codigo ComandoVisualizarTeste::getResultado() {
    ElementoResultado resultado;
    CasoDeTeste casoDeTeste;

    // Remover nome;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setNome(Texto(resultado.getValorColuna()));

    // Remover data;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setData(Data(resultado.getValorColuna()));

    // Remover acao;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setAcao(Texto(resultado.getValorColuna()));

    // Remover resposta;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setResposta(Texto(resultado.getValorColuna()));

    // Remover resultado;
    if (listaResultado.empty())
        throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    casoDeTeste.setResultado(Resultado(resultado.getValorColuna()));
}

ComandoCadastrarCasoDeTeste::ComandoCadastrarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "INSERT INTO casodetestes VALUES (";
    comandoSQL += "'" + casoDeTeste.getNome().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getCodigo().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getData().getValor() + "', ";
    comandoSQL += "'" + casoDeTeste.getAcao().getValor();
    comandoSQL += "'" + casoDeTeste.getResposta().getValor();
    comandoSQL += "'" + casoDeTeste.getResultado().getValor();
}

ComandoEditarCasoDeTeste::ComandoEditarCasoDeTeste(CasoDeTeste casoDeTeste) {
    comandoSQL = "UPDATE casodetestes ";
    comandoSQL += "SET nome = '" + casoDeTeste.getNome().getValor();
    comandoSQL += "', senha = '" + casoDeTeste.getData().getValor();
    comandoSQL += "', telefone = '" + casoDeTeste.getData().getValor();
    comandoSQL += "', acao = '" + casoDeTeste.getAcao().getValor();
    comandoSQL += "', resposta = '" + casoDeTeste.getResposta().getValor();
    comandoSQL += "', resultado = '" + casoDeTeste.getResultado().getValor();
    comandoSQL += "' WHERE codigo = " + casoDeTeste.getCodigo().getValor();
}

ComandoDescadastrarCasoDeTeste::ComandoDescadastrarCasoDeTeste(Codigo codigo) {
    comandoSQL = "DELETE FROM casodetestes WHERE codigo = ";
    comandoSQL += codigo.getValor();
}