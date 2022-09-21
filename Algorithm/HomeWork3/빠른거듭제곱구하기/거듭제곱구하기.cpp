#include <stdio.h>
#include <iostream>
using namespace std;

int a, n;
int expo(int a,int n);
int main(){
    int t;
    cin >> t;
    for(int testCase=0; testCase<t; testCase++){
        cin >> a >> n;

        int answer = expo(a,n);
        cout << answer << endl;
    }
    
}

int expo(int a, int n){
    if(n <= 0) return 1;
    else{
        if(n%2 == 1){
            int b = expo(a,(n-1)/2);
            int ans = a*b*b%1000;
            return ans;
        }
        else{
            int b = expo(a,n/2);
            int ans = b*b%1000;
            return ans;
        }
    }
}