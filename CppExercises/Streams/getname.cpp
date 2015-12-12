/* This file contains Task3 of lecture 10 */

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	std::string Greetings (" Hello!");
	std::cout << Greetings << std::endl;
	
	ofstream outFile; // Declare variable
	
	// Prompt the user to enter their first name
	std::cout << " Enter your first name : " << std::endl;
	string firstname_string; // Declare the variable that will store the user's first name
	getline(cin,firstname_string); // using getline() (STL std::string)
	
	// Prompt the user to enter their last name
	std::cout << " Enter your last name : " << std::endl;
	string lastname_string; // Declare the variable that will store the user's last name
	getline(cin, lastname_string); // using getline() (STL std::string)
	
	// Prompt the user to enter their age
	std::cout << " Enter enter your age : " << std::endl;
	int age_int; // Declare the variable that will store the user's age
	std::cin >> age_int;
	std::cin.clear(); // clear any error flag
	std::cin.ignore(80, '\n'); // clears input buffer
	
	
	outFile.open("Identity.txt");
	outFile << " First name : " << "\t" << firstname_string << std::endl;
	outFile << " Last name : " << "\t" << lastname_string << std::endl;
	outFile << " Age : " << "\t" << age_int << std::endl;
	
	outFile.close();

	return 0;
}
