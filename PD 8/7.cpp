#include <iostream>
using namespace std;
void convertpin(string pin);
main()
{
    string pin;
    cout << "Enter your PIN (4 digits): ";
    cin >> pin;
    bool check = true;
    if (pin.length() != 4)
    {
        cout << "Invalid input.";
        check=false;
    }
    else if (pin.length() == 4 )
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                if (pin[i] == j + '0')
                {
                    break;
                }
                else if (j == 9)
                {
                    cout << "Invalid input.";
                    check=false;
                    break;
                }
            }
            if (check==false){
                break;
            }
        }
    }
    if (check!=false){
    convertpin(pin);
    }
}

void convertpin(string pin)
{
    string Array[10] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado", "Pop", "Lock", "Arabesque"};
    for (int i = 0; i < 4; i++)
    {
        int var = (pin[i] - '0') + i;
        if (var <= 9 && i != 3)
        {
            cout << Array[var] << ", ";
        }
        else if (var > 9 && i != 3)
        {
            cout << Array[var % 10 ] << ", ";
        }
        else if (var <= 9 && i == 3)
        {
            cout << Array[var];
        }
        else if (var > 9 && i == 3)
        {
            cout << Array[var % 10 ];
        }
    }
}