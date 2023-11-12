#include <iostream>
#include <string>
using namespace std;
string findBrokenKeys(string correctPhrase, string actualTyped);
int main() {
    string correctPhrase, actualTyped;
    cout << "Enter the correct phrase:";
    getline(cin, correctPhrase);
    cout << "Enter the phrase You entered:";
    getline(cin, actualTyped);
    cout<<findBrokenKeys(correctPhrase,actualTyped);
    return 0;
}
string findBrokenKeys(string correctPhrase, string actualTyped) {
    string brokenKeys;
    for (int i = 0; i < correctPhrase.length(); i++) {
        if (correctPhrase[i] != actualTyped[i] && brokenKeys.find(correctPhrase[i]) == string::npos) {
            brokenKeys +=correctPhrase[i];
        }
    }
    return brokenKeys;
}
