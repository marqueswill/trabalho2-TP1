#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

//---------------------------------------------------------------------
// ENTIDADE ENTIDADE
/**
 * @brief Padrão de representação para a superclasse Entidade.
 *
 * Essa classe é usada como padrão para representar uma entidade genérica.
 * 
 * Superclasse é uma classe que servirá de forma a servir de herança para os métodos e atributos das classes derivadas.
 *
 * As classes derivadas devem implementar o método de validação de acordo com suas respectivas regras de formato.
 *
 * As classes derivadas desta biblioteca herdarão no modo public, ou seja: 
 * - Os atributos e métodos públicos serão herdados normalmente pelas classes derivadas.
 * - Os atributos e métodos privados só serão herdados se declarados nas classes derivadas.
 * - Métodos ou atributos protected serão herdados no modo public permanecem protected.
 * 
 * Os métodos das classes derivadas devem tratar do armazenamento e retorno de seus atributos.
 * 
 * Implementado por 221006351.
 */
class Entidade {
   private:
    Texto nome;

   public:
    void setNome(const Texto &);
    /**
     * @brief Armazena objeto da classe Texto.
     *
     * @return
     */

    /**
     * @brief Retorna objeto da classe Texto.
     *
     * @return Texto.
     */
    Texto getNome() const;
};


inline void Entidade::setNome(const Texto &nome) {
    this->nome = nome;
}


inline Texto Entidade::getNome() const {
    return nome;
}

//---------------------------------------------------------------------
// ENTIDADE DESENVOLVEDOR - 221006351
/**
 * @brief Padrão de representação para a classe Desenvolvedor.
 * 
 * Herda métodos e atributos no modo public da classe Entidade.
 * 
 * É uma classe que representa um desenvolvedor, que possui como atributos:
 * - Uma matrícula.
 * - Uma senha.
 * - Um telefone.
 * 
 * Tais atributos são objetos de classes definidas em domínios.
 * 
 * Implementado por 221006351.
 */
class Desenvolvedor : public Entidade {
   private:
    Matricula matricula;
    Senha senha;
    Telefone telefone;

   public:
    /**
     * @brief Método que armazena objeto da classe Matricula.
     *
     */
    void setMatricula(const Matricula &);

    /**
     * @brief Método que retorna objeto da classe Matricula.
     *
     * @return Matricula.
     */
    Matricula getMatricula() const;

    /**
     * @brief Método que armazena objeto da classe Senha.
     *
     */
    void setSenha(const Senha &);

    /**
     * @brief Retorna objeto da classe Senha.
     *
     * @return Senha
     */
    Senha getSenha() const;

    /**
     * @brief Método que armazena objeto da classe Telefone.
     *
     */
    void setTelefone(const Telefone &);

    /**
     * @brief Retorna objeto da classe Telefone.
     *
     * @return Telefone.
     */
    Telefone getTelefone() const;
};

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

//---------------------------------------------------------------------
// ENTIDADE TESTE - 221006389
/**
 * @brief Padrão de representação para a classe Teste.
 * 
 * Herda métodos e atributos no modo public da classe Entidade.
 * 
 * É uma classe que representa um teste, que possui como atributos:
 * - Um codigo.
 * - Uma classe.
 * 
 * Tais atributos são objetos de classes definidas em domínios.
 * 
 * Implementado por 221006389.
 */
class Teste : public Entidade {
   private:
   /**
    * @brief Atributo que é instância da classe Codigo.
    * 
    */
    Codigo codigo;
    /**
     * @brief Atributo que é instância de Classe.
     * 
     */
    Classe classe;

   public:
    /**
     * @brief Método que armazena objeto da classe Codigo.
     *
     */
    void setCodigo(const Codigo &);

    /**
     * @brief Método que retorna objeto da classe Codigo.
     *
     * @return Codigo
     */
    Codigo getCodigo() const;

    /**
     * @brief Método que armazena objeto da classe Classe.
     *
     */
    void setClasse(const Classe &);

    /**
     * @brief Método que retorna objeto da classe Classe.
     *
     * @return Classe
     */
    Classe getClasse() const;
};

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
//---------------------------------------------------------------------
// ENTIDADE CASO DE TESTE
/**
 * @brief Padrão de representação para a classe CasoDeTeste.
 * 
 * Herda métodos e atributos no modo public da classe Entidade.
 * 
 * É uma classe que representa um caso de teste, que possui como atributos:
 * - Um código.
 * - Uma data.
 * - Uma ação.
 * - Uma resposta.
 * - Um resultado.
 * 
 * Tais atributos são objetos de classes definidas em domínios.
 * 
 * Implementado por 221006351.
 *
 */
class CasoDeTeste : public Entidade {
   private:
    /**
     * @brief Atributo que é instância da classe Codigo.
     *
     */
    Codigo codigo;

    /**
     * @brief Atributo que é instância da classe Data.
     *
     */
    Data data;

    /**
     * @brief Atributo que é instância da classe Texto.
     *
     */
    Texto acao;

    /**
     * @brief Atributo que é instância da classe Texto.
     *
     */
    Texto resposta;

    /**
     * @brief Atributo que é instância da classe Resultado.
     *
     */
    Resultado resultado;

   public:
    /**
     * @brief Método que armazena objeto da classe Codigo.
     *
     */
    void setCodigo(const Codigo &);

    /**
     * @brief Método que retorna objeto da classe Codigo.
     *
     * @return Codigo.
     */
    Codigo getCodigo() const;

    /**
     * @brief Método que armazena objeto da classe Data.
     *
     */
    void setData(const Data &);

    /**
     * @brief Método que retorna objeto da classe Data.
     *
     * @return Data.
     */
    Data getData() const;

    /**
     * @brief Método que armazena objeto "acao" da classe Texto.
     *
     */
    void setAcao(const Texto &);

    /**
     * @brief Retorna o objeto "acao" da classe Texto.
     *
     * @return Texto.
     */
    Texto getAcao() const;

    /**
     * @brief Método que armazena objeto "resposta" da classe Texto.
     *
     */
    void setResposta(const Texto &);

    /**
     * @brief Método que retorna objeto "resposta" da classe Texto.
     *
     * @return Texto.
     */
    Texto getResposta() const;

    /**
     * @brief Método que armazena objeto da classe Resultado.
     *
     */
    void setResultado(const Resultado &);

    /**
     * @brief Método que retorna objeto da classe Resultado.
     *
     * @return Resultado
     */
    Resultado getResultado() const;
};

class ResultadoAutenticacao: public Resultado, Desenvolvedor{
    private:
        Matricula matricula;
        Senha senha;
};
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

//---------------------------------------------------------------------
