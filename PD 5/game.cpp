#include<iostream>
#include<windows.h>
using namespace std;
int px=40,py=25;
int ex1=4,ey1=3;
int ex2=84,ey2=3;
int ex3=45,ey3=3;
void printenemy1();
void printenemy2();
void printenemy3();
void printplayer();
void moveplayer();
void printmaze();
void gotoxy(short x,short y);
void moveenemy1();
void moveenemy3();
void moveenemy2();
void eraseplayer();
void eraseenemy1();
void eraseenemy2();
void eraseenemy3();
char getCharAtxy(short int x, short int y);
void movePlayerRight();
void movePlayerLeft();
int main(){
system("cls");
printmaze();
printenemy1();
printenemy2();
while(true){
moveenemy1();
moveenemy2();
moveenemy3();
printplayer();
        if (GetAsyncKeyState(VK_RIGHT)) 
        {
            movePlayerRight();
        }
        
        if (GetAsyncKeyState(VK_LEFT)) 
        {
            movePlayerLeft();
        }
        Sleep(100) ;

}
}
void printmaze(){
cout<<"#########################################################################################################################"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#                                                                                                                       #"<<endl;
cout<<"#########################################################################################################################"<<endl;
}
void moveplayer(){
}
void printplayer(){
gotoxy(px,py);
cout<<"                 /\\"<<endl;
gotoxy(px,py+1);
cout<<"                |^^|"<<endl;
gotoxy(px,py+2);
cout<<"                |{}|"<<endl;
gotoxy(px,py+3);
cout<<" _______________/~~\\________________"<<endl;
gotoxy(px,py+4);
cout<<"'========--------.  .--------========'"<<endl;
gotoxy(px,py+5);
cout<<"                 ||"<<endl;
gotoxy(px,py+6);
cout<<"                 ||"<<endl;
gotoxy(px,py+7);
cout<<"                 ||"<<endl;
gotoxy(px,py+8);
cout<<"                 ||"<<endl;
gotoxy(px,py+9);
cout<<"             ,---||---,"<<endl;
gotoxy(px,py+10);
cout<<"             '---<>---'"<<endl;
}
void printenemy1(){
gotoxy(ex1,ey1);
cout<<" .-.    _,  .-.  ,_    .-."<<endl;
gotoxy(ex1,ey1+1);
cout<<"'-._'--'  \\_| |_/  '--'_.-'"<<endl;
gotoxy(ex1,ey1+2);
cout<<"    '-._  \\ | | /  _.-'"<<endl;
gotoxy(ex1,ey1+3);
cout<<"        `-.^| |^.-'"<<endl;
gotoxy(ex1,ey1+4);
cout<<"           `\\=/`"<<endl;
gotoxy(ex1,ey1+5);
cout<<"            `"<<endl;

}
void printenemy2(){
gotoxy(ex2,ey2);
cout<<" .-.    _,  .-.  ,_    .-."<<endl;
gotoxy(ex2,ey2+1);
cout<<"'-._'--'  \\_| |_/  '--'_.-'"<<endl;
gotoxy(ex2,ey2+2);
cout<<"    '-._  \\ | | /  _.-'"<<endl;
gotoxy(ex2,ey2+3);
cout<<"        `-.^| |^.-'"<<endl;
gotoxy(ex2,ey2+4);
cout<<"           `\\=/`"<<endl;
gotoxy(ex2,ey2+5);
cout<<"            `"<<endl;
}
void moveenemy1(){
eraseenemy1();
ex1=ex1+1;
if(ex1==30){ 
ex1=7; 
}
printenemy1();


}
void moveenemy2(){
eraseenemy2();
ex2=ex2-1;
if(ex2==60){ 
ex2=82; 
}
gotoxy(ex2,ey2);
printenemy2();




}
void eraseenemy2(){
gotoxy(ex2,ey2);
cout<<"                          "<<endl;
gotoxy(ex2,ey2+1);
cout<<"                            "<<endl;
gotoxy(ex2,ey2+2);
cout<<"                        "<<endl;
gotoxy(ex2,ey2+3);
cout<<"                   "<<endl;
gotoxy(ex2,ey2+4);
cout<<"                 "<<endl;
gotoxy(ex2,ey2+5);
cout<<"             "<<endl;
}
void printenemy3(){
	
gotoxy(ex3,ey3);
cout<<" .-.    _,  .-.  ,_    .-."<<endl;
gotoxy(ex3,ey3+1);
cout<<"'-._'--'  \\_| |_/  '--'_.-'"<<endl;
gotoxy(ex3,ey3+2);
cout<<"    '-._  \\ | | /  _.-'"<<endl;
gotoxy(ex3,ey3+3);
cout<<"        `-.^| |^.-'"<<endl;
gotoxy(ex3,ey3+4);
cout<<"           `\\=/`"<<endl;
gotoxy(ex3,ey3+5);
cout<<"            `"<<endl;
}
void moveenemy3(){
eraseenemy3();
ex3 = ex3+2;
ey3 = ey3+1;
if(ey3==25 )
{
ex3 = 44;
ey3 = 3;
}
printenemy3();
}
void eraseenemy3(){
gotoxy(ex3,ey3);
cout<<"                          "<<endl;
gotoxy(ex3,ey3+1);
cout<<"                            "<<endl;
gotoxy(ex3,ey3+2);
cout<<"                        "<<endl;
gotoxy(ex3,ey3+3);
cout<<"                   "<<endl;
gotoxy(ex3,ey3+4);
cout<<"                 "<<endl;
gotoxy(ex3,ey3+5);
cout<<"             "<<endl;
}
void gotoxy(short x,short y){
COORD points={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), points);
}
char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0, 0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}
void eraseenemy1(){
gotoxy(ex1,ey1);
cout<<"                          "<<endl;
gotoxy(ex1,ey1+1);
cout<<"                            "<<endl;
gotoxy(ex1,ey1+2);
cout<<"                        "<<endl;
gotoxy(ex1,ey1+3);
cout<<"                   "<<endl;
gotoxy(ex1,ey1+4);
cout<<"                 "<<endl;
gotoxy(ex1,ey1+5);
cout<<"             "<<endl;

}
void eraseplayer(){
gotoxy(px,py);
cout<<"                    "<<endl;
gotoxy(px,py+1);
cout<<"                    "<<endl;
gotoxy(px,py+2);
cout<<"                    "<<endl;
gotoxy(px,py+3);
cout<<"                                     "<<endl;
gotoxy(px,py+4);
cout<<"                                      "<<endl;
gotoxy(px,py+5);
cout<<"                   "<<endl;
gotoxy(px,py+6);
cout<<"                   "<<endl;
gotoxy(px,py+7);
cout<<"                   "<<endl;
gotoxy(px,py+8);
cout<<"                   "<<endl;
gotoxy(px,py+9);
cout<<"                       "<<endl;
gotoxy(px,py+10);
cout<<"                       "<<endl;
}
void movePlayerRight(){
 if (getCharAtxy(px+40 , py) == ' ') 
  {
    eraseplayer() ;
    px = px + 1 ;
    printplayer() ;
       }
}

void movePlayerLeft(){
    if (getCharAtxy(px - 5 , py) == ' ')
    {
    eraseplayer() ;
    px = px - 1 ;
    printplayer() ;
    }
}


