#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //입출력 편하게 한다고 하는건데 뭔지는 잘 모르겠군
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //N, A 입력
    int N;
    cin >> N;
    vector<int> A(N, 0);
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    // 정렬
    sort(A.begin(), A.end());
    
    //좋은 수 갯수
    int result = 0;
    
    //K는 지정한 숫자
    for(int k = 0; k < N; k++){
        long find = A[k]; // 찾아야 하는 값
        
        // 투 포인터 지정
        int i = 0;
        int j = N - 1;
        
        // 투 포인터 알고리즘
        while(i<j) { //기본 대 전제
            if(A[i] + A[j] == find) {
                if(i != k && j != k) { //i와 j는 k이면 안 되니까 예외처리
                    result++;
                    break;
                }
                else if (i == k) {
                    i++; //이거 좀 이상한데..
                }
                else if (j == k) {
                    j--;
                }
            }
            else if (A[i] + A[j] < find) {
                i++;
            }
            else {
                j--;
            }
        }
    }
    cout << result << endl;
}