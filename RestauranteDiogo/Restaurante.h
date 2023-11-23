#pragma once
#include "Cliente.h"
#include "Pedido.h"
#include <iostream>
#include <vector> 
#include <string> 
#include <cstdlib> // system("cls")
#include <ctime> 
using namespace std;
 
class Restaurante {
private:
    string ementa;
    vector<Prato> ementaPratos;
    vector<Pedido> pedidos;
    vector<Cliente> clientes;
    vector<int> vendasPorPrato;
    vector<Bebida> ementaBebidas;
    vector<int> vendasPorBebida;

    int numMesa;

public:
   
    Restaurante();
    void adicionarPrato();
    void armazenarPrato(string nome, double preco,string dataValidade);
    void removerPrato();
    void verEmenta();
    void adicionarStockaPrato();

    void adicionarCliente(const string& nome, const string& telefone, const string& endereco, int numCliente);
    void addCliente();
    void removerCliente(const string& nome);
    void apagarCliente();
    void alterarNomeCliente(const string& nome, const string& novoNome);
    void editarCliente();
    void imprimirClientes();

    void inserirPedidoCliente();
    double calcularTotalPedido(const Pedido& pedido) const;
    void verPedidoCliente() const;
    void imprimirRecibo() const;
    void dataRecibo() const;
    bool verificarsorteado(const Pedido& pedido) const;
    double calcularTotalMesa(int numMesa) const;


    void adicionarBebida(const string& nome, double preco);
    void removerBebida();
    void editarBebida();
    void verEmentaBebidas();

    void relatorioStock();
    void relatorioVendasPorPrato(string nome);
    void rVendasPorPrato();
    void relatorioVendasTotal();
    void relatorioPratoMaisVendido();
    void relatorioPratoMenosVendido();
    void relatorioPratoMaiorLucro();
    void relatorioClienteMaisComprou();

    bool verificarStockPrato(const string& nome) const;

    int lerInteiro();

    void menuInicial();
    void menuMesa();
    void menuEmenta();
    void menuCliente();
    void menuRelatorio();
    void entrarPrograma();

  
   
    

};
