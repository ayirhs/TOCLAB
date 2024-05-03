#include <iostream>
using namespace std;
int currentState = 0;
int prevState= 0;
bool isAccepted(string);
int main()
{

    string input;
	cout<<"Enter any string of a and b : "<<endl;
	cin>>input;
    if (isAccepted(input)) {

        cout<<"STRING ACCEPTED";
    }
    else{
         cout<<"STRING NOT ACCEPTED";
    }
    return 0;
}
void checkq0(char c){
    if(c=='a'){
        currentState = 1;
    }
    else if(c=='b'){
        currentState = 0;
    }

    cout<<"Move("<<prevState<<","<<c<<")="<<currentState<<endl;
    prevState = currentState;
}
void checkq1(char c){
    if(c=='a'){
        currentState = 1;
    }
    else if(c=='b'){
        currentState = 2;
    }

    cout<<"Move("<<prevState<<","<<c<<")="<<currentState<<endl;
    prevState = currentState;
}
void checkq2(char c){
    if(c=='a'){
        currentState = 3;
    }
    else if(c=='b'){
        currentState = 0;
    }

    cout<<"Move("<<prevState<<","<<c<<")="<<currentState<<endl;
    prevState = currentState;
}
void checkq3(char c){
    if((c=='a') || (c=='b')){
        currentState = 3;
    }
    cout<<"Move("<<prevState<<","<<c<<")="<<currentState<<endl;
    prevState = currentState;
}
bool isAccepted(string str)
{
    int i, len = str.length();

    for (i = 0; i < len; i++) {
        if (currentState == 0)
            checkq0(str[i]);

        else if (currentState == 1)
            checkq1(str[i]);

        else if (currentState == 2)
            checkq2(str[i]);

        else if (currentState == 3)
            checkq3(str[i]);
        else
            return 0;
    }

    if (currentState == 3)
        return 1;
    else
        return 0;
}


