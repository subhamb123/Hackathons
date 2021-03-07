#include "header.h"
#include "LinkedUsersLite.h"
#include "topic.h"

class program {
public:
	program();
	void runApp();
	userProfile* user();
	userProfile* addUser();
	void editUsers();
	void storeUsers();
	void chat_f();
	void storeChat(userProfile * otherUser);
	int displayMenu();
	void setCurrentUser(userProfile * user = nullptr);
	userProfile* match_score_outside();
	fstream profiles_stream;
	fstream chat_stream;
	LinkedUsersLite users;
	string chat;
	double chat_rating;
	int chat_num;
	Topic topics;
	userProfile* current_user;
};