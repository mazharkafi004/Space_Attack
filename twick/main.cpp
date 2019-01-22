
#include "SFML/Window.hpp"
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




Music music;
Music music2;




bool stopmusic = false;

int gethigh()
    {
        int high;
        std::freopen("save/score.dat","r",stdin);
        std::scanf("%d",&high);
        std::fclose(stdin);
        return high;
    }
void print_high(int high)
{
    std::freopen("save/score.dat","w",stdout);
    std::printf("%d\n",high);
    std::fclose(stdout);
    return ;
}


int main()
{

    int score=0,highscore=gethigh();


    RenderWindow Window(VideoMode(1120, 950), "WALL BREAKER!!!");

    Window.setFramerateLimit(60);
    Font font1;
    Font font2;
    Font font3;
    Font font4;


    Music game_music;

    game_music.openFromFile("music/music.ogg");
    game_music.setVolume(25);
   Music game_music2;
    game_music2.openFromFile("music/GameOVER.ogg");
    game_music2.setVolume(500);
    Music game_music3;
    game_music3.openFromFile("music/awesome.ogg");
    game_music3.setVolume(500);



    if(!stopmusic)
        game_music.play();


    Texture t1,t2,t3,t4,t5;
    t1.loadFromFile("images/block03.png");
    t2.loadFromFile("images/background_1.jpg");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/tui.png");
    t5.loadFromFile("images/menu.jpg");

    font1.loadFromFile("fonts/Denka Demo.ttf");
    font2.loadFromFile("fonts/COLONNA.ttf");
    font3.loadFromFile("fonts/ALGER.ttf");
    font4.loadFromFile("fonts/ARLRDBD.ttf");


    //sf::Clock clock;
    //sf::Clock clock2;
    bool playscreen = false;



    Text h1,m1,m2,m3,m4;
    h1.setFont(font1);
    h1.setCharacterSize(70);
    h1.setPosition(380, 150);
    h1.setFillColor(Color::Red);
    h1.setString("WALL BREAKER");
    h1.setRotation(0);
    h1.Bold;
    h1.Italic;

    h1.setOutlineThickness(10);
    h1.setOutlineColor(Color::White);

    m1.setFont(font3);
    m1.setCharacterSize(50);
    m1.setPosition(510, 300);
    m1.setFillColor(Color::Yellow);
    m1.setString("PLAY");
    m1.setOutlineColor(Color::White);
    m1.setOutlineThickness(2);
    m1.Italic;

    m2.setFont(font3);
    m2.setCharacterSize(50);
    m2.setPosition(510, 600);
    m2.setFillColor(Color::Blue);
    m2.setString("EXIT");
    m2.setOutlineColor(Color::White);
    m2.setOutlineThickness(2);
    m2.Italic;


    m3.setFont(font3);
    m3.setCharacterSize(50);
    m3.setPosition(510, 400);
    m3.setFillColor(Color::Blue);
    m3.setString("MUSIC ON");
    m3.setOutlineColor(Color::White);
    m3.setOutlineThickness(2);
    m3.Italic;


    m4.setFont(font3);
    m4.setCharacterSize(50);
    m4.setPosition(510, 500);
    m4.setFillColor(Color::Blue);
    m4.setString("Highscore");
    m4.setOutlineColor(Color::White);
    m4.setOutlineThickness(2);
    m4.Italic;

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
        FloatRect collision5 = m4.getGlobalBounds();

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
            m2.setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Button::Left))
                //if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                playscreen = false;
                break;
            }
        }
        else
        {
            m2.setFillColor(Color::Green);
        }

        if (collision3.contains(point))
        {
            h1.setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Button::Left))
                //if (Keyboard::isKeyPressed(Keyboard::Down))
            {


            }
        }
        else
        {
            h1.setFillColor(Color::Green);
        }

        if (collision4.contains(point))
        {
            m3.setFillColor(Color::Red);
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
            m3.setFillColor(Color::Green);
        }
        if (collision5.contains(point))
        {
            m3.setFillColor(Color::Red);
            if (Mouse::isButtonPressed(Mouse::Left))
                //if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                string ss="Highscore:  ";
                ss+=to_string(highscore);
                m4.setString(ss);

            }


        }
        else
        {
            m4.setFillColor(Color::Green);
        }



        Window.clear();
         Sprite sBG2(t5);
    Window.draw(sBG2);
        Window.draw(m2);
        Window.draw(h1);
        Window.draw(m3);
        Window.draw(m1);
        Window.draw(m4);

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
    for (int i=1; i<=17; i++)
        for (int j=1; j<=16; j++)
        {
            P[n].setTexture(t1);
            P[n].setPosition(i*60,j*30);
            n++;
        }

    float dx=6, dy=5;
    float x=700, y=900;
    Font font;

    Text high;
    high.setString("Score: 0");
    high.setPosition(00,800);
    high.setFillColor(Color::Cyan);
    high.setCharacterSize(40);
    high.setOutlineThickness(1);
    high.setOutlineColor(Color::Transparent);
    high.setFont(font4);

    Text high2;
    high2.setString("HighScore: %d");
    high2.setPosition(00,760);
    high2.setFillColor(Color::Yellow);
    high2.setCharacterSize(40);
    high2.setOutlineThickness(1);
    high2.setOutlineColor(Color::Black);
    high2.setFont(font4);



    Sprite gameover;
    Texture GMtexture;

    GMtexture.loadFromFile("images/gameover_1.jpg");
    gameover.setTexture(GMtexture);
    gameover.setPosition(1120,950);//2.f -50, 950/2.f);
    gameover.setOrigin(1120, 950);



    while(Window.isOpen())
    {


        Event e;
        while (Window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                Window.close();
        }

        x+=dx;
        paddleposition = sP.getPosition();




        for (int i=0; i<n; i++)
            if ( FloatRect(x+3,y+3,6,6).intersects(P[i].getGlobalBounds()) )
            {
                P[i].setPosition(-100,0);
                dx=-dx;
                hey.openFromFile("sounds/brick1.wav");
                hey.setVolume(100);

                    hey.play();

                score+=10;
                if(score>highscore)
                {
                    highscore=score;
                    print_high(highscore);

                }
            }

        y+=dy;
        for (int i=0; i<n; i++)
            if ( FloatRect(x+3,y+3,6,6).intersects(P[i].getGlobalBounds()) )
            {
                P[i].setPosition(-100,0);
                dy=-dy;
                hey.openFromFile("sounds/brick1.wav");
                hey.setVolume(100);

                    hey.play();

                score+=10;
                if(score>highscore)
                {

                    highscore=score;
                    print_high(highscore);

                    game_music3.play();
                }
            }

        if (x<0 || x>1120)
            dx=-dx;
        if(y<0)
            dy=-dy;







        if (Keyboard::isKeyPressed(Keyboard::Right))
            sP.move(9,0);
        if (Keyboard::isKeyPressed(Keyboard::Left))
            sP.move(-9,0);

        if ( FloatRect(x,y,12,12).intersects(sP.getGlobalBounds()) )
            dy=-(rand()%5+2);

        sB.setPosition(x,y);


        if(y>1120 )
        {
            game_music.stop();




            Window.draw(gameover);
            Window.display();
            Window.clear();


        }
        else
        { game_music2.play();

            Window.draw(sBG);
            Window.draw(sB);
            Window.draw(sP);


            for (int i=0; i<n; i++)
                Window.draw(P[i]);
            string ss="Score: ";
            ss+=to_string(score);
            high.setString(ss);
            Window.draw(high);
            string sd="HighScore: ";
            sd+=to_string(highscore);
            high2.setString(sd);
            Window.draw(high2);
            Window.draw(high);
            Window.display();
            Window.clear();
        }


    }


    return 0;
}
