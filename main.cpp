#include <iostream>
#include <string.h>
#include "stack.h"

using namespace std;

#define MAX_OP_SIZE 127

int main(){
    Stack<char> p(MAX_OP_SIZE);
    cout << "Size Vector ("  << p.getSize() << ")" << endl;
    char op[MAX_OP_SIZE];
    cout << "Enter Operations Ex [{()}]: ";
    cin >> op;

    bool isValid = true;

    for(unsigned int i = 0; i < strlen(op); i++){
        if(op[i] == '[' || op[i] == '{' || op[i] == '('){
            p.push(op[i]);
        }else{
            char tmp = p.pop();

            if(tmp == '('){
                tmp = ')';
            }else if(tmp == '['){
                tmp = ']';
            }else if(tmp == '{'){
                tmp = '}';
            }

            if(op[i] != tmp){
              isValid = false;
            }
        }
    }

    if(isValid && p.isEmpty()){
        cout << "Valid Expression" << endl;
    }else{
        cout << "Invalid Expression" << endl;
    }

    return 0;
}
