#include "node.h"

// Siqi Wen
// This file contains a test program for the trash can pickup
// program. This test program will complete the missions that
// the user wants by calling different functions we implemented
// in the classes in the .h files based on user's choice from
// the menu.

int main()
{
	welcome();

	int a_task = 0; // Create an int variable for user's choice from menu.

	char input[100];
	char *input_idnum = NULL;
	int vec_size = 0;

	cll car_list;
	table trashcan_list;
	vector<address> the_truck;

	do
	{
		menu(a_task); // Call menu function.

		// Add trash cans, enter info for the trash cans.
		// And enter if it has a delivery car or not.
		if (a_task == 1)
		{
			do
			{
				cout << "\n\n\nEnter the ID number for the trash can."
					 << "\nIt would be some letters combined with numbers: ";

				cin.get(input, 100, '\n');
				cin.ignore(100, '\n');

				input_idnum = new char[strlen(input) + 1];
				strcpy(input_idnum, input);

				if (trashcan_list.insert_hash(input_idnum))
				{
					char answer;
					cout << "\n\n\nYou just added a trash can!\n\n\n"
						 << "\n\n\nDoes this trash can have a delivery"
						 << " car?\n\n\nEnter Y/y for yes, N/n for no.\n\n";
					cin >> answer;
					cin.ignore(100, '\n');

					if (answer == 'Y' || answer == 'y')
					{
						car_list.insert_a_car();
						cout << "\n\n\nYou added a delivery car "
							 << "successfully!\n\n\n";
					}
					else
					{
						cout << "\n\nThis trash can will have no "
							 << "delivery car...\n\n\n";
					}
				}
				else
				{
					cout << "\n\n\nOops, we couldn't add the trash can...\n\n\n";
				}

				cout << "\n\n\nWanna add another trash can?\n\n";

			} while (again());

			// if(input_idnum)
			// delete []input_idnum;
		}

		// Add the addresses the pickup truck will pass.
		else if (a_task == 2)
		{
			do
			{
				address an_address;

				cout << "\n\n\nEnter an address the truck will pass"
					 << " while picking up the trash cans: ";
				cin.get(input, 100, '\n');
				cin.ignore(100, '\n');

				input_idnum = new char[strlen(input) + 1];
				strcpy(input_idnum, input);

				an_address.add_address(input_idnum);

				the_truck.push_back(an_address);

				cout << "\n\n\nWanna add another address the truck will pass?\n\n";

			} while (again());
		}

		// Remove a trash can.
		else if (a_task == 3)
		{
			cout << "\n\n\nEnter the ID number of the trash can "
				 << "you want to delete: ";
			cin.get(input, 100, '\n');
			cin.ignore(100, '\n');

			input_idnum = new char[strlen(input) + 1];
			strcpy(input_idnum, input);

			if (trashcan_list.remove_one_from_table(input_idnum))
				cout << "\n\n\nCongrats!!We removed the trash can"
					 << " with ID: " << input_idnum << "\n\n\n";

			// if(input_idnum)
			// delete []input_idnum;
		}

		// Remove a trash pickup station address.
		else if (a_task == 4)
		{
			cout << "\n\n\nTo remove a trash pickup station, you"
				 << " need to enter an address: ";
			cin.get(input, 100, '\n');
			cin.ignore(100, '\n');

			int removed_already = 0;

			for (int i = 0; i < the_truck.size(); ++i)
			{
				if (!removed_already)
				{
					if (the_truck[i].compare_address(input))
					{
						// the_truck[i].remove_one_address();
						the_truck.erase(the_truck.begin() + i);

						removed_already = 1;
						cout << "\n\n\nCongrats! We removed the address: "
							 << input << "\n\n\n";
					}
				}
			}
			if (!removed_already)
				cout << "\n\n\nSorry, we couldn't remove the"
					 << " address: " << input << "\n\n\n";
		}

		// Check if there is a trash can with a specific ID number.
		else if (a_task == 5)
		{
			cout << "\n\n\nTo look for a specific trash can.\n"
				 << "You need to enter the ID number: \n";

			cin.get(input, 100, '\n');
			cin.ignore(100, '\n');

			strcpy(input_idnum, input);

			if (!trashcan_list.find_match(input_idnum))
			{
				cout << "\n\n\nOops, there is no matching trash can...\n\n\n";
			}
		}

		// Check if there is a car with a specific address.
		else if (a_task == 6)
		{
			cout << "\n\n\nTo check if there is a car with a specific"
				 << " address.\nYou need to enter an address: ";
			cin.get(input, 100, '\n');
			cin.ignore(100, '\n');
			strcpy(input_idnum, input);

			if (!car_list.find_matching_car(input_idnum))
			{
				cout << "\n\n\nOops, we didn't find the matching car...\n\n\n";
			}
		}

		// Check if the truck passes some specific address.
		else if (a_task == 7)
		{
			cout << "\n\n\nTo find a matching address, you need"
				 << " to enter an address: ";
			cin.get(input, 100, '\n');
			cin.ignore(100, '\n');

			vec_size = the_truck.size();

			int matched_already = 0;

			for (int i = 0; i < vec_size; ++i)
			{
				if (!matched_already)
				{
					if (the_truck[i].compare_address(input))
					{
						matched_already = 1;
						cout << "\n\n\nCongrats! We found the matching"
							 << " address: " << input << "\n\n\n";
					}
				}
			}
			if (!matched_already)
				cout << "\n\n\nSorry, there is no matching"
					 << " address...\n\n\n";
		}

		// Display all the trash cans.
		else if (a_task == 8)
		{
			trashcan_list.display_all();
		}

		// Display all the delivery cars.
		else if (a_task == 9)
		{
			if (!car_list.display_cll())
				cout << "\n\n\nThere is no delivery car...\n\n\n";
		}

		// Display all the addresses the truck passes.
		else if (a_task == 10)
		{
			vec_size = the_truck.size();

			for (int i = 0; i < vec_size; ++i)
			{
				the_truck[i].display_address();
			}
		}

		if (a_task != 11)
			cout << "\n\n\nCheck the menu again??\n\n";

	} while (a_task != 11 && again()); // Call again function. Continue until user wants to stop.

	cout << "\n\n\n\nThank you for using our program!"
		 << "\n\nHave a wonderful day!\n\n\n\n\n";

	return 0;
}

