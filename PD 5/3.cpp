#include<iostream>
#include<windows.h>
#include<cmath>
#include<string>
using namespace std;
int main(){
    int price,price1,price2,price3,price4,price5;
    char code;
 cout<<"Enter the vehicle type code:";
 cin>>code;
 cout<<"Enter The price of the vehicle: $";
 cin>>price;
 price1=price+(price*6/100);
  price2=price+(price*8/100);
   price3=price+(price*10/100);
    price4=price+(price*12/100);
     price5=price+(price*15/100);
 if(code=='M'){
 cout<<"The final price of vehicle type M after adding the tax is $"<<price1;
 }
  if(code=='E'){
 cout<<"The final price of vehicle type M after adding the tax is $"<<price2;
 }
  if(code=='S'){
 cout<<"The final price of vehicle type M after adding the tax is $"<<price3;
 }
  if(code=='V'){
 cout<<"The final price of vehicle type M after adding the tax is $"<<price4;
 }
  if(code=='T'){
 cout<<"The final price of vehicle type M after adding the tax is $"<<price5;
 }

}
