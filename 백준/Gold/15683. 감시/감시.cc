#include <iostream>

using namespace std;

struct CCTV {
	int type, y, x;
};

int n, m, ret;
int map[8][8];
int cctv_size;
CCTV cctv[8];

const int rot_size[] = { 4,2,4,4,1 };

void map_copy(int desc[8][8], int src[8][8]) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			desc[y][x] = src[y][x];
		}
	}
}

//한방향씩 체크를 업데이트
void update(int dir, CCTV cctv) {
	dir = (dir % 4);

	if (dir == 0) {
		//동쪽
		for (int x = cctv.x + 1; x < m; x++) {
			if (map[cctv.y][x] == 6)
				break;
			map[cctv.y][x] = -1;
		}
	}
	if (dir == 1) {
		//북쪽
		for (int y = cctv.y - 1; y >= 0; y--) {
			if (map[y][cctv.x] == 6)
				break;
			map[y][cctv.x] = -1;
		}
	}
	if (dir == 2) {
		//서쪽
		for (int x = cctv.x - 1; x >= 0; x--) {
			if (map[cctv.y][x] == 6)
				break;
			map[cctv.y][x] = -1;
		}
	}
	if (dir == 3) {
		//북쪽
		for (int y = cctv.y + 1; y < n; y++) {
			if (map[y][cctv.x] == 6)
				break;
			map[y][cctv.x] = -1;
		}
	}
}

void dfs(int cctv_index) {
	//종료조건
	if (cctv_index == cctv_size) {
		int candi = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (map[y][x] == 0) {
					candi++;
				}
			}
		}
		if (ret > candi) {
			ret = candi;
		}
		return;
	}

	int backup[8][8]; //백트래킹을 위한 백업
	int type = cctv[cctv_index].type;
	for (int dir = 0; dir < rot_size[type]; dir++) {
		//map backup
		map_copy(backup, map);
		//map update
		if (type == 0) {
			update(dir, cctv[cctv_index]);
		}
		else if (type == 1) {
			update(dir, cctv[cctv_index]);
			update(dir + 2, cctv[cctv_index]);
		}
		else if (type == 2) {
			update(dir, cctv[cctv_index]);
			update(dir+1, cctv[cctv_index]);
		}
		else if (type == 3) {
			update(dir, cctv[cctv_index]);
			update(dir +1 , cctv[cctv_index]);
			update(dir +2, cctv[cctv_index]);
		}
		else if (type == 4) {
			update(dir, cctv[cctv_index]);
			update(dir+1, cctv[cctv_index]);
			update(dir+2, cctv[cctv_index]);
			update(dir+3, cctv[cctv_index]);
		}
		dfs(cctv_index + 1);

		//map 원상복구
		map_copy(map, backup);
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];

			//cctv가 나오면 cctv의 정보를 담기
			if (map[y][x] != 0 && map[y][x] != 6) {
				cctv[cctv_size].y = y;
				cctv[cctv_size].x = x;
				cctv[cctv_size].type = map[y][x] -1; //type을 0부터 지정하기 위해 -1
				cctv_size++;
			}
		}
	}

	ret = 100;
	dfs(0);
	cout << ret;

	return 0;
}  