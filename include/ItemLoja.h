#ifndef ITEMLOJA_H
#define ITEMLOJA_H

#include <string>

class ItemLoja {
private:
    std::string nome;
    float preco;
    int quantia;
public:
    std::string getNome();
    void setNome(std::string  palavra);
    float getPreco();
    void setPreco(float valor);
    int getQuantia();
    void setQuantia(int quantidade);
};

#endif // ITEMLOJA_H
