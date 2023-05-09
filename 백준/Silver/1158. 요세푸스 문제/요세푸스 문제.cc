#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    vector<int> ans;

    cin>>n>>k;
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }

    while(!q.empty()){
        for(int i=1; i<=k; i++){
            if(i==k){
                ans.push_back(q.front());
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
    }
    cout<<"<";
    for(int i=0; i<ans.size(); i++){
        if(i==ans.size()-1){
            cout<<ans[i]<<">";
        }
        else
            cout<<ans[i]<<','<<" ";
    }
}