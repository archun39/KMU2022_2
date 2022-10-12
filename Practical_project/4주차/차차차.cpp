#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int N;
int map[100][5];
bool canGo[100][5];

void printMap();
void mapping();
int process();
void reset();
int compareMax(int row,int col);
int setValue(int row,int col);

int main(){
    int t;
    cin >> t;
    for(int testcase=0; testcase<t; testcase++){
        cin >> N;
        int n;
        for(int row=0; row<N; row++){
            for(int col=0; col<5; col++){
                cin >> n;
                if(n==1) map[row][col] = -1;
                else map[row][col] = n;
                //출발지점 세팅
                if(row == N-1 && map[row][col] != -1) {
                    if(col > 0 && col < 4 )canGo[row][col] = true;
                }
            }
        }
        mapping();

        int result = process();

        //printMap();
        cout << result << '\n';

        //초기화
        reset();

        
    }
}
void printMap(){
    for(int row=0; row<N; row++){
        for(int col=0; col<5; col++){
           cout << map[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int row=0; row<N; row++){
        for(int col=0; col<5; col++){
           cout << canGo[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void mapping(){
    for(int row=0; row<N; row++){
        for(int col=0; col<5; col++){
           if(map[row][col] == -1) {
               if(col-1 >=0 && map[row][col-1] != -1)  map[row][col-1]++;
               if(col+1 <5 && map[row][col+1] != -1 ) map[row][col+1]++;
           }
        }
    }
}

//비교값이 -1일 경우
int process(){
    for(int row=N-1; row>=0; row--){
        for(int col=0; col<5; col++){
            if(row<N && map[row][col] != -1 && (canGo[row+1][col] == true || canGo[row+1][col+1] == true || canGo[row+1][col-1] == true)) canGo[row][col] = true;
        }
    }
    for(int row=N-1; row>=0; row--){
        for(int col=0; col<5; col++){
            if(row< N && map[row][col] != -1){
                map[row][col] += compareMax(row,col);
            }
        }
    }
    
    vector<int> v;
    for(int i=0; i<5; i++){
        if(canGo[0][i] == true){
            v.push_back(map[0][i]);
        }
    }
    int answer = 0;
    for(int i=0; i<v.size(); i++){
        answer = max(answer,v[i]);
    }
    return answer;
}

void reset(){
    for(int row=0; row<N; row++){
            for(int col=0; col<5; col++){
               map[row][col] = 0;
               canGo[row][col] = false;
            }
        }
}
int setValue(int row, int col){
    if(col>=0 && col<5){
        if(canGo[row][col] == true) return map[row][col];
    }
    return 0;
}

int compareMax(int row,int col){
    int left = setValue(row+1,col-1);
    int mid = setValue(row+1,col);
    int right = setValue(row+1,col+1);
    
    int result = max({left,mid,right,0});

    return result;
    
}