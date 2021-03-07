#include "header.h"
#include "program.h"
#include "LinkedUsersLite.h"
#include "userProfile.h"

//pre: l must contain at least one user after where curr points to
//Kelsi can you finish this it should return a higher score the more different they are.
double compare_users(userProfile* p1, userProfile* p2)
{
	int age_1 = p1->age;
	int age_2 = p2->age;
	double match_score_age;
	if (age_1 >= age_2)
	{
		match_score_age = ((double)age_1 - (double) age_2) / (double)age_1;
	}
	else
	{
		match_score_age = ((double)age_2 - (double) age_1) / (double)age_2;
	}

	string region_1 = p1->region;
	string region_2 = p2->region;
	int match_score_region;
	if (region_1 == region_2)
	{
		match_score_region = 0;
	}
	else
	{
		match_score_region = 1;
	}

	int political_leaning_1 = p1->ratings[0];
	int political_leaning_2 = p2->ratings[0];
	double match_score_political_leaning;
	if (political_leaning_1 >= political_leaning_2)
	{
		match_score_political_leaning = (double)political_leaning_1 - (double)political_leaning_2;
	}
	else
	{
		match_score_political_leaning = (double)political_leaning_2 - (double)political_leaning_1;
	}

	return match_score_political_leaning + match_score_region + match_score_age;
}

program::program() {
	users = LinkedUsersLite();
	chat = "";

	string temp_stories = "";
	temp_stories += "IMF ";
	temp_stories += "federal reserve";
	topics = (Topic("Monitary policy", temp_stories, users));
	chat_num = 0;

}

void program::runApp() {
	int option = 0;
	userProfile* profile;

	cout << "Hello!" << endl << endl;

	profile = user();

	cout << endl;

	while (option != 5) {
		option = this->displayMenu();
		switch (option) {
		case 1:
			editUsers();
			cout << endl;
			break;
		case 2:
			users.printList();
			cout << endl;
			break;
		case 3:
			storeUsers();
			cout << endl;
			break;
		case 4:
			chat_f();
			cout << endl;
			break;
		case 5:
			storeUsers();
			cout << endl << "Goodbye!" << endl << endl;
			break;
		default:
			cout << endl << "Invalid input!" << endl << endl;
			break;
		}
	}
}

userProfile* program::user() {
	profiles_stream.open("profiles.txt", ios::in);
	userProfile* newUser;


	while (!profiles_stream.eof()) {
		newUser = new userProfile();
		profiles_stream >> newUser->name;
		profiles_stream >> newUser->region;
		for (int i = 0; i < 5; i++)
			profiles_stream >> newUser->ratings[i];
		for (int i = 0; i < 5; i++) {
			int temp = 0;
			profiles_stream >> temp;
			newUser->interests[i] = (bool) temp;
		}
		profiles_stream >> newUser->age;
		users.add(newUser);
	}

	users.resetCurr();

	int option = 0;
	userProfile* profile = nullptr;
	string name = "";

	while (option != 1 && option != 2) {
		cout << "Choose from the following menu:" << endl << endl;
		cout << "1. Add user" << endl;
		cout << "2. Select current user" << endl << endl;
		cin >> option;
	}

	switch (option) {
	case 1:
		profile = addUser();
		break;
	case 2:
		users.printList();
		do {
			users.resetCurr();
			cout << "Type the username" << endl;
			cin >> name;
			while (!users.pastEnd() && users.getCurrUser()->name != name) {
				users.next();
			}
			if (!users.pastEnd()) {
				profile = users.getCurrUser();
			}
			else {
				cout << "no Such user." << endl;
			}
		} while (users.pastEnd());

		users.resetCurr();
		break;
	}

	profiles_stream.close();
	this->current_user = profile;
	return profile;
}

//feel free to improve the catagories
userProfile* program::addUser() {
	userProfile* newUser = new userProfile();
	cout << "Enter a name: ";
	cin >> newUser->name;
	cout << "enter an age: ";
	cin >> newUser->age;
	cout << "enter a region: ";
	cin >> newUser->region;
	cout << "rank the following 1-5: " << endl;
	cout << "\tpolitical idiology 1 right wing 5 left wing" << endl;
	cin >> newUser->ratings[0];
	cout << "\tUS intervetnion in the middle east 1 good 5 bad" << endl;
	cin >> newUser->ratings[1];
	cout << "\tCOVAX intitive	1 very effective 5 not very effective" << endl;
	cin >> newUser->ratings[2];
	cout << "\tNormalization of ties with Isreal amoung middle eastern countries 1 like 5 dislike." << endl;
	cin >> newUser->ratings[3];
	cout << "\tThe Nigerian governments compating armed groups. 1 it is doing an effective job, 5 it is doing an ineffective job" << endl;
	cin >> newUser->ratings[4];
	cout << "enter a 1 if you like, zero if you dislike: " << endl;
	cout << "\tsports" << endl;
	cin >> newUser->interests[0];
	cout << "\tpolitics" << endl;
	cin >> newUser->interests[1];
	cout << "\ttv/movies" << endl;
	cin >> newUser->interests[2];
	cout << "\tbirds" << endl;
	cin >> newUser->interests[3];
	cout << "\tcargoshipping" << endl;
	cin >> newUser->interests[4];
	this->users.add(newUser);
	return newUser;
}

