#include "ItemLoja.h"

std::string ItemLoja::getNome() {
    return nome;
}

void ItemLoja::setNome(std::string palavra) {
    nome = palavra;
}

float ItemLoja::getPreco() {
    return preco;
}

void ItemLoja::setPreco(float valor) {
    preco = valor;
}

int ItemLoja::getQuantia() {
    return quantia;
}

void ItemLoja::setQuantia(int quantidade) {
    quantia = quantidade;
}
