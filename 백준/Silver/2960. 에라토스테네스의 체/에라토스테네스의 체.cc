#include <iostream>

using namespace std;

int arr[1001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}
	int delete_order = 0;
	int p = 2;
	while (1) {
		if (arr[p] == 0) {
			p++;
			continue;
		}
		else {
			for (int i = 1; p * i <= n; i++) {
				if (arr[p*i] == 0) {
					continue;
				}
				else {
					delete_order++;
					arr[p*i] = 0;
					if (delete_order == k) {
						cout << p * i;
						return 0;
					}
				}
				
			}
		}
		p++;
		
	}
	
	return 0;
}