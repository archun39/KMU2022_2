#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t;
int N,M,A,B;
vector<tuple<int,int,int>> v;
vector<tuple<int,int,int>> tmp;
vector<int> w;
queue<pair<int,int>> q; //
bool visited[1000]; //  
int targetWeight; //
bool possible = false; // 

bool bfs();
void binarySearch(int idx, bool detect);

int main(){
    cin >> t;
    for(int testCase = 0; testCase<t; testCase++){
        cin >> N >> M >> A >> B;
        for(int roadNum = 0; roadNum<M; roadNum++){
            int O,D,C;
            cin >> O >> D >> C;
            v.push_back({O,D,C});
            w.push_back(C);
        }
        sort(w.begin(),w.end());
        //무게중복 제거
        w.erase(unique(w.begin(),w.end()),w.end());
        int idx = w.size()/2;
        
        while(w.size()>1){
            targetWeight = w[idx];
            for(int i=0; i<v.size(); i++){
                if(get<2>(v[i]) >= targetWeight){
                    tmp.push_back({get<0>(v[i]),get<1>(v[i]),get<2>(v[i])});
                    if(get<0>(v[i]) == A) q.push({A,get<1>(v[i])});
                    if(get<1>(v[i]) == A) q.push({A,get<0>(v[i])});
                }
            }
            
            binarySearch(idx,bfs());

            //초기화
            while(!q.empty()){
                q.pop();
            }
            idx = w.size()/2;
            tmp.clear();
            for(int i=0; i<1000; i++){
                visited[i] =false;
            }
            possible = false;

            
        }
        
        cout << w[0] << endl;
        v.clear();
        w.clear();  
    }
}


void binarySearch(int idx, bool detect){
    
    if(detect){
        w.erase(w.begin(),w.begin()+idx);
    }
    else{
       w.erase(w.begin()+idx,w.end());
    }
}

bool bfs(){
    while(!q.empty()){
            int from = q.front().first;
            int to = q.front().second;
            visited[from] = true;
            q.pop();
            if(to == B) {
                return true;
            }
            for(int i=0; i<tmp.size(); i++){
                if(visited[to] == false){
                    if(to == get<0>(tmp[i])) q.push({to,get<1>(tmp[i])});
                    else if(to == get<1>(tmp[i])) q.push({to,get<0>(tmp[i])});
                }
            }
    }
    return false;
}

