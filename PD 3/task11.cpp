#include<iostream>
using namespace std;
int main(){
int age,moved;
cout<< "Enter the Person's age:";
cin>>age;
cout<< "Enter the number of times you have moved:";
cin>>moved;
int average=age/(moved+1);
cout<< "Average number of years lived in same house:"<<average;





return 0;
}