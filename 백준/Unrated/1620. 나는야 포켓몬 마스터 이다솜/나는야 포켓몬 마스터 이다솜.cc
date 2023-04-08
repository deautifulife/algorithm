#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    map<int, string> pokeNum;
    map<string, int> pokeStr;
    vector<string> answer;

    for(int i=1; i<=n; i++) {
        string name;
        cin>>name;
        pokeNum.insert(make_pair(i,name));
        pokeStr.insert(make_pair(name,i));
    }

    for(int i=0; i<m; i++) {
        string quiz;
        cin>>quiz;
        if(quiz[0]<'A') { //포켓몬 이름이 아니고 도감번호면
            answer.push_back(pokeNum[stoi(quiz)]); //quiz는 string이어서 int형으로 형변환
        }
        else
            answer.push_back(to_string(pokeStr[quiz])); // 출력이 int이므로 string vector에 넣기위해 형변환

    }

    for(int i=0; i<m; i++) {
        cout<<answer[i]<<'\n';
    }
    

    return 0;
}