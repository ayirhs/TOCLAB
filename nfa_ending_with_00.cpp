#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, unordered_map<char, unordered_set<int>>> transitions;
unordered_set<int> finalStates = {2};

void initializeTransitions() {
    
    transitions[0]['0'] = {0, 1}; 
    transitions[0]['1'] = {0};

    
    transitions[1]['0'] = {2}; 
}

bool isAccepted(string str) {
    unordered_set<int> currentStates = {0}; 

    for (char c : str) {
        unordered_set<int> nextStates;
        for (int state : currentStates) {
            if (transitions[state].count(c)) {
                for (int nextState : transitions[state][c]) {
                    nextStates.insert(nextState);
                }
            }
        }
        currentStates = nextStates;
    }

    
    if (str.back() == '0') {
        for (int state : currentStates) {
            if (finalStates.count(state)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    initializeTransitions();

    string input;
    cout << "Enter any string of 0s and 1s: " << endl;
    cin >> input;

    if (isAccepted(input)) {
        cout << "STRING ACCEPTED";
    } else {
        cout << "STRING NOT ACCEPTED";
    }

    return 0;
}
