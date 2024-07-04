#include <iostream>

using namespace std;

int jm, sm; //준현이 성민잉 가진 현금
int js, ss; //둘의 주식 보유수
int stock[14];
int upcnt, downcnt;

void BNP(int price){
	if(jm > price){
		js += jm/price;
		jm = jm%price;
	}
}

void TIMING(int price){
	if(sm > price){
		if(upcnt >= 3){
		sm += ss*price; //전량 매도
		ss = 0;
		}
		if(downcnt >= 3){
			ss += sm/price; //전량 매수
			sm = sm%price;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int money;
	cin>>money;

	jm = money;
	sm = money;
	
	for(int i=0; i<14; i++){
		cin>>stock[i];
		BNP(stock[i]);
		if(i>0 && stock[i] > stock[i-1]){
			upcnt++;
			downcnt = 0;
		}
		if(i>0 && stock[i] < stock[i-1]){
			downcnt++;
			upcnt = 0;
		}
		TIMING(stock[i]);
	}

	jm += stock[13] * js;
	sm += stock[13] * ss;

	if(jm > sm)
		cout<<"BNP";
	else if(jm < sm)
		cout<<"TIMING";
	else if(jm == sm)
		cout<<"SAMESAME";

	return 0;
}