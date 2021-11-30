#include "Game.h"
#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;
	this->finalizar = false;
}
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Lista de Compras!", sf::Style::Default);

	this->window->setFramerateLimit(60);
}



void Game::initBorda_Superior()
{
	borda_esq.setSize(sf::Vector2f(7.f, 100.f));
	borda_esq.setFillColor(sf::Color::Black);
	borda_esq.setPosition(0, 0);

	borda_dir.setSize(sf::Vector2f(7.f, 100.f));
	borda_dir.setFillColor(sf::Color::Black);
	borda_dir.setPosition(1273, 0);

	borda_cima.setSize(sf::Vector2f(1280.f, 7.f));
	borda_cima.setFillColor(sf::Color::Black);
	borda_cima.setPosition(0, 0);

	borda_baixo.setSize(sf::Vector2f(1280.f, 7.f));
	borda_baixo.setFillColor(sf::Color::Black);
	borda_baixo.setPosition(0, 93);

	barra_vermelha.setSize(sf::Vector2f(1266.f ,86.f));
	barra_vermelha.setFillColor(sf::Color::Red);
	barra_vermelha.setPosition(7, 7);
}

void Game::initBorda_Meio()
{
	borda_esq_meio.setSize(sf::Vector2f(7.f, 625.f));
	borda_esq_meio.setFillColor(sf::Color::Black);
	borda_esq_meio.setPosition(0, 0);

	borda_dir_meio.setSize(sf::Vector2f(7.f, 625.f));
	borda_dir_meio.setFillColor(sf::Color::Black);
	borda_dir_meio.setPosition(1273, 0);

	borda_cima_meio.setSize(sf::Vector2f(1280.f, 7.f));
	borda_cima_meio.setFillColor(sf::Color::Black);
	borda_cima_meio.setPosition(0, 93);

	borda_baixo_meio.setSize(sf::Vector2f(1280.f, 7.f));
	borda_baixo_meio.setFillColor(sf::Color::Black);
	borda_baixo_meio.setPosition(0, 625);
}

void Game::initLinhas_Meio()
{
	linha_meio_1.setSize(sf::Vector2f(7.f, 526.f));
	linha_meio_1.setFillColor(sf::Color::Black);
	linha_meio_1.setPosition(426, 99);

	linha_meio_2.setSize(sf::Vector2f(7.f, 526.f));
	linha_meio_2.setFillColor(sf::Color::Black);
	linha_meio_2.setPosition(855, 99);
}

void Game::initBorda_Inferior()
{
	borda_esq_inferior.setSize(sf::Vector2f(5.f, 50.f));
	borda_esq_inferior.setFillColor(sf::Color::Black);
	borda_esq_inferior.setPosition(50, 640);

	borda_dir_inferior.setSize(sf::Vector2f(5.f, 50.f));
	borda_dir_inferior.setFillColor(sf::Color::Black);
	borda_dir_inferior.setPosition(295, 640);

	borda_cima_inferior.setSize(sf::Vector2f(250.f, 5.f));
	borda_cima_inferior.setFillColor(sf::Color::Black);
	borda_cima_inferior.setPosition(50, 640);

	borda_baixo_inferior.setSize(sf::Vector2f(250.f, 5.f));
	borda_baixo_inferior.setFillColor(sf::Color::Black);
	borda_baixo_inferior.setPosition(50, 690);
}

void Game::initTexture()
{
	if (!fundo.loadFromFile("Figures/fundo.jpeg"))
		std::cout << "ERROR::GAME::INITTEXTURE::Falha ao carregar a textura(fundo) !!!" << "\n";

	if (!carrinho.loadFromFile("Figures/Cestinha.png"))
		std::cout << "ERROR::GAME::INITTEXTURE::Falha ao carregar a textura(dinheiro) !!!" << "\n";

	if (!dinheiro.loadFromFile("Figures/dinheiro.png"))
		std::cout << "ERROR::GAME::INITTEXTURE::Falha ao carregar a textura(dinheiro) !!!" << "\n";

	sprite_fundo.setTexture(fundo);
	sprite_carrinho.setTexture(carrinho);
	sprite_dinheiro.setTexture(dinheiro);


	sprite_carrinho.setPosition(300, 620);

	sprite_dinheiro.setPosition(950, 610);
}

void Game::initSprite()
{

}

int Game::initMusic()
{
	if(!this->music.openFromFile("Music/music.ogg"))
	{
		std::cout << "ERROR::GAME::INITMUSIC::Falha ao carregar a musica music!!!" << "\n";
		return -1;
	}
	music.play();
}

