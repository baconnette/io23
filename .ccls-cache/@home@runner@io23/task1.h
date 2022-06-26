#include <iostream> 
#include <stdlib.h> // for rand()
#include <cstring>
using namespace std;

bool isUnique();
string generateCode();

// not sure if string? seems to be a more convenient option for saving the bulls/cows data (than arrays)
// im thinking of just a stringified integer where:
// string[0] = # of bulls
// string[1] = # of cows
string result(); 
void userPrompt();

// for limits i think:
// 1. letters (if using stoi(), should also filter floats!)
// 2. >4 and <4 digits
// 3. use isUnique and forbid repeating same number (maybe?)
string validInput();