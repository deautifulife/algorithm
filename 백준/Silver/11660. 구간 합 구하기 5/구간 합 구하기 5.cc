#include <iostream>

using namespace std;

long long board[1025][1025];
long long sum[1025][1025];
int n,m;
int ret[100001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n>>m;
	for (int y = 1; y <= n; y++) {
		sum[y][0] = sum[y - 1][n];
		for (int x = 1; x <= n; x++) {
			cin>>board[y][x];
			sum[y][x] = sum[y - 1][x] + sum[y][x - 1] + board[y][x] - sum[y - 1][x - 1];
		}
	}
	
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		ret[i] = sum[y2][x2] - sum[y1-1][x2] - sum[y2][x1-1] + sum[y1-1][x1-1];
	}

	for (int i = 0; i < m; i++) {
		cout << ret[i]<<'\n';
	}

	

	return 0;
}