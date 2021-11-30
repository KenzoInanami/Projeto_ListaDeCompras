#include "listaCad.h"
#include <string.h>
#include <iostream>

listaCad::listaCad() {

}

bool listaCad::estaNaLista(ItemLoja it) {
    bool okNum;
    ItemLoja valorTeste;
    getPrim(&valorTeste, &okNum);
    if (valorTeste.getNome() == it.getNome()) {
        return true;
    }

    while (true) {
        getProx(&valorTeste, &okNum);
        if (valorTeste.getNome() == it.getNome()) {
            return true;
        }
        if (!okNum) {
            return false;
        }
    }

}

void listaCad::insere(ItemLoja it, bool* deuCerto) {
    if (!cheia()) {
        node* ponteiro = new node;
        ponteiro->prox = nullptr;
        ponteiro->anterior = nullptr;
        ponteiro->item = it;
        if (vazia()) {
            primeiro = ponteiro;
            ultimo = ponteiro;
            nElementos++;
        }
        else {
            if (estaNaLista(it)) {
                node* procura;
                procura = primeiro;
                while (it.getNome() != procura->item.getNome()) {
                    procura = procura->prox;
                }

                procura->item.setQuantia(procura->item.getQuantia() + it.getQuantia());
            }
            else {
                ponteiro->anterior = ultimo;
                ultimo->prox = ponteiro;
                ultimo = ponteiro;
                nElementos++;
            }
        }
        *deuCerto = true;
    }
    else {
        *deuCerto = false;
    }
}

void listaCad::retira(ItemLoja item, bool* deuCerto) {
    if (!vazia()) {
        if (estaNaLista(item)) {

            node* ponteiro = primeiro;
            node* ponteiroAux = new node;
            while (true) {
                if (ponteiro->item.getNome() == item.getNome()) {
                    if (ponteiro == primeiro && nElementos > 1) {
                        primeiro = ponteiro->prox;
                        primeiro->anterior = nullptr;
                    }
                    else if (ponteiro == primeiro) {
                        primeiro = nullptr;
                        ultimo = nullptr;
                    }
                    else if (ponteiro == ultimo) {
                        ultimo = ponteiroAux;
                        ponteiroAux->prox = nullptr;
                    }
                    else {
                        ponteiroAux->prox = ponteiro->prox;
                    }

                    ponteiro = nullptr;
                    delete ponteiro;

                    nElementos--;
                    break;
                }
                else {
                    ponteiroAux = ponteiro;
                    ponteiro = ponteiro->prox;
                }

            }


        }
        else {
            *deuCerto = false;
        }
    }
    else {
        *deuCerto = false;
    }
}



bool listaCad::vazia() const {
    if (primeiro == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

bool listaCad::cheia() const {
    return false;
}

void listaCad::getPrim(ItemLoja* it, bool* okNum) {
    if (!vazia()) {
        selecionada = primeiro;
        *it = primeiro->item;
        *okNum = true;
    }
    else {
        *okNum = false;
    }


}

void listaCad::getProx(ItemLoja* it, bool* okNum) {
    if (selecionada != nullptr) {
        selecionada = selecionada->prox;
    }
    if (selecionada != nullptr) {
        *okNum = true;
        *it = selecionada->item;
    }
    else {
        *okNum = false;
    }
}

int listaCad::getnElementos() const {
    return nElementos;
}

void listaCad::aumQuantItem(int i)
{
    if (i == 0)
    {
        primeiro->item.setQuantia(primeiro->item.getQuantia() + 1);
    }
    else
    {
        node* navegando;

        navegando = primeiro;
        for (int j = 0; j < i; j++)
        {
            navegando = navegando->prox;
        }
        navegando->item.setQuantia(navegando->item.getQuantia() + 1);
    }
}

void listaCad::dimQuantItem(int i)
{
    if (i == 0)
    {
        if (primeiro->item.getQuantia() > 0)
            primeiro->item.setQuantia(primeiro->item.getQuantia() - 1);
    }
    else
    {
        node* navegando;

        navegando = primeiro;
        for (int j = 0; j < i; j++)
        {
            navegando = navegando->prox;
        }
        if (navegando->item.getQuantia() > 0)
            navegando->item.setQuantia(navegando->item.getQuantia() - 1);
    }
}
