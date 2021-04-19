#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"
Client::Client(String& ID, String& name, char gender, int age, char** hobbies, int num_of_hobbies)
{
	this->ID.operator=(ID);//this->ID=ID;we have deep copying because of CCtor
	this->name = name;//we have deep copying because of CCtor
	this->gender = gender;//char
	this->age = age;
	this->num_of_hobbies = num_of_hobbies;
	if (num_of_hobbies)
	{
		this->hobbies = new char*[num_of_hobbies];//dinamic alloc
		for (int i = 0; i < num_of_hobbies; ++i)
		{
			this->hobbies[i] = new char[strlen(hobbies[i]) + 1];
			strcpy(this->hobbies[i], hobbies[i]);
		}
	}

}

Client::Client(const Client& c)//cctor deep copying with alloc
{
	this->ID = c.ID;
	this->name = c.name;
	this->gender = c.gender;
	this->age = c.age;
	this->num_of_hobbies = c.num_of_hobbies;
	if (num_of_hobbies>0)
	{
		this->hobbies = new char*[num_of_hobbies];
		for (int i = 0; i < num_of_hobbies; ++i)
		{
			this->hobbies[i] = new char[strlen(c.hobbies[i]) + 1];
			strcpy(this->hobbies[i], c.hobbies[i]);
		}
	}
}

Client::~Client()//dcor
{
		if (this->hobbies&&num_of_hobbies > 0)
		{
			for (int i = 0; i < num_of_hobbies; ++i)
				delete hobbies[i];
			delete hobbies;
		}
}

ostream &operator<<(ostream &out, const Client& c)//prit operator
{
	out <<  "NAME: " << c.name <<endl<< "ID: " << c.ID << endl << "GENDER: ";
	if (c.gender == 1)//if f
		out << "female" << endl;
	else
		out << "male" << endl;//if m
	out<<"AGE: " << c.age << endl << "HOBBIES: " << endl;

	for (int i = 0; i < c.num_of_hobbies; ++i)
	{
		out << "hobby number " << i+1 << " : ";

		out << c.hobbies[i];

		out << endl;
	}
	
	return out;

}

bool Client::operator==(const Client& c)const
{
	if (this->gender == c.gender)//if same gender false
		return false;
	if (abs(this->age - c.age) > 5)//if older mor then 5 yaers false
		return false;
	for(int i=0;i<this->num_of_hobbies;++i)
		for (int j = 0; j < c.num_of_hobbies; ++j)
		{
			if (!(strcmp(this->hobbies[i], c.hobbies[j])))//if not false and find match true
				return true;
		}
	return false;//if not true and there is no match
}
