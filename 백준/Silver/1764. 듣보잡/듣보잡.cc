#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    map<string, int> map;
    vector<string> v;
    int dbz =0;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        if(map.find(str) != map.end()){
            map[str] += 1;
        }
        else map[str] = 1;
    }
    for(int i=0; i<m; i++){
        string str;
        cin>>str;
        if(map.find(str) != map.end()){
            map[str] += 1;
        }
        else map[str] = 1;
    }

    for(auto i=map.begin(); i != map.end(); i++){
        if(i->second > 1){
            v.push_back(i->first);
            dbz++;
        }
    }
    cout<<dbz<<'\n';
    for(int i=0; i<v.size(); i++)        
        cout<<v[i]<<'\n';




	return 0;
}