#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> visit;
bool flag;

// 주어진 배열 arr에서 시작점 start부터 끝점 N-1까지의 경로가 유효한지 확인하는 함수
void checkRouteValid(vector<long>& arr, int start, int N, long K) {
  
    // 시작점이 끝점에 도달했을 때
    if (start == N - 1) {
        flag = true; // 경로가 유효하다고 표시
    }
    // 시작점(start) 이후의 모든 점에 대해 경로가 유효한지 확인
    for (int j = start + 1; j < N; j++) {
        long result = (long)(j - start) * (1 + abs(arr[start] - arr[j]));
        // 비용이 K 이하이고 방문하지 않은 점이라면
        if (result <= K && visit[j] == 0) {
            visit[j] = 1;
            checkRouteValid(arr, j, N, K); // 재귀적으로 다음 점을 확인
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //첫 번째 줄에 돌의 개수 N이 공백으로 구분되어 주어진다.
    int N;
    cin >> N;
    vector<long> arr(N);

    //두 번째 줄에는 N개의 돌의 수 Ai
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    visit.assign(N, 0);
    long left = 0;
    long right = (long)(N - 1) * (1 + abs(arr[N - 1] - arr[0])); //0에서 N-1로 한번에 가는데 드는 에너지
    long mid = 0;
    long ans = 0;
    while (left <= right) {
        //visit 초기화
        for (int i = 0; i < N; i++) {
            visit[i] = 0;
        }

        visit[0] = 1; // 시작점 방문 표시
        flag = false; // flag 초기화
        mid = (left + right) / 2;
        checkRouteValid(arr, 0, N, mid); //vector<long>& arr, int start, int N, long K
        if (flag) {
            ans = mid;
            right = mid - 1;  // 이진 탐색 범위를 왼쪽으로 축소
        }
        else {
            left = mid + 1; // 유효한 경로가 없다면 이진 탐색 범위를 오른쪽으로 축소
        }
    }
    cout << ans << endl;

    return 0;
}
