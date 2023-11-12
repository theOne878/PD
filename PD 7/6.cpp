#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;}
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int primorial(int n) {
    int result = 1;
    for (int num = 2; n > 0; num++) {
        if (isPrime(num)) {
            result *= num;
            n--;
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a value for n: ";
    cin >> n;
    cout << "Primorial = " << primorial(n);
    return 0;
}