#include <iostream>
using std::cin, std::cout, std::endl;

//using std::ios;
using std::fixed, std::defaultfloat;

using std::left, std::right;

using std::ios;

#include <iomanip>
using std::setw;

using std::setprecision;

#include <fstream>
using std::fstream;

//um registro para organizar dados
struct D_LOJA {
  int n_ferramenta;
  char nome[30];
  int quantidade;
  double valor;
  int status;
};

int tLOJAS;

D_LOJA Ferramentas[8]={
  {3,"Lixadeira",7,57.98,1},
  {17,"Martelo",76,11.99,1},
  {24,"Serra tico-tico",21,11.00,1},
  {39,"Cortador de Grama",3,79.50,1},
  {56,"Serra elétrica",18,99.99,1},
  {68,"Chave de Fenda",106,6.99,1},
  {77,"Marreta",11,21.50,1},
  {83,"Chave Inglesa",34,7.50,1}
};

int posicao(fstream &f, int a){
  D_LOJA c;
  int toR = 0;

  f.clear();
  //posiciona "ponto de leitura" para o byte 0
  f.seekg(0);
  while (true)
  {
    f.read(reinterpret_cast<char *> (&c),sizeof(D_LOJA));

    if (f.eof())
      break;
    if (c.n_ferramenta==a){
      break;
    }
    toR++;
  }

  return toR;

}
bool salvar_dados(D_LOJA c[], int n, fstream &f)
{
  //posiciona "ponto de escrita" para início (byte 0)
  f.seekp(0);  
  for (int i = 0 ; i < n ; i++)
    //reinterpret_cast permite converter entre tipos de ponteiros não relacionados
    f.write(reinterpret_cast<char *>(&c[i]),sizeof(c[i]));

  
  //força a escrita imediata no arquivo
  f.flush();

  return true;
}

int contar_registros(fstream &f)
{
  D_LOJA c;
  int toR = 0;

  f.clear();
  //posiciona "ponto de leitura" para o byte 0
  f.seekg(0);
  while (true)
  {
    f.read(reinterpret_cast<char *> (&c),sizeof(D_LOJA));

    if (f.eof())
      break;
    
    toR++;
  }

  return toR;
}

bool listar_todos(fstream &f)
{  
  D_LOJA c;

  cout << " N do registro " << "      Nome da ferramenta     " << "   Quantidade  " <<"   Preço (R$)  " << endl;
  
  
  cout << fixed;
  f.clear();

  //posiciona "ponto de leitura" para o byte 0
  f.seekg(0);
  while (true)
  {
    f.read(reinterpret_cast<char *> (&c),sizeof(D_LOJA));

    if (f.eof())
      break;

    if (!c.status)
      continue;
    
    cout << setw(7) << c.n_ferramenta << ' ' << setw(30) << right << c.nome << ' ' << setw(15) << right << setprecision(2) << c.quantidade <<setw(15)<<right<<c.valor<< endl;
  }
  cout << defaultfloat;

  return true;
}

bool cadastrar_ferramenta(fstream &f, D_LOJA &c)
{
  D_LOJA ant;
  
  f.clear();
  f.seekg((tLOJAS-1) * sizeof(D_LOJA));

  f.read(reinterpret_cast<char *> (&ant),sizeof(D_LOJA));
  c.status = 1;

  f.seekp(tLOJAS * sizeof(D_LOJA));
  
  f.write(reinterpret_cast<char *> (&c),sizeof(D_LOJA));

  //força a escrita imediata no arquivo
  f.flush();
  
  tLOJAS++;

  return true;
}

bool atualizar_ferramenta(fstream &f, D_LOJA &c)

{
  f.clear();
  f.seekp((posicao(f,c.n_ferramenta)) * sizeof(D_LOJA));
  
  f.write(reinterpret_cast<char *> (&c),sizeof(D_LOJA));

  //força a escrita imediata no arquivo
  f.flush();
  return true;
}
bool repor_estoque(fstream &f, int conta, int num){
   D_LOJA c;

  f.clear();
  f.seekg((posicao(f,conta)) * sizeof(D_LOJA));

  f.read(reinterpret_cast<char *> (&c),sizeof(D_LOJA));
 
  c.quantidade = num;

  f.seekp((posicao(f,conta)) * sizeof(D_LOJA));
  
  f.write(reinterpret_cast<char *> (&c),sizeof(D_LOJA));

  //força a escrita imediata no arquivo
  f.flush();
  return true;
}

