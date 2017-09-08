#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Frogger.h"
#include "Lanes.h"
#include "Car.h"
#include "logs.h"
#include "Others.h"
#include "base.h"
#include "windows.h"

using namespace std;

void render(sf::RenderWindow& window, Frogger& frog, Lanes& lanes, vector<Car> (&cars)[5], vector<Logs> (&logs)[5], base (&base)[5],bool (&bInBase)[5], Others& others)
{
	window.clear(); // clear the screen
	lanes.lanesDraw(window); // draw the background
	sf::Texture baseTex; // texture of the base frog
	baseTex.loadFromFile("../../assets/base.png"); // image file of the base frog

	for(int i = 0; i < 5; i++) // logs and cars
	{
		for(int j=0; j < logs[i].size(); j++ ) //the amount of logs to draw
		{
			logs[i].at(j).draw(window); // draw the logs
		}
		for(int j=0; j < cars[i].size(); j++ ) //the amount of cars to draw
		{
			cars[i].at(j).draw(window); // draw the cars
		}
	}

	//base
	if(bInBase[0] == true) // frog is in 1st base
	{
		sf::Sprite baseSprite; // sprite
		baseSprite.setTexture(baseTex); //texture of the sprite
		baseSprite.setPosition(16.0f, 64.0f); // the base position
		baseSprite.setScale(2,2); // base sprite scale
		window.draw(baseSprite); // draw the base sprite
	}
	if(bInBase[1] == true) // frog is in 2nd base
	{
		sf::Sprite baseSprite; // sprite
		baseSprite.setTexture(baseTex); //texture of the sprite
		baseSprite.setPosition(112.0f, 64.0f); // the base position
		baseSprite.setScale(2,2); // base sprite scale
		window.draw(baseSprite); // draw the base sprite
	}
	if(bInBase[2] == true) // frog is in 3rd base
	{
		sf::Sprite baseSprite; // sprite
		baseSprite.setTexture(baseTex); //texture of the sprite
		baseSprite.setPosition(208.0f, 64.0f); // the base position
		baseSprite.setScale(2,2); // base sprite scale
		window.draw(baseSprite); // draw the base sprite
	}
	if(bInBase[3] == true) // frog is in 4th base
	{
		sf::Sprite baseSprite; // sprite
		baseSprite.setTexture(baseTex); //texture of the sprite
		baseSprite.setPosition(304.0f, 64.0f); // the base position
		baseSprite.setScale(2,2); // base sprite scale
		window.draw(baseSprite); // draw the base sprite
	}
	if(bInBase[4] == true) // frog is in 5th base
	{
		sf::Sprite baseSprite; // sprite
		baseSprite.setTexture(baseTex); //texture of the sprite
		baseSprite.setPosition(400.0f, 64.0f); // the base position
		baseSprite.setScale(2,2); // base sprite scale
		window.draw(baseSprite); // draw the base sprite
	}
	if(bInBase[0] == true && bInBase[1] == true && bInBase[2] == true && bInBase[3] == true && bInBase[4] == true) // if all the frog is the base win
	{
		// reset the base
		bInBase[0] = false;
		bInBase[1] = false;
		bInBase[2] = false;
		bInBase[3] = false;
		bInBase[4] = false;
	}

	frog.frogDraw(window); //draw frog

	//lives
	if(frog.iGetLifeCounter() == 3) // 3 lives
	{
		others.life3Draw(window);
	}
	if(frog.iGetLifeCounter() == 2 || frog.iGetLifeCounter() == 3) // 2 lives
	{
		others.life2Draw(window);
	}
	if(frog.iGetLifeCounter() == 1 || frog.iGetLifeCounter() == 2 || frog.iGetLifeCounter() == 3 ) // 1 iife
	{
		others.life1Draw(window); // life counter = 1
	}
	if(frog.iGetLifeCounter() == 0) // no lives
	{
		others.GameOverDraw(window); //gameover
	}
	window.display(); // display all of the images and sprites
}
void update(sf::RenderWindow& window, Frogger& frog, vector<Car> (&cars)[5],float delay, float ETime, vector<Logs> (&logs)[5], base (&base)[5],bool (&bInBase)[5],Others& others)
{
	sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close(); //close game
			}
			if (event.type == sf::Event::KeyPressed)
			{
				//frog's movement keys
				if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {frog.frogMovement(Left, window);} //frog moves left
				if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {frog.frogMovement(Down, window);} //frog moves down
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {frog.frogMovement(Right, window);} //frog moves right
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {frog.frogMovement(Up, window);} //frog moves up
			}
		}
		//game over
		if(frog.iGetLifeCounter() == 0) // if no lives
		{
			if(frog.iGetLifeCounter() == 0)
			{
				others.GameOverDraw(window); //gameover screen
			}
			frog.iSetLifeCounter(3); // back to 3 lives
			// reset the the base
			bInBase[0] = false; 
			bInBase[1] = false; 
			bInBase[2] = false; 
			bInBase[3] = false; 
			bInBase[4] = false; 
		}

		//spawning the cars
		int iRandom = rand() % 50 + 1; // random spawning
		//lane 1
		if (iRandom == 1) //the random number
		{
			if(cars[0].size() >0) //vector
			{
				if (ETime - cars[0].back().GetSpawnTime() > 0.8f) // spawn timer after the car has been spawned
				{
					Car car = Car("car.png", 2 /*scale*/,480 /*x*/,418 /*y*/,true /*rotation*/,ETime /*elapsed*/);
					car.SetSpeed(1.7f); // speed
					cars[0].push_back(car);// car in that vector
				}
			}
			else // spawn one if the lane is empty
			{
				Car car = Car("car.png", 2 /*scale*/,480 /*x*/,418 /*y*/,true /*rotation*/,ETime /*elapsed*/);
				car.SetSpeed(1.7f); // speed
				cars[0].push_back(car);
			}
		}
		//lane 2
		if (iRandom == 2)
		{
			if(cars[1].size() >0)
			{
				if (ETime - cars[1].back().GetSpawnTime() > 0.5f) // spawn timer after the car has been spawned
				{
					Car car = Car("car2.png", 2 /*scale*/,-32 /*x*/,386 /*y*/,false /*rotation*/,ETime /*elapsed*/);
					car.SetSpeed(2.0f); // speed
					cars[1].push_back(car);
				}
			}
			else // spawn one if the lane is empty
			{
				Car car = Car("car2.png", 2 /*scale*/,-32 /*x*/,386 /*y*/,false /*rotation*/,ETime /*elapsed*/);
				car.SetSpeed(2.0f); // speed
				cars[1].push_back(car);
			}
		}
		//lane 3
		if (iRandom == 3)
		{
			
			if(cars[2].size() >0)
			{
				if (ETime - cars[2].back().GetSpawnTime() > 0.7f) // spawn timer after the car has been spawned
				{
					Car car = Car("car3.png", 2 /*scale*/,480 /*x*/,354 /*y*/,true /*rotation*/,ETime /*elapsed*/);
					car.SetSpeed(1.5f); // speed
					cars[2].push_back(car);
				}
			}
			else // spawn one if the lane is empty
			{
				Car car = Car("car3.png", 2 /*scale*/,480 /*x*/,354 /*y*/,true /*rotation*/,ETime /*elapsed*/);
				car.SetSpeed(1.5f); // speed
				cars[2].push_back(car);
			}
		}
		//lane 4
		if (iRandom == 4)
		{
			if(cars[3].size() >0)
			{
				if (ETime - cars[3].back().GetSpawnTime() > 0.6f) // spawn timer after the car has been spawned
				{
					Car car = Car("car4.png", 2 /*scale*/,-32 /*x*/,322 /*y*/,false /*rotation*/,ETime /*elapsed*/);
					car.SetSpeed(2.2f); // speed
					cars[3].push_back(car);
				}
			}
			else // spawn one if the lane is empty
			{
				Car car = Car("car4.png", 2 /*scale*/,-32 /*x*/,322 /*y*/,false /*rotation*/,ETime /*elapsed*/);
				car.SetSpeed(2.2f); // speed
				cars[3].push_back(car);
			}
		}
		//lane 5
		if (iRandom == 5)
		{
			if(cars[4].size() >0)
			{
				if (ETime - cars[4].back().GetSpawnTime() > 0.6f) // spawn timer after the car has been spawned
				{
					Car car = Car("truck.png", 2 /*scale*/,480 /*x*/,290 /*y*/,true /*rotation*/,ETime /*elapsed*/);
					car.SetSpeed(2.6f); // speed
					cars[4].push_back(car);
				}
			}
		else // spawn one if the lane is empty
			{
				Car car = Car("truck.png", 2 /*scale*/,480 /*x*/,290 /*y*/,true /*rotation*/,ETime /*elapsed*/);
				car.SetSpeed(2.6f); // speed
				cars[4].push_back(car);
			}
		}

		//spawning the logs
		if (iRandom == 6)
		{
			if(logs[0].size() >0)
			{
				if (ETime - logs[0].back().GetSpawnTime() > 1.6f) // spawn timer after the log has been spawned
				{
					Logs log = Logs("log1.png", 2 /*scale*/,480 /*x*/,102 /*y*/,true /*rotation*/,ETime /*elapsed*/);
					log.SetSpeed(0.25f); // speed
					logs[0].push_back(log);
				}
			}
			else // spawn one if the lane is empty
			{
				Logs log = Logs("log1.png", 2 /*scale*/,480 /*x*/,102 /*y*/,true /*rotation*/,ETime /*elapsed*/);
				log.SetSpeed(0.25f); // speed
				logs[0].push_back(log);
			}
		}
		//lane 2
		if (iRandom == 7)
		{
			if(logs[1].size() >0)
			{
				if (ETime - logs[1].back().GetSpawnTime() > 1.0f) // spawn timer after the log has been spawned
				{
					Logs log = Logs("log1.png", 2 /*scale*/,-32 /*x*/,134 /*y*/,false /*rotation*/,ETime /*elapsed*/);
					log.SetSpeed(0.5f); // speed
					logs[1].push_back(log);
				}
			}
			else // spawn one if the lane is empty
			{
				Logs log = Logs("log1.png", 2 /*scale*/,-32 /*x*/,134 /*y*/,false /*rotation*/,ETime /*elapsed*/);
				log.SetSpeed(0.5f); // speed
				logs[1].push_back(log);
			}
		}
		//lane 3
		if (iRandom == 8)
		{
			if(logs[2].size() >0)
			{
				if (ETime - logs[2].back().GetSpawnTime() > 1.3f) // spawn timer after the log has been spawned
				{
					Logs log = Logs("log1.png", 2 /*scale*/,480/*x*/,166 /*y*/,true /*rotation*/,ETime /*elapsed*/);
					log.SetSpeed(0.27f); // speed
					logs[2].push_back(log);
				}
			}
			else // spawn one if the lane is empty
			{
				Logs log = Logs("log1.png", 2 /*scale*/,480 /*x*/,166 /*y*/,false /*rotation*/,ETime /*elapsed*/);
				log.SetSpeed(0.27f); // speed
				logs[2].push_back(log);
			}
		}
		//lane 4
		if (iRandom == 9)
		{
			if(logs[3].size() >0)
			{
				if (ETime - logs[3].back().GetSpawnTime() > 1.0f) // spawn timer after the log has been spawned
				{
					Logs log = Logs("log1.png", 2 /*scale*/,-32 /*x*/,198 /*y*/,false /*rotation*/,ETime /*elapsed*/);
					log.SetSpeed(0.44f); // speed
					logs[3].push_back(log);
				}
			}
			else // spawn one if the lane is empty
			{
				Logs log = Logs("log1.png", 2 /*scale*/,-32 /*x*/,198 /*y*/,false /*rotation*/,ETime /*elapsed*/);
				log.SetSpeed(0.44f); // speed
				logs[3].push_back(log);
			}
		}
		//lane 5
		if (iRandom == 10)
		{
			if(logs[4].size() >0)
			{
				if (ETime - logs[4].back().GetSpawnTime() > 0.8f) // spawn timer after the log has been spawned
				{
					Logs log = Logs("log1.png", 2 /*scale*/,480 /*x*/,230 /*y*/,true /*rotation*/,ETime /*elapsed*/);
					log.SetSpeed(0.4f); // speed
					logs[4].push_back(log);
				}
			}
		else // spawn one if the lane is empty
			{
				Logs log = Logs("log1.png", 2 /*scale*/,480 /*x*/,230 /*y*/,true /*rotation*/,ETime /*elapsed*/);
				log.SetSpeed(0.4f); // speed
				logs[4].push_back(log);
			}
		}

		//car
		for(int i = 0; i < 5; i++)
		{
			for(int j= cars[i].size()-1; j >= 0; --j ) // i = lanes
			{
				if(cars[i].at(j).IsOffScreen()) // j = cars
				{
					cars[i].erase(cars[i].begin()+j); // delete the cars when it's off screen
				}
			}
			for(int j= 0; j < cars[i].size(); j++ )
			{
				cars[i].at(j).CarsMovement(1.0f * cars[i].at(j).GetSpeed() /*the speed of the cars*/ + delay); // i gets the lane and j gets the cars
				if(frog.Collision(frog.GetFrogBound(),cars[i].at(j).GetCarBound())) // if frog hits car
				{
					frog.setFrogDead(true); // if the frog hits the cars
				}
			}

			//logs
			frog.setOnLog(false); // not on the log

			for(int i = 0; i < 5; i++)
			{
				for(int j= logs[i].size()-1; j >= 0; --j ) // i = lanes
				{
					if(logs[i].at(j).IsOffScreen()) // j = logs
					{
						logs[i].erase(logs[i].begin()+j); // delete the logs when it's off screen
					}
				}
				for(int j= 0; j < logs[i].size(); j++ )
				{
					logs[i].at(j).logsMovement(1.0f * logs[i].at(j).GetSpeed() /*the speed of the logs*/ ); // i gets the lane and j gets the logs
					if(frog.Collision(frog.GetFrogBound(),logs[i].at(j).GetlogBound())) // frog on the logs
					{	
						
						frog.setOnLog(true); // the frog is now on log
						frog.moveOnLog(logs[i].at(j),window); // frog move with the logs
						
					}
				}
			}
			//water death
			if(frog.GetPosition() < 260)
			{
				frog.setFrogDead(true); // if over 260 the frog is dead
				if(frog.getOnLog() == true) // if on log it's safe
				{
					frog.setFrogDead(false); // the frog isn't dead
				}
				else if(frog.getOnLog() == false) // death if not on log
				{
					frog.setFrogDead(true); // dead
				}
			}
		}
		//base
		for(int i = 0; i < 5; i++)
		{
			if(base[i].GetbaseBound().intersects(frog.GetFrogBound(), base[i].GetbaseBound())) // if frog hits the bounding box of the base
			{
				if(bInBase[i] == true) // frog been to base before
				{
					frog.setFrogDead(true); //dead
				}
				else // base has nothing inside it
				{
					//frog.iSetLifeCounter (frog.iGetLifeCounter()+1);
					cout << frog.iGetLifeCounter();
					bInBase[i] = true; // base is now full
					frog.frogDeployment(); // reset frog
				}
			}
		}
}

