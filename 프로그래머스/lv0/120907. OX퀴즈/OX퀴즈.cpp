#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(int i=0; i<quiz.size(); i++){    
        int x,y,z;
        char op, eq;
        
        stringstream ss;
        ss.str(quiz[i]);
        ss>>x>>op>>y>>eq>>z;
        
        if(op=='+'){
            if(x+y==z)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
        
        else if(op =='-'){
            if(x-y==z)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
    }       
    return answer;
}