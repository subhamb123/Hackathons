#include "header.h"
#include "LinkedUsersLite.h"

class Topic {
public:
	Topic();
	Topic(string name, string stories, LinkedUsersLite users);
	explicit Topic(Topic & t);
	   
	string name;
	string stories;
	LinkedUsersLite users;
private:

};