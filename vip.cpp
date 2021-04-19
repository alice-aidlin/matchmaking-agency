#define _CRT_SECURE_NO_WARNINGS
#include "vip.h"


bool Vip::operator==(const Vip& v)const
{
	int counter = 0;
	if ((Client::operator==(v)) == false)//if no even 1 common hobbie
		return false;
	else 
		for (int i = 0; i < this->get_num_hobbies(); ++i)
		{
			for (int j = 0; j < v.get_num_hobbies(); ++j)
			{
				if ((strcmp(this->get_hobbies()[i], v.get_hobbies()[j])==0))//if found match
					++counter;//to count common hobbies
			}
		
		}
	if (counter < this->num_of_common_hobbies)//if less common hobbies then ask
		return false;
	else return true;
}