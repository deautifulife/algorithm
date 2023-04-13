#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> tree;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int height;
        cin>>height;
        tree.push_back(height);
    }

    sort(tree.begin(), tree.end());

    long long s = 0;
    long long e = tree[n-1];
    long long mid = (s+e)/2;
    long long sum = 0;
    int result =0;

    while(s <= e){
        sum = 0;
        mid = (s+e)/2;
        for(int i=0; i<n; i++){
            if(tree[i] - mid > 0)
                sum += tree[i] - mid;
        }
        if(sum >= m){
            s= mid+1;
            result = mid;
        }
        if(sum < m)
            e= mid-1;
    }
    cout<<result;

    return 0;
}