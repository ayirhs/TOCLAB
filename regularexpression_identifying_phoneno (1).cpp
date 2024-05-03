#include <iostream>
#include <regex>
using namespace std;

int main() {
    
    regex pattern("(98|97)\\d{8}");

    string input;
    cout << "Enter a phone number: ";
    getline(cin, input);

    
    if (regex_match(input, pattern)) {
        cout << "Valid phone number detected!" << endl;
    } else {
        cout << "Not a valid phone number!" << endl;
    }

    return 0;
}
