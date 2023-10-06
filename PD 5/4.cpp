#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;
void projecttimecalculation()
{
    float hours, days, numb;
    cout << "Enter the needed hours:";
    cin >> hours;
    cout << "Enter the days that the firm has:";
    cin >> days;
    cout << "Enter the number of all workers:";
    cin >> numb;
    float remainingdays = days - days / 10;

    float res = ((remainingdays)*numb * 10);
   
    int calulation = res - hours;
    if (calulation > 0)
    {
        cout << "YES!" << calulation << "hours left";
    }
    else
    {
        cout << "Not enough time!" << -1*calulation << "hours needed";
    }
}
int main()
{
    projecttimecalculation();
    //    cout<<result;
    //    return 0;
}