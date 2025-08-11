//문제 이해가 더 어려움

#include <iostream>  
#include <string> 
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0; 
}