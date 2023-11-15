#include <iostream>
#include "Contatos.h"
#include <string>
Agenda *pessoas[200];
int cont=0;
using  std::string,std::cout;
void contato::cadastrar_pessoa_fisica(std::string cpf, std::string nome, std::string endereco, std::string data_nasc, std::string email, std::string estado_civ){
  pessoas[cont]={new Pessoa_Fisica(cpf,nome,endereco,data_nasc,email,estado_civ)};
  cont++;
}
void contato::cadastrar_pessoa_juridica(std::string cnpj, std::string nome, std::string endereco, std::string insc_estadual, std::string email, std::string razao_social){
  pessoas[cont]={new Pessoa_Juridica(cnpj,nome,endereco,insc_estadual,email,razao_social)};
  cont++;
}
void contato::imprimir_agenda(){
  cout<<"Contatos na Agenda:"<<endl;
  for (int i=0;i<cont;i++){
    if (pessoas[i]!=NULL){
    pessoas[i]->imprimir();}
  }
}

void contato::pesquisar_na_agenda(std::string no){
  for (int i=0;i<cont;i++){
    pessoas[i]->pesquisar(no);
  }
}
void contato::remover_contato(std::string no){
  for (int i=0;i<cont;i++){
    if (pessoas[i]->getNome()==no){
      pessoas[i]=NULL;
    }
  }
}
