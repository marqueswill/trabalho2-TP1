//---------------------------------------------------------------------
// BIBLIOTECAS
#include "../headers/dominios.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//---------------------------------------------------------------------
// VALIDAÇÃO DE CLASSE
void Classe::validar(const string& classe) {
    vector<string> classes = {"UNIDADE", "INTEGRACAO", "FUMACA", "SISTEMA", "REGRESSAO", "ACEITACAO"};
    bool encontrou = false;
    for (const auto& classe_valida : classes) {
        if (classe == classe_valida) {
            encontrou = true;
            break;
        }
    }
    if (encontrou == false) {
        throw invalid_argument("Classe(s) inválida(s).");
    }
}

//---------------------------------------------------------------------
// VALIDAÇÃO DO CÓDIGO - 221006351
void Codigo::validar(const string& codigo) {
    if (codigo.size() != 6) {
        throw invalid_argument("Código deve conter 6 caracteres.");
    }

    for (int i = 0; i < codigo.size(); i++) {
        if (i < 3) {
            if (!isalpha(codigo[i])) {
                throw invalid_argument("Os três primeiros caracteres devem ser letras.");
            }
        } else {
            if (!isdigit(codigo[i])) {
                throw invalid_argument("Os três últimos caracteres devem ser números.");
            }
        }
    }
}

//---------------------------------------------------------------------
// VALIDAÇÃO DA DATA - 221020940
vector<string> Data::extrairData(const string& data) {
    vector<string> dia_mes_ano;
    string temp_str = "";

    for (int i = 0; i < data.size(); i++) {
        if (data[i] == '/') {
            dia_mes_ano.push_back(temp_str);
            temp_str.clear();
        } else {
            temp_str += data[i];
            if (i == data.size() - 1) {
                dia_mes_ano.push_back(temp_str);
            }
        }
    }

    return dia_mes_ano;
}

void Data::validar(const string& data) {
    vector<string> meses = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    vector<int> dias = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (count(data.begin(), data.end(), '/') != 2) {
        throw invalid_argument("Formato de data inválido.");
    }

    vector<string> dia_mes_ano = extrairData(data);

    int dia, ano;
    string mes;
    try {
        dia = stoi(dia_mes_ano[0]);
        mes = dia_mes_ano[1];
        ano = stoi(dia_mes_ano[2]);
    } catch (invalid_argument& excecao) {
        throw invalid_argument("Data Inválida.");
    }

    if (ano < 2000 || ano > 2999) {
        throw invalid_argument("Ano da data informada deve estar entre 2000 e 2999.");
    }

    int pos = distance(meses.begin(), find(meses.begin(), meses.end(), mes));
    if (pos == 12) {
        throw invalid_argument("Sigla do mês inválida.");
    }

    if (mes == "FEV") {
        if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
            dias[1]++;
        }
    }

    if (dia < 1 || dia > dias[pos]) {
        throw invalid_argument("Dia do mês inválido.");
    }
};

//---------------------------------------------------------------------
// VALIDAÇÃO DA MATRICULA - 221006351
void Matricula::validar(const string& matricula) {
    if (matricula.size() != 7) {
        throw invalid_argument("A matrícula deve conter 7 dígitos");
    }

    int fator = 1, soma = 0, digito_encontrado;
    for (int i = 0; i < matricula.size() - 1; i++) {
        if (!isdigit(matricula[i])) {
            throw invalid_argument("Matrícula deve conter apenas dígitos");
        }

        int valor = matricula[i] - '0';
        soma += fator * valor;

        if (i % 2 == 0) {
            fator = 2;
        } else {
            fator = 1;
        }
    }

    soma = soma % 10;
    if (soma != 0) {
        digito_encontrado = 10 - soma;
    } else {
        digito_encontrado = soma;
    }

    int digito_verificador = matricula[6] - '0';
    if (digito_verificador != digito_encontrado) {
        throw invalid_argument("Dígito verificador inválido.");
    }
}

//---------------------------------------------------------------------
// VALIDAÇÃO DE RESULTADO
void Resultado::validar(const string& resultado) {
    vector<string> resultados = {"APROVADO", "REPROVADO"};
    bool encontrou = false;
    for (const auto& resultado_valido : resultados) {
        if (resultado == resultado_valido) {
            encontrou = true;
            break;
        }
    }
    if (encontrou == false) {
        throw invalid_argument("Resultado inválido.");
    }
}

//---------------------------------------------------------------------
// VALIDAÇÃO DA SENHA - 221020940
void Senha::validar(const string& senha) {
    string digitos = "0123456789";
    string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string pontuacao = "@#$%&";
    string caracteres_validos = letras + digitos + pontuacao;

    if (senha.size() != 6) {
        throw invalid_argument("A senha deve conter 6 caracteres.");
    }

    for (auto ch : senha) {
        if (count(senha.begin(), senha.end(), ch) > 1) {
            throw invalid_argument("A senha não pode conter caracteres repetidos.");
        }
    }

    for (auto ch : senha) {
        if (find(caracteres_validos.begin(), caracteres_validos.end(), ch) == caracteres_validos.end()) {
            throw invalid_argument("Senha contém caractere(s) inválido(s).");
        }
    }
}

//---------------------------------------------------------------------
// VALIDAÇÃO DO TELEFONE - 221006351
void Telefone::validar(const string& telefone) {
    if (telefone.size() < 8 || telefone.size() > 16) {
        throw invalid_argument("O telefone deve conter \"+\" seguido de 7 a 15 dígitos.");
    }

    for (int i = 0; i < telefone.size(); i++) {
        if (i == 0) {
            if (telefone[i] != '+')
                throw invalid_argument("O primeiro caractere deve ser \"+\".");
        } else {
            if (!isdigit(telefone[i])) {
                throw invalid_argument("Número de telefone inválido.");
            }
        }
    }
}

//---------------------------------------------------------------------
// VALIDAÇÃO DO TEXTO - 221020940
void Texto::validar(const string& texto) {
    string digitos = "0123456789";
    string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string pontuacao = ".,;?!:-@#$%&";
    string caracteres_validos = letras + digitos + pontuacao + " ";

    if (texto.size() < 10 || texto.size() > 20) {
        throw invalid_argument("Texto deve conter de 10 e 20 caracteres.");
    }

    for (auto ch : texto) {
        if (find(caracteres_validos.begin(), caracteres_validos.end(), ch) == caracteres_validos.end()) {
            throw invalid_argument("Texto contém caractere(s) inválido(s).");
        }
    }

    if (texto.find("  ") != string::npos) {
        throw invalid_argument("Texto contém espaços em branco em sequência.");
    }
}
