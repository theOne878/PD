#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
string checkStudentStatus(int examhour, int examminute, int
studenthour, int studentminute);
int main(){
    int examhour,examminute,studenthour,studentminute;
    cout<<"Enter exam starting time(in hours): ";
    cin>>examhour;
    cout<<"Enetr exam starting time(in minutes): ";
    cin>>examminute;
    cout<<"Enter Student hour of arrival: ";
    cin>>studenthour;
    cout<<"Enter student minutes of arrival: ";
    cin>>studentminute;
    cout<<checkStudentStatus(examhour,examminute,studenthour,studentminute);
    return 0;
}
string checkStudentStatus(int examhour, int examminute, int
studenthour, int studentminute){
    if(examhour-studenthour==0&&examminute-studentminute==0){
        return "On Time";
    }
    if(examhour-studenthour>0){
        int res=((examhour-studenthour)*60)+(examminute-studentminute);
        int min=res%60;
        int hour=res/60;
        return "Early\ntest: "+ to_string(res)+"\n"+to_string(hour)+":"+to_string(min)+" hours before the start";
    }
    if(examhour-studenthour<0){
    int res=((examhour-studenthour)*60)+(examminute-studentminute))*-1;
    int min=res%60;
    int hour=res/60;
       return "Late\ntest: "+ to_string(res)+"\n"+to_string(hour)+":"+to_string(min)+" hours after the start";
    }
    return " ";
}

