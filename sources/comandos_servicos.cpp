//---------------------------------------------------------------------------
#include "database.db"
#include "database.db.sql"
#include "../headers/comandos_servicos.h"
// Atributo estatico.

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
// Implementacao para classe EErroPersistencia

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}
string EErroPersistencia::what() {
        return mensagem;
}

//---------------------------------------------------------------------------
// Implmentacao para classe ElementoResultado

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

//---------------------------------------------------------------------------
// Implementacao para classe ComandoSQL


void ComandoSQL::conectar() {
      nomeBancoDados = "database.db";
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() {
    rc = sqlite3_close(bd);
    if (rc != SQLITE_OK)
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar(string comandoSQL) {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                sqlite3_free(mensagem);
                desconectar();
                throw EErroPersistencia("Erro na execucao do comando SQL");
        }
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
    comandoSQL = "SELECT senha FROM desenvolvedores WHERE matricula = ";
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
        // Comandosql = new ComandoSQL();
        // Comandosql->executar(comandoSQL);
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
ComandoLerCodigo::ComandoLerCodigo(Codigo codigo, int escolha) {
    comandoSQL = "SELECT codigo FROM " + tabelas[escolha] + "WHERE codigo = ";
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
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
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
        comandoSQL = "INSERT INTO desenvolvedores(nome,matricula,senha,telefone) VALUES (";
        comandoSQL += "'" + desenvolvedor.getNome().getValor() + "', ";
        comandoSQL += "'" + desenvolvedor.getMatricula().getValor() + "', ";
        comandoSQL += "'" + desenvolvedor.getSenha().getValor() + "', ";
        comandoSQL += "'" + desenvolvedor.getTelefone().getValor() + "', ";
        comandoSQL += ")";
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
}

ComandoDescadastrarDesenvolvedor::ComandoDescadastrarDesenvolvedor(Matricula matricula) {
        comandoSQL += "DELETE FROM testes WHERE matricula = ";
        comandoSQL += matricula.getValor();
        comandoSQL = "DELETE FROM desenvolvedores WHERE matricula = ";
        comandoSQL += matricula.getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
}

ComandoEditarDesenvolvedor::ComandoEditarDesenvolvedor(Desenvolvedor desenvolvedor) {
        comandoSQL = "UPDATE desenvolvedores ";
        comandoSQL += "SET nome = '" + desenvolvedor.getNome().getValor();
        comandoSQL += "', senha = '" + desenvolvedor.getSenha().getValor();
        comandoSQL += "', telefone = '" + desenvolvedor.getTelefone().getValor();
        comandoSQL += "' WHERE matricula = " + desenvolvedor.getMatricula().getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
}
//---------------------------------------------------------------------------
// Implementacao para ComandoLerCodigo
ComandoLerCodigo::ComandoLerCodigo(Codigo codigo){
        comandoSQL = "SELECT codigo FROM testes WHERE codigo = ";
        comandoSQL += codigo.getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
}

string ComandoLerCodigo::getResultado(){
        ElementoResultado resultado;
        string codigo;

        //Remover matricula;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");;
        resultado = listaResultado.back();
        listaResultado.pop_back();
        codigo = resultado.getValorColuna();

        return codigo;
}
//---------------------------------------------------------------------------
// Implementacao para ComandoVisualizarTeste

ComandoVisualizarTeste::ComandoVisualizarTeste(Codigo codigo){
comandoSQL = "SELECT * from testes INNER JOIN desenvolvedores on testes.matricula = desenvolvedores.matricula where codigo = ";
        comandoSQL += codigo.getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);        
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
        comandoSQL = "INSERT INTO testes(nome,codigo,classe) VALUES (";
        comandoSQL += "'" + teste.getNome().getValor() + "', ";
        comandoSQL += "'" + teste.getCodigo().getValor() + "', ";
        comandoSQL += "'" + teste.getClasse().getValor() + "', ";
        comandoSQL += ")";
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
        
}

ComandoEditarTeste::ComandoEditarTeste(Teste teste) {
        comandoSQL = "UPDATE testes ";
        comandoSQL += "SET nome = '" + teste.getNome().getValor();
        comandoSQL += "', classe = '" + teste.getClasse().getValor();
        comandoSQL += "' WHERE codigo = " + teste.getCodigo().getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
}

ComandoDescadastrarTeste::ComandoDescadastrarTeste(Codigo codigo) {
        comandoSQL += "DELETE FROM casodetestes WHERE codigotestes = ";
        comandoSQL += codigo.getValor();
        comandoSQL = "DELETE FROM testes WHERE codigo = ";
        comandoSQL += codigo.getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);

}

