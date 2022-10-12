#include <stdio.h>
#include <iostream>

using namespace std;

int n;

int findMax(int a[], int idx, int max);

int main(){
    int tc;
    cin >> tc;
    for(int testcase = 0; testcase<tc; testcase++){
        cin >> n;
        int nums[101];
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }
        cout << findMax(nums,0,-1e9) << '\n';
    }
}

int findMax(int a[], int idx, int max){
    if(idx < n){
        int tmp = a[idx];
        if(tmp > max) return findMax(a,idx+1,tmp);
        else return findMax(a,idx+1,max);
    }
    return max;
}