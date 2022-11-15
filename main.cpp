/**
 * @file main.cpp
 * @ingroup MalAarCal
 * @authors Aaron Jarnes, Caleb Carter, Malik Robinson
 * @brief Primary file for game loop
 * @date 10-24-2022
 */
#include "header.h"
//#include "Game.h"

int main()
{
       
    
    
    RenderWindow Window(VideoMode(240,200), "Game",Style::Default);
    
    bool nojump = true;
    
    int x = -240;
    int x2 = -340;
    RectangleShape obs;
    RectangleShape plat;
    Texture obst;
    Texture platt;
    platt.loadFromFile("sprites/floatingPlatform.png");
    obst.loadFromFile("sprites/Spike-1.png");
    //obs.setFillColor(Color(0,0,0));
    obs.setSize(Vector2f(20,20));
    obs.setTexture(&obst);
    obs.setOrigin(x,-130);
    plat.setSize(Vector2f(20,20));
    plat.setOrigin(x2, -100);
    plat.setTexture(&platt);
    
   

    Objects floor;
    Objects player;
    Objects BackGround;
    BackGround.makeBackground(240);
    player.makePlayer();
    floor.makeFloor(120);
    bool start = false;

 
    while(Window.isOpen())
    {
        Event e;
        while(Window.pollEvent(e))
        {
            if(e.type == e.Closed)
            {
                Window.close();
            }
        }

        if(start == false)
        {
            while(start == false)
                {
                    while(Window.pollEvent(e))
                    {
                        if(e.type == e.Closed)
                        {
                            Window.close();
                        }
                    }
                    RectangleShape Gamestart;
                    Texture startg;
                    startg.loadFromFile("startgame.png");
                    Gamestart.setFillColor(Color::Blue);
                    Gamestart.setTexture(&startg);
                    Gamestart.setSize(Vector2f(240,200));
                    Gamestart.setOrigin(0,0);
                    Window.clear();
                    Window.draw(Gamestart);
                    Window.display();
                    if(Keyboard::isKeyPressed(Keyboard::Key::Enter))
                    {
                        start = true;
                    }
                    

                }

        }
        Window.clear();
        srand(time(nullptr));
        int mrand = rand()%10;
        
    
        if(x > 0 and mrand%2==0)
        {
            x=-240;
            
        }
        if(x > 0 and mrand%2!=0)
        {
            x = -400;
        } 
        if(x2 > 0)
        {
            x2 = -340;
        }
        floor.moveFloor(120);
        BackGround.moveBackground();

        

       if(Keyboard::isKeyPressed(Keyboard::Key::Down))
       {   
             
             player.ptext2.loadFromFile("sprites/psycho.png");
             player.Player.setTexture(&player.ptext2);

       }
       if(!Keyboard::isKeyPressed(Keyboard::Key::Down))
       {
            player.Player.setTexture(&player.ptext);
       }
       
        player.jump(-70,10,10, x2, nojump);
        Window.draw(BackGround.background);
        Window.draw(BackGround.background2);
        Window.draw(player.Player);
        obs.setOrigin(x, -130);
        Window.draw(obs);


        
        Window.draw(floor.one);
        Window.draw(floor.two);
        Window.draw(floor.three); 
        plat.setOrigin(x2,-100);
        Window.draw(plat);
        

        Window.display();
        


        
        
        x += 10;
        
       
        x2 += 5;
        
        
       if(player.playerX == x and player.playerY < -100)
       {
            while(!Keyboard::isKeyPressed(Keyboard::Key::S))
            {
                while(Window.pollEvent(e))
                {
                    if(e.type == e.Closed)
                    {
                        Window.close();
                    }
                }
                RectangleShape Gameover;
                Texture over;
                over.loadFromFile("gameover.png");
                Gameover.setTexture(&over);
                Gameover.setFillColor(Color::Red);
                Gameover.setSize(Vector2f(240,200));
                Gameover.setOrigin(0,0);
                Window.clear();
                Window.draw(Gameover);
                Window.display();     

            }
            start = false;
       }
        
        usleep(55000);
        
    }
        

    //initilize variables
    /*
    Game game(522, 522, "Trig Trot");
    
    
    
    Objects Player;
    //adjust initial variables
    Player.player.setOrigin(Player.player.getRadius(), Player.player.getRadius());
    //Player.player.setPosition(game.getWindowSize("x"), game.getWindowSize("y"));
    Player.player.setFillColor(Color::Green);

    //game loop
    while (game.isRunning()){
        //checks events
        game.events();
        //adjust player's movement
        
        //render updates to window
        //game.update(player, platform1, platform2, platform3);
    }
    */
    
 
    

    return 0;
}
