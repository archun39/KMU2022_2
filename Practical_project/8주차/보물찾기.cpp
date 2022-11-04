#include <stdio.h>
#include <iostream>
using namespace std;

string map[51][51];
int visited[51][51][4];
char dir[4] = {'F','B','R','L'};

int n;

void process(int row, int col, char l);
char nextDir(char bD, char mD);
void printMap();
void reset();


int main(){
    int tc;
    cin >> tc;
    for(int testcase=0; testcase<tc; testcase++){
        cin >>n;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                cin >> map[row][col];
            }
        }
        process(0,0,'B');
        reset();
    }
}
void reset(){
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++){
            for(int k=0; k<4; k++){
                visited[i][j][k] = 0;
            }
            map[i][j] = "A";
        }
    }
}
void process(int row, int col, char l){
   // printMap();
    
    string tmp = map[row][col];
    char d = tmp[0];
    int m = tmp[1] - '0';
    char nd = nextDir(l,d);


    int k;
    if(nd == 'F') k = 0;
    if(nd == 'B') k = 1;
    if(nd == 'R') k = 2;
    if(nd == 'L') k = 3;


    if(visited[row][col][k] == 1) {
        
        cout << row << " " << col << endl;
        return;
    }

   
    visited[row][col][k] = 1;
    
    //d = 지도에 표시된 방향,l = 전 이동 방향
    

    if(row+m < n || col+m < n || row-m >= 0 || col-m >= 0){
        if(nd == 'F') process(row+m,col,nd);
        if(nd == 'B') process(row-m,col,nd);
        if(nd == 'L') process(row,col-m,nd);
        if(nd == 'R') process(row,col+m,nd);
    }
    else cout << 0 << " " << 0 << endl;

}

//bD = 전 이동방향 , mD = 지도에 표시된 방향
char nextDir(char bD, char mD){
    if(bD=='F'){
        if(mD=='F') return 'F';
        if(mD=='R') return 'R';
        if(mD=='L') return 'L';
        if(mD=='B') return 'B';
    }
    if(bD=='R'){
        if(mD=='F') return 'R';
        if(mD=='R') return 'B';
        if(mD=='L') return 'F';
        if(mD=='B') return 'L';
    }
    if(bD=='L'){
        if(mD=='F') return 'L';
        if(mD=='R') return 'F';
        if(mD=='L') return 'B';
        if(mD=='B') return 'R';
    }
    if(bD=='B'){
        if(mD=='F') return 'B';
        if(mD=='R') return 'L';
        if(mD=='L') return 'R';
        if(mD=='B') return 'F';
    }
    return ' ';
}


void printMap(){
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            cout << visited[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

