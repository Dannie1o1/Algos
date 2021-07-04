#include <iostream>

using namespace std;

void bubbleSort(int arr[], int sizeOfArr){

    int n = sizeOfArr;
    printf("n = %i \n", n);

    for (int i=0; i<n; i++){
        for (int j=0; j <n-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
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
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int sizeOfArr = sizeof(arr)/sizeof(arr[0]);
    //print original array
    printArr(arr,sizeOfArr);
    bubbleSort(arr, sizeOfArr);
    printArr(arr,sizeOfArr);
    return 0;
}