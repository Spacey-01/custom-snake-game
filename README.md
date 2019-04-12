# custom-snake-game

Tasks for Games28

1.
Drawline func parameters:
Void Drawline(unsigned int x, unsigned int y, int length, bool isVerticle, Color c)

Remember for this case we are only either drawing a line parallel to the x-axis 

or the y-axis. We do NOT need a sloped line.
    

Answer:

void Drawline(unsigned int x, unsigned int y,  unsigned int length, bool isVerticle, Color c)

{

        if(isVerticle)
	
        {
	
                for (int i = y ; i < y+ length; i++)
		
                       putpixel(x,i,c);  // draws vertical line as " i " is changing in the " y " axis
		       
        } 
	
        else 
	
        {
	
                for (int i = x; i < x + length; i++)
		
                        putpixel(i,y,c);  //draws horizontal line and " i " changing the " x " axis
			
        }
	
}
	
