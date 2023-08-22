#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector <int> visited;
vector <int> ans;
int cnt;

bool compare(int i, int j){
	return i > j;
}

void bfs(int r){
	visited[r] = 1;
	queue<int> q;
	q.push(r);
	ans[r] = ++cnt; //처음 방문한 곳 카운트
	while(!q.empty()){
		int dx = q.front();
		q.pop();
		for(int i=0; i<map[dx].size(); i++){
			int nx = map[dx][i];
			if(visited[nx] == 0){
				q.push(nx);
				visited[nx] = 1;
				ans[nx] = ++cnt;
			}
		}
	}
}


int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int n,m,r;
	cin>>n>>m>>r;

	map.resize(n+1); //인덱스를 0이 아닌 1부터 시작하기 위함
	visited.resize(n+1);
	ans.resize(n+1);

	for(int i=0; i<m; i++)	{
		int u,v;
		cin>>u>>v;
		//방향이 없으므로 양방향
		map[u].push_back(v);
		map[v].push_back(u);

	}

//내림차순 정리
	for(int i=1; i<=n; i++)	{
		sort(map[i].begin(), map[i].end(), compare);
	}

	bfs(r);

	for(int i=1; i<=n; i++){
		cout<<ans[i]<<'\n';
	}

}