void Game::initFont()
{
	if (!this->fontBaby.loadFromFile("Fonts/baby_blocks.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Falha ao carregar a fonte baby_blocks.ttf!!!" << "\n";
	}
	if (!this->fontDragon.loadFromFile("Fonts/EightBitDragon.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Falha ao carregar a fonte EightBitDragon.ttf!!!" << "\n";
	}
	if (!fonte1.loadFromFile("Fonts/Montserrat-Regular.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Falha ao carregar a fonte !!!" << "\n";
	}

	if (!fonte2.loadFromFile("Fonts/BebasNeue-Regular.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Falha ao carregar a fonte !!!" << "\n";
	}
}

void Game::initText()
{
	uiText.setFont(fonte2);
	uiText.setPosition(80, 10);
	uiText.setCharacterSize(60);
	uiText.setFillColor(sf::Color::White);
	uiText.setString("NOME");

	produto.setFont(fonte1);
	produto.setPosition(30, 110);
	produto.setCharacterSize(25);
	produto.setFillColor(sf::Color::Black);
	produto.setString("NOME");

	quantidade.setFont(fonte1);
	quantidade.setPosition(453, 115);
	quantidade.setCharacterSize(25);
	quantidade.setFillColor(sf::Color::Black);
	quantidade.setString("NOME");

	price.setFont(fonte1);
	price.setPosition(882, 110);
	price.setCharacterSize(25);
	price.setFillColor(sf::Color::Black);
	price.setString("NOME");

	total.setFont(fonte1);
	total.setPosition(75, 650);
	total.setCharacterSize(25);
	total.setFillColor(sf::Color::Black);
	total.setString("NOME");

}

//Constructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initMusic();
	this->initBorda_Superior();
	this->initBorda_Meio();
	this->initLinhas_Meio();
	this->initBorda_Inferior();
	this->initFont();
	this->initText();
	this->initTexture();
	this->initLista();
	this->initBotoes();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

//Acessors
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		case sf::Event::MouseButtonReleased:
			if (this->ev.mouseButton.button == sf::Mouse::Left)
			{
				//Botoes de alterar a quantidade
				for (int i = 0; i < this->lista.getnElementos(); i++)
				{
					if (this->vetorAumentar[i].getGlobalBounds().contains(this->mousePosView))
						this->lista.aumQuantItem(i);

					if (this->vetorDiminuir[i].getGlobalBounds().contains(this->mousePosView))
						this->lista.dimQuantItem(i);
				}

				//Botao de finalizar
				if (this->bFinalizarCompra.getGlobalBounds().contains(this->mousePosView))
					this->finalizarCompra();
			}
			break;
		default:
			break;
		}
	}
}

//Functions
void Game::update()
{
	this->pollEvents();

	this->updateText();

	this->mousePos();
}


void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
	target.draw(this->produto);
	target.draw(this->quantidade);
	target.draw(this->price);
	target.draw(this->total);
	target.draw(this->finalcompra);
}

void Game::updateText()
{
	std::stringstream ss;
	ss << "SUPER MARKET UFSCar";
	uiText.setString(ss.str());

	std::stringstream prod;
	prod << "PRODUTO: ";
	produto.setString(prod.str());

	std::stringstream quant;
	quant << "QUANTIDADE: ";
	quantidade.setString(quant.str());

	std::stringstream pri;
	pri << "VALOR: ";
	price.setString(pri.str());

	std::stringstream tot;
	tot << "TOTAL: ";
	total.setString(tot.str());

}

void Game::render()
{
	this->window->clear(sf::Color(149, 149, 149, 255));

	this->window->draw(sprite_fundo);

	//this->window->draw(this->borda_esq);
	//this->window->draw(this->borda_dir);
	//this->window->draw(this->borda_cima);
	//this->window->draw(this->borda_baixo);

	//this->window->draw(this->borda_esq_meio);
	//this->window->draw(this->borda_dir_meio);
	//this->window->draw(this->borda_cima_meio);
	//this->window->draw(this->borda_baixo_meio);

	//this->window->draw(this->linha_meio_1);
	//this->window->draw(this->linha_meio_2);

	//this->window->draw(this->borda_esq_inferior);
	//this->window->draw(this->borda_dir_inferior);
	//this->window->draw(this->borda_cima_inferior);
	//this->window->draw(this->borda_baixo_inferior);

	this->renderBotoes(*this->window);

	//this->window->draw(this->barra_vermelha);
	//this->window->draw(this->sprite_carrinho);
	//this->window->draw(this->sprite_dinheiro);

	this->renderLista(*this->window);




	//this->renderText(*this->window);

	this->window->display();
}

