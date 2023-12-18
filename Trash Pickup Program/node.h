#include "trash_pickup.h"

// Siqi Wen
// This file contains two classes. A cll class which contains
// a delivery_car pointer and a table class that contains a
// pointer to a trash_can pointer.

class cll
{
public:
	cll();
	~cll();
	void insert_a_car(); // Only if the trash can has a car, then implement this.
	int find_matching_car(char *input_addr);
	int remove_a_car(char *input_addr);
	int display_cll();

private:
	delivery_car *rear;
	int find_matching_car(char *input_addr, delivery_car *&rear);
	void remove_a_car(char *, delivery_car *&, delivery_car *&, delivery_car *&);
	int display_cll(delivery_car *&rear);
};

// To store each trash can's ID number.
class table
{
public:
	table(int size = 5); // Constructor - initialize the data members.
	~table();			 // Destructor - release all dynamically allocated memory.
	int remove_all_ht();
	int hash_function_table(char *input_idnum);
	int insert_hash(char *input_idnum);
	int find_match(char *some_id);
	int change_fullness_with_id(char *some_id, char input_full);
	int remove_one_from_table(char *some_id);
	void display_all();

private:
	trash_can **hash_table;
	int ht_size;
	void remove_all_ht_recursion(trash_can *&current);
	void insert_hash(trash_can *&current, char *input_idnum);
	int find_match(trash_can *&current, char *some_id);
	int change_fullness_with_id(trash_can *&current, char *some_id, char input_full);
	int remove_one_from_table(trash_can *&current, char *some_id);
	void display_all(trash_can *&current);
};
