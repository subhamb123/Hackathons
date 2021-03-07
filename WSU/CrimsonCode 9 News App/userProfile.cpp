#include "userProfile.h"

userProfile::userProfile() {
	name = "";
	region = "";
	age = 0;
	for (int i = 0; i < 5; i++) {
		ratings[i] = 1;
		interests[i] = false;
	}
}

void userProfile::print(){
	cout << name << endl << region << endl << "age: " << age << endl;
}