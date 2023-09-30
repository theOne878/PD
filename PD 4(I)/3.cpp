#include<iostream>
#include<windows.h>
using namespace std;
void printmaze();
void gotoxy(short x,short y);
void moveplayer(int x,int y);
int main(){
   int x=4,y=3;
   system("cls");
   printmaze();
   moveplayer(x,y);
   gotoxy(15,15);
   return 0;
}
void moveplayer(int x,int y){
   gotoxy(4,3);
   cout<<"P";
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
