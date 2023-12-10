/* Employee Management - project
-> Write Employee Record 
-> Read Employee Record
-> Delete Employee Record
-> Get Deleted Records
*/

// header files

#include<iostream>
// input and output file
#include<fstream>
// manipulating the format of input and output streams.
#include<iomanip> 
// involve memory allocation, random number generation, 
// and other general-purpose functions.
#include<stdlib.h>

using namespace std;

//function declaration

void project();
void addData();
void displayData();
void deleteData();
void getTrash();

// Employee class

class Employee

{
	// member variables
	int employeeNo;
	char ename[20];
	char egender;
	int emp;
	float emarks;
	double epercentage;

	// member functions

public:
	
	void getData();
	void showData();
	int getAdmno()
	{
		return employeeNo;
	}

}s; // object of class employee

// Main functions

int main()
{
	project();

	return 0;
}

void project()
{
	int ch;

	do

	{	
		// clear screen
		system("cls");

		// Showing choices on console
		cout << "************** EMPLOYEE MANAGEMENT SYSTEM ***************\n";

		cout << "1. Write Employee Record\n";

		cout << "2. Read Employee Record\n";

		cout << "3. Delete Employee Record\n";

		cout << "4. Get Deleted Employee Records\n";

		cout << "0. Exit\n";

		cout << "Enter your choice: ";

		// Input the choice (ch), reading data from the keyboard by using cin object
		cin >> ch;

		system("cls");

		// check what user's choice and invode the funtions I created before
		switch (ch)
		{
			case 1: addData(); // add employee data to file - emp.txt
				break;

			case 2: displayData();  // read data from file - emp.txt
				break;

			case 3: deleteData(); // remove data from - emp.txt and store in Trash.txt  
				break;

			case 4: getTrash();  // add data from Trash.txt to emp.txt
				break;
		}

		system("pause");

	} while(ch);
}

// Will get the data from console

void Employee::getData()
{
	cout << "\n\n*******Enter Employee Data*******\n";

	cout << "Employee No.: "; cin >> employeeNo;

	cout << "Full Name: "; cin.ignore(); cin.getline(ename, 20);

	cout << "Gender (M/F): "; cin >> egender;

	cout << "Class: "; cin >> emp;

	cout << "Total Marks (/500): "; cin >> emarks;

	cout << endl;

	epercentage = emarks * 100.0 / 500.00;
}

// Will display the data to console in a well-formatted manner

void Employee::showData()
{

	cout << "\n\n*******Employee Details*******\n";

	cout << "EmployeeNo No.: " << employeeNo << endl;

	cout << "Full Name: " << ename << endl;

	cout << "Gender: " << egender << endl;

	cout << "Class: " << emp << endl;

	cout << "Total Marks (/500): " << emarks << endl;

	cout << "Percentage: " << epercentage << endl;

	cout << endl;

}

// Write the data in the file and close it

void addData()
{	
	// fout means the name of the output file, meaning write data into file
	ofstream fout;

	// binary mean non-readable data
	fout.open("Emp.txt", ios::out | ios::app | ios::binary);

	// get data from console and store in s object
	s.getData();

	// read( (char *) & s, sizeof(s));
	// write( (char *) & s, sizeof(s));
	// s - object to write data to file
	// write data in file - Emp.txt
	fout.write((char*)&s, sizeof(s));

	// close the file - write in memory
	fout.close();

	cout << "\n\n*******Data Successfully Saved to File*******\n";

}

// Read the data

void displayData()
{
	// read data from ifstream object, fin is the name of the file.
	ifstream fin; // input stream

	// read binary data
	// open file in input mode
	fin.open("Emp.txt", ios::in | ios::binary); 

	// read file
	while (fin.read((char*)&s, sizeof(s))) 
	{
		// will show data on console
		s.showData(); 

	}

	// close the file after operation
	fin.close(); 

	cout << "\n\n******Data Reading from File Successfully Done*****\n";

}

// delete data from file - Emp.txt

void deleteData() 
{

	int n, flag = 0;

	ifstream fin;

	// file output and trash output
	ofstream fout, tout;

	// open Emp.txt in input mode
	fin.open("Emp.txt", ios::in | ios::binary); 

	// open Temp.txt in append mode
	fout.open("Temp.txt", ios::out | ios::app | ios::binary); 

	// open Trash.txt in append mode
	tout.open("Trash.txt", ios::out | ios::app | ios::binary); 

	cout << "Enter Admission Number : ";

	cin >> n;


	// read the file Emp.txt
	while (fin.read((char*)&s, sizeof(s))) 
	{
		if (n == s.getAdmno())
		{

			cout << "This Record " << n << " has been sent to Trash:\n";

			// display the content on console
			s.showData();

			// write data to TRASH.txt
			tout.write((char*)&s, sizeof(s)); 

			flag++;

		}

		else
		{
			// write data to TEMP.txt
			fout.write((char*)&s, sizeof(s)); 

		}

	}

	fout.close();

	tout.close();

	fin.close();

	//close all files

	if (flag == 0) // if no record found
		cout << "� �" << n << "No Record found*****\n\n";

	// delete Emp.txt
	remove("Emp.txt");

	// rename temp.txt - Emp.txt
	rename("Temp.txt", "Emp.txt"); 

}

// Trash function

void getTrash()

{	
	// open file in input mode
	ifstream fin; 

	fin.open("Trash.txt", ios::in | ios::binary);

	// read data from file
	while (fin.read((char*)&s, sizeof(s)))
	{
		// display data on console
		s.showData(); 

	}

	// close file
	fin.close(); 

	cout << "\n\n*******Data Reading from Trash File Successfully Done*****\n";

}