#ifndef CONTA_H
#define CONTA_H

#include <exception>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstring>
#include "Pessoa.h"

using std::string;

using namespace std;

class saldo_insuficiente_error : public std::out_of_range 
{
public:
  saldo_insuficiente_error(const char *e="Saldo Insuficiente") : std::out_of_range(e) {}
};

class alem_do_limite_error : public std::out_of_range 
{
public:
  alem_do_limite_error(const char *e="Valor além do Limite ") : std::out_of_range(e) {}
};

class Date_hour{
  public:
  string hour(){
    char hora[9];
    strcpy(hora, "");
    strncat(hora, __TIME__ ,8);
    return hora;
  }

  string date(){
    char data[15] = "";
    strncat(data, __DATE__ +4, 3);
    strncat(data, __DATE__ , 4);
    strncat(data, __DATE__ +7, 4);
    return data;
  }
};

class Conta 
{
public:
  Conta(int conta, Pessoa correntista, double saldo = 0.0): conta(conta),correntista(correntista),saldo(saldo) { }


  
  virtual ~Conta() {}

  void operator <<(float valor)
  {
    Date_hour dh;
    string descricao;
    cout << "Insira a descricao da trasação: ";
    cin >> descricao;
    OPERACAO operacao = {dh.date(), dh.hour(), valor, descricao};
    op.push_back(operacao);
    saldo += valor;
  }


  virtual void operator >>(float valor)
  {
    try {
      if (valor > saldo){
        throw saldo_insuficiente_error();
      }
      Date_hour dh;
      string descricao;
      cout << "Insira a descricao da trasação: ";
      cin >> descricao;
      OPERACAO operacao = {dh.date(), dh.hour(), valor, descricao};
      op.push_back(operacao);
      saldo -= valor;
    }
    catch (saldo_insuficiente_error &e){
      cerr << e.what() << endl;
      cout << endl;
    }
  }


  virtual void extrato() = 0;

protected:
  int conta;
  Pessoa correntista;
  double saldo;


  struct OPERACAO {
    string data;
    string hora;
    double valor;
    string descricao;
  };

  vector<struct OPERACAO> op ;

};

#endif