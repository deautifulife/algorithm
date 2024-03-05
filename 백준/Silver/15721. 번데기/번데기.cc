#include <iostream>
#include <vector>

using namespace std;

int arr[2001];
int funcnt, degicnt;
int mulfun, muldegi;

int a, t;
bool isdegi;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> t >> isdegi;

    int rount = 0;
    int cnt = 0, res = 0;
    while (1) {
        rount++;
        vector<int> list{ 0,1,0,1 }; //0:뻔, 1:데기
        for (int i = 1; i <= rount + 1; i++)
            list.push_back(0);
        for (int i = 1; i <= rount + 1; i++)
            list.push_back(1);
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == isdegi)
                cnt++;

            if (cnt == t) {
                cout << res;
                return 0;
            }
            res++;
            res%= a;
        }
        list.clear();
    }

    

    return 0;
    
}