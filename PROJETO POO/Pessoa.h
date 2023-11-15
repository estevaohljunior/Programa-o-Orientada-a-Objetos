#ifndef PESSOA_H
#define PESSOA_H 

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Pessoa 
{
  friend ostream &operator<<(ostream &o, const Pessoa &p);
public:
  Pessoa(string nome = "", int idade = 0, float altura = 0.0f);

  Pessoa &setNome(const string &);
  Pessoa &setIdade( int );
  Pessoa &setAltura( float);

  const string &getNome() const {return nome;}
  int getIdade() const {return idade;}
  float getAltura() const {return altura;}

private:
  string nome;
  int idade;
  float altura;
};

#endif