#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
string findZodiacSign(int day, string month);
int main(){
    int day;
    string month;
    cout<<"Enter the day of birth: ";
    cin>>day;
    cout<<"Enter the month of birth: ";
    cin>>month;
    
    cout<<"Zodiac sign: "<<findZodiacSign(day,month);
    return 0;
}
string findZodiacSign(int day, string month){
    if(month=="march"&&day>=21||month=="april"&&day<=19){
        return "Aries";
    }
        else if((month=="april"&& day >= 20)||(month=="may"&& day<=20)){
        return "Taurus ";
    }
        else if((month=="may"&&day>=21)||(month=="june"&&day<=20)){
        return "Gemini ";
    }
        else if(month=="june"||month=="july"){
        return "Cancer ";
    }
        else if(month=="july"||month=="august"){
        return "Leo ";
    }
        else if(month=="august"&&day>=23||month=="september"&&day<=22){
        return "Virgo";
    }
        else if((month=="september"&&day>=23)||(month=="october"&&day<=22)){
        return "Libra ";
    }
        else if((month=="october"&&day>=23)||(month=="november"&&day<=21)){
        return "Scorpio ";
    }
        else if((month=="november"&&day>=22)||(month=="december"&&day<=21)){
        return "Sagittarius";
    }
        else if(month=="march"||month=="april"){
        return "Capricorn ";
    }
        else if(month=="december"||month=="january"){
        return "Aquarius ";
    }
        else if(month=="january"||month=="feburary"){
        return "Pisces";
    }
}