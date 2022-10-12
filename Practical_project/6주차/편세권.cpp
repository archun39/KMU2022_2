#include <stdio.h>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int n,c;
int map[50][50];

void mapping(vector<pair<int,int>> v);
void printMap();
tuple<int,int,int> result();
void reset();

int main(){
    int tc;
    cin >> tc;
    for(int testcase = 0; testcase < tc; testcase++){
        cin >> n >> c;
        vector<pair<int,int>> v;
        for(int i=0; i<c; i++){
            int row,col;
            cin >> row >> col;
            v.push_back({row,col});
        }
        
        mapping(v);
        tuple<int,int,int> ans = result();

        cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << endl;
        
        reset();
    }
}

void mapping(vector<pair<int,int>> v){
    for(int i=0; i<v.size(); i++){
        int row = v[i].first;
        int col = v[i].second;
        map[row][col] = -1;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(map[j][k] != -1){
                    int tmp = abs(row-j) + abs(col-k);
                    if(tmp <= 10) map[j][k] += 1;
                    if(tmp <= 3) map[j][k] +=2 ;
                }
            }
        }
    }
}

tuple<int,int,int> result(){
    int max = -1;
    int r,c;
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(map[row][col] > max){
                r = row;
                c = col;
                max = map[row][col];
            }
        }
    }

    return {r,c,max};
}
void reset(){
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            map[row][col] = 0;
        }
    }
}
void printMap(){
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            cout << map[row][col] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}