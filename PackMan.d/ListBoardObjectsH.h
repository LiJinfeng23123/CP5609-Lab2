#include <vector>
#include  "BoardObjectH.h"
#include  "PlayerH.h"
#include  "CookieH.h"
#ifndef H_LIST_OF_OBJECTS
#define H_LIST_OF_OBJECTS
typedef BoardObject* pBoardObject;


Aclass  ListBoardObjects
{
	std::vector <pBoardObject> list;
	std::vector < pBoardObject>::iterator internalIterator;
public:
	ListBoardObjects(pBoardObject theFirst);

	p_BoardObject theFirst();
	p_BoardObject theNext();
	void addOne(p_BoardObject newOne);
	void removeOnePlayer();
	bool isThereAWall();
	int isCookieValue();
};
#endif
