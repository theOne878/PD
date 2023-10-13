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