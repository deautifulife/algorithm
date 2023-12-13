#include <iostream>
#include <vector>

int P[10001];
int S[10001];
int D[10001];
int N, K;

using namespace std;
	

int main() {

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
	}

	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= N; j++) {
			P[D[j]] = S[j];
		}
		for (int j = 1; j <= N; j++) {
			S[j] = P[j]; // 루프를 위해 기존 S값을 새로운 S값으로 변경
		}
	}

	for (int j = 1; j <= N; j++) {
		cout<<P[j]<<" ";
	}

	return 0;
}