// Output the welcome message and explain what the program can do.
void welcome()
{
	cout << "\n\nWelcome to our trash can pickup service program!\n\n"
		 << "In this program, we have three smart devices:\n1. smart "
		 << "trash can;\n2. delivery car;\n3. pickup truck.\n\nThe user"
		 << " will need to enter some specific info as prompted.\nThen "
		 << "the user can choose what they want to do from the options in"
		 << " the menu.\n\n\nAll three smart devices have info of an address."
		 << "\nThis program can check if a trash can needs delivery to a "
		 << "trash pickup station when it's full so that the pickup truck "
		 << "will be able to empty it since the truck has a specific route "
		 << "it goes on.\nIt can check if some trash can is registered "
		 << "based on its ID number so that the user can know if they can use"
		 << " this service or not.\nIt can add a new delivery car's info when "
		 << "the user wants to have a delivery car for their trash can.\nSo on."
		 << "\n\n\n\n\n";
}

// This function asks the user if they want to do it again by
// prompting the user for an input, true or false will be returned.
bool again()
{
	char answer; // Create a character variable
	do
	{
		cout << "\n\n\n\nPlease enter Y/y or N/n: ";
		cin >> answer; // Read in the user's answer.
		cin.ignore(100, '\n');
		answer = toupper(answer); // Convert the character to an uppercase letter
		if (answer != 'Y' && answer != 'N')
			cout << "\n\nYou entered a wrong letter. Please enter Y/y or N/n.";
	} while (answer != 'Y' && answer != 'N'); // continue until the uppercase letter is Y or N
	if (answer == 'Y')						  // This function will return true if answer is Y
		return true;
	return false; // Return false if answer is N
}

// This function takes an integer as an argument and it will show the user the menu, and
// prompts the user to enter a choice in terms of which task the user wants to do.
void menu(int &task)
{
	cout << "\n\n\n\nHere is the menu:\n\n"
		 << "Enter 1 - Add trash cans, enter info for the trash cans.\n\n"
		 << "And enter if it has a delivery car or not.\n\n"
		 << "Enter 2 - Add the addresses the pickup truck will pass.\n\n"
		 << "Enter 3 - Remove a trash can.\n\n"
		 << "Enter 4 - Remove a trash pickup station address. (The truck won't"
		 << " pass this address anymore).\n\n"
		 << "Enter 5 - Check if there is a trash can with a specific ID number.\n\n"
		 << "Enter 6 - Check if there is a car with a specific address.\n\n"
		 << "Enter 7 - Check if the truck passes some specific address.\n\n"
		 << "Enter 8 - Display all the trash cans.\n\n"
		 << "Enter 9 - Display all the delivery cars.\n\n"
		 << "Enter 10 - Display all the addresses the truck passes.\n\n"
		 << "Enter 11 - Exit.\n\n\n\n\n"
		 << "Now, please enter a number (1-11): ";
	do
	{
		cin >> task; // Read in the user's answer.
		cin.ignore(100, '\n');
		if (task < 1 || task > 11)
			cout << "\n\nYou entered a wrong number!\n\nPlease enter "
				 << "a number between 1 and 11(inclusive): ";
	} while (task < 1 || task > 11); // Repeat until user enters a proper number.
}
