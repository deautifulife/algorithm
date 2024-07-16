#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<string> v;
set<string> s;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
	int n,k;
	cin>>n>>k;

	//나의 카드 추가
	for(int i=0; i<n; i++){
		string num;
		cin>>num;
		v.push_back(num);
	}

	//k값에 따른 완탐
	if(k==2){
		for(int i=0; i<v.size(); i++){
			for(int j=0; j<v.size(); j++){
				if(i==j)
					continue;
				string temp= "";
				temp += v[i];
				temp += v[j];
				s.insert(temp);
			}
		}
	}

	else if(k==3){
		for(int i=0; i<v.size(); i++){
			for(int j=0; j<v.size(); j++){
				for(int k=0; k<v.size(); k++){
					if(i==j || i==k || j==k)
						continue;
					string temp = "";
					temp += v[i];
					temp += v[j];
					temp += v[k];
					s.insert(temp);
				}
			}
		}
	}

	else if(k==4){
		for(int i=0; i<v.size(); i++){
			for(int j=0; j<v.size(); j++){
				for(int k=0; k<v.size(); k++){
					for(int l=0; l<v.size(); l++){
						if(i==j || i==k || i==l || j==k || j==l || k==l)
						continue;
					string temp = "";
					temp += v[i];
					temp += v[j];
					temp += v[k];
					temp += v[l];
					s.insert(temp);
					}
				}
			}
		}
	}

	cout<<s.size();
    
    return 0;
}