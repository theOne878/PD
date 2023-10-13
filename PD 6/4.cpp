#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
using namespace std;
float calculatePrice(char service_code, char call_time, int minutes);
int main()
{
    int minutes;
    char service_code, call_time;
    float price;


    cout << "Enter the service code (R/r for regular, P/p for premium): ";
    cin >> service_code;

    if (service_code == 'P' || service_code == 'p')
    {
        cout << "Enter time of the call (D/d for day, N/n for night): ";
        cin >> call_time;
    }

    cout << "Enter the number of minutes used: ";
    cin >> minutes;

    price = calculatePrice(service_code, call_time, minutes);                     

    if (service_code == 'P' || service_code == 'p')
    {
        cout << "Service Type: Premium" << endl;
    }

    if (service_code == 'R' || service_code == 'r')
    {
        cout << "Service Type: Regular" << endl;
    }

    cout << "Total Minutes Used: " << minutes << " minutes" << endl;
    cout << "Amount Due: $" << price;
return 0;
}

float calculatePrice(char service_code, char call_time, int minutes)
{
    float price;
    if (service_code == 'R' || service_code == 'r')
    {
        if (minutes <= 50)
        {
            price = 10;
        }
        else
        {
            minutes = minutes - 50;
            price = minutes * 0.20;
            price = price + 10;
        }
    }

    if (service_code == 'P' || service_code == 'p')
    {
        if (call_time == 'D' || call_time == 'd')
        {
            if (minutes <= 75)
            {
                price = 25;
            }
            else
            {
                minutes = minutes - 75;
                price = minutes * 0.10;
                price = price + 25;
            }
        }

        if (call_time == 'N' || call_time == 'n')
        {
            if (minutes <= 100)
            {
                price = 25;
            }
            else
            {
                minutes = minutes - 100;
                price = minutes * 0.05;
                price = price + 25;
            }
        }
    }
    return price;
}