#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> vec;
int v;
int cnt;

int main(void) {

    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        vec.push_back(num);
    }

    cin>>v;

    for(int i=0; i<vec.size(); i++){
        if(vec[i] == v){
            cnt++;
        }
    }
    
    cout<<cnt;

    return 0;
}
