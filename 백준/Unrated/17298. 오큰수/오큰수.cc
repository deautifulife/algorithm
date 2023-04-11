#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> s;
int ans[1000001];
int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    //수열 입력
    for(int i=0; i<n; i++) 
        cin>>arr[i];
    
    //오큰수
    for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top()<=arr[i]) //스택이 비지 않고, 스택의 top보다 현재 인덱스값이 클때
                s.pop();

            if(s.empty())
                ans[i] = -1; //스택이 다 비었으면 오큰수가없다.
            else
                ans[i] = s.top(); //안비었으면 스택의 top이 오큰수

            s.push(arr[i]);
    }

    //출력
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";

    return 0;

}
