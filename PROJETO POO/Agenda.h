#ifndef AGENDA_H
#define AGENDA_H

#include "Pessoa.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;

class Agenda{
public:
  Agenda();
  ~Agenda();
  void cadastrarContato(string nome, int idade, float altura);
  void cadastrarContato(const Pessoa &p);

  void removerContato(string nome);

  void buscaContato(string nome) const; 
  void imprimirContatos() const; // imprime todos os dados de todas as pessoas da agenda

private:
  vector<Pessoa> contatos;
};

#endif