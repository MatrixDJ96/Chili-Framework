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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

void Game::DrawCrosshair(int offset_x, int offset_y, Color color = Colors::White)
{
	gfx.PutPixel(offset_x + 5, offset_y, color);
	gfx.PutPixel(offset_x + 4, offset_y, color);
	gfx.PutPixel(offset_x + 3, offset_y, color);
	gfx.PutPixel(offset_x - 3, offset_y, color);
	gfx.PutPixel(offset_x - 4, offset_y, color);
	gfx.PutPixel(offset_x - 5, offset_y, color);

	gfx.PutPixel(offset_x, offset_y + 5, color);
	gfx.PutPixel(offset_x, offset_y + 4, color);
	gfx.PutPixel(offset_x, offset_y + 3, color);
	gfx.PutPixel(offset_x, offset_y - 3, color);
	gfx.PutPixel(offset_x, offset_y - 4, color);
	gfx.PutPixel(offset_x, offset_y - 5, color);
}

void Game::DrawCrosshairSquare(int offset_x, int offset_y, Color color = Colors::White)
{
	// LT
	gfx.PutPixel(offset_x - 5, offset_y - 5, color);

	gfx.PutPixel(offset_x - 4, offset_y - 5, color);
	gfx.PutPixel(offset_x - 3, offset_y - 5, color);

	gfx.PutPixel(offset_x - 5, offset_y - 4, color);
	gfx.PutPixel(offset_x - 5, offset_y - 3, color);

	// RT
	gfx.PutPixel(offset_x - 5, offset_y + 5, color);

	gfx.PutPixel(offset_x - 4, offset_y + 5, color);
	gfx.PutPixel(offset_x - 3, offset_y + 5, color);

	gfx.PutPixel(offset_x - 5, offset_y + 4, color);
	gfx.PutPixel(offset_x - 5, offset_y + 3, color);

	// RB
	gfx.PutPixel(offset_x + 5, offset_y + 5, color);

	gfx.PutPixel(offset_x + 4, offset_y + 5, color);
	gfx.PutPixel(offset_x + 3, offset_y + 5, color);
						  
	gfx.PutPixel(offset_x + 5, offset_y + 4, color);
	gfx.PutPixel(offset_x + 5, offset_y + 3, color);

	// LB
	gfx.PutPixel(offset_x + 5, offset_y - 5, color);

	gfx.PutPixel(offset_x + 4, offset_y - 5, color);
	gfx.PutPixel(offset_x + 3, offset_y - 5, color);
										
	gfx.PutPixel(offset_x + 5, offset_y - 4, color);
	gfx.PutPixel(offset_x + 5, offset_y - 3, color);

}

void Game::ComposeFrame()
{
	const Color color = wnd.kbd.KeyIsPressed(VK_CONTROL) ? Colors::Red : Colors::White;
	const bool shape = wnd.kbd.KeyIsPressed(VK_SHIFT);

	int offset_x = 400;
	int offset_y = 300;

	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		offset_y -= 50;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		offset_y += 50;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		offset_x -= 50;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		offset_x += 50;
	}

	if (shape) {
		DrawCrosshairSquare(offset_x, offset_y, color);
	}
	else {
		DrawCrosshair(offset_x, offset_y, color);
	}
}
