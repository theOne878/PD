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