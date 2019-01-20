
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;
using namespace sf;

    RenderWindow Window(VideoMode(1120, 950), "WALL BREAKER!!!");


bool isGameOver = false;

int score{ 0 };
int level{ 1 };
int button{ 0 };

Music music;
Music music2;


Texture loading;
Texture texture;

Sprite sprite;


Text points;
Text lvltxt;
Font font;
bool stopmusic = false;





int main()
{

    int Points=0;


    RenderWindow Window(VideoMode(1120, 950), "WALL BREAKER!!!");

    Window.setFramerateLimit(60);
    Font font1;
	Font font2;


    Music game_music;

	game_music.openFromFile("music/music.ogg");
	game_music.setVolume(35);
	Music gameover_music;

	if(!stopmusic) game_music.play();

	loading.loadFromFile("images/gameover.jpg");

	RectangleShape loadingscreen;

	Vector2f size1;
	size1.x = 100, size1.y = 100;
	loadingscreen.setTexture(&loading);
	loadingscreen.setFillColor(Color::White);
	loadingscreen.setScale({ 1,1 });

	Sprite gameover;
	Texture GMtexture;

	GMtexture.loadFromFile("images/gameover_1.jpg");
	gameover.setTexture(GMtexture);
	gameover.setPosition(950/2.f -50, 1120/2.f);
	gameover.setOrigin(202, 180);



    Texture t1,t2,t3,t4;
    t1.loadFromFile("images/block03.png");
    t2.loadFromFile("images/background_1.jpg");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/tui.png");
	texture.loadFromFile("images/score.png");
	font1.loadFromFile("fonts/Denka Demo.ttf");
	font2.loadFromFile("fonts/COLONNA.ttf");
	Vector2u size = texture.getSize();
	sprite.setTexture(texture);


	sf::Clock clock;
	sf::Clock clock2;
	bool playscreen = false;

	Text h1,m1,m2,m3;
	h1.setFont(font1);
	h1.setCharacterSize(60);
	h1.setPosition(400, 150);
	h1.setFillColor(Color::Yellow);
	h1.setString("WALL BREAKER");
	h1.setRotation(0);
	h1.setOutlineThickness(5);
	h1.setOutlineColor(Color::White);

	m1.setFont(font2);
	m1.setCharacterSize(50);
	m1.setPosition(510, 300);
	m1.setFillColor(Color::Blue);
	m1.setString("PLAY");
	m1.setOutlineColor(Color::White);
	m1.setOutlineThickness(2);
	m1.Italic;

	m2.setFont(font2);
	m2.setCharacterSize(50);
	m2.setPosition(510, 500);
	m2.setFillColor(Color::Blue);
	m2.setString("EXIT");
	m2.setOutlineColor(Color::White);
	m2.setOutlineThickness(2);
	m2.Italic;

	m3.setFont(font2);
	m3.setCharacterSize(50);
	m3.setPosition(510, 400);
	m3.setFillColor(Color::Blue);
	m3.setString("MUSIC ON");
	m3.setOutlineColor(Color::White);
	m3.setOutlineThickness(2);
	m3.Italic;

	while (Window.isOpen())
	{
		Event Event;
		while (Window.pollEvent(Event))
		{
			if (Event.type == Event::Closed)
				Window.close();
		}


		FloatRect collision2 = m2.getGlobalBounds();
		FloatRect collision = m1.getGlobalBounds();
		FloatRect collision3 = h1.getGlobalBounds();
		FloatRect collision4 = m3.getGlobalBounds();

		Vector2f point;
		point.x = (float) Mouse::getPosition(Window).x;
		point.y = (float) Mouse::getPosition(Window).y;
		if (collision.contains(point))
		{
			m1.setFillColor(Color::Red);
			//if(Event.type == Event.KeyPressed && Event.KeyPressed==Keyboard::Enter)
			if (Event.type == Event.MouseButtonReleased && Event.mouseButton.button == Mouse::Left)
			{
				playscreen = true;
				break;
			}
		}
		else
		{
			m1.setFillColor(Color::Green);
		}

		if (collision2.contains(point))
		{
			m2.setFillColor(Color::Black);
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			//if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				playscreen = false;
				break;
			}
		}
		else
		{
			m2.setFillColor(Color::Magenta);
		}

		if (collision3.contains(point))
		{
			h1.setFillColor(Color::Yellow);
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			//if (Keyboard::isKeyPressed(Keyboard::Down))
			{

			}
		}
		else
		{
			h1.setFillColor(Color::Black);
		}

		if (collision4.contains(point))
		{
			m3.setFillColor(Color::White);
			if (Mouse::isButtonPressed(Mouse::Left))
			//if (Keyboard::isKeyPressed(Keyboard::Enter))
			{

					m3.setString("MUSIC OFF");
					stopmusic = true;
					game_music.stop();
			}

			//else //if (Keyboard::isKeyPressed(Keyboard::Enter))
            else    if(Mouse::isButtonPressed(Mouse::Right))
			{
				m3.setString("MUSIC ON");
				stopmusic = false;
				game_music.play();
			}
		}
		else
		{
			m3.setFillColor(Color::Red);
		}



		Window.clear();
		Window.draw(m2);
		Window.draw(h1);
		Window.draw(m3);
		Window.draw(m1);
		Window.display();
		if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
		{
			playscreen = true;
			break;
		}

	}



     Music hey;


    Sprite sBG(t2), sB(t3), sP(t4);
    Vector2f paddleposition;
    sP.setPosition(700,940);


    Sprite P[1000];

    int n=0;
    for (int i=1;i<=17;i++)
    for (int j=1;j<=15;j++)
      {
         P[n].setTexture(t1);
         P[n].setPosition(i*60,j*30);
         n++;
      }

    float dx=6, dy=5;
    float x=700, y=940;



	 while(Window.isOpen()) {


       Event e;
       while (Window.pollEvent(e))
       {
         if (e.type == Event::Closed)
             Window.close();
       }

    x+=dx;
    paddleposition = sP.getPosition();




    for (int i=0;i<n;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(P[i].getGlobalBounds()) )
             {P[i].setPosition(-100,0); dx=-dx;
             hey.openFromFile("sounds/brick1.wav");
	hey.setVolume(100);
	if(!stopmusic) hey.play();
             score+=10;}

    y+=dy;
    for (int i=0;i<n;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(P[i].getGlobalBounds()) )
             {P[i].setPosition(-100,0); dy=-dy;
             hey.openFromFile("sounds/brick1.wav");
	hey.setVolume(100);
	if(!stopmusic) hey.play();
               score+=10; }


    if (x<0 || x>1120)  dx=-dx;
    if(y<0) dy=-dy;

//    If(sB.getPosition.y()>1120 ) gameover = true;





    if (Keyboard::isKeyPressed(Keyboard::Right)) sP.move(9,0);
    if (Keyboard::isKeyPressed(Keyboard::Left)) sP.move(-9,0);

    if ( FloatRect(x,y,12,12).intersects(sP.getGlobalBounds()) ) dy=-(rand()%5+2);

    sB.setPosition(x,y);

    Window.clear();
    Window.draw(sBG);
    Window.draw(sB);
    Window.draw(sP);

    for (int i=0;i<n;i++)
     Window.draw(P[i]);

    Window.display();


    }


  return 0;
}
