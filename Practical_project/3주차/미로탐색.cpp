#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int t;
int n,m;
int map[101][101];
int tmp[101][101];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(int x, int y);
void resetmap();


int main(){
    cin >> t;
    vector<int> ans;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        for(int a=0; a<n; a++){
            for(int b=0; b<m; b++){
                scanf("%1d",&map[a][b]);
            }
        }
        bfs(0,0);
        cout << tmp[n-1][m-1]+1 <<endl;
        resetmap();

    }

}

void bfs(int x, int y){

    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(x == n-1 && y == m-1) break;
        for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(map[nx][ny] == 1){
                    map[nx][ny] = 0;
                    if(tmp[nx][ny] == 0) tmp[nx][ny] = tmp[x][y] + 1;

                    q.push({nx,ny});
                }
            }

        }
        
    }
    
}

void resetmap(){
    for(int i = 0; i<101;i++){
        for(int j =0; j<101; j++){
            map[i][j] = 0;
            tmp[i][j] = 0;
        }
    }
}

