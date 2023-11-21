#include<iostream>
using namespace std;
void checkLargest(string Array[], int num);
main(){
    int num;
    cout<<"Enter the number of words: ";
    cin >>num;
    string Array[num];
    cout<<"Enter the words, one by one: "<<endl;
    for(int i=0; i<num; i++){
        cin>>Array[i];
    }
    checkLargest(Array, num);
    }
void checkLargest(string Array[], int num){
    string largest="";
for(int i=0; i<num; i++){
    int length=Array[i].length();
    for(int j=0 ;j<length; j++){
        if(Array[i][j]=='k' || Array[i][j]=='m' || Array[i][j]=='v' || Array[i][j]=='w' || Array[i][j]=='x'){
            break;
        }
        else if(j == length-1 && length > largest.length()){
            largest=Array[i];
        }
    }
}
cout << "Longest 7-segment word: " << largest;
}