#include <iostream>

using namespace std;

void binarySearch(int array[], int arrSize, int x){
    int k = 0;
    int n = arrSize;

    for (int b = n/2; b>=1; b/=2){
        while(k+b < n && array[k+b] <= x) k += b;
    }

    if (array[k] == x){
        printf("x = %i was found!\n", x);
    }

    return;
}

void binarySearch2(int array[], int arrSize, int x){
    int n = arrSize;
    int a = 0;
    int b = n-1;

    while (a <= b){
        int k = (a+b)/2;

        if (array[k] == x){
            printf("x = %i was found!\n", x);
        }
        if (array[k] < x){
            a = k+1;
        }
        else{
            b = k-1;
        }
    }

    
    return;
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int arrSize = sizeof(array)/sizeof(array[0]);
    int x = 10;

    binarySearch(array, arrSize, x);
    
    x = 5;
    binarySearch2(array, arrSize, x);
}