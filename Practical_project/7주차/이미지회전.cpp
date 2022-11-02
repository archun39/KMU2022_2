#include <stdio.h>
#include <iostream>
using namespace std;

int img[50][50];

void reset();
void process(int n, int d);
void printImg(int n); 

int main(){
    int tc;
    cin >> tc;
    for(int testcase = 0; testcase < tc; testcase++){
        int n,d;
        cin >> n >> d;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                scanf("%1d",&img[row][col]);
            }
        }

        process(n,d);
        reset();
    }
}

void reset(){
    for(int row=0; row<50; row++){
        for(int col=0; col<50; col++){
            img[row][col] = 0;
        }
    }
}
void process(int n, int d){
    int tmp[n][n];
    if(d == 90 || d == -270){
        for(int row=0; row<n; row++){
            for(int col=n-1; col>=0; col--){
                cout << img[col][row];
            }
            cout << '\n';
        }
    }
    else if (d == 180 || d == -180){
        for(int row=n-1; row>=0; row--){
            for(int col=n-1; col>=0; col--){
                cout << img[row][col];
            }
            cout << '\n';
        }
    }
    else if(d==270 || d==-90){
        for(int row=n-1; row>=0; row--){
            for(int col=0; col<n; col++){
                cout << img[col][row];
            }
            cout << '\n';
        }
    }
    else{
        printImg(n);
    }
}

void printImg(int n){
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            cout << img[row][col];
        }
        cout << '\n';
    }
}