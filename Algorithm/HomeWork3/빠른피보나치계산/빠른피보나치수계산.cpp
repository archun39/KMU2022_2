#include <stdio.h>
#include <iostream>

using namespace std;

int map[2][2] = {{1,1},{1,0}};
int F[2][2] = {{1,1},{1,0}};

void fibo(int n);
void printFibo();

int main(){
    int t;
    cin >> t;
    for(int testCase=0; testCase<t; testCase++){
        int n;
        cin >> n;

        //"피사노 주기"
        //주기의 길이가 P 이면, N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M을 나눈 나머지와 같습니다. 
        //M = 10k 일 때, k > 2 라면, 주기는 항상 15 × 10k-1 입니다
        
        
        fibo(n%1500);
        

        int answer = F[1][1];
        

        cout << answer << endl;
        
        F[0][0] = 1;
        F[1][0] = 1;
        F[0][1] = 1;
        F[1][1] = 0;

    }
}

void fibo(int n){
    if(n>0){
    int tmp00 = F[0][0]*map[0][0] + F[1][0]*map[1][0];
    int tmp01 = F[0][0]*map[0][1] + F[0][1]*map[1][1];
    int tmp10 = F[1][0]*map[0][0] + F[1][1]*map[1][0];
    int tmp11 = F[1][0]*map[0][1] + F[1][1]*map[1][1];
    F[0][0] = tmp00%1000;
    F[0][1] = tmp01%1000;
    F[1][0] = tmp10%1000;
    F[1][1] = tmp11%1000;
    fibo(n-1);
    
    }
   
}

void printFibo(){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}