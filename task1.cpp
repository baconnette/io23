#include "task1.h"

string compSecret;

bool isUnique(string code) {
    bool isUnique = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (code[i] == code[j] && i != j) {
                isUnique = false;
            }
        }
    }
    return isUnique;
}

string generateCode() {
    string code;
    do {
        code = to_string(rand() % 10000);
    }
    while(!isUnique(code));

    return code;
}

string getResult(string secret, string guess) {
    int B = 0, C = 0, i = 0;
    int digitS[10] = {0}, digitG[10] = {0};
    string ret = "";
        
    for (i = 0; i < 4; ++i)
    {
        if (secret[i] == guess[i])
            ++B;
        else
        {
            ++digitS[secret[i] - '0'];
            ++digitG[guess[i] - '0'];
        } 
    }
    for (i = 0; i < 10; ++i)
    {
        if (digitS[i] == digitG[i])
            C += digitS[i];
        else if (digitS[i] > 0 && digitG[i] > 0)
            C += (digitS[i] > digitG[i] ? digitG[i] : digitS[i]);
    }
    ret = to_string(B) + " bulls and " + to_string(C) + " cows";
        
    return ret;
}

void userPrompt() {
    string userGuess;
    string result;
    for (int i = 0; i < 7; ++i) {
        cout << "\n\nYou guess: ";
        cin >> userGuess;
        // userGuess = validInput();
        result = getResult(compSecret, userGuess);

        cout << "\nResult: " << result;
    }
}

// string validInput() {
    
// }