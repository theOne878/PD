#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y);
void printenemy1();
void eraseenemy1();
void printenemy2();
void eraseenemy2();
void printenemy3();
void eraseenemy3();
void eraseplayer();
void printplayer();
void movePlayerLeft();
void movePlayerRight();
void movePlayerDown();
void movePlayerUp();
void moveenemy1(string direction);
void moveenemy2(string direction);
void moveenemy3(string direction);
string changeDirection(string direction);
void printmaze();
char getCharAtxy(short int x, short int y);
int score1=1;
int score2=1;
int score3=1;
int score4=1;
int score5=1;
int score6=1;
int score=0;
int eX = 2, eY = 2;
int pX = 45, pY = 25;
int eX1 = 80, eY1 = 7;
int eX2 = 45, eY2 = 7;
main()
{
    system("cls");
   printmaze();
    printenemy1();
    printenemy2();
    printenemy3();
    printplayer();
    string enemyDirection = "right";
    while (true)
    {

 
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
        }
        
if (GetAsyncKeyState(VK_UP)) {
            movePlayerUp();
           
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        moveenemy1(enemyDirection);
        enemyDirection = changeDirection(enemyDirection);
        Sleep(30);
        moveenemy2(enemyDirection);
        enemyDirection = changeDirection(enemyDirection);
        Sleep(30);
        moveenemy3(enemyDirection);
        enemyDirection = changeDirection(enemyDirection);
        Sleep(30);

if(pX==45 && pY==26 && score1==1){
score=score+1;
score1=0;
}if(pX==45 && pY==27 && score2==1){
score=score+1;
score2=0;
}
if(pX==46 && pY==24 && score3==1){
score=score+1;
score3=0;
}if(pX==46 && pY==22 && score4==1){
score=score+1;
score4=0;
}if(pX==46 && pY==19 && score5==1){
score=score+1;
score5=0;
}if((pX==85||pX==73||pX==74||pX==72||pX==75||pX==76||pX==90) && (pY==22||pY==21||pY==23) && score6==1){
score=score+1;
score6=0;
}
gotoxy(150,10);
cout <<"score ";
gotoxy(152,11);
cout <<score;
    }
}
string changeDirection(string direction)
{

    if (direction == "right" && eX >= 30)
    {
        direction = "left";
    }
    if (direction == "left" && eX <= 2)
    {
        direction = "right";
    }
    return direction;
}
void moveenemy1(string direction)
{

    eraseenemy1();
    if (direction == "right")
    {
        eX = eX + 1;
    }
    if (direction == "left")
    {
        eX = eX - 1;
    }
    printenemy1();
}

void movePlayerRight(){
 if (getCharAtxy(pX+39 , pY) == ' ') 
  {
    eraseplayer() ;
    pX = pX + 1 ;
    printplayer() ;
       }


}

void movePlayerLeft(){
    if (getCharAtxy(pX-2 , pY) == ' ')
    {
    eraseplayer() ;
    pX = pX - 1 ;
    printplayer() ;
    }

}

void movePlayerUp(){
    if (getCharAtxy(pX  , pY-17) == ' ')
    {
    eraseplayer() ;
    pY = pY - 1 ;
    printplayer() ;
    }

}

void movePlayerDown() {
    if (getCharAtxy(pX  , pY+11) == ' ') {
        eraseplayer();
        pY = pY + 1;
        printplayer();
    }

}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printenemy1(){
gotoxy(eX,eY);
cout<<" .-.    ,  .-.  ,    .-."<<endl;
gotoxy(eX,eY+1);
cout<<"'-._'--'  \\_| |_/  '--'_.-'"<<endl;
gotoxy(eX,eY+2);
cout<<"    '-._  \\ | | /  _.-'"<<endl;
gotoxy(eX,eY+3);
cout<<"        `-.^| |^.-'"<<endl;
gotoxy(eX,eY+4);
cout<<"           \\=/"<<endl;
gotoxy(eX,eY+5);
cout<<"            `"<<endl;
}

void eraseenemy1(){
gotoxy(eX,eY);
cout<<"                          "<<endl;
gotoxy(eX,eY+1);
cout<<"                            "<<endl;
gotoxy(eX,eY+2);
cout<<"                        "<<endl;
gotoxy(eX,eY+3);
cout<<"                   "<<endl;
gotoxy(eX,eY+4);
cout<<"                 "<<endl;
gotoxy(eX,eY+5);
cout<<"             "<<endl;
}
void printenemy2(){
gotoxy(eX1,eY1);
cout<<"            `"<<endl;
gotoxy(eX1,eY1-1);
cout<<"           \\=/"<<endl;
gotoxy(eX1,eY1-2);
cout<<"        `-.^| |^.-'"<<endl;
gotoxy(eX1,eY1-3);
cout<<"    '-._  \\ | | /  _.-'"<<endl;
gotoxy(eX1,eY1-4);
cout<<"'-._'--'  \\_| |_/  '--'_.-'"<<endl;
gotoxy(eX1,eY1-5);
cout<<" .-.    ,  .-.  ,    .-."<<endl;
}

