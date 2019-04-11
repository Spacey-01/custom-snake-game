#pragma once

#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void Drawcell(Location& loc);
	void FelconUp(Location& loc);
	void FelconDown(Location& loc);
	void FelconLeft(Location& loc);
	void FelconRight(Location& loc);
	void TFighter(Location& loc);
	void Explode(Location& loc);
	void RegularStar(Location& loc);
	void BrightStar1(Location& loc);
	void BrightStar2(Location& loc);
	bool InsideBoard(const Location& loc) const;
	void DrawBoundry();
	int Getwidth();
	int Getheight();
private:
	static constexpr int dimension = 20;	//cargo width OR height
	static constexpr int width = 32;		//number of cells x-axis
	static constexpr int height = 24;		//number cells y-axis
	static constexpr int x = 70;			//origin boarder x-axis
	static constexpr int y = 50;			//origin boarder y-axis
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr Color borderColor = Colors::Yellow;
	const int off_x = x;// +borderWidth + borderPadding;
	const int off_y = y;// +borderWidth + borderPadding;
	Graphics& gfx;
};