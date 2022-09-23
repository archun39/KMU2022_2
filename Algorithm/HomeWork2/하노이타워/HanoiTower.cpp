#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int countC;
int third[10];
void hanoi(int n, int a, int b, int c);
int main(){
    int t;
    cin >> t;
    for(int testcase=0; testcase<t; testcase++){
        cin >> n;
        
        hanoi(n,1,3,2);

        countC = 0;
        for(int i=0; i<10; i++){
            third[i] = 0;
        }
        cout << endl;

    }
    

}

// a : 1, b : 3, c : 2
void hanoi(int n, int a, int b, int c){
    
    if(n>0){
        hanoi(n-1,a,c,b);
        if(b==3) {
            cout << n << " ";
            countC++;
            third[countC] = n;
        }
        if(a==3){
            countC--;
            if(countC==0) cout << 0 << " ";
            else cout << third[countC] << " ";
        }
        hanoi(n-1,c,b,a);
    }
}