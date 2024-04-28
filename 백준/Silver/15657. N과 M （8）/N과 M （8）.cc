#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[9];
int sequence[9];

void makesequence(int depth){
    if(depth == m){
        for (int index = 0; index < m; index++) {
            cout << sequence[index] << ' ';
        }
        cout << '\n';
        return;
    }

    else{
        for(int index = 0; index < n; index++){
            if(num[index] >= sequence[depth-1]){
                sequence[depth] = num[index];
                makesequence(depth+1);
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    sort(num, num+n);

    makesequence(0);

	return 0;
}