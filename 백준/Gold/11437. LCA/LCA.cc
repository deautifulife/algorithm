#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int N, M;
static vector<vector<int>> tree;
static vector<int> depth;
static vector<int> parent;
static vector<bool> visited;

void BFS(int node);
int excuteLCA(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;

	tree.resize(N+1);
	depth.resize(N+1);
	parent.resize(N+1);
	visited.resize(N+1);

	for(int i=0; i<N-1; i++){
		int s,e;
		cin>>s>>e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	BFS(1);

	cin>>M;

	for(int i=0; i<M; i++){
		int a,b;
		cin>>a>>b;
		int LCA = excuteLCA(a,b);
		cout<<LCA<<"\n";
	}
}

void BFS(int node) {
	queue<int> myqueue;
	myqueue.push(node);
	visited[node] = true;
	int level = 1;
	int now_size = 1; //현재 depth(level) 크기
	int count = 0; //현재 depth에서 내가 몇 개 노드를 처리했는지 알려주는 변수

	while(!myqueue.empty()){
		int now_node = myqueue.front();
		myqueue.pop();
		for(int next : tree[now_node]){
			if(!visited[next]){
				visited[next] = true;
				myqueue.push(next);
				parent[next] = now_node; //부모 노드 저장
				depth[next] = level; //노드 깊이 넣어주는 부분
			}
		}
		count++;
		if(count == now_size){
			count = 0;
			now_size = myqueue.size();
			level++;
		}
	}
}

int excuteLCA(int a, int b){
	if(depth[a] < depth[b]){
		int temp = a;
		a = b;
		b = temp;
	}
	//depth 맞추기
	while(depth[a] != depth[b]){
		a = parent[a];
	}
	// 같은 조상이 나올 때 까지 두 노드가 함께 한칸씩 올라가기
	while(a != b){
		a = parent[a];
		b = parent[b];
	}

	return a;
}