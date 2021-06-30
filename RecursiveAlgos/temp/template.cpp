#include <iostream>

using namespace std;

int fib(int n)
{
    //n = n + (n-1)
    // fib(0) = 0
    // fib(1) = 1 + 0
    // fib(2) = 2 + fib(2-1)

    //base
    if (n==0) return 0;
    else if (n==1) return 1;
    
    //Recursive Logic
    return (n+fib(n-1));
}


int main()
{
    // fib(5) = 5 + fib(4) = 5 + (4+fib(3)) = 5 + (4 + [3 + fib(2)]) = 5 + (4 + [3 + {2+1}])
    //5 + fib(4) = 5 + 10 = 15
      //fib (4) = 4+fib(3) = 4+6 = 10
        //fib(3) = 3 + fib(2) = 3+3 = 6
          // fib(2) = 2+fib(1) = 2+1 = 3
            //fib(1)  = 1
    cout << fib(1) << endl;
    cout << fib(2) << endl;
    cout << fib(3) << endl;
    cout << fib(4) << endl;
    cout << fib(5) << endl;
    return 0;
}