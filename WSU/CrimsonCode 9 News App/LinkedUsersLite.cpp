#include "LinkedUsersLite.h"

void LinkedUsersLite::next() {
	if (current != nullptr) {
		current = current->next;
	}
}

bool LinkedUsersLite::pastEnd() {
	return (current == nullptr);
}

void LinkedUsersLite::resetCurr() {
	this->current = this->head; 
}

UserNode LinkedUsersLite::getCurr() {
	return *current;
}

userProfile* LinkedUsersLite::getCurrUser() {
	return current->p;
}

LinkedUsersLite::LinkedUsersLite() {
	this->head = nullptr;
	this->tale = nullptr;
	this->current = nullptr;
}

void LinkedUsersLite::add(userProfile* u) {
	UserNode* node = new UserNode();
	node->p = u;
	if (head == nullptr) {
		this->current = node;
		this->tale = node;
		this->head = node;
	}
	else {
		this->tale->next = node;
		this->tale = tale->next;
	}
}

UserNode* LinkedUsersLite::removeCurr() {
	if (current == nullptr)
	{
		return current;
	}
	else if (current == head) {
		head = head->next;
		UserNode* temp = current;
		current = current->next;
		return temp;
	}
	else {
		UserNode* temp = head;
		while (temp->next != current) {
			temp = temp->next;
		}
		UserNode* temptemp = temp->next;
		temp->next = temp->next->next;
		return temptemp;
	}
}

LinkedUsersLite::LinkedUsersLite(LinkedUsersLite & l){
	this->head = l.head;
	this->tale = l.tale;
	this->current = l.current;
}

// pre: list must not be empty
void LinkedUsersLite::printList(){

	this->resetCurr();
	
	userProfile * currProfile = this->getCurrUser();
	currProfile->print();
	this->next();
	cout << endl;
	while(!this->pastEnd()){
		
		userProfile * currProfile = this->getCurrUser();
		currProfile->print();
		cout << endl;
	
		this->next();
	}
}