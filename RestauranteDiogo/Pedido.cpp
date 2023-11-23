#include "Pedido.h"

Pedido::Pedido(Prato prato, int quantidadePrato, Bebida bebida, int quantidadeBebida, int numMesa, Cliente cliente)
    : prato(prato), bebida(bebida), quantidadePrato(quantidadePrato), quantidadeBebida(quantidadeBebida),
    numMesa(numMesa), totalAPagar(0.0), cliente(cliente), sorteado(false) {
   
}

Prato Pedido::getPrato() const {
    return prato;
}

Bebida Pedido::getBebida() const {
    return bebida;
}

int Pedido::getQuantidadePrato() const {
    return quantidadePrato;
}

int Pedido::getQuantidadeBebida() const {
    return quantidadeBebida;
}

int Pedido::getNumMesa() const {
    return numMesa;
}

double Pedido::getTotalAPagar() const {
    return totalAPagar;
}

void Pedido::calcularTotal() {
    totalAPagar = (prato.preco * quantidadePrato) + (bebida.preco * quantidadeBebida);
}

Cliente Pedido::getCliente() const {
    return cliente;
}



Cliente Pedido::getNumCliente() const
{
    return getNumCliente();
}


bool Pedido::foiSorteado() const {
    return sorteado;
}

void Pedido::marcarComoSorteado() {
    sorteado = true;
}

void Pedido::setSorteado(bool valor)
{
    sorteado = valor;
}


