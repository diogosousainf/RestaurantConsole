#pragma once
#include "Cliente.h"
#include <string>
using namespace std;

struct Prato {
    string nome;
    double preco;
    int quantidadeEmStock;
    string dataValidade;
};

struct Bebida {
    string nome;
    double preco;
    int quantidadeEmStock;
};
//struct serve para agrupar variaveis de tipos diferentes podem ser 

class Pedido {
private:
    Prato prato;
    Bebida bebida;
    int quantidadePrato;
    int quantidadeBebida;
    int numMesa;
    double totalAPagar;
    Cliente cliente;
    bool refeicaoGratis;
    double total;
    bool sorteado;


public:
    Pedido(Prato prato, int quantidadePrato, Bebida bebida, int quantidadeBebida, int numMesa, Cliente cliente);
    Prato getPrato() const;
    Bebida getBebida() const;
    int getQuantidadePrato() const;
    int getQuantidadeBebida() const;
    int getNumMesa() const;
    double getTotalAPagar() const;
    void calcularTotal();
    Cliente getCliente() const;
    int getNumLinha() const;
    Cliente getNumCliente() const;

    bool foiSorteado() const;
    void marcarComoSorteado();
    void setSorteado(bool valor);
};
