#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int countThird;

void hanoi(int n, int from, int to, int tmp);


int main(){
    int t;
    cin >> t;
    for(int testCase = 0; testCase<t; testCase++){
        int n;
        cin >> n;
        
        //초기화
        countThird = 0;
        hanoi(n,1,3,2);

        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;

        v.erase(v.begin(),v.end());


    }
}

//from = 1, to = 3, tmp= 2;
void hanoi(int n, int from, int to, int tmp){
   if(n>0)
    {   
        hanoi(n-1,from,tmp,to);
        if(to==3){
            v.push_back(n);
            countThird++;
        }
        if(from == 3){
            countThird--;
            if(countThird== 0) v.push_back(0);
            else v.push_back(v[v.size()-2]);
        }
		hanoi(n-1,tmp,to,from);
        
    }
}