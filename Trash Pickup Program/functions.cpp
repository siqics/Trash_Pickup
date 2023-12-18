#include "node.h"

// Siqi Wen
// This file contains the implementations of member functions
// in those classes in the .h files. With using these functions,
// the user will be able to insert, remove, retrieve and display
// info of the devices.

// Default constructor, initialize the data member
// to its zero equivalent value.
address::address() : address_info(nullptr), has_a_trash_can(0)
{
}

// Copy constructor, it does a deep copy of the data member.
address::address(const address &source)
{
	// if(address_info)
	// delete []address_info;

	address_info = new char[strlen(source.address_info) + 1];
	strcpy(address_info, source.address_info);
	// has_a_trash_can = source.has_a_trash_can;
}

// Destructor, it deletes dynamic memory and reset the data member
// to its zero equivalent value.
address::~address()
{
	remove_one_address();
}

// This function takes no argument and return nothing.
// It removes the info of an address.
void address::remove_one_address()
{
	if (address_info)
	{
		delete[] address_info;
		address_info = NULL;
	}

	has_a_trash_can = 0;
}

// This function prompts the user for an address and return the success.
// If the data member already has address info, then 2 will be returned,
// this means the client will not be able to input address for this device.
// If the input is valid, then 1 will be returned, if invalid, 0 will be
// returned. The user's input will be stored in the data member.
int address::input_address()
{
	if (address_info)
		return 2;

	char user_input[100];

	cout << "\n\nPlease enter the address for this device: ";
	cin.get(user_input, 100, '\n');
	cin.ignore(100, '\n');

	return add_address(user_input);
}

// This function takes a char pointer and returns an integer.
// It would copy the data from the argument into the data
// member. 1 will be returned for success, 0 will be returned
// for failure.
int address::add_address(char *input_addr)
{
	if (!input_addr)
		return 0;

	address_info = new char[strlen(input_addr) + 1];
	strcpy(address_info, input_addr);

	has_a_trash_can = 0;

	return 1;
}

// This function takes a char pointer as an argument, it would
// compare if the argument and the data member matches, if they
// match, 1 will be returned, if not, 0 will be returned.
int address::compare_address(const char *to_compare) const
{
	if (!address_info)
		return 0;

	if (!strcmp(to_compare, address_info))
		return 1;
	return 0;
}

// This function takes no argument and returns nothing.
// It changes the data member: has_a_trash_can to 1, meaning
// there is a trash can at this address.
void address::add_trash_at_this_address()
{
	has_a_trash_can = 1;
}

// This function takes no argument and returns nothing.
// It changes the data member: has_a_trash_can to 0, meaning
// there is no trash can here.
void address::remove_trash_can_here()
{
	has_a_trash_can = 0;
}

// This function displays the address, it takes no argument,
// and it doesn't return anything.
void address::display_address() const
{
	if (!address_info)
		return;

	cout << "\n\nThe address is: \n"
		 << address_info << "\n\n\n";
}

// This function is the default constructor of the trash_can class.
// It would initialize the data members to their zero equivalent values.
trash_can::trash_can() : fullness(0), id_num(nullptr), nextptr(nullptr)
{
}

// This is the copy constructor of the trash_can class.
// This class manages dynamic memory. The function has
// an initialization list to cause the base class's
// copy constructor to be invoked.
trash_can::trash_can(const trash_can &source) : address(source)
{
	fullness = source.fullness;
	id_num = new char[strlen(source.id_num) + 1];
	strcpy(id_num, source.id_num);

	// NOT SURE
	// nextptr = source.nextptr;
}

// This is the destructor for trash_can class.
trash_can::~trash_can()
{
	del_trash_can();
}

// This function takes no argument and returns nothing.
// It would delete the info of a trash can.
void trash_can::del_trash_can()
{
	fullness = 0;

	if (id_num)
	{
		delete[] id_num;
		id_num = NULL;
	}

	nextptr = NULL;
}

