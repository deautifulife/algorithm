#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> sang;
vector<int> candi;
int ret[500001];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		sang.push_back(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		candi.push_back(num);
	}

	sort(sang.begin(), sang.end());

	for (int i = 0; i < m; i++) {
		int s = 0;
		int e = n - 1;
		while (s <= e) {
			int mid = (s + e) / 2;

			if (sang[mid] == candi[i]) {
				ret[i] = 1;
				break;
			}
			if (sang[mid] > candi[i]) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << ret[i] << ' ';
	}

	return 0;
}