
#include  <string>
#include <iostream>
#include  "BoardH.h"
#include  "ListBoardObjectsH.h"

using namespace std;


void touch_all (pListBoardObjects aList)
{
	pBoardObject toIterate;

	toIterate=aList->theFirst();

	while (NULL!=toIterate)
	{
		toIterate->touch();

		//cerr << "Touching "<< toIterate->get_x() <<"," <<toIterate->get_y() << std::endl;
		toIterate=aList->theNext();

	}

}

char game_all (pListBoardObjects aList)
{
	
	pBoardObject toIterate;

	toIterate=aList->theFirst();

	ObjectColours color =  BACKGROUND;

	while (NULL!=toIterate)
	{
		if ( BACKGROUND != toIterate->getColor() )
		   color=toIterate->getColor();

		toIterate=aList->theNext();
	}

	switch (color)
	{	case YELLOW : return 'Y';
	 	case BLACK : return '#';
	 	case BLUE : return 'B';
	 	case RED : return 'R';
	 	case INVISIBLE : return 'I';
	 	case BACKGROUND : return '*';
	}
}

void Board:: move(char command)
{
	if ('p'!=command)
	{
	  switch (command)
	   { case 'e': if (playerId_x<=0) break;
			else
			  { 
                            if (!  mySpace[playerId_x-1][playerId_y]->isThereAWall())
			      { mySpace[playerId_x][playerId_y]->removeOnePlayer();
			        playerId_x--;
			        startPlayer = new Player(playerId_x,playerId_y);
                                mySpace[playerId_x][playerId_y]->addOne(startPlayer);

                              }
			  }
		     break;
	     case 'x': if (playerId_x>=the_rows-1) break;
			else
			  { 
                            if (!  mySpace[playerId_x+1][playerI_y]->isThereAWall())
			      { mySpace[playerId_x][playerId_y]->removeOnePlayer();
			        playerId_x++;
			        startPlayer = new Player(playerId_x,playerId_y);
                                mySpace[playerId_x][playerId_y]->addOne(startPlayer);
                              }
			  }
		     break;
	     case 's': if (playerId_y<=0) break;
			else
			  { 
                            if (!  mySpace[playerId_x][playerId_y-1]->isThereAWall())
			      { mySpace[playerId_x][playerId_y]->removeOnePlayer();
			        playerId_y--;
			        startPlayer = new Player(playerId_x,playerId_y);
                                mySpace[playerId_x][playerId_y]->addOne(startPlayer);
                              }
			  }
		     break;
	     case 'd': if (player_id_y>=the_cols-1) break;
                       else
			  { 
                            if (!  mySpace[playerId_x][playerId_y+1]->isThereAWall())
			      { mySpace[playerId_x][playerId_y]->removeOnePlayer();
			        playerId_y++;
			        startPlayer = new Player(playerId_x,playerId_y);
                                mySpace[playerId_x][playerId_y]->addOne(startPlayer);
                              }
			  }
		     break;
	   }
	   int cookieValue = mySpace[playerId_x][playerId_y]->isCookieValue();
	   if (cookieValue>0)
		{
		    std::cerr << "Ate a cookie\n";
		    currentScore+=cookieValue;
		}

	}
}

void Board:: paint()
	{ char draw;
          std::string row;

          for (int i=0; i<the_rows; i++)
	   { row="";
	     for (int j=0; j<the_cols; j++)
		{  touch_all (mySpace[i][j]);
		   draw =game_all(mySpace[i][j]);
		   row.push_back(draw);
		}
              cout << row << endl;
           }
	   cout << "CURRENT SCORE : "<< currentScore << endl;
	}

