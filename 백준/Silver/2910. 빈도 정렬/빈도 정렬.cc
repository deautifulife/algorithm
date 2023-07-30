#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> order; //index 저장 (순서), first->num, second->index

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second) //count값이 같으면
		return order[a.first] < order[b.first]; //index 값이 작은것부터 출력
	
	return a.second > b.second; //빈도 수 기준 내림차순
}

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,c;
	cin>>n>>c;

	map<int, int> m; //first -> num, second -> count

	for(int i=0; i<n; i++){
		int inum;
		cin>>inum;
		m[inum]++;

		if(order[inum] == 0)
			order[inum] = i + 1; //순서 저장	
	}

	vector<pair<int, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), cmp);

	for(auto x : v){
		for(int i=0; i<x.second; i++){
			cout<<x.first<<" ";
		}
	}



}