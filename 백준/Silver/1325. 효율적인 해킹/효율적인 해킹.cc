#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 10001
int n,m;
vector<int> map[MAX];
bool visited[MAX];
queue<int> q;
vector<pair<int,int>> v; //COM num, 해킹가능한 COM tn
int hacked = 1;

void BFS(int v){
	visited[v] = true;
	q.push(v);
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(int i=0; i<map[v].size(); i++){
			int next_v = map[v][i];
			if(visited[next_v] == 0){
				visited[next_v] = true;
				q.push(next_v);
				hacked++;
			}
		}
	}
}


void resetVisited() {
	for(int i=0; i<=n; i++)
		visited[i] = 0;
}

int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<m; i++){
		int s,e;
		cin>>s>>e;
		map[e].push_back(s);
	}

	for(int i=1; i<=n; i++){
		BFS(i);
		resetVisited();
		v.push_back(make_pair(i,hacked));
		hacked = 1;
	}

	int maxHack = -1;
	for(int i=0; i<v.size(); i++){
		if(v[i].second > maxHack)
			maxHack = v[i].second;
	}

	for(int i=0; i< v.size(); i++){
		if(v[i].second == maxHack)
			cout<<v[i].first<<" ";
	}
}