#ifndef CONTATOS_H
#define CONTATOS_H 
#include <iostream>
#include "Pessoa_fisica.h"
#include "Pessoa_Juridica.h"
#include "Agenda.h"
#include <string>
using std::string;
using std::cout, std::endl;
class contato: public Agenda{
public:

void cadastrar_pessoa_fisica(string cpf,string nome, string endereco,string data_nasc, string email,string estado_civ);
void imprimir_agenda();
void cadastrar_pessoa_juridica(string cnpj,string nome, string endereco,string insc_estadual, string email,string razao_social);
void pesquisar_na_agenda(string no);
void remover_contato(string no);
};
#endif
