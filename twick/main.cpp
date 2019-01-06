
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <time.h>
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(1120, 950), "SPACE ATTACK!!!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3,t4;
    t1.loadFromFile("images/block01.png");
    t2.loadFromFile("images/background.jfif");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");


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

    while (app.isOpen())
    {
       Event e;
       while (app.pollEvent(e))
       {
         if (e.type == Event::Closed)
             app.close();
       }

    x+=dx;
    paddleposition = sP.getPosition();

    for (int i=0;i<n;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(P[i].getGlobalBounds()) )
             {P[i].setPosition(-100,0); dx=-dx;}

    y+=dy;
    for (int i=0;i<n;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(P[i].getGlobalBounds()) )
             {P[i].setPosition(-100,0); dy=-dy;}

    if (x<0 || x>1120)  dx=-dx;
    if (y>940 && y>=paddleposition.x && y<= paddleposition.x+99) dy=-dy;

    if (Keyboard::isKeyPressed(Keyboard::Right)) sP.move(9,0);
    if (Keyboard::isKeyPressed(Keyboard::Left)) sP.move(-9,0);

    if ( FloatRect(x,y,12,12).intersects(sP.getGlobalBounds()) ) dy=-(rand()%7);

    sB.setPosition(x,y);

    app.clear();
    app.draw(sBG);
    app.draw(sB);
    app.draw(sP);

    for (int i=0;i<n;i++)
     app.draw(P[i]);

    app.display();
    }

  return 0;
}

