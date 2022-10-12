#include <stdio.h>
#include <iostream>
using namespace std;

int n;

int main(){
    int tc;
    cin >> tc;
    for(int testcase=0; testcase<tc; testcase++){
        cin >> n;
        int a[101];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        for(int i=1; i<n; i++){
            int tmp = a[i] + a[i-1];
            if(a[i] < tmp) a[i] = tmp;
        }
        int left = 0;
        int right = 0;
        int max = -1e9;
        for(int i=0; i<n; i++){
            if(a[i] > max){
                right = i;
                max = a[i];
            }
        }
        for(int i=right; i>=0; i--){
            if(a[i]>0) left = i;
            else break;
        }
        if(max <= 0) cout << 0 << " " << -1 << " " << -1 << '\n';
        else cout << max << " " << left << " " << right << '\n';
        
    }
}
