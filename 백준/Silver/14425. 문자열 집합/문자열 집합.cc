#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_set<string> st;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        st.insert(s);
    }

    int ans = 0;
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        if(st.find(s) != st.end())
            ans++;
    }
    cout<<ans;
}