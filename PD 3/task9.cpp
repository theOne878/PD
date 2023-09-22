#include<iostream>
using namespace std;
int main(){
int digits;
cout << "Enter a 4-digit number:";
cin>>digits; 
int r1=digits%10;
int q1=digits/10;
int q2=q1/10;
int r2=q1%10;
int q3=q2/10;
int r3=q2%10;
int r4=q3%10;
int sum=r1+r2+r3+r4;
cout << "Sum of individual digits:" << sum;







return 0;
}