void Game::initLista()
{
	this->tlista.setFont(this->fonte1);
	this->tlista.setPosition(35, 150);
	this->tlista.setCharacterSize(18);
	this->tlista.setFillColor(sf::Color::Black);
	this->tlista.setString("Nome");
}

void Game::renderLista(sf::RenderTarget& target)
{
	if (!this->lista.vazia())
	{
		std::stringstream info;
		ItemLoja aux;
		bool ok;
		float height = 185;
		float total = 0;
		this->lista.getPrim(&aux, &ok);

		info.precision(0);
		info << aux.getNome();
		this->tlista.setString(info.str());
		this->tlista.setPosition(35, height);
		target.draw(tlista);
		info.str("");

		info << aux.getQuantia();
		this->tlista.setString(info.str());
		this->tlista.setPosition(500, height);
		target.draw(tlista);
		info.str("");

		info.precision(2);
		info << std::fixed << aux.getPreco();
		this->tlista.setString(info.str());
		this->tlista.setPosition(900, height);
		target.draw(tlista);
		info.str("");

		total = total + aux.getPreco() * aux.getQuantia();
		this->lista.getProx(&aux, &ok);
		while (ok)
		{
			height = height + 40.f;

			info.precision(0);
			info << aux.getNome();
			this->tlista.setString(info.str());
			this->tlista.setPosition(35.f, height);
			target.draw(tlista);
			info.str("");

			info << aux.getQuantia();
			this->tlista.setString(info.str());
			this->tlista.setPosition(500.f, height);
			target.draw(tlista);
			info.str("");

			info.precision(2);
			info << std::fixed << aux.getPreco();
			this->tlista.setString(info.str());
			this->tlista.setPosition(900.f, height);
			target.draw(tlista);
			info.str("");

			total = total + aux.getPreco() * aux.getQuantia();
			this->lista.getProx(&aux, &ok);
		}

		info.precision(2);
		info << "R$ ";
		info << std::fixed << total;
		this->tlista.setString(info.str());
		this->tlista.setPosition(180.f, 660.f);
		target.draw(tlista);
	}
}

void Game::setLista(listaCad l)
{
	this->lista = l;
}

void Game::initBotoes()
{
	/*Insere o tamanho e o visual dos botões*/
	this->bDiminuir.setSize(sf::Vector2f(20.f, 20.f));
	this->bDiminuir.setFillColor(sf::Color::Red);

	this->bAumentar.setSize(sf::Vector2f(20.f, 20.f));
	this->bAumentar.setFillColor(sf::Color::Green);

	this->bFinalizarCompra.setSize(sf::Vector2f(70.f, 50.f));
	this->bFinalizarCompra.setFillColor(sf::Color::Transparent);
}

void Game::renderBotoes(sf::RenderTarget& target)
{
	/*   Mostra os botões na tela enquanto o botao de finalizar
	nao for pressionado.
	initPosY = posição inicial da coordenada Y para inserir
			   o botão ao lado do número da quantidade
			   (aumenta a cada repetição)
	O botão de finalizar fica na altura do Total da compra
	para a direita.
	*/

	if (!finalizar)
	{
		int i;
		float initPosY = 185;
		for (i = 0; i < this->lista.getnElementos(); i++)
		{
			this->bAumentar.setPosition(540.f, initPosY);
			target.draw(bAumentar);
			this->vetorAumentar.push_back(this->bAumentar);

			this->bDiminuir.setPosition(450.f, initPosY);
			target.draw(bDiminuir);
			this->vetorDiminuir.push_back(this->bDiminuir);

			initPosY += 40;
		}

		//Finalizar compra
		this->bFinalizarCompra.setPosition(925.f, 645.f);
		target.draw(bFinalizarCompra);
	}
}

void Game::mousePos()
{
	//Posicao do mouse referente a janela
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Game::finalizarCompra()
{
	/*  Retira todos os itens da lista que possuirem
		'quantidade' = 0*/
	ItemLoja auxiliar;
	bool ok;

	this->lista.getPrim(&auxiliar, &ok);
	if (auxiliar.getQuantia() == 0)
		lista.retira(auxiliar, &ok);

	while (ok)
	{
		this->lista.getProx(&auxiliar, &ok);
		if (auxiliar.getQuantia() == 0)
			lista.retira(auxiliar, &ok);
	}

	finalizar = true;
}
