#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(short x,short y);
void printmaze();
int main(){
   system("cls");
   printmaze();
   return 0;
}
void printmaze(){
   cout<<"#######################"<<endl;
   cout<<"#                     #"<<endl;
   cout<<"#                     #"<<endl;
   cout<<"#                     #"<<endl;
   cout<<"#                     #"<<endl;
   cout<<"#                     #"<<endl;
   cout<<"#                     #"<<endl;
   cout<<"#                     #"<<endl;
   cout<<"#######################"<<endl;
}
void gotoxy(short x,short y)
{
COORD coordinates={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}