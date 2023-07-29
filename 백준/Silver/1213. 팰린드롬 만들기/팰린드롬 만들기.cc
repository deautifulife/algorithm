#include <iostream>
#include <vector>

using namespace std;

int alpha[26];

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string name;
	cin>>name;
	for(int i=0; i<name.length(); i++){
		alpha[name[i]-'A']++;
	}

	//1. 펠린드롬을 만들 수 있는지 체크
	int cnt=0;
	char save;
	for(int i=0; i<26; i++){
		if(alpha[i]%2==1){
			cnt++;
			save = i+'A';
			alpha[i]--;
		}
		//홀수개의 알파벳이 2개 이상이면 펠린드롬을 못만든다.
		if(cnt>1){
			cout<<"I'm Sorry Hansoo";
			return 0;
		}
	}

	vector<char> answer;
	//2. 펠린드롬 만들기
	for(int i=0; i<26; i++){
		if(alpha[i]>=1){
			int temp = alpha[i];
			if(temp >= 2){
				while(alpha[i] > temp/2){
					answer.push_back(i+'A');
					alpha[i]--;
				}
			}
			else{
				answer.push_back(i+'A');
				alpha[i]--;
			}
		}
	}
	if(cnt==1){
		answer.push_back(save);
	}
	
	for(int i=25; i>=0; i--){
		if(alpha[i]>=1){
			int temp = alpha[i];
			for(int j=0; j<temp; j++){
				answer.push_back(i+'A');
				alpha[i]--;
			}
		}
	}

	for(int i=0; i<answer.size(); i++){
		cout<<answer[i];
	}

}