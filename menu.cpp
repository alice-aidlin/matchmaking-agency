#include"Menu.h"
Menu::Menu()
{
	int choice;
	do {
		cout << "please enter your choice" << endl << "1 ) Add a new client  to the database\n2 ) Remove an existing client from the database\n3 ) Print all clients\n4 ) Print all matches for a client \n5 ) Quit the program\n";
		cin >> choice;
		switch (choice)

		{
		case 1:
			add_new_client();
			cout << "\n";
			break;
			case 2:
				remove_client();
				cout << "\n";
				break;
			case 3:
				print_agency();
				cout << "\n";
				break;
			case 4:
				all_matches();
				cout << "\n";
				break;
		case 5:
			match_agency.~MatchmakingAgency();//free allocations
			cout << "good bye";
			cout << "\n";
			break;
		default:cout << "bad input try again\n";
			cout << "\n";
			break;
		}
	} while (choice != 5);
}

void Menu::add_new_client()
{
	int what;
	int gender;
	char name_char[50];
	char id_char[50];
	char hobby[50];
	int age, num_of_hobbies, num_of_common;
	char** hobbies;

	cout << "enter your name" << endl;
	cin.ignore();
	cin.getline(name_char, 50);
	String name(name_char);//to make the nape to string and no char *
	cout << "enter your ID" << endl;
	cin >> id_char;
	String id(id_char);//to make the id to string and no char*
	cout << "enter your gender for female enter 1 for male enter 0" << endl;
	cin >> gender;
	while (gender != 0&&gender != 1)//if enter bad choice
	{
		cout << "bad input try again" << "\n";
		cin >> gender;
	}
	cout << "enter your age, you must to be over 18" << endl;
	cin >> age;
	while (age < 18)//if age under 18
	{
		cout << "you under 18, try again" << "\n";
		cin >> age;
	}
	cout << "enter your number of hobbies" << endl;
	cin >> num_of_hobbies;
	hobbies = new char*[num_of_hobbies];//aloc for hobbies
	for (int i = 0; i < num_of_hobbies; ++i)
	{
		cout << "enter hobby #" << i + 1 << " : ";
		cin >> hobby;
		hobbies[i] = new char[strlen(hobby) + 1];
		strcpy(hobbies[i] , hobby);
		cout << "\n";
	}
	cout << "do you want to upgrade to VIP client? press 1 to yes and 0 for no\n";
	cin >> what;
	if (what == 1)//vip
	{
		cout << "Congratulations now you are a VIP client\n" << endl;
		cout << "enter number of common hobbies you want" << endl;
		cin >> num_of_common;
		while (num_of_common > num_of_hobbies)//cant be more common the hobbies
		{
			cout << "number of common hobbies cant be bigger of the number of your hobbies, try again\n" << endl;
			cin >> num_of_common;
		}
		Vip* new_client = new Vip(id, name, gender, age, hobbies, num_of_hobbies, num_of_common);//new client
		match_agency += *new_client;//add to arry
	}
	
	else//regular
	{
		cout << " you are a regular client" << endl;
		Client* new_client = new Client(id, name, gender, age, hobbies, num_of_hobbies);//alloc new client
		match_agency += *new_client;//add to arr
	}
}

void Menu::remove_client()
{
	char Remove_id[50];
	cout << "enter id to remove client\n";
	cin >> Remove_id;
	String remove_id(Remove_id);//get id in string object
	if (match_agency.if_client_exist( remove_id))//if we have client with this id
	{
		Client temp = this->match_agency.get_client(remove_id);//temp object has the client we want to remove
		this->match_agency -=temp;//remove from arr
		cout << "Client removed!\n" << endl;//massege
	}
	else
	{
		cout << "client not found\n" << endl;//ig client_exist reurn false we dont have this client
	}

	
	
}

void Menu::print_agency()
{
	cout << match_agency;
}
void Menu::all_matches()
{
	char Match_client_id[50];
	cout << "enter id to find match\n";
	cin >> Match_client_id;
	String match_client_id(Match_client_id);//id in string
	cout << "\nyour matches:\n" << endl;
	if (match_agency.if_client_exist(match_client_id))//if this client exixt
	{
		match_agency.print_match(match_client_id);//print the matches for this client
		cout << "\n";
	}

}