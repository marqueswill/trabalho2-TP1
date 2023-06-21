#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <iomanip>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

//--------------------------------------------------------------------------------------------
class Dominios {
   private:
    string valor;

   protected:
    virtual void validar(const string&) = 0;

   public:
    void setValor(string);
    string getValor() const;
};

inline void Dominios::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

inline string Dominios::getValor() const {
    return valor;
}

//--------------------------------------------------------------------------------------------
class Classe : public Dominios {
   private:
    string classe;
    void validar(const string&);

   public:
    Classe(){};
    Classe(string);
};

inline Classe::Classe(string valor) {
    validar(valor);
    classe = valor;
}

//--------------------------------------------------------------------------------------------
class Codigo : public Dominios {
   private:
    string codigo;
    void validar(const string&);

   public:
    Codigo(){};
    Codigo(string);
};

inline Codigo::Codigo(string valor) {
    validar(valor);
    codigo = valor;
}

//--------------------------------------------------------------------------------------------
class Data : public Dominios {
   private:
    string data;
    vector<string> extrairData(const string& data);
    void validar(const string&);

   public:
    Data(){};
    Data(string);
};

inline Data::Data(string valor) {
    validar(valor);
    data = valor;
}

//--------------------------------------------------------------------------------------------
class Matricula : public Dominios {
   private:
    string matricula;
    void validar(const string&);

   public:
    Matricula(){};
    Matricula(string);
};

inline Matricula::Matricula(string valor) {
    validar(valor);
    matricula = valor;
}

//--------------------------------------------------------------------------------------------
class Resultado : public Dominios {
   private:
    string resultado;
    void validar(const string&);

   public:
    Resultado(){};
    Resultado(string);
};

inline Resultado::Resultado(string valor) {
    validar(valor);
    resultado = valor;
}

//--------------------------------------------------------------------------------------------
class Senha : public Dominios {
   private:
    string senha;
    void validar(const string&);

   public:
    Senha(){};
    Senha(string);
};

inline Senha::Senha(string valor) {
    validar(valor);
    senha = valor;
}

//--------------------------------------------------------------------------------------------
class Telefone : public Dominios {
   private:
    string telefone;
    void validar(const string&);

   public:
    Telefone(){};
    Telefone(string);
};

inline Telefone::Telefone(string valor) {
    validar(valor);
    telefone = valor;
}

//--------------------------------------------------------------------------------------------
class Texto : public Dominios {
   private:
    string texto;
    void validar(const string&);

   public:
    Texto(){};
    Texto(string);
};

inline Texto::Texto(string valor) {
    validar(valor);
    texto = valor;
}

#endif  // DOMINIOS_H_INCLUDED