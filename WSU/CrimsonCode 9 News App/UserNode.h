#pragma once

#include "header.h"
#include "userProfile.h"

class UserNode
{
public:
	UserNode();
	userProfile* p;
	UserNode* next;
};