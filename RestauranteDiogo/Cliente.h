#pragma once
#include <string>
using namespace std;

class Cliente {
private:
    string nome;
    string telefone;
    string endereco;
    int numContribuinte;
    double totalGasto;
    int numCliente;

public:
    Cliente(const string& nome, const string& telefone, const string& endereco,int numCliente);
    string getNome() const;
    string getTelefone() const;
    string getEndereco() const;
    double getTotalGasto() const; 
    void setNome(const string& novoNome);
    void adicionarGasto(double valor); 
    int getNumCliente() const;
    void setNumCliente(int numCliente);
    int getNumContribuinte() const;
    //o uso de const nas funcoes servem para nao alterar os valores das variaveis
};

