#pragma once

#include "UserNode.h"

//not test yet I would say there is a 90% everything works correctly
class LinkedUsersLite
{
public:
	LinkedUsersLite();
	LinkedUsersLite(LinkedUsersLite & l);
	//adds a user profile to the end
	void add(userProfile * u);
	//resets the current pointer to the had
	void resetCurr();
	//for getting the node might not be needed
	UserNode getCurr();
	//use this
	userProfile* getCurrUser();
	//advances the current point one 
	void next();
	//returns true if the current pointer has gone past the end
	bool pastEnd();

	//void removeUserByName();
	//removes the user pointed to by current and movers current to the next user
	UserNode* removeCurr();
	//void destroyAll();
	void printList();

private:
	UserNode* head;
	UserNode* tale;
	UserNode* current;
};

