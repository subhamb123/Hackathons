#pragma once

#include "header.h"

class userProfile {
public:
	userProfile();
	void print();
	string name;
	string region;
	int ratings[5];
	bool interests[5];
	int age;
};