//---------------------------------------------------------------------------
// Implementacao para ComandoVisualizarTeste
ComandoVisualizarCasoDeTeste::ComandoVisualizarCasoDeTeste(Codigo codigo){
        comandoSQL = "SELECT * from casodetestes INNER JOIN testes on casodetestes.codigo = testes.codigo  WHERE codigo2 = ";
        comandoSQL += codigo.getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);        
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
        comandoSQL = "INSERT INTO casodetestes(nome,codigo2,data,acao,resposta,resultado) VALUES (";
        comandoSQL += "'" + casoDeTeste.getNome().getValor() + "', ";
        comandoSQL += "'" + casoDeTeste.getCodigo().getValor() + "', ";
        comandoSQL += "'" + casoDeTeste.getData().getValor() + "', ";
        comandoSQL += "'" + casoDeTeste.getAcao().getValor();
        comandoSQL += "'" + casoDeTeste.getResposta().getValor();
        comandoSQL += "'" + casoDeTeste.getResultado().getValor();
        comandoSQL += ")";
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
}

ComandoEditarCasoDeTeste::ComandoEditarCasoDeTeste(CasoDeTeste casoDeTeste) {
        comandoSQL = "UPDATE casodetestes ";
        comandoSQL += "SET nome = '" + casoDeTeste.getNome().getValor();
        comandoSQL += "', senha = '" + casoDeTeste.getData().getValor();
        comandoSQL += "', telefone = '" + casoDeTeste.getData().getValor();
        comandoSQL += "', acao = '" + casoDeTeste.getAcao().getValor();
        comandoSQL += "', resposta = '" + casoDeTeste.getResposta().getValor();
        comandoSQL += "', resultado = '" + casoDeTeste.getResultado().getValor();
        comandoSQL += "' WHERE codigo2 = " + casoDeTeste.getCodigo().getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);

}

ComandoDescadastrarCasoDeTeste::ComandoDescadastrarCasoDeTeste(Codigo codigo) {
        comandoSQL = "DELETE FROM casodetestes WHERE codigo2 = ";
        comandoSQL += codigo.getValor();
        Comandosql = new ComandoSQL();
        Comandosql->executar(comandoSQL);
}

// ComandoListarTeste::ComandoListarTeste(Matricula matricula){
//         Teste teste;
//         comandoSQL = "SELECT codigo FROM r_des_casos_testes WHERE matricula.PK = ";
//         comandoSQL += matricula.getValor();
//         Comandosql = new ComandoSQL();
//         Comandosql-> executar(comandoSQL);       
// }

// vector <Teste> ComandoListarTeste::getLista(){
//         ElementoResultado resultado;
//         Teste teste;
//         vector <Teste> testes;

//         // // Remover nome;
//         // if (listaResultado.empty())
//         //         throw EErroPersistencia("Lista de resultados vazia.");
//         // resultado = listaResultado.back();
//         // listaResultado.pop_back();
//         // teste->setNome.setValor(resultado.getValorColuna());
//         // desenvolvedor.setNome(texto);

//         // // Remover matricula;
//         // if (listaResultado.empty())
//         //         throw EErroPersistencia("Lista de resultados vazia.");
//         // resultado = listaResultado.back();
//         // listaResultado.pop_back();
//         // matricula.setValor(resultado.getValorColuna());
//         // desenvolvedor.setMatricula(matricula);

//         // // Remover senha;
//         // if (listaResultado.empty())
//         //         throw EErroPersistencia("Lista de resultados vazia.");
//         // resultado = listaResultado.back();
//         // listaResultado.pop_back();
//         // senha.setValor(resultado.getValorColuna());
//         // desenvolvedor.setSenha(senha);

//         // // Remover telefone;
//         // if (listaResultado.empty())
//         //         throw EErroPersistencia("Lista de resultados vazia.");
//         // resultado = listaResultado.back();
//         // listaResultado.pop_back();
//         // telefone.setValor(resultado.getValorColuna());
//         // desenvolvedor.setTelefone(telefone);

//         return testes;

// }
