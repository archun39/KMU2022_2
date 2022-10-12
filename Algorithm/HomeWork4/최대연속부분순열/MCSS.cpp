#include <iostream>
#include <stdio.h>
using namespace std;

int n;

int Divde(int a[], int left, int right);
int Conquer(int a[], int left, int right);
int findMax(int a[],int left,int right);
int findMaxFromMid(int a[],int left,int mid, int right);

int main(){
    int tc;
    cin >> tc;
    for(int testcase=0; testcase<tc; testcase++){
        cin >> n;
        int a[101];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int answer = Divde(a,0,n-1);
        cout << answer << '\n';
        
    }

}

int Divde(int a[], int left, int right){
    //cout << "divde " << left << " : " << right << '\n';
    int mid = (left+right)/2;
    int result;
    if(left == right) return a[left];
    int x1 = Divde(a,left,mid);
    int x2 = Divde(a,mid+1,right);
    int x3 = Conquer(a,left,right);
    if(x1 > x2){
        if(x1 > x3) result = x1;
        else result = x3;
    }
    else{
        if(x2 > x3) result = x2;
        else result = x3;
    }
    //cout << result << " " << left << " : " << right << '\n';
    return result;

}
int Conquer(int a[],int left,int right){
    //cout << "conquer "<< left << " : " << right << '\n';
    int result;
    int mid = (left+right)/2;
    //1번 "미드를 기준으로 왼쪽 맥스 찾기"
    int x1 = findMax(a,left,mid);
    //2번 "미드를 기준으로 오른쪽 맥스 찾기"
    int x2 = findMax(a,mid,right);
    //3번 "미드를 기준으로 연속된 합의 맥스 찾기"
    int x3 = findMaxFromMid(a,left,mid,right);
    //3개 중 최댓값 찾기
    if(x1 > x2){
        if(x1 > x3) result = x1;
        else result = x3;
    }
    else{
        if(x2 > x3) result = x2;
        else result = x3;
    }

    return result;

}

int findMax(int a[],int left,int right){
    int max = -1e9;
    for(int i=left; i<right; i++){
        if(a[i] > max) max = a[i];
    }
    return max;
}

int findMaxFromMid(int a[],int left,int mid, int right){
    int i = mid-1;
    int j = mid;
    int maxL = a[i];
    int maxR = a[j];
    int tmpL = 0;
    while(left <= i){
        tmpL = tmpL + a[i--];
        if(tmpL > maxL) maxL = tmpL;
    }
    int tmpR = 0;
    while(j<=right){
        tmpR = tmpR + a[j++];
        if(tmpR > maxR) maxR = tmpR;
    }
    if( maxR + maxL  > 0) return maxR + maxL;
    else return 0;
}