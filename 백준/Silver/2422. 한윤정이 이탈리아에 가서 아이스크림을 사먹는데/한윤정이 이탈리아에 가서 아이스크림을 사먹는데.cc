#include <iostream>
#include <vector>

using namespace std;

bool npair[205][205];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		npair[a][b] = npair[b][a] = 1;
	}

	int ret = 0;

	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			//i,j조합
			if (npair[i][j])
				continue;
			for (int k = j + 1; k <= n; k++) {
				//i,k 조합
				if (npair[i][k])
					continue;
				//j,k조합
				if (npair[j][k])
					continue;

				ret++;
			}
		}
	}
	
	cout << ret;

	return 0;
}