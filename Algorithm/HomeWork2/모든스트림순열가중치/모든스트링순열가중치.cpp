#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;


int usedword[9];
string s;
char words[9];
int s_len;
int answer;
int check;
int num;
int countdfs;

int w(int k, string s);
void dfs(string tmp);
int factorial(int n);

int main(){
    int t;
    cin >> t;
    for(int testCase = 0; testCase<t; testCase++){
        cin >> s;
        s_len = s.length();

        for(int i=0; i<s_len; i++){
            words[i] = s[i];
            usedword[i] = 1;
        }
        for(int i=0; i<s_len; i++){
            check += (int(s[i])-int('a'));
        }
        string tmp;

        if(s_len%2 ==0) {
            num = factorial(s_len/2);
        }
        else {
            num = factorial(s_len/2+1);
        }
        
        dfs(tmp);

        answer = factorial(s_len) - answer;
        
        cout << answer << endl;
        
        //초기화
        for(int i=0; i<9; i++){
            usedword[i] = 1;
            words[i] = ' ';
        }
        answer = 0;
        check = 0;
        num = 0;
        
        
    }
}

int factorial(int n){
    if(n==1) return 1;
    else return n*factorial(n-1);
}


int w(int k, string s){
    int answer = 0;
    for(int i=0; i<k; i++){
        answer += (int(s[i])-int('a'));
    }
    return answer;
}

void dfs(string tmp){
    if(tmp.length() == s_len/2){
        countdfs++;
        
        int total;
        if(check % 2== 0) total = check/2-1;
        else total = check/2;
        if(w(tmp.length(),tmp) > total) {
            answer += num;
        }
    }
    
        string s = tmp;
        for(int i=0; i<s_len; i++){
            if(usedword[i] == 1){
                usedword[i] = 0;
                s += words[i];
                dfs(s);
                s = tmp;
                usedword[i] = 1;
            }
        }
    
    
}


