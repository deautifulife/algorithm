#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    vector<int> a;
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());

    cin>>m;
    for(int i=0; i<m; i++){
        int number;
        cin>>number;

        cout<<binary_search(a.begin(), a.end(), number)<<'\n';
    }


    return 0;
}
