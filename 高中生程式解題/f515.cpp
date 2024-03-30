#include <string>
#include <vector>
#include <iostream>
#include <cctype>   // isalpha(), tolower
using namespace std;

char convert(string s){
    if(s == "for"){
        return '4';
    }
    else if(s == "you"){
        return 'u';
    }
    else if(s == "and"){
        return 'n';
    }
    else if(s == "to"){
        return '2';
    }
    return s[0] - 'a'+'A';
}

int main(){
    string it,answer;
    string x;
    getline(cin, it);
    for(int i = 0; i < it.size(); i++){
        if(it[i] != ' '){
            x+=tolower(it[i]);
        }
        else{
            answer += convert(x);
            x="";
        }
    }
    answer += convert(x);
    std::cout << answer << endl;
}