#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(pair<int, string> a, pair<int,string> b);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,string>> A(n);

    for(int i=0; i<n; i++) {
        cin>>A[i].first;
        cin>>A[i].second;
    }

    stable_sort(A.begin(), A.end(), Comp);

    for(int i=0; i<n; i++) {
        cout<<A[i].first<<" ";
        cout<<A[i].second<<'\n';
    }

}

bool Comp(pair<int, string> a, pair<int,string> b){
        return a.first < b.first;
}
