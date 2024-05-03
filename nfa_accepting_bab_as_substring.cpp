#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, unordered_map<char, unordered_set<int>>> transitions;
unordered_set<int> finalStates = {3};

void initializeTransitions() {
   
    transitions[0]['a'] = {0}; 
    transitions[0]['b'] = {0,1}; 

    
    transitions[1]['a'] = {2};

    
    transitions[2]['b'] = {3}; 

    
    transitions[3]['a'] = {3}; 
    transitions[3]['b'] = {3};    
}

bool isAccepted(string str) {
    unordered_set<int> currentStates = {0}; // Start with the initial state 0

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

    
    for (int state : currentStates) {
        if (finalStates.count(state)) {
            return true;
        }
    }

    return false;
}

int main() {
    initializeTransitions();

    string input;
    cout << "Enter any string: " << endl;
    cin >> input;

    if (isAccepted(input)) {
        cout << "STRING ACCEPTED";
    } else {
        cout << "STRING NOT ACCEPTED";
    }

    return 0;
}
