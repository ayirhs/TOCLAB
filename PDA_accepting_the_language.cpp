#include <iostream>
#include <stack>
using namespace std;

bool isAccepted(string str) {
    stack<char> stack;

    for (char c : str) {
        if (c == 'a') {
            stack.push('a'); 
        } else if (c == 'b') {
            if (!stack.empty() && stack.top() == 'a') {
                stack.pop();
            } else {
                return false; 
            }
        } else {
            return false; 
        }
    }

    
    return stack.empty();
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isAccepted(input)) {
        cout << "String accepted." << endl;
    } else {
        cout << "String not accepted." << endl;
    }

    return 0;
}
