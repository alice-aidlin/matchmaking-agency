#define _CRT_SECURE_NO_WARNINGS

#include "String.h"

String::String(char* string)
{
	this->string = new char[strlen(string) + 1];//new alloc
	strcpy(this->string,string);//copy string to object by func from string.h
}


String::String(String const& s)
{
	if (s.string)//verify that string is not empty 
	{
		this->string = new char[strlen(s.string)+1];//new alloc
		for (int i = 0; i <( strlen(s.string) + 1); ++i)
			this->string[i] = s.string[i];
	}
	else
		this->string = NULL;
}

String::~String()
{
	if (this->string)//verify that string is not empty 
	{
		delete[] this->string;
		this->string= NULL;
	}
	
}

bool String::operator==(const String& s)const
{
	if (strcmp(this->string, s.string) == 0)//copmer by fanction from string.h
		return true;
	else return false;

}


ostream &operator<<(ostream &out, const String& s)
{
	//verify that string is not empty to avoid access violation
	if (s.string)
	{
		out << s.string;
	}
	return out;
	
}


void String::operator=(const String& s)
{
	if (this->string)//if exist than free
		delete this->string;
	this->string = new char[strlen(s.string) + 1];//new alloc
	for (int i = 0; i < (strlen(s.string) + 1); ++i)
		this->string[i] = s.string[i];
}

