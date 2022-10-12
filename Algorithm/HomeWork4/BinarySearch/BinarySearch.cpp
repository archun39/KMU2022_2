#include <stdio.h>
#include <iostream>

using namespace std;

void binarySearch(int nums[], int left, int right, int n, int k);
int answer = -1;
int main(){
    int tc;
    cin >> tc;
    for(int testcase=0; testcase<tc; testcase++){
        int n,k;
        cin >> n >> k ;
        int nums[101];
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }
        int left = 0;
        int right = n-1;
        
        binarySearch(nums,left,right,n,k);

        cout << answer << endl;
        answer = -1;
    }
}
void binarySearch(int nums[], int left, int right, int n, int k){
    int mid = (left + right) / 2;
    if(left<=right){
        if(nums[mid] > k){
            right = mid - 1;
            binarySearch(nums,left,right,n,k);
        }
        else if(nums[mid] < k){
            left = mid + 1;
            binarySearch(nums,left,right,n,k);
        }
        else{
            answer = mid;
        }
    }
}