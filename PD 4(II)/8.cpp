#include <iostream>
using namespace std;
void pet(int holidays) {
    const int workingDays = 365 - holidays;
    const int workingMinutesPerDay = 63;
    const int holidayMinutesPerDay = 127;
    const int annualNorm = 30000;
    const int gameTime = workingDays * workingMinutesPerDay + holidays * holidayMinutesPerDay;
    const int difference = annualNorm - gameTime;
    int hours = difference / 60;
    int minutes = difference % 60;
  if (difference >= 0) {
        cout << "Tom sleeps well" << endl;
    cout << hours << " hours and " << minutes << " minutes" << " less for play" << endl;
} else if (difference < 0) {
        cout << "Tom will run away" << endl;
    cout << hours*-1 << " hours and " << minutes*-1 << " minutes" << " for play" << endl;
}
}
int main() {
    int holidays;
    cout << "Holidays: ";
    cin >> holidays;
    pet(holidays);
    return 0;
}