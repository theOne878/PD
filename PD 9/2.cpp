#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    int size;
    int count=0;
    cout<<"Enter how many words you want to enter:";
    cin>>size;
    char c;
    string array[size];
    for(int i=0;i<size;i++){
        cout<<"Enter word "<<i+1<<": ";
        cin>>array[i];
    }
        cout<<"Enter the letter you want to calculate: ";
        cin>> c;

        for(int i=0;i<size;i++){
            for(int j=0;j<array[i].length();j++){
                if(array[i][j]==tolower(c)){
                    count++;
                }
            }
        }
        cout<<count;
        return 0;
    }
