/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek({ 2,2 })
{
	for (int i = 0; i < maxCargo; i++)
	{
		cargos[i].container(rng, brd, snek);
	}
	for (int i = 0; i < maxTie; i++)
	{
		ties[i].tiefighter(rng, brd, snek);
	}
	for (int i = 0; i < maxRegularStars; i++)
	{
		Regularstars[i].StarSet(rng, brd);
	}
	for (int i = 0; i < maxBrightStars; i++)
	{
		Brightstars[i].StarSet(rng, brd);
	}
	wnd.kbd.DisableAutorepeat();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}
static bool keyWasPessed = false;

void Game::UpdateModel()
{
	//debug movement by limiting snek one move per key press
	if (GameIsStarted)
	{
		if (!GameIsOver)
		{

			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				keyWasPessed = true;
				delta_loc = { 0,-1 };
				dir = Direction::UP;
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_loc = { 0,1 };
				dir = Direction::DOWN;

			}
			else if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1, 0 };
				dir = Direction::LEFT;

			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1,0 };
				dir = Direction::RIGHT;

			}



			BrightStarCounter++;
			if (BrightStarCounter >= BrightStarresetMax)
			{
				BrightStarCounter = 0;
			}


			//snek.DirectionUpdate(wnd.kbd);
			Snakeresetcounter++;

			if (Snakeresetcounter == SnakeResetMax)
			{
				Snakeresetcounter = 0;
				const Location next = snek.GetnextHeadLocation(delta_loc);
				for (int i = 0; i < maxTie; i++)
				{

					if (!brd.InsideBoard(next)
						|| snek.InsideTrialExceptEnd(next)
						|| ties[i].Collision(next))
					{
						GameIsOver = true;
					}
				}
				for (int i = 0; i < maxCargo; i++)
				{

					if (snek.GetnextHeadLocation(delta_loc) == cargos[i].getLocation())
					{
						cargos[i].Respawn(rng, brd, snek);
						snek.Grow();

					}

				}
				//corrects the issue moving close to a wall edge
				Keyboard::Event kbdEvent = wnd.kbd.ReadKey();
				if (brd.InsideBoard(next))
				{
					snek.moveby(delta_loc);
					snek.DirectionUpdate(dir);

					keyWasPessed = false;


				}

			}
		}
	}
	else
	{
		GameIsStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}

void Game::ComposeFrame()
{
	if (GameIsStarted)
	{
		

		for (int i = 0; i < maxRegularStars; i++)
		{
			Regularstars[i].DrawDStar(brd);
		}
		for (int i = 0; i < maxBrightStars; i++)
		{
			if (BrightStarCounter > 50)
			{
				Brightstars[i].DrawBrightStar2(brd);
			}
			else if (BrightStarCounter < 50)
			{
				Brightstars[i].DrawBrightStar1(brd);
			}
		}
		for (int i = 0; i < maxCargo; i++)
		{
			cargos[i].Draw(brd);
		}

		for (int i = 0; i < maxTie; i++)
		{
			ties[i].Draw(brd);
			if (ties[i].Collision(snek.GetnextHeadLocation(delta_loc)))
			{
				ties[i].DrawExplode(brd);
			}
			if (GameIsOver)
			{
				Titles::EndImage(350, 265, gfx);
			}
		}
		snek.Draw(brd);



		brd.DrawBoundry();

		Titles::Screentitle(350, 530, gfx);

	}
	else
	{
		Titles::StartImage(350, 265, gfx);
	}
}
