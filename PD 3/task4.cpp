#include<iostream>
using namespace std;
int main(){
double playercount,impcount;
cout << "Enter imposter count:" ;
cin >> impcount;
cout << "  Enter player count:" ;
cin >> playercount;
double percentage=100*(impcount/playercount);
cout << "chance of being an imposter:" << percentage <<"%";















return 0;
}