int main()
{
	sf::RenderWindow GameWindow(sf::VideoMode(448, 512), "Frogger!",sf::Style::Default); // size of the window
	GameWindow.setVerticalSyncEnabled(true); // stops Vertical lagging - vsync Vertical synchronization
	Frogger frog = Frogger(); //frog
	Lanes lanes = Lanes(); // background
	Others others = Others(); // other
	
	vector<Car> vCarsDeployment[5]; // vector for cars
	vector<Logs> vLogsDeployment[5]; // vector for logs

	//bass
	base aBase[5]; // array of base spaces
	//position of the base
	aBase[0] = base(16.0f, 48.0f);
	aBase[1] = base(112.0f, 48.0f);
	aBase[2] = base(208.0f, 48.0f);
	aBase[3] = base(304.0f, 48.0f);
	aBase[4] = base(400.0f, 48.0f);
	bool bInBase[5] = {{false}}; // not in base

	srand(time(0)); // random number
	sf::Clock timer; // makes clock
	const float tick_sec = 1.0f/60.0f; // sets the tick per sec - update the logic e.g updating car movment
	float nextTick = timer.getElapsedTime().asSeconds(); // current time of the clock
	float tick = 0; // total tick at the start

	//game loop timer(gaffer on games)
	while (GameWindow.isOpen()) 
	{
		//time
		float timerNow = timer.getElapsedTime().asSeconds(); // current time in the loop
		float frame = timerNow - nextTick; //times difference between the recorded time
		if (frame > 0.25f) // if the time difference is greater than 1/4 of a second
		{
			frame = 0.25f; // set the time to become 1/4 of a second
		}
		nextTick = timerNow; //Set current time
		tick += frame; //increment ticks by time difference

		while (tick >= tick_sec)
		{
			float interpolation = tick/ tick_sec; // the current tick / the tick per sec (1/60)
			update(GameWindow,frog,vCarsDeployment,interpolation,timerNow,vLogsDeployment,aBase,bInBase,others); // updates the game
			if(frog.getfrogDead() == true) //if frog is dead
			{
				frog.UpdateDeadTimer(frame); // start timer
			}
			tick-=tick_sec;
		}
		
		//draw and display
		render(GameWindow,frog,lanes,vCarsDeployment,vLogsDeployment,aBase,bInBase,others); // draws the sprites and images from render
		if(frog.iGetLifeCounter() == 0) // if life hits 0
		{
			Sleep(3000); // pause the game for 3 secounds for the user to see gameover screen
		}
	}

return 0;
}
