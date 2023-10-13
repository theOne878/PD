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