#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

//---------------------------------------------------------------------
// CLASSE DOMINIOS

/**
 * @brief  Padrão de representação para a superclasse Dominios.
 * 
 * Essa classe é usada para representar um domínio genérico.
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
 * Os métodos das classes derivadas devem tratar do armazenamento, retorno e validação de seus atributos.
 *  
 *  Implementado por 221020940.
 */
class Dominios {
   private:
    string valor;

   protected:
    virtual void validar(const string&) = 0;

   public:
    /**
     * @brief Define o valor do domínio.
     *
     * Este método define o valor do domínio armazenado na classe, caso o mesmo seja válido.
     *
     * @param valor Valor a ser definido para o domínio.
     *
     * @throw invalid_argument Caso o valor informado seja inválido.
     */
    void setValor(string);

    /**
     * @brief Retorna o valor do domínio.
     *
     * Este método retorna o valor do domínio atualmente armazenado na classe.
     *
     * @return Valor atual do domínio.
     */
    string getValor() const;
};


inline void Dominios::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

inline string Dominios::getValor() const {
    return valor;
}

//---------------------------------------------------------------------
// DOMINIO CLASSE
/**
 * @brief Padrão de representação para a classe Classe.
 * 
 * Herda métodos e atributos no modo public da classe Dominios.
 * 
 * Classe que representa 6 palavras - strings - pré-definidas.
 *
 * Regras de formato:
 * - Strings com seis formatos possíveis.
 * - 1ª opção: UNIDADE.
 * - 2ª opção: INTEGRACAO.
 * - 3ª opção: FUMACA.
 * - 4ª opção: SISTEMA.
 * - 5ª opção: REGRESSAO.
 * - 6ª opção: ACEITACAO.
 *
 * Implementado por 221006389.
 *
 */
class Classe : public Dominios {
   private:
    string classe;
    void validar(const string&);
};

//---------------------------------------------------------------------
// DOMINIO CODIGO

/**
 * @brief Padrão de representação da classe Codigo.
 * 
 * Herda métodos e atributos no modo public da classe Dominios.
 * 
 * É uma classe que representa um codigo padronizado.
 *
 * Regras de formato:
 * - Strings de 6 caracteres.
 * - Os 3 primeiros caracteres são letras (maiúsculas ou minúsculas).
 * - Os 3 últimos caracteres são dígitos (de 0 a 9).
 *
 * Implementado por 221006351.
 */

class Codigo : public Dominios {
   private:
    string codigo;
    void validar(const string&);
};

//---------------------------------------------------------------------
// DOMINIO DATA

/**
 * @brief Padrão de representação para a classe Data.
 *
 * Herda métodos e atributos no modo public da classe Dominios.
 *  
 * É uma classe que representa uma data padronizada.
 * 
 * Regras de formato:
 * - Formato: DD/MMM/AAAA.
 * - DD é um valor inteiro entre 1 e 31 (depende do mês e do ano).
 * - MMM é uma string correspondente à sigla do mês (JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ).
 * - AAAA é um valor inteiro entre 2000 e 2999 correspondente ao ano.
 *
 * Implementado por 221020940.
 */
class Data : public Dominios {
   private:
    string data;
    vector<string> extrairData(const string& data);
    void validar(const string&);
};

//---------------------------------------------------------------------
// DOMINIO MATRICULA

/**
 * @brief Padrão de representação para a classe Matricula.
 * 
 * Herda métodos e atributos no modo public da classe Dominios.
 * 
 * É uma classe que representa uma matricula seguindo uma série de regras.
 *
 * Regras de formato:
 * - Strings de 7 caracteres.
 * - Os caracteres são números inteiros de 0 a 9
 * - O último dígito da string é o dígito verificador de módulo 10.
 * - O dígito verificador define se a string é válida ou não.
 * 
 * Implementado por 221006351.
 */
class Matricula : public Dominios {
   private:
    /**
     * @brief Atributo do tipo string armazenado na classe.
     *
     */
    string matricula;
    /**
     * @brief Método que verifica se o parâmetro é válido para a classe ou não.
     *
     * Validações executadas:
     * - Verificar se o parâmetro é uma string de 7 caracteres.
     * - Verificar se todos os caracteres da string são números inteiros de 0 a 9.
     * - Verificar se o último caractere da string é o dígito verificador correto.
     *
     * @param matricula.
     *
     * @throw invalid_argument se a matrícula for inválida.
     */
    void validar(const string&);
};

//---------------------------------------------------------------------
// DOMINIO RESULTADO
/**
 * @brief Padrão de representação para a classe Resultado.
 *
 * Herda métodos e atributos no modo public da classe Dominios.
 *  
 * É uma classe que representa um resultado "APROVADO" ou um resultado "REPROVADO".
 *
 * Regras de formato:
 * - String com dois formatos possíveis.
 * - 1° opção: APROVADO.
 * - 2° opção: REPROVADO.
 *
 * Implementado por 221006389.
 */
class Resultado : public Dominios {
   private:
    string resultado;
    void validar(const string&);
};

//---------------------------------------------------------------------
// DOMINIO SENHA

/**
 * @brief Padrão de representação para a classe Senha.
 *
 * Herda métodos e atributos no modo public da classe Dominios.
 * 
 * É uma classe usada para representar uma senha de formato válido.
 *
 * Regras de formato:
 * - Formato: XXXXX.
 * - X é um caractere válido que não se repete (vide validar).
 *
 * Implementado por: 221020940.
 */
class Senha : public Dominios {
   private:
    string senha;
    void validar(const string&);
};

//---------------------------------------------------------------------
// DOMINIO TELEFONE

/**
 * @brief Padrão de representação da classe Telefone.
 * 
 * Herda métodos e atributos no modo public da classe Dominios.
 * 
 * É uma classe que representa um número de telefone.
 *
 * Regras de formato:
 * - Valor do telefone deve possui de 8 a 16 caracteres;
 * - O primeiro caractere sempre é "+";
 * - Os demais caracteres são dígitos;
 * - Podem haver de 7 a 15 dígitos;
 * - Cada dígito é um número inteiro de 0 a 9.
 *
 * Implementado por: 221006351.
 *
 */
class Telefone : public Dominios {
   private:
    string telefone;
    void validar(const string&);
};

//---------------------------------------------------------------------
// DOMINIO TEXTO

/**
 * @brief Padrão de representação para a classe Texto.
 * 
 * Herda métodos e atributos no modo public da classe Dominios.
 * 
 * É uma classe que representa um texto padronizado.
 *
 * Padrão de representação de um texto:
 * - Possuem de 10 a 20 caracteres;
 * - Não há acentuação;
 * - Não há espaços brancos consecutivos.
 *
 * A validação do valor do texto é realizada pelo método herdado 'validar'.
 *
 * Implementado por: 221020940.
 */
class Texto : public Dominios {
   private:
    string texto;
    void validar(const string&);
};

#endif  // DOMINIOS_H_INCLUDED
