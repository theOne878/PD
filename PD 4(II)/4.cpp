#include<iostream>
using namespace std;
void checkspeed(int speed);
int main(){
int speed;
cout<<"Speed: ";
cin>> speed;
checkspeed(speed);
}
void checkspeed(int speed){
if(speed<=100){
cout<<"Perfect! You're going good.";
}
if(speed>100){
cout<<"Halt... YOU WILL BE CHALLENGED!!!";
}
}