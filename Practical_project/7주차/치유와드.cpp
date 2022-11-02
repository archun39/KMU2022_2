#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[21][21];

void processPoison(vector<pair<int,int>> dead, int n, int m, int stack);
void processHeal(vector<pair<int,int>> ward, int n, int m, int stack);
void printMap(int n);
void reset();

int main()
{
    int tc;
    cin >> tc;
    for(int testcase=0; testcase<tc; testcase++){
        //n : 크기 , m : 시간
        int n,m;
        cin >> n >> m;
        
        //a : 시체 수 , b : 치유와드 수
        int a,b;
        cin >> a >> b;

        vector<pair<int,int>> dead;
        vector<pair<int,int>> ward;

        for(int i=0; i<a; i++){
            int row, col;
            cin >> row >> col ;
            dead.push_back({row,col});
        }

        for(int i=0; i<b; i++){
            int row, col;
            cin >> row >> col ;
            ward.push_back({row,col});
        }

        processPoison(dead,n,m,1);
        processHeal(ward,n,m,1);
        int poison = (m - n+1)*a;
        int heal = (m - 2*n+1)*b;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (poison > 0) map[i][j] -= poison;
                if (heal > 0) map[i][j] += heal;
            }
        }    
        printMap(n);
        reset();
    }
}

void reset(){
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            map[i][j] = 0;
       }
    }  
}

void processPoison(vector<pair<int,int>> dead, int n, int m, int stack){
    if(stack == n || stack == m + 1) return;
    
    int row,col;
    for(int i=0; i<dead.size(); i++){
        row = dead[i].first;
        col = dead[i].second;

        for(int r=row-stack; r<=row+stack; r++){
            for(int c=col-stack; c<=col+stack; c++){
                if(r>=0 && r<n && c>=0 && c<n) map[r][c] -= 1;
            }
        }
    }
    processPoison(dead, n, m, stack+1);
}

void processHeal(vector<pair<int,int>> ward, int n, int m, int stack){
    if(stack == 2 * n || stack == m + 1) return;
    int row,col;
    for(int i=0; i<ward.size(); i++){
        row = ward[i].first;
        col = ward[i].second;
        for(int r=row-stack; r<=row+stack; r++){
            for(int c=col-stack; c<=col+stack; c++){
                if(r>=0 && r<n && c>=0 && c<n) {
                    int tmp = abs(r-row)+abs(c-col);
                    if(stack >= tmp) {
                        map[r][c] += 1;
                    }
                }
            }
        }
    }
    processHeal(ward, n, m, stack+1);
}
void printMap(int n){
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            cout << map[r][c] << " ";
        }
        cout << endl;
    }
}