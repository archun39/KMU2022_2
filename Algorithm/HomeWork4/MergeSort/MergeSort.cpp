#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int result = 0;

void merge(int a[], int low, int mid, int high);
void mergeSort(int a[],int low,int high);
void printList(int a[]);

int main (){
    int tc;
    cin >> tc;
    int a[100];
    for(int testcase=0; testcase<tc; testcase++){
        cin >> n;
        result = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        mergeSort(a,0,n-1);
        cout << result << '\n';
        
        result = 0;
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[100];
    for(int i=low; i<=high; i++){
        tmp[i] = a[i];
    }
    i = low;
    k = low;
    j = mid + 1;
    while(i <= mid && j <= high){
        result++;
        if(tmp[i] <= tmp[j]) {
            a[k++] = tmp[i++];
        }
        else a[k++] = tmp[j++];
    }
    while(i<=mid) a[k++] = tmp[i++];
    while(j<=high) a[k++] = tmp[j++];
}

void mergeSort(int a[],int low,int high){
    int mid;
    if(low == high) return;

    mid = (low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
}

void printList(int a[]){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}