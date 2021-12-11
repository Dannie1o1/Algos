#include<iostream>
#include<vector>
using namespace std;
/*
    Problem: How to calculate teh number of way n queens can be placed on an n x n chessboard 
    so that no two queens attack each other
*/

int n;
int cnt;
vector<int> col, diag1, diag2;



void search(int y){
    if (y==n){
        cnt++;
        cout << "base cased reached cnt =" << cnt << endl;
        return;
    }
    for (int x=0; x<n; x++){
        if(col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] =0;
    }
}

int main(){
    //set global variables
    //using example from Guide to Competitive Programming
    n = 4;
    cnt = 0;
    col.resize(n);
    diag1.resize(2*n);
    diag2.resize(2*n);
    search(0);
    cout << cnt << endl;
}