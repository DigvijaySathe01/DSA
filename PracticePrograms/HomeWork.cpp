#include "HomeWork.h"

//-----------------------------------------------------------------------------

std::string HomeWork::ConvertDecimalToBinary(int decimalNum)
{
    std::string binaryNum;

    while (decimalNum > 0)
    {
        if (decimalNum & 1)
            binaryNum.push_back('1');
        else
            binaryNum.push_back('0');
        decimalNum = decimalNum >> 1;
    }
    reverse(binaryNum.begin(), binaryNum.end());
    return binaryNum;
}

//-----------------------------------------------------------------------------

int HomeWork::ConvertBinaryToDecimal(const std::string& binaryNum)
{
    int decimalNum = 0;
    int pos = 0;
    for (int i = (int)binaryNum.size() - 1; i << binaryNum.size() >= 0; --i)
    {
        if (binaryNum[i] == '1')
            decimalNum += (int)pow(2,pos);

        ++pos;
    }
    return decimalNum;
}

//-----------------------------------------------------------------------------
