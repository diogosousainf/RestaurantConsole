#include "cliente.h"

Cliente::Cliente(const string& nome, const string& telefone, const string& endereco , int numCliente)
    : nome(nome), telefone(telefone), endereco(endereco), totalGasto(0.0) ,numCliente(numCliente) {
}

string Cliente::getNome() const {
    return nome;
}

string Cliente::getTelefone() const {
    return telefone;
}

string Cliente::getEndereco() const {
    return endereco;
}

double Cliente::getTotalGasto() const {
    return totalGasto;
}

void Cliente::setNome(const string& novoNome) {
    nome = novoNome;
}

void Cliente::adicionarGasto(double valor) {
    totalGasto += valor;
}

int Cliente::getNumCliente() const
{
    return numCliente;
}

void Cliente::setNumCliente(int numCliente)
{
    	this->numCliente = numCliente;
}

int Cliente::getNumContribuinte() const
{
    return numContribuinte;
}
