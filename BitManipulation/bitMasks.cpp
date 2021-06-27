#include<iostream>

using namespace std;

int main(){

    int x = 40;
    for (int k = 31; k>=0; k--){
        if (x&(1<<k)) cout <<"1";
        else cout << "0";
    }
    cout << endl;

//For Int Masks:
    //x & (1<<k) access the value at the k-th position of a #
    //x | (1<<k) sets the k-th bit  to 1
    //x & ~(1<<k) inverts the k-th bit of x
    //x & (x-1) sets the last one bit of x to zero
    //x & -x sets all the one bits to zero
    //x | (x-1) inverts all the bits after the last one bit
    // x & (x-1) means the number is a exactly a power of 2
//For Long Long masks
    // 1LL << k

    int x = 5328;// 00000000000000000001010011010000
    cout << __builtin_clz(x) << endl; //19  - the number of zeros at the beginning of the bit representation
    cout << __builtin_ctz(x) << endl; //4 - the number of zeros at the end of the bit representation 
    cout << __builtin_popcount(x) << endl;//5 - the number of ones in the bit representation
    cout << __builtin_parity(x) << endl; //1 - the parity (even of odd) of the number of ones in the bit representation 
    //These functions are also available for LL


    
    return 0;
}