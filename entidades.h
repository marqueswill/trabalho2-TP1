#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

//----------------------------------------------------------------------------------------------------------------------
class Entidade {
   protected:
    Texto nome;

   public:
    void setNome(const Texto &);
    Texto getNome() const;
};

inline void Entidade::setNome(const Texto &nome) {
    this->nome = nome;
}

inline Texto Entidade::getNome() const {
    return nome;
}

//----------------------------------------------------------------------------------------------------------------------
class Desenvolvedor : public Entidade {
   private:
    Matricula matricula;
    Telefone telefone;
    Senha senha;

   public:
    Desenvolvedor(){};
    Desenvolvedor(Matricula, Texto, Telefone, Senha);

    void setMatricula(const Matricula &);
    Matricula getMatricula() const;
    void setSenha(const Senha &);
    Senha getSenha() const;
    void setTelefone(const Telefone &);
    Telefone getTelefone() const;
};

inline Desenvolvedor::Desenvolvedor(Matricula matricula, Texto nome, Telefone telefone, Senha senha) {
    this->matricula = matricula;
    this->nome = nome;
    this->telefone = telefone;
    this->senha = senha;
}

inline void Desenvolvedor::setMatricula(const Matricula &matricula) {
    this->matricula = matricula;
}

inline Matricula Desenvolvedor::getMatricula() const {
    return matricula;
}

inline void Desenvolvedor::setSenha(const Senha &senha) {
    this->senha = senha;
}

inline Senha Desenvolvedor::getSenha() const {
    return senha;
}

inline void Desenvolvedor::setTelefone(const Telefone &telefone) {
    this->telefone = telefone;
}

inline Telefone Desenvolvedor::getTelefone() const {
    return telefone;
}

//----------------------------------------------------------------------------------------------------------------------
class Teste : public Entidade {
   private:
    Codigo codigo;
    Classe classe;

   public:
    Teste(){};
    Teste(Codigo, Texto, Classe);

    void setCodigo(const Codigo &);
    Codigo getCodigo() const;
    void setClasse(const Classe &);
    Classe getClasse() const;
};

inline Teste::Teste(Codigo codigo, Texto nome, Classe classe) {
    this->codigo = codigo;
    this->nome = nome;
    this->classe = classe;
}

inline void Teste::setCodigo(const Codigo &codigo) {
    this->codigo = codigo;
}

inline Codigo Teste::getCodigo() const {
    return codigo;
}

inline void Teste::setClasse(const Classe &classe) {
    this->classe = classe;
}

inline Classe Teste::getClasse() const {
    return classe;
}

//----------------------------------------------------------------------------------------------------------------------
class CasoDeTeste : public Entidade {
   private:
    Codigo codigo;
    Data data;
    Texto acao;
    Texto resposta;
    Resultado resultado;

   public:
    CasoDeTeste(){};
    CasoDeTeste(Codigo, Texto, Data, Texto, Texto, Resultado);

    void setCodigo(const Codigo &);
    Codigo getCodigo() const;
    void setData(const Data &);
    Data getData() const;
    void setAcao(const Texto &);
    Texto getAcao() const;
    void setResposta(const Texto &);
    Texto getResposta() const;
    void setResultado(const Resultado &);

    Resultado getResultado() const;
};

inline CasoDeTeste::CasoDeTeste(Codigo codigo, Texto nome, Data data, Texto acao, Texto resposta, Resultado resultado) {
    this->codigo = codigo;
    this->data = data;
    this->acao = acao;
    this->resposta = resposta;
    this->resultado = resultado;
}

inline void CasoDeTeste::setCodigo(const Codigo &codigo) {
    this->codigo = codigo;
}

inline Codigo CasoDeTeste::getCodigo() const {
    return codigo;
}

inline void CasoDeTeste::setData(const Data &data) {
    this->data = data;
}

inline Data CasoDeTeste::getData() const {
    return data;
}

inline void CasoDeTeste::setAcao(const Texto &acao) {
    this->acao = acao;
}

inline Texto CasoDeTeste::getAcao() const {
    return acao;
}

inline void CasoDeTeste::setResposta(const Texto &resposta) {
    this->resposta = resposta;
}

inline Texto CasoDeTeste::getResposta() const {
    return resposta;
}

inline void CasoDeTeste::setResultado(const Resultado &resultado) {
    this->resultado = resultado;
}

inline Resultado CasoDeTeste::getResultado() const {
    return resultado;
}

#endif  // ENTIDADES_H_INCLUDED

//----------------------------------------------------------------------------------------------------------------------
