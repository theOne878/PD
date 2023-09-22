#include<iostream>
using namespace std;
int main(){
string name;
double target;
cout << "Enter the name of the person:";
getline(cin,name);
cout<< "Enter the target weight loss in kilograms:";
cin >> target;
double days=target*15;
cout<< name << " will need " << days <<" days to lose " << target << "KG weight by following doctor's advice";















return 0;
}