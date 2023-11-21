#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void printHeader();
void loginPage();
string signPage(int option);
void adminMenu();
void customerMenu();

int newCount = 0, deviceCount = 6;
string devices[10] = {"Macbook", "Mobile", "Laptop", "Smart Watch", "Gaming PC", "HandsFree"};
double devicePrices[10] = {150000, 100000, 80000, 10000, 200000, 2000};
string newName[100], newPassword[100], role[100];

int main()
{
	while (true)
	{
		printHeader();
		cout << endl
			 << endl
			 << endl;
		int opt;
		loginPage();
		cout << "Enter the option...";
		cin >> opt;
		string userRole = signPage(opt);

		if (userRole == "Admin")
		{
			adminMenu();
		}
		else if (userRole == "Customer")
		{
			customerMenu();
		}
		else if(userRole == "Thanks for coming here.")
		{
			system("cls");
			printHeader();
			cout << userRole;
			break;
		}
		else{
			cout << userRole;
		}
		cout << endl
			 << "Press any Key to continue..";
		getch();
		system("cls");
	}
	return 0;
}

void printHeader()
{
	cout << "___________________________________________________________________________________________________________________________" << endl;
	cout << "|                                                                                                                         |" << endl;
	cout << "|                                                                                                                         |" << endl;
	cout << "|                              ____  _   _ _____ ___ _  ___   _   _____ _____ ____ _   _                                  |" << endl;
	cout << "|                             | ___|| | | | ____|_ _| |/ | | | | |_   _| ____| ___| | | |                                 |" << endl;
	cout << "|                             |___ || |_| |  _|  | || ' /| |_| |   | | |  _| | |  | |_| |                                 |" << endl;
	cout << "|                              ___)||  _  | |___ | || . \\|  _  |   | | | |__ | |__|  _  |                                 |" << endl;
	cout << "|                             |____||_| |_|_____|___|_|\\_|_| |_|   |_| |_____|____|_| |_|                                 |" << endl;
	cout << "|                                                                                                                         |" << endl;
	cout << "|                                                                                                                         |" << endl;
	cout << "|                                                                                                                         |" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
}
void loginPage()
{
	cout << "1. Sign In" << endl;
	cout << "2. Sign Up" << endl;
	cout << "3. Exit" << endl
		 << endl;
}

string signPage(int option)
{
	system("cls");
	printHeader();
	cout << endl
		 << endl
		 << endl;
	if (option == 1)
	{
		string Name, Password;
		cout << "Enter Username: ";
		cin >> Name;
		cout << "Enter Password: ";
		cin >> Password;
		for (int j = 0; j < 100; j++)
		{
			if (Name == newName[j] && Password == newPassword[j])
			{
				system("cls");
				return role[j];
			}
		}
		return "You are not registered yet.";
	}
	if (option == 2)
	{
		cout << "Enter Username: ";
		cin >> newName[newCount];
		cout << "Enter Password: ";
		cin >> newPassword[newCount];
		cout << "Enter your role (Admin/Customer): ";
		cin >> role[newCount];
		cout << endl;
		newCount++;
		return "You have successfully registered.";
	}
	if (option == 3)
	{
		system("cls");
		return "Thanks for coming here.";
	}
}

void adminMenu()
{
	int choice = 1;
	string cdPrice;
	double changedPrice;
	while (choice != 0)
	{
		system("cls");
		printHeader();
		cout << "You have successfully logged in as an Admin.";
		cout << endl
			 << endl
			 << endl;
		cout << "Enter 1 to check already present devices with their prices." << endl;
		cout << "Enter 2 to Add new Device " << endl;
		cout << "Enter 3 to Change Prices of Device " << endl;
		cout << "Enter 4 to Give Discounts " << endl;
		cout << "Enter 5 to Order the Stock " << endl;
		cout << "Enter 0 to escape the matrix" << endl
			 << endl;

		cout << "Enter your choice... ";
		cin >> choice;

		system("cls");
		printHeader();

		switch (choice)
		{
		case 1:
			cout << "Following is the list of devices with their prices." << endl
				 << endl;
			for (int i = 0; i < deviceCount; i++)
			{
				cout << "The price for " << devices[i] << " is " << devicePrices[i] << endl;
			}
			break;
		case 2:
			cout << "Enter the name of the device: ";
			cin >> devices[deviceCount];
			cout << "Enter the price for this device: ";
			cin >> devicePrices[deviceCount];
			deviceCount++;
			break;
		case 3:
			cout << "Enter the name of the device of which you want to change price...";
			cin >> cdPrice;
			cout << "Enter the new price for " << cdPrice << ": ";
			for (int i = 0; i < 10; i++)
			{
				if (cdPrice == devices[i])
				{
					cin >> devicePrices[i];
					changedPrice = devicePrices[i];
					break;
				}
			}
			cout << endl
				 << endl
				 << "The new price for " << cdPrice << " has been updated to " << changedPrice;
			break;

		case 4:
			cout << "Give Discounts..." << endl;
			break;

		case 5:
			cout << "Order the Stock..." << endl;
			break;

		case 0:
			cout << " ";
			break;

		default:
			cout << "Invalid choice. Please enter a valid option." << endl;
			break;
		}
		if (choice != 0)
		{
			cout << endl
				 << "Press any key to go back to Menu.... ";
			getch();
		}
	}
}
void customerMenu()
{
	int choice = 1;
	string buyDevice;
	double budget;
	while (choice != 0)
	{
		system("cls");
		printHeader();
		cout << "You have successfully logged in as an Customer.";
		cout << endl
			 << endl
			 << endl;
		cout << "Enter 1 to Watch the available devices" << endl;
		cout << "Enter 2 to Watch the Prices of available Devices" << endl;
		cout << "Enter 3 to Select the Device you Wanna Buy " << endl;
		cout << "Enter 4 to Select the Amount of Devices " << endl;
		cout << "Enter 5 to Select the Number of devices " << endl;
		cout << "Enter 6 to Select FirstHand or SecondHand " << endl;
		cout << "Enter 0 to escape the matrix" << endl
			 << endl;
		cout << "Enter your choice... ";
		cin >> choice;

		system("cls");
		printHeader();
		switch (choice)
		{
		case 1:
			cout << "Available Devices: " << endl
				 << endl;
			for (int i = 0; i < deviceCount; i++)
			{
				cout << i + 1 << ". " << devices[i] << endl;
			}
			break;
		case 2:
			cout << "Prices for the Devices are: " << endl
				 << endl;
			cout << "   Devices \t \t  Prices" << endl
				 << endl;
			for (int i = 0; i < deviceCount; i++)
			{
				cout << i + 1 << ". " << devices[i] << "\t \t" << devicePrices[i] << endl;
			}
			break;
		case 3:
			cout << "Enter the Device you Wanna Buy...";
			cin >> buyDevice;
			for (int i = 0; i < 10; i++)
			{
				if (buyDevice == devices[i])
				{
					cout << "The price for " << buyDevice << " is " << devicePrices[i] << " only.";
					break;
				}
			}
			break;
		case 4:
			cout << "Select the Number of devices..." << endl;
			break;
		case 5:
			cout << "Select the Number of devices..." << endl;
			break;
		case 6:
			cout << "Select FirstHand or SecondHand..." << endl;
			break;
		case 0:
			cout << " ";
			break;
		default:
			cout << "Invalid choice. Please enter a valid option." << endl;
			break;
		}
		if (choice != 0)
		{
			cout << endl
				 << "Press any key to go back to Menu.... ";
			getch();
		}
	}
}