// This function takes no argument and returns a
// pointer by reference.
trash_can *&trash_can::go_nextptr()
{
	return nextptr;
}

// This function takes no arguments and it returns a number.
// It prompts the user to enter some info for a trash can.
// An integer will be returned as the index for the hash table.
int trash_can::add_trashcan(char *input_idnum)
{
	if (!input_idnum)
		return 0;

	id_num = new char[strlen(input_idnum) + 1];
	strcpy(id_num, input_idnum);

	cout << "\n\n\nThe ID number you entered is:   "
		 << id_num << "\n\n\n";

	input_address();

	cout << "\n\n\nNow, enter the fullness.\n"
		 << "Enter 1 if it's full. Enter 0 if it's not full.\n\n\n";
	cin >> fullness;
	cin.ignore(100, '\n');

	return 1;
}

// This function takes a char pointer and returns an integer.
// It would check if there's a match. 1 will be returned if
// there's a match, 0 will be returned otherwise.
int trash_can::find_matching_trashcan(char *some_id) const
{
	if (!some_id)
		return 0;

	if (!strcmp(some_id, id_num))
		return 1;
	return 0;
}

// This function takes a char pointer as an argument, and it returns
// nothing. It would change the data member: fullness based on the
// argument.
void trash_can::change_the_fullness(char input_full)
{
	if (input_full == 'Y' || input_full == 'y')
		fullness = 1;
	else
		fullness = 0;
}

// This function takes no argument and returns an integer. It
// checks if the trash can is full, 1 will be returned if it's
// full; otherwise, 0 will be returned.
int trash_can::is_full() const
{
	if (fullness)
		return 1;
	return 0;
}

// This function takes no argument and returns nothing. It changes
// the data member: fullness to zero.
void trash_can::remove_trash()
{
	fullness = 0;
	cout << "\n\n\nThe trash has been removed.\n\n\n";
}

// This function takes no argument and returns nothing. It displays
// the status of the fullness of the trash can.
void trash_can::display_trash_status() const
{
	cout << "\n\n\nFor Trash Can #" << id_num << ":\n";

	display_address();

	if (fullness)
		cout << "\nIt is FULL!\n\n\n";
	else
		cout << "\nIt is NOT full...\n\n\n";
}

// This is the default constructor of the delivery_car class.
// It will initialize the data member to their default values
// in this class.
delivery_car::delivery_car() : is_at_home(1), is_at_trash_station(0), next(nullptr)
{
}

// The destructor for the delivery_car class.
delivery_car::~delivery_car()
{
	is_at_home = 0;
	is_at_trash_station = 0;
	next = NULL;
}

// This function takes no arguments and returns a pointer
// by reference.
delivery_car *&delivery_car::go_next()
{
	return next;
}

// This function takes a delivery_car pointer as an argument,
// and returns nothing. In this function, we make the pointer
// in the argument point to where the next pointer points to.
void delivery_car::connect_next(delivery_car *&current)
{
	current = next;
}

// This function takes a delivery_car pointer as an argument,
// and returns nothing. In this function, we make the next
// pointer point to where the pointer in the argument points to.
void delivery_car::connect_next_another(delivery_car *temp)
{
	next = temp;
}

// This function takes no argument and returns true or false.
// It checks if the delivery car is ready to delivery, if it
// is, then true will be returned; if not, false will be returned.
bool delivery_car::is_ready() const
{
	if (is_at_home)
		return true;
	return false;
}

// This function takes no arguments and returns nothing. It
// changes the data member: is_at_home to 0, it means the delivery
// car is delivering instead of being at home.
void delivery_car::is_delivering()
{
	is_at_home = 0;
}

// This function takes no arguments and returns nothing. It changes
// the data member: is_at_home to 0 and is_at_trash_station to 1. It
// means the delivery car is at a trash station instead home.
void delivery_car::arrived_at_station()
{
	is_at_home = 0;
	is_at_trash_station = 1;
}

