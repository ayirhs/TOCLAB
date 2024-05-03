#include <iostream>
#include <regex>
using namespace std;

int main() {
  
    regex pattern(".*aba.*");

    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    
    if (regex_match(input, pattern)) {
        cout << "String accepted" << endl;
    } else {
        cout << "String not accepted" << endl;
    }

    return 0;
}
