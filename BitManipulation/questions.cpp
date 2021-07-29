#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

// 1) Create a function to convert any decimal between 0-255 to binary then print the result. Develop an algorithm utilizing masks to achieve this. (e.g. 8 = 1000) 
void  convertDecimalToBinary(int decimalNumber)
{
    //Print the binary equivalent
    // 8 -> 1000 (base 2)
    // 1000 ->  0*2^(0)+ 0*2^(1)+ 0*2^(2)+ 1*2^(3)  = 8
    // 8/2 %2 = 0 
    // 4/2 %2 = 0
    // 2/2 %2 = 0
    // 1/2 %2 = 1

    // 18%2 == 0   ; 0
    // 9%2 == 1    ; 1
    // 4%2 == 0    ; 0
    // 2%2 == 0    ; 0
    // 1%2 == 1    ; 1
    // if <= 1 stop
    // 10010  == 18

    int tmp = decimalNumber;
    string binaryNumber = "";
    int mask = 2;
    
    while (tmp > 0)
    {
        if (tmp%mask==0)
        {
            binaryNumber.push_back('0');
        }
        else
        {
            binaryNumber.push_back('1');
        }

        tmp /= mask;
    }

    // for(int i = binaryNumber.size()-1; i >= 0 ; i--)
    // {
    //     cout << binaryNumber[i];
    // }

    reverse(binaryNumber.begin(), binaryNumber.end());
    
    cout << binaryNumber << endl;;
    
    //binaryNumber = 01001
    //10010

}

// 2) Create a function that calculates the product of two 8-bit unsigned numbers using bit shifting and masks. (e.g. 8*5 = 1000<<2 + 8 = 32)

void getProduct(uint a, uint b)
{
    int mask = 1;
    int product = a;

    //What is the power of two to shift shift the other number? 
    // 


    for( )
    {
        product = a << 
    }

    return product;
}


	
// 3) For any 16-bit unsigned number, swap the first byte (8-bits) with the most significant byte. Develop an algorithm utilizing masks to achieve this. (e.g. 11111111 00000000 = 00000000 11111111)

// 4) For any 8-bit number,  toggle all bits in odd bit positions and complement all bits in even bit positions. Develop an algorithm utilizing masks to achieve this. (e.g. 10101010 = 0101010)

// 5) Write a function that accepts an 8-bit number and bit positions then extract the values at those positions from the original number. Develop an algorithm utilizing masks to achieve this.  [e.g.  BitPositions = {0,2,4,5)  Num = 1111 1111  Extract(BitPositions, Num) = 0011 0101]


int main()
{
    convertDecimalToBinary(8);
    return 0;
}