// This function takes no argument and returns nothing.
// It changes the data members that represents the status
// of the delivery car.
void delivery_car::go_home()
{
	is_at_home = 1;
	is_at_trash_station = 0;
}

// This function takes no arguments and returns nothing.
// It displays the status of the delivery car.
void delivery_car::display_car_status() const
{
	cout << "\n\n\nFor this delivery car:\n";
	display_address();

	if (is_at_home)
	{
		cout << "\n\n\nThe delivery car is at home, "
			 << "and it's ready to deliver.\n\n\n";
	}
	else
	{
		cout << "\n\n\nThe delivery car is NOT at home...\n\n\n";
	}
	if (is_at_trash_station)
	{
		cout << "\n\n\nThe delivery car is at a trash "
			 << "station.\n\n\n";
	}
	else
	{
		cout << "\n\n\nThe delivery car is NOT at a trash station.\n\n\n";
	}
}

// This is the default constructor of the pickup_truck class.
// It initializes the data members to their default values.
pickup_truck::pickup_truck() : trash_amount(0), at_station_center(1)
{
}

// This function takes no arguments and returns nothing.
// It changes the data member: at_station_center, which
// represents if the truck is at the station center or
// on the way picking up trash. If it's at the station
// center, then the value is 1; if it's on the way, the
// value is 0.
void pickup_truck::on_the_way()
{
	at_station_center = 0;
}

// This function takes no arguments and returns nothing.
// It calls the display_address function in the address
// class.
void pickup_truck::at_which_station() const
{
	display_address();
}

// This function takes no arguments and returns nothing.
// It changes the data member: at_station_center to 1,
// and it means the truck is back to the station center.
void pickup_truck::finished_one_route()
{
	at_station_center = 1;
}

// This function takes no arguments and returns nothing.
// It displays the amount of trash that the pickup truck
// has picked up.
void pickup_truck::display_amount_trash() const
{
	cout << "\n\n\nThe amount of trash picked up is: "
		 << trash_amount << "\n\n\n\n";
}

// The default constructor for cll class.
// delivery_car * rear;
cll::cll() : rear(nullptr)
{
}

// The destructor for cll class.
cll::~cll()
{
	if (rear)
	{
		delivery_car *current;
		rear->connect_next(current);
		rear->connect_next_another(NULL);

		while (current)
		{
			current->connect_next(rear);
			delete current;
			current = rear;
		}
	}
}

// This function takes no argument and returns nothing.
// It would add a car's information into the CLL.
// Only if the trash can has a car, then implement this.
void cll::insert_a_car()
{

	if (!rear)
	{
		rear = new delivery_car;
		rear->go_next() = rear;
	}
	else
	{
		delivery_car *temp = rear->go_next();
		rear->go_next() = new delivery_car;
		rear = rear->go_next();
		rear->go_next() = temp;
	}

	cout << "\n\n\nNow, you need to enter the address of this car.\n"
		 << "Warning: This car's address needs to be exactly the SAME"
		 << "\nas the trash can's address that you just entered!!\n\n";

	rear->input_address();
	rear->add_trash_at_this_address();

	rear->go_home();
}

// This function takes a char pointer as an argument, it would call
// a recursive function to check if there's a matching car in the CLL,
// if there is, 1 will be returned. Otherwise, 0 will be returned.
// At the end, we would need to reconnect the CLL.
int cll::find_matching_car(char *input_addr)
{
	if (!input_addr || !rear)
		return 0;

	delivery_car *hold_end = rear;

	delivery_car *hold = rear->go_next();
	rear->go_next() = NULL;
	rear = hold;

	int result = find_matching_car(input_addr, rear);

	rear = hold_end;
	rear->go_next() = hold;
	return result;
}

// This function takes a char pointer and a delivery_car pointer as arguments,
// the second argument is passed by reference. It is a recursive function, it
// would look for the matching car in the CLL. 1 will be returned if there's a
// match, 0 will be returned otherwise.
int cll::find_matching_car(char *input_addr, delivery_car *&rear)
{
	if (!rear)
		return 0;

	if (rear->compare_address(input_addr))
	{
		rear->display_car_status();
		return 1;
	}

	return find_matching_car(input_addr, rear->go_next());
}

