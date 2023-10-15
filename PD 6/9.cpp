#include <iostream>
using namespace std;

string checkPointPosition(int h, int x, int y);

int main() {
    int h,x,y;
    cout << "Enter height: ";
    cin >> h;
    cout << "Enter x coordinate: ";
    cin >> x;
    cout << "Enter y coordinate: ";
    cin >> y;
    cout << checkPointPosition(h, x, y);
}

string checkPointPosition(int h, int x, int y) {
    if (x < 0 || x > h * 3 || y < 0 || y > 4 * h) {
        return "Outside";
    }

    if (x % h == 0 && (y == h || y == 3 * h)) {
        return "Border";
    }

    if (x > h && x < 2 * h && y > h && y < 3 * h) {
        return "Inside";
    }

    return "Outside";
}
