#include <iostream>
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

using namespace std;

int n, sum = 0;
int map[21][21] = { 0, };

int solve(int x, int y, int d1, int d2) {
	int temp[21][21] = { 0, };
	temp[x][y] = 5;
	//(x,y), (x+1, y-1) , ..., (x+d1, y-d1)
	//(x+d2, y+d2),(x+d2+1,y+d2-1),...,(x+d2+d1,y+d2-d1)
	for (int i = 1; i <= d1; i++) {
		temp[x + i][y - i] = 5;
		temp[x + d2+i][y + d2-i] = 5;
	}
	//(x,y), (x+1,y+1), ...,(x+d2,y+d2)
	//(x+d1,y-d1),(x+d1+1,y-d1+1),...,(x+d1+d2,y-d1+d2)
	for (int i = 1; i <= d2; i++) {
		temp[x + i][y + i] = 5;
		temp[x + d1+i][y -d1 + i] = 5;
	}

	//1번 선거구 : 1 <= r < x+d1, 1 <= c <= y
	int aa = 0;
	for (int r = 1; r < x + d1; r++) {
		for (int c = 1; c <= y; c++) {
			if (temp[r][c] == 5) {
				break;
			}
			aa += map[r][c];
		}
	}
	//2번 선거구 : 1 <= r <= x+d2, y < c <= N
	int bb = 0;
	for (int r = 1; r <= x + d2; r++) {
		for (int c = n; c > y; c--) {
			if (temp[r][c] == 5) {
				break;
			}
			bb += map[r][c];
		}
	}
	//3번 선거구 : x+d1 <= r <= N, 1 <= c < y-d1 + d2
	int cc = 0;
	for (int r = x + d1; r <= n; r++) {
		for (int c = 1; c < y - d1 + d2; c++) {
			if (temp[r][c] == 5) {
				break;
			}
			cc += map[r][c];
		}
	}
	//4번 선거구 : x+d2 < r <= N, y-d1+d2 <= c <= N
	int dd = 0;
	for (int r = x + d2 + 1; r <= n; r++) {
		for (int c = n; c >= y - d1 + d2; c--) {
			if (temp[r][c] == 5) {
				break;
			}
			dd += map[r][c];
		}
	}
	int ee = sum - aa - bb - cc - dd;
	int max_val = MAX(aa, MAX(bb, MAX(cc, MAX(dd, ee))));
	int min_val = MIN(aa, MIN(bb, MIN(cc, MIN(dd, ee))));
	return (max_val - min_val);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			cin >> map[x][y];
			sum += map[x][y];
		}
	}

	int ret = 0x7fffffff;
	//(d1,d2 >=1, 1<=x < x+d1+d2 <= N, 1 <= y-d1 < y < y+d2 <= N)
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (x + d1 + d2 > n)
						continue;
					if (1 > y - d1)
						continue;
					if (y + d2 > n)
						continue;
					ret = MIN(ret, solve(x, y, d1, d2));
				}
			}
		}
	}
	cout << ret;
	return 0;
}