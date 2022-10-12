#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n,m,d;
int map[202][200];

void printMap(int row, int col);
void process(int row, int col);
void answer(int col);
void reset();

int main(){
    int tc;
    cin >> tc;
    for(int testcase=0; testcase<tc; testcase++){
        cin >> n >> m >> d;
        string s;
        cin.ignore();
        int mapSize;
        for(int i=0; i<m; i++){
            getline(cin,s);
            mapSize = s.length();
            for(int c=0; c<mapSize; c++){
                if(s[c] == '+') map[i][c+1] = 1;
                if(s[c] == '?') map[i][c+1] = 2;
            }
        }
        process(m, d*2-1);
        //cout << "---" <<endl;
        //printMap(m,mapSize+2);
        answer(mapSize+2);

        reset();
    }
}

void reset(){
    for(int r=0; r<202; r++){
        for(int c=0; c<200; c++){
            map[r][c] = 0;
        }
    }
}

void printMap(int row, int col){
    for(int r=0; r<row; r++){
        for(int c=0; c<col; c++){
            cout << map[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void answer(int col){
    for(int i=0; i<col; i++){
        if(map[0][i] == 3) cout << i/2+1 << " ";
    }

    cout << endl;
}

void process(int row, int col){
    int left,mid,right;
    left = map[row-1][col-1];
    right = map[row-1][col+1];
    mid = map[row-1][col];
    if(row==1) map[row-1][col] = 3;
    else{
        if(left == 2 || right == 2 || mid == 2){
            process(row-1,col);
            process(row-1,col-2);
            process(row-1,col+2);
        }
        else{
            if(left == 0 && right == 0 && mid == 1) process(row-1,col);
            else if(left == 1&& right == 0 && mid == 1) process(row-1,col-2);
            else if(left == 0 && right == 1 && mid == 1) process(row-1,col+2);
        }
    }
}