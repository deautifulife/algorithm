#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int minCityDistance = 99999;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> selected;

void calculateDistance() {
	int cityDistance = 0;
	for (int i = 0; i < house.size(); i++) {
		int minHouseDistance = 99999;
		for (int j = 0; j < chicken.size(); j++) {
			if (selected[j] == 1) {
				int houseDistance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
				if (houseDistance < minHouseDistance)
					minHouseDistance = houseDistance;
			}
		}
		cityDistance += minHouseDistance;
	}
	if (cityDistance < minCityDistance)
		minCityDistance = cityDistance;
}

void selectChicken() {
	for (int i = 0; i < chicken.size() - m; i++) {
		selected.push_back(0);
	}
	for (int i = 0; i < m; i++) {
		selected.push_back(1);
	}
	do {
		calculateDistance();
	} while (next_permutation(selected.begin(), selected.end()));
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	//정보 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int flag;
			cin >> flag;
			if (flag == 1)
				house.push_back(make_pair(i, j));
			else if (flag == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	selectChicken();
	cout << minCityDistance;


}