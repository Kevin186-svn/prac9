#include <stack>
#include <algorithm>
#include "PrefixExp.h"


PrefixExp::PrefixExp(vector<string> prefixExp){
    result = 0;
    this->prefixExp = prefixExp;
}

string PrefixExp::getInfixExp(){
    return infixExp;
}

int PrefixExp::getResult(){
    return result;
}

void PrefixExp::convert(){

    stack<string> exps; // expressions
    stack<int> numbers; // operands

    // store intermediate results
    string tmp;
    int tmpResult;

    // store the current operator and two operations
    string op, operandExps[2]; 
    int operands[2];

    string priority[2][2] = {{"*", "/"}, {"+", "-"}}; // specify operator priority

    bool flag = false; // if have read the entire prefix expression

    // read prefix expressions from right to left
    for(int i = prefixExp.size() - 1; i >= 0; i--){

        // encounter an operand, push it into the stack
        if(prefixExp[i][0] >= '0' && prefixExp[i][0] <= '9'){
            exps.push(prefixExp[i]);
            numbers.push(stoi(prefixExp[i]));
        }
        // encounter an operator
        else{
            // the expression is not a valid prefix expression
            if(exps.size() < 2){
                flag = true;
                break;
            }

            // pop the top two elements on the stack
            operandExps[0] = exps.top();
            exps.pop();
            operandExps[1] = exps.top();
            exps.pop();

            operands[0] = numbers.top();
            numbers.pop();
            operands[1] = numbers.top();
            numbers.pop();

            //  If the current operator is * or /, and the preceding operator is + or -, parentheses are added to the expression
            if(find(priority[0], priority[0]+2, prefixExp[i])-priority[0] != 2 && find(priority[1], priority[1]+2, op)-priority[1] != 2)
                tmp = "(" + operandExps[0] + ")";
            else
                tmp = operandExps[0];

            op = prefixExp[i];
            tmpResult = calculate(operands[0], prefixExp[i][0], operands[1]);
            tmp += " " + op + " " + operandExps[1];

            // push the result into the stack
            exps.push(tmp);
            numbers.push(tmpResult);
        }
    }

    // the expression is not a valid prefix expression
    if(exps.size() > 1 || flag)
        infixExp = "Error";
        
    else{
        infixExp = exps.top();
        result = numbers.top();
    } 

}

int PrefixExp::calculate(int a, char op, int b){
    int tmp;
    switch(op){
    case '*':
        tmp = a * b;
        break;
    case '/':
        tmp = a / b;
        break;
    case '+':
        tmp = a + b;
        break;
    case '-':
        tmp = a - b;
        break;
    }
    return tmp;
}