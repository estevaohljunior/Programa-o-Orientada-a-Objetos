#include <iostream>
#include "Contatos.h"
#include <string>
int main() {
  contato *agenda;
agenda->cadastrar_pessoa_fisica("123.456.789.23", "Ellisson", "João Pessoas", "13/05/2021", "ellisson@gmail.com", "Solteiro");
agenda->cadastrar_pessoa_fisica("234.567.789.25", "Everson", "Campina Grande", "22/01/2021", "everson@gmail.com", "solteiro");
agenda->cadastrar_pessoa_juridica("12.123.154-0001/25", "Kdk", "Limoeiro", "KDK Rio Grande do Norte", "kdk@contato.com", "Kdk tintas");
agenda->imprimir_agenda();
agenda->pesquisar_na_agenda("Ellisson");
agenda->remover_contato("Ellisson");
agenda->imprimir_agenda();
}