#include <iostream>

using namespace std;

void printBinary(int num)
{

    for (int i = 0; i <= 31; i++)
    {
        if (num & (1 << i))
            cout << i << " ";
        //else cout << "0";
    }

    cout << "\n";
}

void processSubset(int set, int setSize){
    for(int b = 0; b< (1<<setSize);b++){
        //process subset b
    }
}

void processSubsetWithKElements(int set, int setSize, int k){
    for(int b = 0; b< (1<<setSize);b++){
        if(__builtin_popcount(b) == k){
            //process subset b
        }
    }


}

void processSet(int set){
    int b = 0;
    do
    {
        /* code */
    } while (b=(b-set)&set);

    //b = 0000 set = 0101
    //b-set = 0000 + 1011= 1011; 1011 & 0101 = 0001
    //b-set = 0001 + 1011= 1100; 1100 & 0101 = 0100
    //b-set = 0100 + 1011= 1111; 1111 & 0101 = 0101
    //b-set = 0101 + 1011= 10000; 10000 & 0101 = 0000
    //terminate loop
}

int main()
{

    int x = 0;
    int y = 0;

    // x |= (1<<1);
    // x |= (1<<3);
    // x |= (1<<4);
    // x |= (1<<8);
    x = (1<<1) | (1<<3) | (1<<4) | (1<<8);

    // y |= (1<<3);
    // y |= (1<<6);
    // y |= (1<<8);
    // y |= (1<<9);
    y = (1<<3) | (1<<6) | (1<<8) | (1<<9);

    printBinary(x);
    printBinary(y);

    //Set Operations:

    /*
        Intersection: a&b
        Union: a|b
        Complement: ~a
        Difference: a & 
    */

   //Intersection:
   printBinary(x&y);

   //Union:

   printBinary(x|y);

   //Complement
   printBinary(~x);
   printBinary(~y);

   //Difference:
   printBinary(x&(~y));
   printBinary(y&(~x));

   


}