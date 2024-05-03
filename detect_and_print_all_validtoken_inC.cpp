#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char statement[1000];
    cout << "Enter a C program statement: ";
    cin.getline(statement, sizeof(statement));

    
    char *token = strtok(statement, " \t\n\r;(),{}[]");
    while (token != NULL) {
        cout << "Token: " << token << endl;
        token = strtok(NULL, " \t\n\r;(),{}[]");
    }

    return 0;
}
