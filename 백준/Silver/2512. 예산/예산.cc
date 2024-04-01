#include <iostream>
#include <algorithm>

using namespace std;

int sector[10001];
int n, m;
int ret;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	//첫째 줄에는 지방의 수를 의미하는 정수 N
	cin >> n;
	//다음 줄에는 각 지방의 예산요청을 표현하는 N개의 정수가 빈칸을 사이에 두고 주어진다.
	for (int i = 0; i < n; i++) {
		cin >> sector[i];
	}

	// 그 다음 줄에는 총 예산을 나타내는 정수 M
	cin >> m;

	sort(sector, sector + n);

	int s = 0;
	int e = sector[n - 1];
	int mid = (s + e) / 2;
	int sum = 0;
	while (s <= e) {
		sum = 0;
		mid = (s + e) / 2;
		for (int i = 0; i < n; i++) {
			if (sector[i] > mid) {
				sum += mid;
			}
			else {
				sum += sector[i];
			}
		}

		if (sum == m) {
			ret = mid;
			break;
		}
		else if (sum > m) {
			e = mid - 1;
			
		}
		else {
			s = mid + 1;
			ret = mid;
		}

	}
	cout << ret;

	return 0;
}