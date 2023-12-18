#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

// Siqi Wen
// This file contains four classes that form a hierarchy. The base class is address,
// and the derived classes are trash_can, car and truck. Each class has its own
// responsibilities. The responsibilities of the base class(address) is: read in
// address; change address; compare addresses and display address. It also has a
// copy constructor since it manages dynamic memory. The data members are an array
// of characters and an integer showing if it has a trash_can or not. The trash_can
// class deals with checking if the trash can is full; making sure if some trash can
// is registered and can use this service; checking if it needs to be delivered somewhere
// to be picked up; and display the status of the trash can. The car class deals with
// checking if the car is ready to deliver; checking if it's on the way or arrived, and
// so on. The truck class deals with checking if it's on the way for picking up trash;
// figuring out which station it is at currently; checking if it's finished one route;
// display the amount of trash it picked up. It has two data members: an integer
// representing the amount of trash picked up and an integer showing if the truck is
// at station center or not.

class address
{
public:
	address();
	address(const address &source); // copy constructor
	~address();

	void remove_one_address();
	int input_address();
	int add_address(char *input_addr);
	int compare_address(const char *) const;
	void add_trash_at_this_address();
	void remove_trash_can_here();
	void display_address() const;

protected:
	char *address_info;
	int has_a_trash_can;
};

// hash table
class trash_can : public address
{
public:
	trash_can();
	trash_can(const trash_can &source); // copy constructor
	~trash_can();

	void del_trash_can();

	trash_can *&go_nextptr();

	int add_trashcan(char *input_idnum);

	int find_matching_trashcan(char *some_id) const;

	void change_the_fullness(char input_full);
	int is_full() const;
	void remove_trash();
	void display_trash_status() const;

protected:
	int fullness; // the fullness of the trash can
	char *id_num;
	trash_can *nextptr; // for array of LLL
};

// CLL
class delivery_car : public address
{
public:
	delivery_car();
	~delivery_car();
	delivery_car *&go_next();
	void connect_next(delivery_car *&current);
	void connect_next_another(delivery_car *temp);
	bool is_ready() const;
	void is_delivering();
	void go_home();
	void arrived_at_station();
	void display_car_status() const;

protected:
	int is_at_home;			 // whether it's at home or not
	int is_at_trash_station; // whether it's at a trash station or not
	delivery_car *next;		 // for CLL
};

// vector
class pickup_truck : public address
{
public:
	pickup_truck(); // default constructor
	void on_the_way();
	void at_which_station() const;
	void finished_one_route();
	void display_amount_trash() const;

protected:
	int trash_amount; // the amount of trash picked up
	int at_station_center;
};

// Prototypes
void welcome();		  // Output the welcome message.
bool again();		  // Ask if the user wants to do again.
void menu(int &task); // Show the user the menu.
