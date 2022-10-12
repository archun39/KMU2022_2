#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

long long int process(vector<long long int> v);

int main(){
    int tc;
    cin >> tc;
    for(int testcase = 0; testcase<tc; testcase++){
        long long int d;
        cin >> d;
        vector<long long int> v;
        for(int i=0; i<d; i++){
            long long int num;
            cin >> num;
            v.push_back(num);
        }

        long long int result = process(v);
        
        cout << result << endl;
        
    }
}

long long int process(vector<long long int> v){
    long long int total = 0;
    long long int max = 0;
    for(int i=v.size()-1; i>=0; i--){
        if(v[i] > max){
            max = v[i];
        }
        else{
            total += max-v[i];
        }
    }
    return total;
}