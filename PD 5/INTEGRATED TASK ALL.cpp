//task 1

#include<iostream>
using namespace std;
int value1=10;
int value2=2;
int sum(){
value1=40;
return value1+value2;
}
main(){
int x=value1;
value1=100;x=20;
value2=sum();
cout<<value1<<" "<<value2;
}


//task2

#include<iostream>
#include<windows.h>
#include<cmath>
#include<string>

using namespace std;
double millimeters(double length,double width,double height){
        double answer=((length*1000)*(width*1000)*(height*1000))/3;
        return answer;
}

 double meters(double length,double width,double height){
 double answer=(height*width*length)/3;
 return answer;
}
double kilometers(double length,double width,double height){
    double answer=((length/100)*(width/100)*(height/100))/3000;
    return answer;
}
double centimeters(double length,double width,double height){
 double answer=((height*100)*(width*100)*(length*100))/3;
 return answer;
}
string output(string c){
return c;

}
int main(){
    double length,width,height,result1,result2,result3,result4;
    string unit;
    string c=" ";
    cout<<"Enter the length of pyramid is: ";
    cin>>length;
    cout<<"Enter the width of pyramid: ";
    cin>>width;
    cout<<"Enter the height of pyramid: ";
    cin>>height;
    cout<<"Enter the desired output unit(milimeter,centimeter,kilometer,meters): ";
    cin>>unit;
    if(unit=="meters"){
    result1=meters(length,width,height);
    cout<<"The volume of pyramid is : "<<result1 <<" cubic meters";
    }
    else if(unit=="centimeters"){
    result2=centimeters(length,width,height);
    cout<<"The volume of pyramid is : "<<result2 <<" cubic centimeters";
    }
        else if(unit=="millimeters"){
    result3=millimeters(length,width,height);
    cout<<"The volume of pyramid is : "<<result3 <<" cubic milliimeters";
    }
        else if(unit=="kilometers"){
    result4=kilometers(length,width,height);
    cout<<"The volume of pyramid is : "<<result4 <<" cubic kilometers";
    }

}

//task3

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


//task4
#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;
void projecttimecalculation()
{
    float hours, days, numb;
    cout << "Enter the needed hours:";
    cin >> hours;
    cout << "Enter the days that the firm has:";
    cin >> days;
    cout << "Enter the number of all workers:";
    cin >> numb;
    float remainingdays = days - days / 10;

    float res = ((remainingdays)*numb * 10);
   
    int calulation = res - hours;
    if (calulation > 0)
    {
        cout << "YES!" << calulation << "hours left";
    }
    else
    {
        cout << "Not enough time!" << -1*calulation << "hours needed";
    }
}
int main()
{
    projecttimecalculation();
    //    cout<<result;
    //    return 0;
}