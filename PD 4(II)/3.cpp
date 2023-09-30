#include <iostream>
using namespace std;

void airlineCompany(string name, float amount);

main() 
{
	string name;
	cout << "Enter the country's name: ";
	cin >> name;
	float amount;
	cout << "Enter the ticket price in dollars: $";
	cin >> amount;
	airlineCompany(name, amount);
}
void airlineCompany(string name, float amount)
{
	float discountAmount, discountFactor = 1;
	if(name == "Pakistan")discountFactor = 0.95;
	if(name == "Ireland")discountFactor = 0.90;
	if(name == "India")discountFactor = 0.80;
	if(name == "England")discountFactor = 0.70;
	if(name == "Canada")discountFactor = 0.55;
	discountAmount = amount * discountFactor;
	cout<< "Final ticket price after discount: $" << discountAmount;
}