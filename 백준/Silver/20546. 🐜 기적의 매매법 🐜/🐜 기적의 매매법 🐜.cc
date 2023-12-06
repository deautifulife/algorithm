#include <iostream>

using namespace std;

int M;
int stock[14];
int Jmoney, Smoney, Jstock, Sstock;
int upcnt, downcnt;
int Jret, Sret;

void BMP(int day) {
	if (Jmoney >= stock[day]) {
		Jstock += Jmoney / stock[day];
		Jmoney = Jmoney % stock[day];
	}
}

void TIMING(int day) {
	if (day > 0 && stock[day] > stock[day - 1]) {
		upcnt++;
		downcnt = 0;
	}
	else if (day > 0 && stock[day] < stock[day - 1]) {
		downcnt++;
		upcnt = 0;
	}

	//전량매도
	if (upcnt >= 3) {
		Smoney += Sstock * stock[day];
		Sstock = 0;
	}
	//전량매수
	if (downcnt >= 3) {
		if (Smoney >= stock[day]) {
			Sstock += Smoney / stock[day];
			Smoney = Smoney % stock[day];
		}
	}
}
int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M;
	Jmoney =M, Smoney=M;
	for (int i = 0; i < 14; i++) {
		cin >> stock[i];
		BMP(i);
		TIMING(i);
	}

	Jret = Jmoney + stock[13] * Jstock;
	Sret = Smoney + stock[13] * Sstock;

	if (Jret > Sret)
		cout << "BNP";
	else if (Jret < Sret)
		cout << "TIMING";
	else if (Jret == Sret)
		cout << "SAMESAME";

	return 0;
}