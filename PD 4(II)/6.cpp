#include <iostream>
using namespace std;
void printLongestValue(int hours, int minutes) {
   
    if (hours > minutes / 60) {
        cout << hours << endl;
    } else {
        cout << minutes<< endl;
    }
}
int main() {
    int hours, minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    printLongestValue(hours, minutes);
    return 0;
}