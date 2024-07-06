#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t;
	while(cin>>s>>t){
		int cnt=0;
		bool isTrue = false;
		for(int i=0; i<t.length(); i++){
			if(t[i] == s[cnt]){
				cnt++;
			}
			if(cnt == s.length()){
				isTrue = true;
				break;
			}
		}
		
		if(isTrue)
			cout<<"Yes"<<'\n';
		else
			cout<<"No"<<'\n';
	}

	return 0;
}