#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<int> st;
    vector<int> v;
    vector<char> ans;

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }

    int stNum=1;
    for(int i=0; i<v.size(); i++){
        while(1){
            if(st.empty()){
                st.push(stNum);
                ans.push_back('+');
                stNum++;
            }
            else if(st.top()>v[i]){
                cout<<"NO";
                return 0;
            }
            else{
                if(st.top()==v[i]){
                    st.pop();
                    ans.push_back('-');
                    break;
                }
                else{
                    st.push(stNum);
                    ans.push_back('+');
                    stNum++;
                }
            }             
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<'\n';
    }
}