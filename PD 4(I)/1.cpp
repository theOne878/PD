#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int x,int y)
{
COORD position;
position.X=x;
position.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
int main(){
system("cls");
cout<< "Test";
gotoxy(15,15);
cout<<"My name is Muhammad Irzam";
return 0;

}