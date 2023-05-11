#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s,t;
    while(cin>>s>>t){
        int sIdx = 0;
        bool isTrue = false;
        for(int i=0; i<t.length(); i++){
            //문자열 찾기
            if(s[sIdx] == t[i])
                sIdx++;
            
            //다 찾으면
            if(sIdx == s.length()){
                isTrue=true;
                break;
            }
        }
        if(isTrue)
            cout<<"Yes"<<'\n';
        else
            cout<<"No"<<'\n';
    }

	return 0;
}