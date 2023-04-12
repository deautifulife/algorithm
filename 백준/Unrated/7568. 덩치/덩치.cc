#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x,y;
    vector<pair<int,int>> spec;
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>x>>y;
        spec.push_back(make_pair(x,y));
    }
    
    for(int i=0; i<n; i++) {
        int rank = 1;
        for(int j=0; j<n; j++) {
            if(spec[i].first < spec[j].first && spec[i].second < spec[j].second) //키,몸무게 둘다 i보다 큰 j가 나올때마다
                rank++;//등수 밀려남
        }
        cout<<rank<<" ";
    }

    return 0;

}
