#include <iostream>

using namespace std;

//O(N)
void countSort(int arr[], int arrSize, int range){
    int output[arrSize];
    int count[range+1],i;
    memset(count,0,sizeof(count));

    //Store count of each character
    for(int i = 0; i<arrSize; i++){
        ++count[arr[i]];
    }

    //Change count[i] so that count[i] now contains actual
    //position of this character in output arr
    for(int i = 1; i<=range; ++i){
        count[i] += count[i-1];
    }

    //Build the output character array
    for(int i = 0; i < arrSize; ++i){
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }

    //Copy the output array to arr, so that arr now 
    //contains sorted characters
    for(int i = 0; i<arrSize; ++i){
        arr[i]=output[i];
    }

    return;
}

void printArr(int arr[], int sizeOfArr){
    for (int i = 0 ; i < sizeOfArr; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int range = 10;
    int arr[] = {10,9,9,4,4,3,3,2,2,1};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    countSort(arr,arrSize,range);
    printArr(arr,arrSize);
    }