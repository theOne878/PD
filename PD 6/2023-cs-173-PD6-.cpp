1
#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
string decideactivity(string temperature,string humidity);
int main(){
	string temperature,humidity;
	cout<<"Enter temperature (warm or cold): ";
	cin>>temperature;
	cout<<"Enter humidity (dry or humid): ";
	cin>>humidity;
	string result=decideactivity(temperature,humidity);
	cout<<result;
return 0;
}
	string decideactivity(string temperature,string humidity){
		if (temperature=="warm"){
			if(humidity=="dry"){
			return "Play tennis";
			}
			else{
				return "swim";
			}
		}
		else if(temperature=="cold"){
			if(humidity=="dry"){
				return "Play basketball";
			}
			else{
				return "Watch tv";
				}
			
			}
	}
2
#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
float calculateAverage(string name,float marksEnglish, float marksMaths, float
marksChemistry, float marksSocialScience, float marksBiology);
string calculateGrade(float average);
int main(){
    string name;
    float marksEnglish, marksMaths,
marksChemistry,marksSocialScience,marksBiology;
cout<<"Enter student name: ";
cin>>name;
cout<<"Enter marks for English: ";
cin>>marksEnglish;
cout<<"Enter marks for Maths: ";
cin>>marksMaths;
cout<<"Enter marks for chemistry: ";
cin>>marksChemistry;
cout<<"Enter marks for Social science: ";
cin>>marksSocialScience;
cout<<"Enter marks for Biology: ";
cin>>marksBiology;
float average=calculateAverage(name,marksEnglish, marksMaths,
marksChemistry,  marksSocialScience,  marksBiology);
cout<<"Student name: "<<name<<endl;
cout<<"Pecentage: "<<average<<"%"<<endl;
cout<<"Grade: "<<calculateGrade(average);
return 0;

}
float calculateAverage(string name,float marksEnglish, float marksMaths, float
marksChemistry, float marksSocialScience, float marksBiology){
    
float average=(marksEnglish+marksMaths+marksChemistry+marksSocialScience+marksBiology)/500*100;
    return average;

}
string calculateGrade(float average){
if(average>90&&average<=100){
    return "A+";
}
if(average>80&&average<=90){
    return "A";
}
if(average>70&&average<=80){
    return "B+";
}
if(average>60&&average<=70){
    return "B";
}
if(average>50&&average<=60){
    return "C";
}
if(average>40&&average<=50){
    return "D";
}
if(average<40&&average>=0)
{
    return "F";
}
return " ";
}
3
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
4
#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
float calculatePrice(char service_code, char call_time, int minutes);
int main()
{
    int minutes;
    char service_code, call_time;
    float price;


    cout << "Enter the service code (R/r for regular, P/p for premium): ";
    cin >> service_code;

    if (service_code == 'P' || service_code == 'p')
    {
        cout << "Enter time of the call (D/d for day, N/n for night): ";
        cin >> call_time;
    }

    cout << "Enter the number of minutes used: ";
    cin >> minutes;

    price = calculatePrice(service_code, call_time, minutes);                     

    if (service_code == 'P' || service_code == 'p')
    {
        cout << "Service Type: Premium" << endl;
    }

    if (service_code == 'R' || service_code == 'r')
    {
        cout << "Service Type: Regular" << endl;
    }

    cout << "Total Minutes Used: " << minutes << " minutes" << endl;
    cout << "Amount Due: $" << price;
return 0;
}

float calculatePrice(char service_code, char call_time, int minutes)
{
    float price;
    if (service_code == 'R' || service_code == 'r')
    {
        if (minutes <= 50)
        {
            price = 10;
        }
        else
        {
            minutes = minutes - 50;
            price = minutes * 0.20;
            price = price + 10;
        }
    }

    if (service_code == 'P' || service_code == 'p')
    {
        if (call_time == 'D' || call_time == 'd')
        {
            if (minutes <= 75)
            {
                price = 25;
            }
            else
            {
                minutes = minutes - 75;
                price = minutes * 0.10;
                price = price + 25;
            }
        }

        if (call_time == 'N' || call_time == 'n')
        {
            if (minutes <= 100)
            {
                price = 25;
            }
            else
            {
                minutes = minutes - 100;
                price = minutes * 0.05;
                price = price + 25;
            }
        }
    }
    return price;
}
5
#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
const double banana=2.50;
const double apple=1.20;
const double orange=0.85;
const double grapefruit=1.45;
const double kiwi=2.70;
const double pineapple=5.50;
const double grapes=3.85;
const double banana1=2.70;
const double apple1=1.25;
const double orange1=0.90;
const double grapefruit1=1.60;
const double kiwi1=3.00;
const double pineapple1=5.60;
const double grapes1=4.20;
float calculateFruitPrice(string fruit, string dayOfWeek, double
quantity);
int main(){
    string fruit,dayOfWeek;
    double quantity;
    cout<<"Enter fuit name: ";
    cin>>fruit;
    cout<<"Enter the day of week: ";
    cin>>dayOfWeek;
    cout<<"Enter quantity: ";
    cin>>quantity;
    cout<<calculateFruitPrice(fruit,dayOfWeek,
quantity);
}
float calculateFruitPrice(string fruit, string dayOfWeek, double
quantity){
    if(dayOfWeek=="sunday"||dayOfWeek=="saturday"){
        if(fruit=="banana"){
            return banana1*quantity;
        }
        if(fruit=="apple"){
            return apple1*quantity;
        }
        if(fruit=="orange"){
            return orange1*quantity;
        }
        if(fruit=="grapefruit"){
            return grapefruit1*quantity;
        }
        if(fruit=="kiwi"){
            return kiwi1*quantity;
        }
        if(fruit=="pineapple"){
            return pineapple1*quantity;
        }
        if(fruit=="grapes"){
            return grapes1*quantity;
        }

    }
    else if(dayOfWeek=="monday"||dayOfWeek=="tuesday"||dayOfWeek=="wednesday"||dayOfWeek=="thursday"||dayOfWeek=="friday"){
        if(fruit=="banana"){
            return banana*quantity;
        }
        if(fruit=="apple"){
            return apple*quantity;
        }
        if(fruit=="orange"){
            return orange*quantity;
        }
        if(fruit=="grapefruit"){
            return grapefruit*quantity;
        }
        if(fruit=="kiwi"){
            return kiwi*quantity;
        }
        if(fruit=="pineapple"){
            return pineapple*quantity;
        }
        if(fruit=="grapes"){
            return grapes*quantity;
        }

    }
}
6
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
}
7
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

8
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
