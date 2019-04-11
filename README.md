# custom-snake-game

Tasks for Games28

1.
Make a function that draws a line with a length and line thickness.

The line can be drawn at any location on the screen. 
The line only needs to be axis aligned .  
The function must be in the form : 
        void Drawline(int x, int y, int length, int thickness)
NOTE:  
Parameters x and y  signed integers - meaning they can be either positive or negative. 
Use this to your advantage and think about :
    +x moves in a positive direction
    -x moves in a negative direction
    +y moves in a positive direction
    -y moves in a negative direction
    and the absolute value of x and is the start location

Answer:
void Graphics::DrawLine(int in_x, int in_y, int length, int width)
	{
		for (int y = in_y; y < width; y++)
		{
			for (int x = in_x; x < length; x++)
			{
				PutPixel(x, y, Colors::Blue);
			}
		}
	}
