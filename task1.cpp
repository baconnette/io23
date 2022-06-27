#include "task1.h"

string compSecret;

void program() {
    srand(time(NULL)); // changes the initial random number
    compSecret = generateCode();
    userPrompt();
}


bool isUnique(string code) { // TODO more efficient way?
    bool isUnique = true;
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
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
        
    for (i = 0; i < 4; ++i) {
        if (secret[i] == guess[i])
            ++B;
        else
        {
            ++digitS[secret[i] - '0'];
            ++digitG[guess[i] - '0'];
        } 
    }
    for (i = 0; i < 10; ++i) {
        if (digitS[i] == digitG[i])
            C += digitS[i];
        else if (digitS[i] > 0 && digitG[i] > 0)
            C += (digitS[i] > digitG[i] ? digitG[i] : digitS[i]);
    }
    ret = to_string(B) + to_string(C);
        
    return ret;
}

void userPrompt() {
    string userGuess;
    string result;
    char bulls;
    char cows;
    // cout << compSecret; // for testing!
    
    for (int i = 0; i < 7; ++i) {
        cout << "\n\nYou guess: ";
        userGuess = validInput(); 
        
        result = getResult(compSecret, userGuess);
        bulls = result[0];
        cows = result[1];
        
        cout << "\nResult: " << bulls << " bulls and " << cows << " cows";

        if (bulls == '4') {
            cout << "\nYou win! :)";
            return;
        } 
    }

    cout << "\nYou lost! :(";
}


string validInput() {
    string ret;
    int int_check;

    while(true) {

        // Checks [1] :: String contains only numbers?
        try {
            cin >> ret;
            int_check = stoi(ret);
        }
        catch (...) {
            cout << " |_ Invalid; enter numbers only.\n |_ Enter again: ";
            continue;
        }

        // Checks [2] :: String are digits only?
        if (int_check <= 0 || ret.find(".") != string::npos) {
            cout << " |_ Invalid; positive integers only\n |_ Enter again: ";
            continue;
        }

        // Checks [3] :: String contains 4 digits?
        if (ret.length() != 4 || !isUnique(ret)) {
            cout << " |_ Invalid; not unique 4 digits.\n |_ Enter again: ";
            continue;
        }

        return ret;
    }
}

