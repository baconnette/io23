#include "task1.h"

bool isUnique(string code) {
    bool isUnique = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (code[i] == code[j] && i != j) {
                isUnique = false;
            }
        }
    }
    return isUnique;
}

string generateCode() {
    string code = "";
    do {
        for (int i = 0; i < 4; i++) {
            code += to_string(rand() % 10);
        }
    }
    while(!isUnique(code));

    return code;
}

string result() {
    
}

void userPrompt() {
    
}

string validInput() {
    
}