bool modificar_status_ferramenta(fstream &f, int conta, int status)
{
  D_LOJA c;

  f.clear();
  f.seekg((posicao(f,conta)) * sizeof(D_LOJA));

  f.read(reinterpret_cast<char *> (&c),sizeof(D_LOJA));
 
  c.status = status;

  f.seekp((posicao(f,conta)) * sizeof(D_LOJA));
  
  f.write(reinterpret_cast<char *> (&c),sizeof(D_LOJA));

  //força a escrita imediata no arquivo
  f.flush();
  return true;
}
bool atualizar_preco(fstream &f, int conta, int valor){
  D_LOJA c;

  f.clear();
  f.seekg((posicao(f,conta)) * sizeof(D_LOJA));

  f.read(reinterpret_cast<char *> (&c),sizeof(D_LOJA));
 
  c.valor = valor;

  f.seekp((posicao(f,conta)) * sizeof(D_LOJA));
  
  f.write(reinterpret_cast<char *> (&c),sizeof(D_LOJA));

  //força a escrita imediata no arquivo
  f.flush();
  return true;
}

int main() {
  fstream fileIO("contas.dat", ios::out | ios::in);

  //if (!fileIO)
    //fileIO.open("contas.dat", ios::out);
  
  if (!fileIO)
    return 1;
  
  //salvar_dados(Ferramentas, 8, fileIO);

  tLOJAS = contar_registros(fileIO);

  

     while (1)
  {
    cout << "-------------------------------------" << endl;
    cout << "LOJA LEGAL." << endl;
    cout << "Opções:" << endl;
    cout << "0 - Listar Todos as Ferramentas" << endl;
    cout << "1 - Cadastrar nova Ferramenta" << endl;
    cout << "2 - Alterar dados da Ferramenta" << endl;
    cout << "3 - Remover Ferramenta" << endl;
    cout << "4 - Reativar Ferramenta" << endl;
    cout << "5 - Repor Estoque" << endl;
    cout << "6 - Alterar Valor" << endl;
    cout << endl << "-1 - Sair" << endl;
    cout << "Op: ";

    int op;
    cin >> op;

    
    switch (op)
    {
      case 0:
        listar_todos(fileIO);
        break;
      case 1:{
         D_LOJA c;
        cout << "Cadastrando nova Ferramenta..." << endl;
        cout<<"Registro: ";
        cin>>c.n_ferramenta;
        cout << "Nome: ";
        cin >> c.nome;
        cout << "Quantidade: ";
        cin >> c.quantidade;
        cout<<"Preço: ";
        cin>>c.valor;
        
        cadastrar_ferramenta(fileIO, c);
        break;}
      case 2:
        {
        D_LOJA c;
        cout << "Entre com o num da ferramenta:";
        cin>>c.n_ferramenta;
        cout << "Nome: ";
        cin >> c.nome;
        cout << "Quantidade: ";
        cin >> c.quantidade;
        cout<<"Preço: ";
        cin>>c.valor;
        c.status = 1;
        atualizar_ferramenta(fileIO,c);
        break;}
      case 3:
        {int codigo;
        cout << "Entre com o codigo da ferramenta:";
        cin >> codigo;
       modificar_status_ferramenta(fileIO,codigo,0);

        break;
        }
      case 4:
     {
        int codigo;
        cout << "Entre com o num da Ferramenta:";
        cin >> codigo;
        modificar_status_ferramenta(fileIO,codigo,1);

        break;
      }
      case 5:
      {
        int cod,num;
        cout << "Entre com o num do codigo:";
        cin >> cod;        
          cout << "Entre com a quantidade: ";
          cin >> num;
          repor_estoque(fileIO,cod,num);
        break;
      }
      case 6:
      {
        double preco;
        int cod;
        cout << "Entre com o num do codigo:";
        cin >> cod;       
          cout << "Entre com o Preço: ";
          cin >> preco;
          atualizar_preco(fileIO,cod,preco);
        

        break;
      }
      case -1:
        fileIO.close();
        exit(0);
        break;

      default:
        //
        break;
    }
  }
  
  return 0;
  }