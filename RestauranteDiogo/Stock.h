#pragma once
#include <iostream>
#include <string>
#include "Pedido.h"
#include <iomanip>

using namespace std;

class Stock
{
private:
	int id;
	string nome;
	int quantidade;
	double preco;

	struct DataValidade {
		int dia;
		int mes;
		int ano;
	} dataValidade;

public:
	Stock();
	Stock(string nome, int id, int quantidade, int validade, double preco, int dia, int mes, int ano);
	void setValidade(int dia, int mes, int ano);
	int getIds();
	void setIds(int id);
	void gerarIds();
	string getNome();
	int getQuantidade();
	double getPreco();
	void setNome(string nome);
	void setQuantidade(int quantidade);
	void setPreco(double preco);
	double precoVenda();
	void imprimirStock();
	void removerStock(int quantidade);
	void menuStock();


};
