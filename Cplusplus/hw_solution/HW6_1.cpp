#include<iostream>
#include<string>
#include<stack>
using namespace std;
// Leetcode 20. Valid Parentheses

class Solution {
public:
    bool compare(char a,char b){
        if(a == '(' && b == ')')return true;
        if(a == '{' && b == '}')return true;
        if(a == '[' && b == ']')return true;
        return false;
    }

    bool isValid(string s) {
        if(s.size() == 0)return true;
        if(s.size() % 2 == 1)return false;
        stack<char> leftSign;
        char temp = ' ';
        for(auto it:s){
            if(it == '(' || it == '[' || it == '{'){
                temp = it;
                leftSign.push(it);
            }
            else{
                if(leftSign.empty())
                    return false;
                temp = leftSign.top();
                leftSign.pop();
                if(!compare(temp,it))
                    return false;
            }
        }
        return leftSign.empty();
    }
};