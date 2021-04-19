#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"MatchmakingAgency.h"

#ifndef MENU_H
#define MENU_H
using namespace std;

class Menu
{
public:
	Menu();
private:
	void print_agency();
	void remove_client();
	void add_new_client();
	void all_matches();
	MatchmakingAgency match_agency;
};





#endif