void program::editUsers() {
	string temp = "";
	int temp2 = 0;

	users.printList();
	
	do {
		users.resetCurr();
		cout << "Type the first name" << endl;
		cin >> temp;
		while (!users.pastEnd() && users.getCurrUser()->name != temp) {
			users.next();
		}
		if (users.pastEnd()) {
			cout << "no Such user." << endl;
		}
	} while (users.pastEnd());

	users.resetCurr();

	cout << "Edit name (Type ! to skip)" << endl;
	cin >> temp;
	if (temp != "!")
		users.getCurrUser()->name = temp;

	cout << "Edit age (Enter a negative number to skip)" << endl;
	cin >> temp2;
	if (temp2 >= 0)
		users.getCurrUser()->age = temp2;

	cout << "Edit region (Type ! to skip)" << endl;
	cin >> temp;
	if (temp != "!")
		users.getCurrUser()->region = temp;

	cout << "Edit ranking of the following 1-5: (Enter invalid number to skip)" << endl;

	cout << "\tpolitical idiology 1 right wing 5 left wing" << endl;
	cin >> temp2;
	if (temp2 >= 1 && temp2 <= 5)
		users.getCurrUser()->ratings[0] = temp2;

	cout << "\tUS intervetnion in the middle east 1 good 5 bad" << endl;
	cin >> temp2;
	if (temp2 >= 1 && temp2 <= 5)
		users.getCurrUser()->ratings[1] = temp2;

	cout << "\tCOVAX intitive 1 very effective 5 not very effective" << endl;
	cin >> temp2;
	if (temp2 >= 1 && temp2 <= 5)
		users.getCurrUser()->ratings[2] = temp2;

	cout << "\tNormalization of ties with Isreal amoung middle eastern countries 1 like 5 dislike." << endl;
	cin >> temp2;
	if (temp2 >= 1 && temp2 <= 5)
		users.getCurrUser()->ratings[3] = temp2;

	cout << "\tThe Nigerian governments compating armed groups. 1 it is doing an effective job, 5 it is doing an ineffective job" << endl;
	cin >> temp2;
	if (temp2 >= 1 && temp2 <= 5)
		users.getCurrUser()->ratings[4] = temp2;

	cout << "enter a 1 if you like, zero if you dislike: (Enter invalid number to skip)" << endl;
	cout << "\tsports" << endl;
	cin >> temp2;
	if (temp2 == 0 || temp2 == 1)
		users.getCurrUser()->interests[0] = temp2;

	cout << "\tpolitics" << endl;
	cin >> temp2;
	if (temp2 == 0 || temp2 == 1)
		users.getCurrUser()->interests[1] = temp2;

	cout << "\ttv/movies" << endl;
	cin >> temp2;
	if (temp2 == 0 || temp2 == 1)
		users.getCurrUser()->interests[2] = temp2;

	cout << "\tbirds" << endl;
	cin >> temp2;
	if (temp2 == 0 || temp2 == 1)
		users.getCurrUser()->interests[3] = temp2;

	cout << "\tcargoshipping" << endl;
	cin >> temp2;
	if (temp2 == 0 || temp2 == 1)
		users.getCurrUser()->interests[4] = temp2;

	users.resetCurr();
}

void program::storeUsers() {
	profiles_stream.open("profiles.txt", ios::out);
	//you need this before you start iterating
	users.resetCurr();
	while (!users.pastEnd()) {
		profiles_stream << users.getCurrUser()->name << endl << users.getCurrUser()->region << endl;
		for (int i = 0; i < 5; i++)
			profiles_stream << users.getCurrUser()->ratings[i] << endl;
		for (int i = 0; i < 5; i++)
			profiles_stream << users.getCurrUser()->interests[i] << endl;
		profiles_stream << users.getCurrUser()->age << endl << endl;
		users.next();
	}

	users.resetCurr();

	profiles_stream.close();
}

void program::storeChat(userProfile * otherUser) {
	string temp = "chat" + chat_num;
	temp +=".txt";
	chat_stream.open(temp.c_str(), ios::out);
	chat_num++;
	chat_stream << current_user->name << "&" << otherUser->name << endl;
	chat_stream << this->chat<<endl;
	chat_stream << chat_rating<<endl;
	chat_stream.close();
}

int program::displayMenu() {
	int option = 0;

	cout << "Choose from the following menu:" << endl << endl;
	cout << "1. Edit users" << endl;
	cout << "2. Display users" << endl;
	cout << "3. Save current users" << endl;
	cout << "4. Navigate to subject" << endl;
	cout << "5. Exit" << endl << endl;
	cin >> option;

	return option;
}

userProfile* program::match_score_outside() {
	users.resetCurr();
	userProfile* toReturn = nullptr;
	double max_diff = -1.0;
	while (!users.pastEnd()) {
		if (users.getCurrUser() != current_user) {
			double temp_diff = compare_users(this->current_user, users.getCurrUser());
			if (temp_diff > max_diff) {
				max_diff = temp_diff;
			}
			toReturn = users.getCurrUser();
		}
	}
	return toReturn;
}

void program::setCurrentUser(userProfile* user) {
	if (user == nullptr) {
		users.resetCurr();
		this->current_user = users.getCurrUser();
	}
	else {
		this->current_user = user;
	}
}

void program::chat_f(){
	userProfile* other = this->match_score_outside();
	char line[500] = "";

}