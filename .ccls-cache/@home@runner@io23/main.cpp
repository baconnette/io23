#include "task1.h"
#include "test.h"
using namespace std;

int main() {  // test for task1.h
    srand(time(NULL)); // changes the initial random number
    compSecret = generateCode();
    userPrompt();
}

// int main()  // test for test.h
// {
//   int num = Gen();
//   string secret = to_string(num);
//   string guess;

//     cout << "Enter 4 numbers: ";
//     cin >> guess;
//     cout << getHint(secret, guess);
// }