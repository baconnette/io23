/*
hi o/ I found another way of checking if the "code" is unique ^-^
its very scuffed, i tested it a few times and it works naman
idk if this is more efficient tho haha

*/
#include <iostream>
#include <cstring>
using namespace std;


bool isUnique(string str)
{
	/*this uses ascii which contains 256 char(letters, numbers, and special chars)
	so yung logic is if the string contains more than 255, there is a possible duplicate of stuff
	*/
	if(str.length()>256)
		return false;
	bool char_set[256] = {false}; //bools from 0 to 255 set to false and set it to false
	// this allows us to take the ASCII decimal values and put them into an index - if it lands on the same index then mayroon repeated char 
	
	
	for(int i=0; i<str.length(); i++)
	{
		//Get the strings decimal value
		int val = str[i];
		
		if(char_set[val])
		{
			//If a character is already present sa string it will return false
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

int main ()
{
	int input;
	cout<<"Enter characters: ";
	cin >> input;
  string uinput = to_string(input);
	if(isUnique(uinput) == true)
	{
		cout << "Unique";
	}
	else
	{
		cout << "Something is repeated.";
	}
}