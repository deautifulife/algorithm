#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    vector<int> st;
    for(int i=0; i<db.size(); i++){
        if(db[i][0]==id_pw[0]){
            if(db[i][1]==id_pw[1]){
                st.push_back(1);    
            }
            else
                st.push_back(2);
        }
        else
            st.push_back(3);
    }
    sort(st.begin(), st.end());
    if(st[0]==1)
        answer+="login";
    else if(st[0]==2)
        answer+="wrong pw";
    else if(st[0]==3)
        answer+="fail";
    return answer;
}