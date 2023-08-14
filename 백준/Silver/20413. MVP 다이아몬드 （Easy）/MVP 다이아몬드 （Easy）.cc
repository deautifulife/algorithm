#include <iostream>
#include <vector>

using namespace std;

char grade[36];

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; //게임 플레이 개월
	int s,g,p,d; //등급 가격
	
	cin>>n;
	cin>>s>>g>>p>>d;
	for(int i=0; i<n; i++){
		cin>>grade[i];
	}

	int prev =0;
	int pay,sum=0;
	for(int i=0; i<n; i++){
		if(grade[i]=='B'){
			pay = s-1 - prev;
		}
		else if(grade[i]=='S'){
			pay = g-1-prev;
		}
		else if(grade[i]=='G'){
			pay = p-1-prev;
		}
		else if(grade[i]=='P'){
			pay = d-1-prev;
		}
		else if(grade[i]=='D'){
			pay = d; //최대이므로 한달에 최대 다이아몬드 등급 기준액까지 과금이 가능.
		}
		sum += pay;
		prev = pay;
	}

	cout<<sum;
}