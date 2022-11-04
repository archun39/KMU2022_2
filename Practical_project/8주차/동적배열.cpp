#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int answer;

int arr[101];
int arrSize[101];

void process(int a, int c);
int GetEleNum(int a);
int findNewSize(int tmp);
void printV(int a);
void reset();

int main(){
    int tc;
    cin >> tc;
    for(int testcase=0; testcase<tc; testcase++){
        int n;
        cin >> n;
        
        for(int i=0; i<n; i++){
            int a,c;
            cin >> a >> c;
            process(a,c);
        }
        cout << answer << endl;

        reset();
    }
}

void reset(){
    for(int i=0; i<101; i++){
        arr[i] = 0;
        arrSize[i] = 0;
    }
    
    answer = 0;
}

void printV(int a){
    cout << arr[a] << endl;
}
void process(int a, int c){
    //cout << "-----" << endl;
    
    int size = arrSize[a]; //2의 제곱 수
    //cout << size << " : size" << endl;
    int eleNum = GetEleNum(a);
    //cout << eleNum << " : elenum" << endl;
    if((c + eleNum) > size){
        answer += eleNum;
        size = findNewSize(c+eleNum);
        //cout << size << " : newSize" << endl;
        arrSize[a] = size;
        //복사
        arr[a] = c+eleNum;
    }
    //크기가 충분한 경우
    else{
        arr[a] = c+eleNum;
    }
    //printV(a);
}

int GetEleNum( int a){
    return arr[a];
}

int findNewSize(int tmp){
    int newSize;
    for(int i=0; i<100; i++){
        newSize = pow(2,i);
        if(tmp < newSize) break;
    }
    return newSize;
}