// This function takes a char pointer as an argument and return 0 if
// nothing was removed, return 1 if we successfully removed a matching
// item. It would call the recursive function. At the end, it would
// reconnect the CLL.
int cll::remove_a_car(char *input_addr)
{
	if (!input_addr || !rear)
		return 0;

	if (!find_matching_car(input_addr))
		return 0;

	delivery_car *hold_end = rear;

	delivery_car *hold = rear->go_next();
	rear->go_next() = NULL;
	rear = hold;

	remove_a_car(input_addr, rear, hold, hold_end);

	if (!hold)
		hold_end = NULL;
	else
	{
		rear = hold_end;
		rear->go_next() = hold;
	}
	return 1;
}

// This function takes a char pointer and three delivery_car pointers as arguments.
// It returns nothing. This is a recursive function, it will only be called if there
// is a match. This function will find the match and delete the match.
void cll::remove_a_car(char *input_addr, delivery_car *&rear, delivery_car *&hold, delivery_car *&hold_end)
{
	if (rear->compare_address(input_addr))
	{
		if (rear == hold)
			hold = rear->go_next();

		delivery_car *temp = rear->go_next();
		delete rear;
		rear = temp;
		return;
	}
	if (rear->go_next() == hold_end)
		hold_end = rear;

	remove_a_car(input_addr, rear->go_next(), hold, hold_end);
}

// This function takes no argument and returns 0 or 1.
// It would call the recursive function to display the
// CLL. 0 will be returned if there is no element in CLL;
// 1 will be returned if there is/are element(s) in the CLL.
int cll::display_cll()
{
	if (!rear)
		return 0;
	delivery_car *hold = rear->go_next();
	rear->go_next() = NULL;
	rear = hold;

	int result = display_cll(rear);

	rear->go_next() = hold;
	return result;
}

// This function takes a delivery_car pointer as an argument,
// it will be passed by reference. 0 or 1 will be returned.
// It would call the function itself recursively. 0 will be
// returned if there is nothing to display, 1 will be returned
// otherwise.
int cll::display_cll(delivery_car *&rear)
{
	if (!rear)
		return 0;
	if (rear)
	{
		rear->display_car_status();
		if (rear->go_next())
			display_cll(rear->go_next());
	}
	return 1;
}

// Constructor - initialize the data members.
table::table(int size)
{
	// Allocate the hash table and initialize each
	// element and data member.
	hash_table = new trash_can *[size];
	for (int i = 0; i < size; ++i)
		hash_table[i] = NULL;
	ht_size = size;
}

// Destructor - release all dynamically allocated memory.
table::~table()
{
	remove_all_ht();
	ht_size = 0;
}

// This function takes no argument, and returns 0 if nothing was
// in the hash table; returns 1 if something was removed from the
// hash table.
int table::remove_all_ht()
{
	int empty = 0;

	for (int i = 0; i < ht_size; ++i)
	{
		if (hash_table[i])
		{
			remove_all_ht_recursion(hash_table[i]);
			hash_table[i] = NULL;

			empty = 1;
		}
	}

	return empty;
}

// This function takes a trash_can pointer as an argument,
// it is passed by reference. This function would delete
// all the trash_can nodes in each element of the array
// in the hash table. Nothing will be returned.
void table::remove_all_ht_recursion(trash_can *&current)
{
	if (!current)
		return;

	trash_can *hold = current->go_nextptr();
	delete current;
	current = hold;

	return remove_all_ht_recursion(current);
}

// This function takes a char pointer and returns an integer.
// It would use the argument to calculate the index for the
// hash table, the index will be returned as the result.
int table::hash_function_table(char *input_idnum)
{
	int len = strlen(input_idnum);

	int result = 0;
	int index = 0;

	for (int i = 0; i < len; ++i)
		result += input_idnum[i];

	index = result % ht_size;
	return index;
}

