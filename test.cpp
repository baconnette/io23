#include "test.h"

int Gen()
{
  srand(time(NULL));
  return rand(); 
}

string getHint(string secret, string guess) 
{
        int B = 0, C = 0, i = 0, len = 0;
        int digitS[10] = {0}, digitG[10] = {0};
        string ret = "";
        
        len = secret.length();
        for (i = 0; i < len; ++i)
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
        ret = to_string(B)+"B"+to_string(C)+"C";
        
        return ret;
}