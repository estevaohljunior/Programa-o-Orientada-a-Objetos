#include "Pessoa.h"

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;

ostream &operator<<(ostream &o, const Pessoa &p)
{
  o << "Nome: " << p.nome << endl;
  o << "Idade: " << p.idade << endl;
  o << "Altura: " << p.altura << endl;
  return o;
}

Pessoa::Pessoa(string nome, int idade, float altura)
{
  this->nome = nome;
  this->idade = idade;
  this->altura = altura;
}

Pessoa &Pessoa::setNome(const string &nome)
{
  this->nome = nome;
  return *this;
}

Pessoa &Pessoa::setIdade( int idade)
{
  this->idade = idade;
  return *this;
}

Pessoa &Pessoa::setAltura( float altura)
{
  this->altura = altura;
  return *this;
}