// This function takes a char pointer and returns an integer.
// It inserts an element into the hash table, 0 will be returned
// for failure; 1 will be returned if we inserted successfully.
int table::insert_hash(char *input_idnum)
{
	if (!input_idnum)
		return 0;

	int index = hash_function_table(input_idnum);

	insert_hash(hash_table[index], input_idnum);

	return 1;
}

// This function takes a trash_can pointer and a char pointer
// as arguments, nothing will be returned. This is a recursive
// function called in the function above.
void table::insert_hash(trash_can *&current, char *input_idnum)
{
	if (!current)
	{
		current = new trash_can;
		current->go_nextptr() = NULL;
		current->add_trashcan(input_idnum);
		return;
	}
	insert_hash(current->go_nextptr(), input_idnum);
}

// This function takes a char pointer and returns an integer.
// It would look for the match. 0 will be returned if there is
// no match; 1 will be returned if match is found.
int table::find_match(char *some_id)
{
	if (!some_id)
		return 0;

	int ind = hash_function_table(some_id);

	return find_match(hash_table[ind], some_id);
}

// This function takes a trash_can pointer and a char pointer
// as arguments. An integer will be returned for success. This
// is a recursive function that is called in the function above.
int table::find_match(trash_can *&current, char *some_id)
{
	if (!current)
		return 0;

	if (current->find_matching_trashcan(some_id))
	{
		current->display_trash_status();
		return 1;
	}

	return find_match(current->go_nextptr(), some_id);
}

// This function takes a char pointer and a char as arguments,
// an integer will be returned for success. It would change
// the fullness of a trash can.
int table::change_fullness_with_id(char *some_id, char input_full)
{
	if (find_match(some_id))
	{
		int ind = hash_function_table(some_id);

		return change_fullness_with_id(hash_table[ind], some_id, input_full);
	}

	return 0; // No matching id number
}

// This function takes a trash_can pointer, a char pointer and a char as arguments.
// It is a recursive function that is called in the function above. 1 will be returned
// for success, otherwise, 0 will be returned.
int table::change_fullness_with_id(trash_can *&current, char *some_id, char input_full)
{
	if (!current)
		return 0;

	if (current->find_matching_trashcan(some_id))
	{
		current->change_the_fullness(input_full);
		return 1;
	}

	return change_fullness_with_id(current->go_nextptr(), some_id, input_full);
}

// This function takes a char pointer as an argument, it would remove
// an element from the hash table. 1 will be returned if we removed
// successfully, otherwise, 0 will be returned.
int table::remove_one_from_table(char *some_id)
{
	if (!some_id)
	{
		cout << "\n\n\nThe input is not valid!\n\n\n";
		return 0;
	}

	int ind = hash_function_table(some_id);

	if (!find_match(hash_table[ind], some_id))
	{
		cout << "\n\n\nThere is no matching trash can...\n\n\n";
		return 0;
	}

	return remove_one_from_table(hash_table[ind], some_id);
}

// This function takes a trash_can pointer and a char pointer
// as arguments, it is a recursive function called by the function above.
// 0 will be returned for failure, 1 will be return if we removed successfully.
int table::remove_one_from_table(trash_can *&current, char *some_id)
{
	if (!current)
		return 0;

	if (current->find_matching_trashcan(some_id))
	{
		trash_can *hold = current->go_nextptr();

		current->del_trash_can();

		current = hold;
		return 1;
	}

	return remove_one_from_table(current->go_nextptr(), some_id);
}

// This function takes no arguments and returns nothing.
// It display all elements in the hash table.
void table::display_all()
{
	for (int i = 0; i < ht_size; ++i)
		display_all(hash_table[i]);
}

// This function takes a trash_can pointer as an argument.
// It returns nothing. It's a recursive function called by
// the function above.
void table::display_all(trash_can *&current)
{
	if (!current)
		return;

	current->display_trash_status();

	return display_all(current->go_nextptr());
}
