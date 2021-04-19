#pragma once
#include <iostream>
#include <string.h> 
#define _CRT_SECURE_NO_WARNINGS
#ifndef MATCHMAKINGAGENCY_H
#define MATCHMAKINGAGENCY_H
using namespace std;
#include "string.h"
#include "client.h"
#include"vip.h"

class MatchmakingAgency
{
public:
	MatchmakingAgency() {}
	~MatchmakingAgency();
	void print_match(String& ID)const;
	friend ostream &operator<<(ostream &out, const MatchmakingAgency& m);
	bool operator+=(const Client& c);
	bool operator-=(const Client& c);
	bool operator+=(const Vip& v);
	Client get_client(String& const id);
	bool if_client_exist(String& const id);


private:
	Client** arry_of_clients = NULL;

	int size_of_arry = 0;
};






#endif