
#pragma once
#include <iostream>
#include <string.h> 
#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

#ifndef CLIENT_H
#define CLIENT_H
using namespace std;

class Client
{
public:
	Client(String& ID, String& name, char gender, int age, char** hobbies, int num_of_hobbies);//Ctor
	Client(const Client& c);//CCtor
	~Client();//Dtor
	Client() {};
	friend ostream &operator<<(ostream &out, const Client& c);
	bool operator==(const Client& c)const;
	int get_num_hobbies() const{ return num_of_hobbies; }//get private num of hobbies
	char** get_hobbies()const { return hobbies; }//get the hobbies
	String get_ID()const { return ID; }//get string of id
private:
	String ID;
	String name;
	char gender;
	int age;
	char** hobbies=NULL;
	int num_of_hobbies = 0;
};


#endif