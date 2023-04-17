#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> c;
    
    for(int i=0; i<s.length(); i++){
        if(c.empty()){
            c.push(s[i]);
        }
        else
            if(s[i]==')')
                c.pop();
            else
                c.push(s[i]);
    }
    if(c.empty())
        answer = 1;
    else
        answer = 0;
    

    return answer;
}