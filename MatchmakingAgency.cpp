#include"MatchmakingAgency.h"

MatchmakingAgency::~MatchmakingAgency()
{
	if (this->arry_of_clients)//if arr exist
	{
		for (int i = 0; i < this->size_of_arry; ++i)
			delete this->arry_of_clients[i];//free every clint

		delete[] arry_of_clients;//free arry
	}
}
void MatchmakingAgency::print_match(String& ID)const
{
	int index,counter=0;//index for find the client place, counter to know if there is a match
	for (int i = 0; i < this->size_of_arry; ++i)
	{
		if (this->arry_of_clients[i]->get_ID() == ID)//find the ckient by the id
		{
			index = i;//client place
			i = this->size_of_arry;//find client and end loop
		}
	}
	
	for (int j = 0; j < this->size_of_arry; ++j)
	{
		if (this->arry_of_clients[index]->operator==(*this->arry_of_clients[j]) == true) //if operatur == return true and find match print the match
		{
			cout << *this->arry_of_clients[j] << endl;
			++counter;//count for matches
		}	
	}
	if (counter == 0)//if no match found print messege
		cout << "no match found\n" << endl;
}

ostream &operator<<(ostream &out, const MatchmakingAgency& m)
{
	if (m.size_of_arry == 0)//if no clients print messege
		out << "no clients exist"<<endl;
	else //print arry of clients
	{
		for (int i = 0; i < m.size_of_arry; ++i)
			out << *m.arry_of_clients[i] << "\n" << endl;
	}
	return out;
}

bool MatchmakingAgency::operator+=(const Client& c)
{
	if (this->size_of_arry == 0)//if no arry
	{
		Client* temp = new Client(c);//new alloc of client
		++this->size_of_arry;
		this->arry_of_clients = new Client*[this->size_of_arry];
		this->arry_of_clients[0] = temp;
	}
	else
	{
		Client** tempArry = new Client*[++this->size_of_arry];//new arry with new size
		for(int i=0;i<this->size_of_arry-1;++i)//copy untel the last client
		{
			tempArry[i] = this->arry_of_clients[i];
		}
		delete[]this->arry_of_clients;
		this->arry_of_clients = tempArry;
		Client* temp = new Client(c);
		this->arry_of_clients[this->size_of_arry-1] = temp;//add new client in the last plase
	}
	return true;
}

bool MatchmakingAgency::operator+=(const Vip& v)
{
	if (this->size_of_arry == 0)//if no clients
	{
		Client* temp = new Vip(v);//dinamic alloc for global obgect
		++this->size_of_arry;
		this->arry_of_clients = new Client*[this->size_of_arry];
		this->arry_of_clients[0] = temp;
	}
	else
	{
		Client** tempArry = new Client*[++this->size_of_arry];//new arry with new size
		for(int i=0;i<this->size_of_arry-1;++i)
		{
			tempArry[i] = this->arry_of_clients[i];
		}
		delete[]this->arry_of_clients;
		this->arry_of_clients = tempArry;
		Vip* temp = new Vip(v);
		this->arry_of_clients[this->size_of_arry-1] = temp;
	}
	return true;
}

bool MatchmakingAgency::operator-=(const Client& c)

{
	int index;
	if (this->size_of_arry == 0)//if no arry
	{
		return false;//no found clients
	}
	else
	{
		for (int i = 0; i <this->size_of_arry;++i )
			if (this->arry_of_clients[i]->get_ID() == c.get_ID())//find the index of the client
			{
				index = i;
				delete this->arry_of_clients[i];//free the client we want to remove
				i = this->size_of_arry;//end loop

			}
			
				Client** tempArry = new Client*[this->size_of_arry-1];//new arry without the client
				for (int j = 0; j < index; ++j)//copy until the client we want to remove
				{
					tempArry[j] = this->arry_of_clients[j];
				}
				for (int k = index + 1; k < this->size_of_arry; ++k)//copy from the next client after the client we want to remove
				{
					tempArry[k-1] = this->arry_of_clients[k];
				}
					this->size_of_arry -= 1;
					delete[]this->arry_of_clients;
					this->arry_of_clients = tempArry;
					return true;
				
		
	}
}

Client MatchmakingAgency::get_client(String& const id)//to get the client we search
{
	for (int i = 0; i < this->size_of_arry; ++i)
	{
		if (this->arry_of_clients[i]->get_ID() == id)//find by id
			return *arry_of_clients[i];
	}
	
}

bool MatchmakingAgency::if_client_exist(String& const id)//to know if our clint exist
{
	for (int i = 0; i < this->size_of_arry; ++i)
	{
		if (this->arry_of_clients[i]->get_ID() == id)//find by id
			return true;
	}
	return false;
}

