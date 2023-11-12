#include<iostream>
using namespace std;

int main(){
	int number;
	int dots = 0;
	cout << "Enter number of Triangle: ";
	cin >> number;
	
	for(int i=1; i<=number; i++){
		dots = dots+i;
	}
	cout << "Dots in the triangle: " << dots;

}