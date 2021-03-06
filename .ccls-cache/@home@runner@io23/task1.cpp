#include "task1.h"

string compSecret;
char programCont = 'y';

void program() {
    while (programCont == 'y') {
        srand(time(NULL)); // changes the initial random number
        compSecret = generateCode();
        userPrompt();
        tryAgain();
    }
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
    /*
    Generates a string of 4 unique digits.

    NOTE:
    Cannot be generated with only rand() % 10000,
    in case of numbers like 213400006 -- which can default
    to <4 digits. So incremental adding of digits is the way to go (?)
    */
    
    string code;
    do {
        code = "";
        for (int i = 0; i < 4; i++) {
            code += to_string(rand() % 10);
        }
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

    cout << "\nYou lost! :(\nThe secret is " << compSecret;
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


void tryAgain() {
    cout << "\n\nTry again? [y/n]: ";
    while (true) { 
        cin >> programCont;
        if (programCont != 'y' && programCont != 'n') {
            cout<< " |_ Invalid input.\n |_ Please only enter [y/n]: ";
            continue;
        }
        break;
    }

    cout<< "\n\n\n\n";
}