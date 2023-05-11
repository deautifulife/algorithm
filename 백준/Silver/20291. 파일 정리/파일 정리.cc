#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    map<string, int> m;
    cin>>n;
    for(int i=0; i<n; i++){
        // cin>>v[i];
        string str;
        string ext;
        cin>>str;
        
        //확장자 분리
        ext = str.substr(str.find('.')+1);
        
        //확장자가 이미 있으면
        if(m.find(ext) != m.end())
            m[ext] += 1;
        else m[ext] = 1;
    }

    // //사전순 정렬
    // sort(m.begin(), m.end());

    //출력
    for(auto i=m.begin(); i != m.end(); i++){
        cout<<i->first<<" "<<i->second<<'\n';
    }

    
	return 0;
}