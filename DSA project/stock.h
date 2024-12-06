#include<iostream>
#include<string>
#include<cmath>
#include<random>
using namespace std;

class stock
{
	double price,preprice;
	float percentage;
	string name;

public:
	stock();
	stock(string,int);
	void set_new_price();
	double get_price();
	void set_percentage();
	double get_percentage();

	

};

