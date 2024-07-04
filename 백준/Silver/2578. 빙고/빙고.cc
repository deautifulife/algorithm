#include <iostream>

using namespace std;

int map[5][5];
int num[25];
bool endgame = false;
int res;

void check(){
	int bingo =0;
	//가로 체크
	for(int y=0; y<5; y++){
		if(map[y][0] == 0){
			int cnt = 1;
			for(int x=1; x<5; x++){
				if(map[y][x] == 0)
					cnt++;
			}
			if(cnt == 5)
				bingo++;
		}
	}

	//세로체크
	for(int x=0; x<5; x++){
		if(map[0][x] == 0){
			int cnt = 1;
			for(int y=1; y<5; y++){
				if(map[y][x] == 0)
					cnt++;
			}
			if(cnt == 5)
				bingo++;
		}
	}
	//대각체크
	if(map[0][0] == 0){
		int cnt = 1;
		for(int i=1; i<5; i++){
			if(map[i][i] == 0)
				cnt++;
		}
		if(cnt == 5)
			bingo++;
	}
	if(map[0][4] == 0){
		int cnt =1;
		for(int i=1; i<5; i++){
			if(map[i][4-i] == 0)
				cnt++;
		}
		if(cnt == 5)
			bingo++;
	}
	if(bingo >= 3){
		endgame = true;
	}
}

void marking(int num){
	for(int y=0; y<5; y++){
		for(int x=0; x<5; x++){
			if(map[y][x] == num){
				map[y][x] = 0;
				return;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//철수의 빙고판 작성
	for(int y=0; y<5; y++){
		for(int x=0; x<5; x++){
			cin>>map[y][x];
		}
	}

	//사회자의 숫자 부르기
	for(int i=0; i<25; i++){
		cin>>num[i];
	}

	//빙고 체크
	for(int i=0; i<25; i++){
		marking(num[i]);
		check();
		if(endgame == true){
			res = i+1;
			break;
		}
	}

	cout<<res;

	return 0;
}