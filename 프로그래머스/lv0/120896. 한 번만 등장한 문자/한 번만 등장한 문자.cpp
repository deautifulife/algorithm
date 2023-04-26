#include <string>
#include <vector>

using namespace std;

int check[26];

string solution(string s) {
    string answer = "";
    
    for(int i=0; i<s.length(); i++){
        check[s[i]-'a']++;
    }
    
    for(int i=0; i<26; i++){
        if(check[i]==1)
            answer.push_back(i+'a');
    }
    
    return answer;
}