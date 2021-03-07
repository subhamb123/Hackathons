#include "topic.h"

Topic::Topic(){
	this->name = "defult name";
	this->stories = "";
	this->users = LinkedUsersLite();
}

Topic::Topic(string name, string stories, LinkedUsersLite users){
	this->name = name;
	this->stories = stories;
	this->users = users;
}

Topic::Topic(Topic & t){
	this->name = t.name;
	this->stories = t.stories;
	this->users = t.users;
}