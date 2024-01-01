#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    if(N <= K || N < 1 || K < 1)
        return 0;
    vector<int> arr;
    vector<int> boob;
    for(int i = 1; i <= N; i++){
        arr.push_back(i);
        boob.push_back(0);//0->沒淘汰 1->淘汰
    }
    int index = 0;
    while(K > 0){
        for(int i = 1; i <= M-1; i++){
            if(boob[index] == 1){
                index = (index+1)%N;
                i--;
                continue;
            }
            index = (index+1)%N;
        }
        while(boob[index]){
            index = (index+1)%N;
        }
        boob[index] = 1;
        // for(int i = 0; i < N; i++){
        //     cout << boob[i];
        // }
        // cout<<endl;
        // cout << arr[index] << endl;
        K--;
    }
    while(boob[index]){
        index = (index+1)%N;
    }
    cout << arr[index];
}