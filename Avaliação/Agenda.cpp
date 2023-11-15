#include "Agenda.h"

#include <string>
using std::string;

#include <iostream>
using std::cout, std::endl;
#include <vector>
#include <algorithm>

Agenda::Agenda(){}

Agenda::~Agenda(){
  contatos.clear();
}

void Agenda::cadastrarContato(string nome, int idade, float altura){
  Pessoa p( nome, idade,  altura);
  contatos.push_back(p);
}

void Agenda::cadastrarContato(const Pessoa &p){
  contatos.push_back(p);
}

void Agenda::buscaContato(string nome) const {
  for(auto el : contatos){
    if(el.getNome() == nome){
      cout << el;
      break;
    }
  }
}

void Agenda::removerContato(string nome){
  for(int i = 0;contatos.size();i++){
    if(contatos[i].getNome() == nome){
      contatos.erase(contatos.begin()+i);
      break;
    }
  }  
}

void Agenda::imprimirContatos() const {
  cout << "__________ Contatos __________" << endl;
  for(auto el : contatos){
    cout << el << endl;
  }
}