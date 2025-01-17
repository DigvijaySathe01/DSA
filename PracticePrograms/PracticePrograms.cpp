#include <iostream>
#include <vector>
#include "Patterns.h"
#include "HomeWork.h"
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) 
        {
            if (n & 1) 
            {
                ++count;
            }
            n = n >> 1;
        }
        return count;
    }
};

int main()
{
    /*Solution obj;
    std::cout<<obj.hammingWeight(2);*/
    //Patterns::PatternXX();
    std::string temp = "1010";
    HomeWork::ConvertBinaryToDecimal(temp);
   
    return 0;
}