#include "Game.h"
#include "listaCad.h"

void criarListaDeCompras(listaCad* lista);

int main()
{
    //Init game
    Game game;
    listaCad lista;

    criarListaDeCompras(&lista);

    game.setLista(lista);
    //Game loop
    while (game.running())
    {
        //Update
        game.update();

        //Render
        game.render();
    }

    return 0;
}

void criarListaDeCompras(listaCad* lista)
{
    bool ok;

    ItemLoja  arroz, feijao, cebola,
        alface, tomate, manteiga, leite,
        queijo, iogurte, carne, refrigerante;

    arroz.setNome("Arroz 5kg");
    arroz.setPreco(20.99);
    arroz.setQuantia(0);

    feijao.setNome("Feijao 1kg");
    feijao.setPreco(8.50);
    feijao.setQuantia(0);

    cebola.setNome("Cebola Branca kg");
    cebola.setPreco(5);
    cebola.setQuantia(0);

    alface.setNome("Alface");
    alface.setPreco(2.50);
    alface.setQuantia(0);

    tomate.setNome("Tomate kg");
    tomate.setPreco(8.00);
    tomate.setQuantia(0);

    manteiga.setNome("Manteiga 500g Com Sal");
    manteiga.setPreco(6.00);
    manteiga.setQuantia(0);

    leite.setNome("Leite 1L");
    leite.setPreco(5);
    leite.setQuantia(0);

    queijo.setNome("Queijo Mussarela 100g");
    queijo.setPreco(4.49);
    queijo.setQuantia(0);

    iogurte.setNome("Iogurte");
    iogurte.setPreco(3.49);
    iogurte.setQuantia(0);

    carne.setNome("Contra File");
    carne.setPreco(42.99);
    carne.setQuantia(0);

    refrigerante.setNome("Coca Cola 2L");
    refrigerante.setPreco(8.99);
    refrigerante.setQuantia(0);

    lista->insere(arroz, &ok);
    lista->insere(feijao, &ok);
    lista->insere(cebola, &ok);
    lista->insere(alface, &ok);
    lista->insere(tomate, &ok);
    lista->insere(leite, &ok);
    lista->insere(queijo, &ok);
    lista->insere(manteiga, &ok);
    lista->insere(iogurte, &ok);
    lista->insere(carne, &ok);
    lista->insere(refrigerante, &ok);
}
