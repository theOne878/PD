#include<iostream>
using namespace std;
string doesBrickFit(int height, int width, int depth, int bricksize,int brickwidth);
int main(){
int height,width,depth;
int bricksize=1;
int brickwidth=1;
cout<<"Enter the height: ";
cin>>height;
cout<<"Enter the width: ";
cin>>width;
cout<<"Enter the depth: ";
cin>>depth;


cout<<doesBrickFit(height, width, depth,bricksize, brickwidth);
    return 0;
}
string doesBrickFit(int height, int width, int depth, int bricksize,int brickwidth){
    int hole=bricksize*brickwidth;
    cout<<"doesbrickfit("<<height<<","<<width<<","<<depth<<","<<bricksize<<","<<brickwidth<<",";
if(height*width<=hole){
    cout<<")"<<endl;
    return "true";
}
else{
    cout<<")"<<endl;
    return "false";
}
}