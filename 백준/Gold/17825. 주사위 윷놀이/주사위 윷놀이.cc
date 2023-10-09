#include <iostream>

using namespace std;

const int board[33][6] = { //점수,1칸움직이면 가는 배열, 2칸~,3,4,5
	{0,1,2,3,4,5},
	{2,2,3,4,5,6},
	{4,3,4,5,6,7},
	{6,4,5,6,7,8},
	{8,5,6,7,8,9},
	{10,21,22,23,24,25},
	{12,7,8,9,10,11},
	{14,8,9,10,11,12},
	{16,9,10,11,12,13},
	{18,10,11,12,13,14},
	{20,27,28,24,25,26},
	{22,12,13,14,15,16},
	{24,13,14,15,16,17},
	{26,14,15,16,17,18},
	{28,15,16,17,18,19},
	{30,29,30,31,24,25},
	{32,17,18,19,20,32},
	{34,18,19,20,32,32},
	{36,19,20,32,32,32},
	{38,20,32,32,32,32},
	{40,32,32,32,32,32},
	{13,22,23,24,25,26},
	{16,23,24,25,26,20},
	{19,24,25,26,20,32},
	{25,25,26,20,32,32},
	{30,26,20,32,32,32},
	{35,20,32,32,32,32},
	{22,28,24,25,26,20},
	{24,24,25,26,20,32},
	{28,30,31,24,25,26},
	{27,31,24,25,26,20},
	{26,24,25,26,20,32},
	{0,32,32,32,32,32}
};

int in[10];

int get_score(int state) {
	int ret = 0;
	bool visited[33] = { false, }; //같은 위치에 말이 여러마리 있을 수 없다.
	int pos[4] = { 0, }; //각 말의 위치
	for (int turn = 0; turn < 10; turn++) {
		int move = in[turn]; //현재 턴에서 몇칸을 움직여야하는지
		
		//3은 2진수로 표현하면 11, &는 비트단위로 둘다 1이면 1이라서 저렇게 표현하면 3으로 나눈 나머지만 남는것
		int horse = (state >> (turn * 2)) & 0x03; //어떤말이 움직이는가 , 2비트마다 들어와있으므로 *2해서 쉬프트 
												  //마지막 2비트에 해당하는 값이 horse에 들어간다
		int& cur_pos = pos[horse];
		int next_pos = board[cur_pos][move]; //현재위치, 몇칸을 움직이는지
		int add_score = board[next_pos][0];

		//가려는 자리에 말이 있으면
		if (visited[next_pos] && next_pos != 32) {
			return -1;
		}

		ret += add_score;
		visited[cur_pos] = false;
		visited[next_pos] = true;
		cur_pos = next_pos;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> in[i];
	}

	int result = 0;
	//몇번말이 움직이냐
	//2의20제곱
	for (int state = 0; state < (1 << 20); state++) {
		int candi = get_score(state);
		if (result < candi) {
			result = candi;
		}
	}

	cout << result;

	return 0;
}