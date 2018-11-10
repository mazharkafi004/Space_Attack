
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <time.h>
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(520, 450), "SPACE ATTACK!!!");
    app.setFramerateLimit(60);

    Texture t1,t2,t3,t4;
    t1.loadFromFile("images/block01.png");
    t2.loadFromFile("images/background.jfif");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");


    Sprite sBG(t2), sB(t3), sP(t4);
    Vector2f paddleposition;
    sP.setPosition(300,440);


    Sprite P[1000];

    int n=0;
    for (int i=1;i<=10;i++)
    for (int j=1;j<=10;j++)
      {
         P[n].setTexture(t1);
         P[n].setPosition(i*43,j*20);
         n++;
      }

    float dx=6, dy=5;
    float x=300, y=300;

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

    if (x<0 || x>520)  dx=-dx;
    if (y>440 && y>=paddleposition.x && y<= paddleposition.x+99) dy=-dy;

    if (Keyboard::isKeyPressed(Keyboard::Right)) sP.move(6,0);
    if (Keyboard::isKeyPressed(Keyboard::Left)) sP.move(-6,0);

    if ( FloatRect(x,y,12,12).intersects(sP.getGlobalBounds()) ) dy=-(rand()%5+2);

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

