//---------------------------------------------------------------------------
// Incluir cabe�alhos.

#include "../headers/UnidadePersistencia.h"

// Atributo est�tico.

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ErroPersistencia.

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia::what() {
        return mensagem;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoSQL.

void ComandoSQL::conectar() {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar() {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                sqlite3_free(mensagem);
                desconectar();
                throw EErroPersistencia("Erro na execucao do comando SQL");
        }
        desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoLerSenha.

ComandoLerMatricula::ComandoLerMatricula(Matricula matricula) {
        comandoSQL = "SELECT matricula FROM desenvolvedores WHERE matricula = ";
        comandoSQL += matricula.getValor();
}

string ComandoLerMatricula::getResultado() {
        ElementoResultado resultado;
        string senha;

        //Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha = resultado.getValorColuna();

        return senha;
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoPesquisarAluno.

ComandoVisualizarDesenvolvedor::ComandoVisualizarDesenvolvedor(Matricula matricula) {
        comandoSQL = "SELECT * FROM desenvolvedores WHERE matricula = ";
        comandoSQL += matricula.getValor();
}

Desenvolvedor ComandoVisualizarDesenvolvedor::getResultado() {
        ElementoResultado resultado;
        Desenvolvedor desenvolvedor;
        Texto texto;
        Matricula matricula;
        Senha senha;
        Telefone telefone;

        // Remover nome;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        texto.setValor(resultado.getValorColuna());
        desenvolvedor.setNome(texto);

        // Remover matricula;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        matricula.setValor(resultado.getValorColuna());
        desenvolvedor.setMatricula(matricula);

        // Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha.setValor(resultado.getValorColuna());
        desenvolvedor.setSenha(senha);

        // Remover telefone;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        telefone.setValor(resultado.getValorColuna());
        desenvolvedor.setTelefone(&telefone);

        return desenvolvedor;

}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoCadastrarAluno.

ComandoCadastrarDesenvolvedor::ComandoCadastrarDesenvolvedor(Desenvolvedor dev) {
        comandoSQL = "INSERT INTO desenvolvedores VALUES (";
        comandoSQL += "'" + dev.getNome().getValor() + "', ";
        comandoSQL += "'" + dev.getMatricula().getValor() + "', ";
        comandoSQL += "'" + dev.getSenha().getValor() + "', ";
        comandoSQL += "'" + dev.getTelefone().getValor() + "', ";
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoRemoverAluno.

ComandoDescadastrarDesenvolvedor::ComandoDescadastrarDesenvolvedor(Matricula matricula) {
        comandoSQL = "DELETE FROM desenvolvedores WHERE matricula = ";
        comandoSQL += matricula.getValor();
}

//---------------------------------------------------------------------------
// Implementa��es de m�todos da classe ComandoEditarAluno.

ComandoEditarDesenvolvedor::ComandoEditarDesenvolvedor(Desenvolvedor dev) {
        comandoSQL = "UPDATE desenvolvedores ";
        comandoSQL += "SET nome = '" + dev.getNome().getValor();
        comandoSQL += "', senha = '" + dev.getSenha().getValor();
        comandoSQL += "', telefone = '" + dev.getTelefone().getValor();
        comandoSQL += "' WHERE matricula = " + dev.getMatricula().getValor();
}


