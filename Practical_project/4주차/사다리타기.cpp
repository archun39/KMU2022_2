#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int n, m, d;
int map[203][40003];
int mapSize;
int answer = 0;

void printMap();
void process(int row, int col);


int main() {
    int t;
    cin >> t;
    for(int testcase=0; testcase<t; testcase++){
        cin >> n >> m >> d;
        string s;
        cin.ignore();

        for(int i=0; i<m; i++){
            
            
            getline(cin, s);
            mapSize = s.length();
            for(int c=0; c<mapSize; c++){
                if(s[c] == '+') map[i][c+1] = 1;
            }
        }
        //printMap();
        process(m, d*2-1);
        cout << answer << '\n';

        //초기화
        for(int i=0; i<m+1; i++){
            for(int c=0; c<mapSize; c++){
                map[i][c+1] = 0;
            }
        }
        mapSize = 0;
        answer = 0;
    }
}

void printMap(){
    for(int row=0; row<m+1; row++){
        for(int col=0; col<mapSize+1; col++){
            cout << map[row][col] << " " ;
        }
        cout << '\n';
    }
    cout << '\n';
}

void process(int row,int col){
    
    int left,mid,right;
    left = map[row-1][col-1];
    mid = map[row-1][col];
    right = map[row-1][col+1];
    if(row == 1) answer = col/2+1;
    else {
        if(left == 0 && right == 0 && mid == 1) process(row-1,col);
        else if(left == 1&& right == 0 && mid == 1) process(row-1,col-2);
        else if(left == 0 && right == 1 && mid == 1) process(row-1,col+2);
    }
    
}