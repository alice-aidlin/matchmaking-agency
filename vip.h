#pragma once
#include <iostream>
#include <string.h> 
#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include "Client.h"
#ifndef VIP_H
#define VIP_H
using namespace std;

class Vip : public Client
{
public:
	Vip(String& ID, String& name, char gender, int age, char** hobbies, int num_of_hobbies, int num_of_common_hobbies) :
		Client(ID, name, gender, age, hobbies, num_of_hobbies)
	{
		this->num_of_common_hobbies = num_of_common_hobbies;
	};//Ctor
	~Vip() {};
	Vip() {};
	Vip(const Vip& v) :Client(v) 
	{
		num_of_common_hobbies = v.num_of_common_hobbies;
	}
	bool operator==(const Vip& v)const;


private:
	int num_of_common_hobbies = 0;
};







#endif