#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

#ifndef STRING_H
#define STRING_H
using namespace std;

class String
{
public:
	String(char* sentence);//Ctor
	String() {}//def Ctor
	String(const String& s);//CCtor 
	~String();//dctor
	bool operator==(const String& s)const;//object that not change need to be send by const reference
	void operator=(const String& s);//operator assgiment
	String set_(char* name) { return String(name); }
	
	
	friend ostream &operator<<(ostream &out,const String& s);

private:
	char* string = NULL;
};








#endif