void eraseenemy2(){
gotoxy(eX1,eY1);
cout<<"             "<<endl;
gotoxy(eX1,eY1-1);
cout<<"                 "<<endl;
gotoxy(eX1,eY1-2);
cout<<"                   "<<endl;
gotoxy(eX1,eY1-3);
cout<<"                        "<<endl;
gotoxy(eX1,eY1-4);
cout<<"                            "<<endl;
gotoxy(eX1,eY1-5);
cout<<"                          "<<endl;
}
void moveenemy2(string direction)
{

    eraseenemy2();
    if (direction == "right")
    {
        eX1 = eX1 + 1;
    }
    if (direction == "left")
    {
        eX1 = eX1 - 1;
    }
    printenemy2();
}
void eraseplayer(){
gotoxy(pX,pY);
cout<<"                    "<<endl;
gotoxy(pX,pY+1);
cout<<"                    "<<endl;
gotoxy(pX,pY+2);
cout<<"                    "<<endl;
gotoxy(pX,pY+3);
cout<<"                                     "<<endl;
gotoxy(pX,pY+4);
cout<<"                                      "<<endl;
gotoxy(pX,pY+5);
cout<<"                   "<<endl;
gotoxy(pX,pY+6);
cout<<"                   "<<endl;
gotoxy(pX,pY+7);
cout<<"                   "<<endl;
gotoxy(pX,pY+8);
cout<<"                   "<<endl;
gotoxy(pX,pY+9);
cout<<"                       "<<endl;
gotoxy(pX,pY+10);
cout<<"                       "<<endl;
}

void printplayer(){
gotoxy(pX,pY);
cout<<"                 /\\"<<endl;
gotoxy(pX,pY+1);
cout<<"                |^^|"<<endl;
gotoxy(pX,pY+2);
cout<<"                |{}|"<<endl;
gotoxy(pX,pY+3);
cout<<" _______________/~~\\________________"<<endl;
gotoxy(pX,pY+4);
cout<<"'========--------.  .--------========'"<<endl;
gotoxy(pX,pY+5);
cout<<"                 ||"<<endl;
gotoxy(pX,pY+6);
cout<<"                 ||"<<endl;
gotoxy(pX,pY+7);
cout<<"                 ||"<<endl;
gotoxy(pX,pY+8);
cout<<"                 ||"<<endl;
gotoxy(pX,pY+9);
cout<<"             ,---||---,"<<endl;
gotoxy(pX,pY+10);
cout<<"             '---<>---'"<<endl;


}

void printmaze(){
cout<<"########################################################################################################################################"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#___________________                                                                                                    _______________#"<<endl;
cout<<"#___________________|                                                                                                  |_______________#"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                               %                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                               %                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                               %                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                                                                                                      #"<<endl;
cout<<"#                                                               %                                                                      #"<<endl;
cout<<"#                                                               %                                                                      #"<<endl;
cout<<"########################################################################################################################################"<<endl;
}
void printenemy3(){
gotoxy(eX2,eY2);
cout<<"            `"<<endl;
gotoxy(eX2,eY2-1);
cout<<"           \\=/"<<endl;
gotoxy(eX2,eY2-2);
cout<<"        `-.^| |^.-'"<<endl;
gotoxy(eX2,eY2-3);
cout<<"    '-._  \\ | | /  _.-'"<<endl;
gotoxy(eX2,eY2-4);
cout<<"'-._'--'  \\_| |_/  '--'_.-'"<<endl;
gotoxy(eX2,eY2-5);
cout<<" .-.    ,  .-.  ,    .-."<<endl;
}

void eraseenemy3(){
gotoxy(eX2,eY2);
cout<<"             "<<endl;
gotoxy(eX2,eY2-1);
cout<<"                 "<<endl;
gotoxy(eX2,eY2-2);
cout<<"                   "<<endl;
gotoxy(eX2,eY2-3);
cout<<"                        "<<endl;
gotoxy(eX2,eY2-4);
cout<<"                            "<<endl;
gotoxy(eX2,eY2-5);
cout<<"                          "<<endl;
}
void moveenemy3(string direction){
eraseenemy3();
eX2 = eX2+1;
eY2 = eY2+1;
if(eY2==17 )
{
eX2 = 45;
eY2 = 7;
}
printenemy3();
}


char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}