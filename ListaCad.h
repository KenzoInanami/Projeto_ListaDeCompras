#ifndef LISTACAD_H
#define LISTACAD_H

#include "ItemLoja.h"

class listaCad {
public:
    listaCad();
    bool estaNaLista(ItemLoja it);
    void insere(ItemLoja item, bool* deuCerto);
    void retira(ItemLoja item, bool* deuCerto);
    bool vazia() const;
    bool cheia() const;
    void getPrim(ItemLoja* item, bool* okNum);
    void getProx(ItemLoja* item, bool* okNum);
    int getnElementos() const;
    void aumQuantItem(int i);
    void dimQuantItem(int i);

private:
    struct node {
        ItemLoja item;
        node* prox, * anterior;
    };

    node* primeiro = nullptr, * ultimo = nullptr;
    node* selecionada = nullptr;
    int nElementos = 0;

};

#endif // LISTACAD_H
