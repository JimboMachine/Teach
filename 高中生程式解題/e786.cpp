#include<iostream>
#include<vector>

using namespace std;

bool isValid(char s){
    if((s >='A' && s <='Z') || (s >='a' && s <'z') || (s >='0' && s <'9')){
        return true;
    }
    return false;
}

int mian(){
    std::string w;
    bool status = false;
    cin >> w;
    int length = w.size();
    for(int i = 0; i < length; i++){
        status = isValid(w[i]);
    }
    if(status){
        std::string ss = "";
        for(int i = 0; i < length/2; i++){
            if(w[i] == w[length-1-i]){
                ss+=w[i];
            }
            else{
                status = false;
                break;
            }
        }
        if(length%2 == 0){
            status = false;
        }
        if(status){
            cout << "YES" << endl;
            cout << ss;
        }
    }
    if(status == false){
        cout << "NO";
    }
    return 0;
}