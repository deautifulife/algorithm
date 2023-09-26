#include <iostream>
#include<algorithm>

using namespace std;

struct TREE {
	int y, x, age;
};

bool cmp(TREE& a, TREE& b) {
	return(a.age < b.age);
}

//queue 구현
struct QUEUE {
	int f, b; //front, back
	TREE tree[684000]; //MAX값 배열로 잡아주기

	QUEUE() {
		init();
	}

	void init() {
		f = 0, b = 0;
	}

	//empty확인
	bool isempty() {
		return (f == b);
	}

	void push(TREE val) {
		tree[b++] = val;
	}

	void pop() {
		f++;
	}

	TREE front() {
		return tree[f];
	}

	int size() {
		return (b - f);
	}
};

int n, m, k;
QUEUE tree[2];
QUEUE new_tree;
QUEUE dead_tree, birth_of_child_tree;

TREE init_tree[100]; //초기에 입력받는 tree	
int map[10][10], add[10][10]; //현재 양분, 추가되는 양분을 저장할 배열

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> add[y][x];
			map[y][x] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> init_tree[i].y >> init_tree[i].x >> init_tree[i].age;
		//입력은 1부터인데 배열은 0부터이므로
		init_tree[i].y--;
		init_tree[i].x--;
	}

	sort(init_tree, init_tree + m, cmp); //나이가 어린순으로 정렬
	
	int cur = 0, next = 0; 
	for (int i = 0; i < m; i++) {
		tree[cur].push(init_tree[i]);
	}


	for (int i = 0; i < k; i++) {
		next = (cur + 1) % 2;
		
		dead_tree.init();
		birth_of_child_tree.init();
		tree[next].init();

		//봄
		while (!new_tree.isempty()) {
			TREE cur_tree = new_tree.front();
			new_tree.pop();

			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;

				++cur_tree.age;
				tree[next].push(cur_tree);
			}
			else {
				dead_tree.push(cur_tree);
			}
		}
		while (!tree[cur].isempty()) {
			TREE cur_tree = tree[cur].front();
			tree[cur].pop();

			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				map[cur_tree.y][cur_tree.x] -= cur_tree.age;

				++cur_tree.age;
				tree[next].push(cur_tree);

				if (cur_tree.age % 5 == 0) {
					birth_of_child_tree.push(cur_tree);
				}
			}
			else {
				dead_tree.push(cur_tree);
			}
		}

		//여름
		while (!dead_tree.isempty()) {
			TREE cur_tree = dead_tree.front();
			dead_tree.pop();

			map[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
		}

		//가을
		const int dy[] = { -1,-1,-1,0,0,1,1,1 };
		const int dx[] = { -1,0,1,-1,1,-1,0,1 };

		new_tree.init(); //직접 구현한 큐(뒤로만 쌓이는 큐) 이므로 초기화가 필요
		while (!birth_of_child_tree.isempty()) {
			TREE cur_tree = birth_of_child_tree.front();
			birth_of_child_tree.pop();
			for (int dir = 0; dir < 8; dir++) {
				TREE next_tree;
				next_tree.y = cur_tree.y + dy[dir];
				next_tree.x = cur_tree.x + dx[dir];
				next_tree.age = 1;
				if (next_tree.y < 0 || next_tree.y >= n || next_tree.x < 0 || next_tree.x >= n) {
					continue;
				}
				new_tree.push(next_tree);
			}
		}

		//겨울
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				map[y][x] += add[y][x];
			}
		}

		cur = next;
	}

	cout << tree[next].size() + new_tree.size();
	return 0;
}