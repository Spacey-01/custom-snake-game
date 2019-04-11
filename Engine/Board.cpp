#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::Drawcell(Location & loc)
{
	//gfx.DrawRectDim(loc.x *dimension + off_x, loc.y * dimension + off_y, dimension, dimension, c);

	gfx.Cargo(loc.x*dimension + off_x, loc.y * dimension + off_y);
}

void Board::FelconUp(Location & loc)
{
	gfx.FUp(loc.x *dimension + off_x, loc.y * dimension + off_y);
}

void Board::FelconDown(Location & loc)
{
	gfx.FDown(loc.x*dimension + off_x, loc.y * dimension + off_y);
}

void Board::FelconLeft(Location & loc)
{
	gfx.FLeft(loc.x*dimension + off_x, loc.y * dimension + off_y);
}

void Board::FelconRight(Location & loc)
{
	gfx.FRight(loc.x*dimension + off_x, loc.y * dimension + off_y);
}

void Board::TFighter(Location & loc)
{
	gfx.TieFighter(loc.x * dimension + off_x, loc.y * dimension + off_y);
}

void Board::Explode(Location & loc)
{
	gfx.Explosion(loc.x* dimension + off_x, loc.y * dimension + off_y);
}

void Board::RegularStar(Location & loc)
{
	gfx.DrawDStar(loc.x* dimension + off_x, loc.y * dimension + off_y);
}

void Board::BrightStar1(Location & loc)
{
	gfx.DrawBrightStar1(loc.x* dimension + off_x, loc.y * dimension + off_y);
}

void Board::BrightStar2(Location & loc)
{
	gfx.DrawBrightStar2(loc.x* dimension + off_x, loc.y * dimension + off_y);
}

bool Board::InsideBoard(const Location & loc) const
{
	return	loc.x >= 0 && loc.x <= width - 1  &&
			loc.y >= 0 && loc.y <= height - 1;
}

void Board::DrawBoundry()
{
	int sprExtPix = 6;

	const int top		= off_y - borderPadding;
	const int left		= off_x - borderPadding;
	const int bottom	= off_y +  height * dimension + borderPadding + sprExtPix;
	const int right		= off_x +  width * dimension + borderPadding + sprExtPix;
	//top
	gfx.DrawRect(left - borderWidth, top, right + borderWidth, top - borderWidth, borderColor);
	//left
	gfx.DrawRect(left, top, left - borderWidth, bottom, borderColor);
	//right
	gfx.DrawRect(right, top , right + borderWidth, bottom, borderColor);
	//bottom
	gfx.DrawRect(left - borderWidth, bottom, right + borderWidth, bottom + borderWidth, borderColor);
}

int Board::Getwidth()
{
	return width;
}

int Board::Getheight()
{
	return height;
}
