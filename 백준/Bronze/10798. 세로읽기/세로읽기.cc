#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char board[16][5];

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string arr[20];
 
	for (int i = 0; i < 5; ++i) {
		arr[i];
		cin >> arr[i];
	}
 
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i >= arr[j].length()) {
				continue;
			}
			if (arr[j][i] != NULL) {
				cout << arr[j][i];
			}
		}
	}

	return 0;
}