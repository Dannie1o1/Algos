#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid , int right){
    
    //Sizes
    int leftArrSize = mid-left+1;
    int rightArrSize = right-mid;

    //create temp arrays
    int *leftArr = new int[leftArrSize];
    int *rightArr = new int[rightArrSize];

    //Copy data to temp arrays 
    for(int i = 0; i<leftArrSize;i++){
        leftArr[i] = arr[left+i];
    }
    for(int i = 0; i<rightArrSize; i++){
        rightArr[i] = arr[mid+1+i];
    }

    //Merge the temp arrays back into the original array
    int indexOfLeftArr = 0;
    int indexOfRightArr = 0;
    int indexOfMergedArr = left;

    while (indexOfLeftArr<leftArrSize && indexOfRightArr<rightArrSize){
        if(leftArr[indexOfLeftArr] <= rightArr[indexOfRightArr]){
            arr[indexOfMergedArr] = leftArr[indexOfLeftArr];
            indexOfLeftArr++;
        }
        else{
            arr[indexOfMergedArr] = rightArr[indexOfRightArr];
            indexOfRightArr++;
        }
        indexOfMergedArr++;
    }

    //Copy Remaining elements of left and right temp arrays
    while (indexOfLeftArr < leftArrSize){
        arr[indexOfMergedArr] = leftArr[indexOfLeftArr];
        indexOfMergedArr++;
        indexOfLeftArr++;
    }
    while (indexOfRightArr < rightArrSize){
        arr[indexOfMergedArr] = rightArr[indexOfRightArr];
        indexOfMergedArr++;
        indexOfRightArr++;
    }
}

void mergeSort(int arr[], int a, int b){
    if (a==b){
        return;
    }
    else{
        int k = (a+b)/2;
        mergeSort(arr, a, k);
        mergeSort(arr, k+1, b);
        merge(arr, a,k,b );
    }
}

void printArr(int arr[], int sizeOfArr){
    for (int i = 0 ; i < sizeOfArr; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    //int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printArr(arr,n);
    mergeSort(arr,0,n-1);
    printArr(arr,n);
}