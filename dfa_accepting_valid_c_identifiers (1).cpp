#include <iostream>
#include <cctype>
using namespace std;

enum State {
    START,
    IDENTIFIER,
    ERROR
};

bool isValidIdentifier(string str) {
    State currentState = START;
    for (char c : str) {
        switch (currentState) {
            case START:
                if (isalpha(c) || c == '_')
                    currentState = IDENTIFIER;
                else
                    currentState = ERROR;
                break;
            case IDENTIFIER:
                if (isalnum(c) || c == '_')
                    currentState = IDENTIFIER;
                else
                    currentState = ERROR;
                break;
            case ERROR:
                return false; 
        }
    }
    return (currentState == IDENTIFIER);
}

int main() {
    string input;
    cout << "Enter an identifier: ";
    cin >> input;

    if (isValidIdentifier(input)) {
        cout << "Valid C identifier";
    } else {
        cout << "Invalid C identifier";
    }

    return 0;
}
