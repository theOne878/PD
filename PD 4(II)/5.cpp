#include <iostream>
using namespace std;
void canEarnBonus(int yourPosition, int friendPosition) {
    int difference = yourPosition - friendPosition;
    if (difference < 0) {
        difference = -difference;
}
    if (difference >= 1 && difference <= 6) {
        cout << "true" << endl;
}   else {
        cout << "false" << endl;
}
}
int main() {
    int yourPosition, friendPosition;   
    cout << "Enter your position: ";
    cin >> yourPosition;
    cout << "Enter your friend's position: ";
    cin >> friendPosition;
    canEarnBonus(yourPosition, friendPosition);
    return 0;
}