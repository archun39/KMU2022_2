#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int t;
string s;


void swap(int low, int high);
void reverseArray(string s,int low, int high);

int main(){
    cin >> t;
    for(int testCase=0; testCase<t; testCase++){
        cin >> s;
        
        reverseArray(s,0,s.length()-1);
        cout <<  s << endl;
    }
}


void swap(int low, int high){
    char tmp = s[low];
    s[low] = s[high];
    s[high] = tmp;
}

void reverseArray(string s, int low, int high){
    if(low<high){
        swap(low,high);
        reverseArray(s,low+1,high-1);
    }
}