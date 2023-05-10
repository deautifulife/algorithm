#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    float cnt =0;
    map<string, float> m;

    while(getline(cin,str)){
        cnt++;
        //문자열이 map에 이미 있으면 (데이터를 끝까지 못찾을 경우 map.end()를 반환하는데 찾았다는 뜻이니까)
        if(m.find(str) != m.end())
            m[str] += 1;
        else m[str] = 1;
    }

    //소수점 4자리까지 고정
    cout<<fixed;
    cout.precision(4);

    for(auto i=m.begin(); i != m.end(); i++){
        float val = (i->second / cnt) * 100; //비중
        cout<<i->first<<" ";
        cout<<val<<'\n';
    }
    return 0;
}