#include <stdio.h>
#include <iostream>
using namespace std;

int map[8][8];
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int idx = 1;
int m,n,s,t;
bool complete;

void printMap();
void dfs(int row, int col, int idx);
void reset();

int main(){
    int tc;
    cin >> tc;
    for(int testCase=0; testCase<tc; testCase++){
        cin >> m >> n >> s >> t;
        map[s-1][t-1] = idx;
        dfs(s-1,t-1,idx);
        if(complete == true){
            cout << 1 << '\n';
            printMap();
        }
        else cout << 0 << '\n';

        reset();
    }
}

void reset(){
    for(int row=0; row<8; row++){
        for(int col=0; col<8; col++){
            map[row][col] = 0;
        }
    }
    idx = 1;
    complete = false;
}

void dfs(int row, int col, int idx){
    if(idx == m*n) {
        complete = true;
    }
    for(int i=0; i<8; i++){
        int nx = row + dx[i];
        int ny = col + dy[i];
        if(nx>=0 && ny>=0 && nx<m && ny<n){
            if(map[nx][ny] == 0){
                idx++;
                map[nx][ny] = idx;
                dfs(nx,ny,idx);
                if(complete == false){
                     idx--;
                    map[nx][ny] = 0;
                }
            }
        }   
    }
}


void printMap(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}