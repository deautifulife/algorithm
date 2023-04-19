#include <string>
#include <vector>
#include <map>


using namespace std;

string solution(string letter) {
    string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string answer = "";
    string str="";
    vector<string> v;
    map<string, int> m;
    
    for(int i=0; i<26; i++){
        m.insert(make_pair(morse[i],i));
    }
    
    for(int i=0; i<letter.length(); i++){
        if(letter[i]==' '){
            v.push_back(str);
            str="";
        }
        else
            str += letter[i];
    }
    v.push_back(str); //마지막에는 공백이없으니
    
    for(int i=0; i<v.size(); i++){
        answer.push_back((char)m[v[i]]+'a');
    }
    
    return answer;
}