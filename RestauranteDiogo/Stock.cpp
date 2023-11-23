#include "Stock.h"
#include "Restaurante.h"



Stock::Stock()
{
	this->id = 0;
	this->nome = "";
	this->quantidade = 0;
	this->preco = 0.0;
	this->dataValidade.dia = 0;
	this->dataValidade.mes = 0;
	this->dataValidade.ano = 0;

}

Stock::Stock(string nome, int id, int quantidade, int validade, double preco, int dia, int mes, int ano)
{
	this->nome = nome;
	this->quantidade = quantidade;
	this->preco = preco;
	this->dataValidade.dia = dia;
	this->dataValidade.mes = mes;
	this->dataValidade.ano = ano;
}

void Stock::setValidade(int dia, int mes, int ano)
{
	this->dataValidade.dia = dia;
	this->dataValidade.mes = mes;
	this->dataValidade.ano = ano;
}

int Stock::getIds()
{
	return id;
}

void Stock::setIds(int id)
{
	this->id = id;
}

void Stock::gerarIds()
{
	id = rand() % 1000 + 1;

}



string Stock::getNome()
{

	return nome;
}

int Stock::getQuantidade()
{
	return quantidade;
}


double Stock::getPreco()
{
	return preco;
}



void Stock::setNome(string nome)
{
	this->nome = nome;
}

void Stock::setQuantidade(int quantidade)
{
	this->quantidade = quantidade;
}

void Stock::setPreco(double preco)
{
	this->preco = preco;
}

double Stock::precoVenda()
{
	double precoVenda, Aux;
	Aux = preco * 0.3;
	precoVenda = preco + Aux;
	return precoVenda;

}

void Stock::imprimirStock()
{
	cout << "Id: " << id << endl;
	cout << "Nome: " << nome << endl;
	cout << "Quantidade: " << quantidade << endl;
	cout << "Validade: " << dataValidade.dia << "/" << dataValidade.mes << "/" << dataValidade.ano << endl;
	cout << "Preco: " << preco << endl;
	cout << "Preco de Venda: " << precoVenda() << endl;
}

void Stock::removerStock(int quantidade)
{
	this->quantidade -= quantidade;


}

void Stock::menuStock()
{
	cout << "  ______________________________________________\n";
	cout << " |                                              |\n";
	cout << " |                   Gerir STOCK                |\n";
	cout << " |______________________________________________|\n";
	cout << " |                                              |\n";
	cout << " |     1. Adicionar Prato                       |\n";
	cout << " |     2. Adicionar stock a um prato existente. |         |\n";
	cout << " |     3. Remover Prato do menu                 |\n";
	cout << " |     4. Voltar ao Menu Inicial                |\n";
	cout << " |______________________________________________|\n";
	cout << "\n Opcao: ";
}

