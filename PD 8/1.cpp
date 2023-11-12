#include<iostream>
using namespace std;
bool length(string characters);
int main(){
    string characters;
    cout<<"Enter the character:";
    getline(cin,characters);
    cout<<length(characters);
    return 0;
}
bool length(string characters){
    if(characters.length()%2==0){
        return true;
    }
    else{
    return false;
}
}