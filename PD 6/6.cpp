#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
const float studio=50;
const float studio1=75.20;
const float studio2=76;
const float apartment=65;
const float apartment1=68.70;
const float apartment2=77;
string calculateHotelPrices(string month, int numberOfStays);
int main(){
    string month;
    int numberOfStays;
    cout<<"Enter the month: ";
    cin>>month;
    cout<<"Enter the numbebr of stays: ";
    cin>>numberOfStays;
    cout<<calculateHotelPrices(month,numberOfStays)<<endl;
}
string calculateHotelPrices(string month, int numberOfStays){
    if(month=="may"||month=="october"){
        if(numberOfStays>0&&numberOfStays<=7){
        return "apartment:"+ to_string(numberOfStays*studio*0.95)+"$ \n"+"Apartment: "+to_string(numberOfStays*apartment*0.9);
    }
    if(numberOfStays>14){
        return "apartment:"+ to_string(numberOfStays*studio*0.70)+"$ \n"+"Apartment: "+to_string(numberOfStays*apartment*0.9);
    }
    }
    if(month=="june"||month=="september"){
          if(numberOfStays>0&&numberOfStays<=14){
        return "apartment:"+ to_string(numberOfStays*studio1)+"$ \n"+"Apartment: "+to_string(numberOfStays*apartment1);
    }
      if(numberOfStays>14){
        return "apartment:"+ to_string(numberOfStays*studio1*0.80)+"$ \n"+"Apartment: "+to_string(numberOfStays*apartment1*0.9);
    

}
    }
if(month=="july"||month=="august"){
          if(numberOfStays>0&&numberOfStays<=14){
        return "apartment:"+ to_string(numberOfStays*studio2)+"$ \n"+"Apartment: "+to_string(numberOfStays*apartment2);
    }
      if(numberOfStays>14){
        return "apartment:"+ to_string(numberOfStays*studio2)+"$ \n"+"Apartment: "+to_string(numberOfStays*apartment2*0.9);
    
}
    }
    return "";
}