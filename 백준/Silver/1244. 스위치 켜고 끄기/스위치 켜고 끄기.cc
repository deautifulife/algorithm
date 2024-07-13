#include <iostream>

using namespace std;

bool swit[100];
int n,s;

void trans(int numb){
	if(swit[numb]==1)
		swit[numb]=0;
	else
		swit[numb]=1;
}

void turn(int sex, int num){
	if(sex == 1){
		int mul = 1;
		while(num * mul <= n){
			trans(num*mul);
			mul++;
		}
	}
	else{
		trans(num);
		int cnt=1;
		while(1){
			if(num-cnt > 0 && num+cnt <= n && swit[num-cnt] == swit[num+cnt]){
				trans(num-cnt);
				trans(num+cnt);
			}
			else
				break;

			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1; i<=n; i++){
		bool cur;
		cin>>cur;
		swit[i] = cur;
	}

	cin>>s;
	for(int i=1; i<=s; i++){
		int sex, num;
		cin>>sex>>num;
		turn(sex,num);
	}


	for(int i=1; i<=n; i++){
		cout<<swit[i]<<' ';
		if (i % 20 == 0) {
			cout<<'\n';
		}
	}
	return 0;
}
