#include <iostream>

using namespace std;

void printElements(int subset, int numOfBits)
{
    for(int i = 0; i <= numOfBits; i++)
    {
        if(subset&(1<<i))
        {
            cout << i << " ";
        }
    }
    cout << endl;

}

void iterateSubsets(int x, int numOfBits)
{
    //x = {1,2,3} = 1110 
    //numOfBitsof(x) = 4

    int b = 0;
    do 
    {
        printElements(b, numOfBits);
        //process subset b
    }while (b=(b-x)&x);

    // b = 0
    /*
    1st:    b=0;

    2nd:    b = (b-x)&x
            (b-x) =  0000 (- 1110) = 0000 + (0001 + 1) = 0000 + 0010  = 0010
    
             0010    
            &
             1110  <--x
            -----
             0010
    
            --> b = 0010 <--
    
    3rd:    b = (b-x)&x
            (b-x) =  0010 - (1110) = 0010 + 0010 = 0100 

             0100    
            &
             1110
            -----
             0100
    
        
    */

}

int main()
{
    int x = 0;
    //{1,2,3}
    x = 1 << 1 | 1 << 2 | 1 << 3; //1110 = 14
    cout << x << endl;
    iterateSubsets(x,4);
    return 0;
}