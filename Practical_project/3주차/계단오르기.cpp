#include <iostream>
#include <stdio.h>
using namespace std;

int answer;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        int n,p;
        cin >> n >> p;
        if(n%2 == 0){
            if(p%2==0){
                answer = n/2+1;
            }
            else answer = n/2;
        }
        else{
            answer = n/2+1;
        }
        cout <<answer << endl;
    }
}