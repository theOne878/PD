#include<iostream>
using namespace std;
bool isPrime(int number);
double getPrimorial(int number);

int main(){
	int number;
	cout << "Enter Number: ";
	cin >> number;
	cout << getPrimorial(number);
}
bool isPrime(int number)
{
		for(int i=2; i<number ; i++)
		{
			if(number % i == 0)
			return false;
		}
		return true;
}
double getPrimorial(int number)
{	
	int counter=0;
	int num = 2;
	double primorial = 1;
	while(counter<number)
	{
		if(isPrime(num)){
			counter++;
			primorial = primorial * num;
 		}
 		
 		num++;
	}
	return primorial;	
}