#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    // vector<string> A(n);
    string A[n];

    for(int i=0; i<n; i++) {
        cin>>A[i];
    }

    sort(A,  A + n, compare);

    string before;
    for(int i=0; i<n; i++) {
        if(before == A[i]) //중복 단어 제거
            continue;
        cout<<A[i]<<'\n';
        before = A[i];
    }

}

bool compare(string a, string b){
    if(a.length() != b.length()) {
        return a.length() < b.length();
    }
    else
        return a < b;
}