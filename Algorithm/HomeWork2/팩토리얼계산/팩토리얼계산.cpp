#include <stdio.h>
#include <iostream>
using namespace std;

int answer;
int factorial(int n);

int main(){
    int t;
    cin >> t;
    for( int testCase=0; testCase<t; testCase++){
        int n;
        cin >> n;

        answer = factorial(n);

        cout << answer << endl;
    }
}

int factorial(int n){
    if(n == 0) return 1;
    else{
        int tmp = n;
        if(tmp%100 == 0) tmp /= 100;
        if(tmp%10 == 0) tmp /= 10;
        int answer = tmp * factorial(n-1);
        while(true){
            if (answer % 10 == 0){
                answer /=10;
            }
            else break;
        }
        return answer % 1000;
    }
}