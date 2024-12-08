#include<iostream>
#include"share.h"
#include"link_list.h"
#include"link_list_shares.h"

using namespace std;

class user
{
	
	string username;
	double balance;
	link_list_shares users_shares;

public:
	user();
	user(string);
	void set_balance(double);
	double get_balance();
	string get_username();
	void buy(link_list *l);
	void display_users_shares();
	void sell();
	void prediction();


};

