#include <stdio.h>
#include <iostream>

using namespace std;

int gcb(int a, int b);

int main(){
    int  t;
    cin >> t;
    for(int testCase=0; testCase<t; testCase++){
        int a, b;
        cin >> a >> b;

        int answer = gcb(a,b);

        cout << answer << endl;
    }

}

int gcb(int a, int b){
    if(b==0) return a;
    if(b>0){
        return gcb(b,a%b);
    }
    return 0;
}