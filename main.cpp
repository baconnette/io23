#include "task1.h"
#include "test.h"
using namespace std;

int main() {
  srand(time(NULL)); // changes the initial random number
  std::cout << "Hello World!\n";
  std::cout << generateCode();
}

// int main()
// {
//   int num = Gen();
//   string secret = to_string(num);
//   string guess;

//     cout << "Enter 4 numbers: ";
//     cin >> guess;
//     cout << getHint(secret, guess);
// }