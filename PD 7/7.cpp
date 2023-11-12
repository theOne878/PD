#include <iostream>

using namespace std;

int main() {
    int days, doctors = 7, treated = 0, untreated = 0;

    cout << "Enter the number of days for the simulation: ";
    cin >> days;

    for (int day = 1; day <= days; day++) {
        if (day % 3 == 0 && untreated > treated) {
            doctors++;
        }

        int patients = doctors;
        if (untreated > 0) {
            patients += untreated;
            untreated = 0;
        }

        int treated_today = min(7, patients);
        treated += treated_today;
        untreated += patients - treated_today;
    }

    cout << "Treated patients: " << treated << endl;
    cout << "Untreated patients: " << untreated << endl;

    return 0;
}