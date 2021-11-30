#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "listaCad.h"

class Game
{

private:

	//Private Functions
	//Window
	sf::RenderWindow* window;
	sf::Event ev;


	sf::RectangleShape borda_esq, borda_dir, borda_cima, borda_baixo;
	sf::RectangleShape borda_esq_meio, borda_dir_meio, borda_cima_meio, borda_baixo_meio;
	sf::RectangleShape linha_meio_1, linha_meio_2;
	sf::RectangleShape borda_esq_inferior, borda_dir_inferior, borda_cima_inferior, borda_baixo_inferior;
	sf::RectangleShape barra_vermelha;

	sf::Music music;

	//Botoes e vetores para o armazenamento
	sf::RectangleShape bAumentar, bDiminuir, bFinalizarCompra;
	std::vector<sf::RectangleShape> vetorAumentar, vetorDiminuir;

	//Resources

	sf::Texture fundo, carrinho, dinheiro;
	sf::Sprite sprite_fundo, sprite_carrinho, sprite_dinheiro;
	sf::Font fonte1;
	sf::Font fonte2;
	sf::Font fontBaby, fontDragon;

	//Text
	sf::Text uiText, produto, quantidade, price, total, tlista, finalcompra;

	//Posicao do mouse
	sf::Vector2f mousePosView;

	//Lista de compras
	listaCad lista;

	//Se o botao de finalizar foi apertado
	bool finalizar;

	void initVariables();
	void initWindow();
	void initBorda_Superior();
	void initBorda_Meio();
	void initLinhas_Meio();
	void initBorda_Inferior();
	void initTexture();
	void initSprite();

	int initMusic();

	void initBotoes();

	void initLista();
	void initFont();
	void initText();

	void mousePos();
	void finalizarCompra();
public:

	Game();//construtor
	virtual ~Game();//destrutor

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void updateText();
	void setLista(listaCad l);


	void renderLista(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
	void renderBotoes(sf::RenderTarget& target);
	void render();
};

#endif // GAME_H
