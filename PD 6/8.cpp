#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<windows.h>
using namespace std;
int weekend=48;
int calculateVolleyballGames(string yeartype, float holidays, float hometownweekends);
int main(){
    string yeartype;
    float holidays,hometownweekends;
    cout<<"Enter year type: ";
    cin>>yeartype;
    cout<<"Enter Number of holidays: ";
    cin>>holidays;
    cout<<"Enter muber of weekends: ";
    cin>>hometownweekends;
    cout<<calculateVolleyballGames(yeartype, holidays,hometownweekends);
}
int calculateVolleyballGames(string yeartype, float holidays, float hometownweekends){
    float result;
    holidays=holidays*(2.0/3.0);
    float hometownweekends1=48-hometownweekends;
    float hometownweekends2 =hometownweekends1*(3.0/4.0);
    result = hometownweekends+holidays+hometownweekends2;
    if(yeartype=="leap"){
        float leapresult=result+(result*0.15);
        return floor(leapresult);
}
else
{
    return result;
}
}