#include <iostream>
#include <string>
#include <vector>
#include "PrefixExp.h"
using namespace std;



int main(){
    
    string tmp;
    vector<string> prefixExp;
    while(cin >> tmp){
        prefixExp.push_back(tmp);
        if (cin.peek() == ' ')
            cin.get();
        if (cin.peek() == '\n')
            break;
    }

    PrefixExp *pe = new PrefixExp(prefixExp);
    pe->convert();
    cout << pe->getInfixExp();

    if(pe->getInfixExp() != "Error")
        cout << " = " << pe->getResult() << endl;
    else cout <<endl;
}