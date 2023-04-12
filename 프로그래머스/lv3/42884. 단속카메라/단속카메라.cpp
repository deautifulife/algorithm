#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    // 기본 카메라 1대
    int answer = 1;
    
    // 들어온 리스트 정렬(먼저 들어온 차순서)
    sort(routes.begin(), routes.end());
    
    //비교를 위해 첫 차가 나가는 부분 체크
    int temp = routes[0][1];
    
    //리스트 순회하기
    for(int i=1; i<routes.size(); i++) {
        //다음차가 지금차가 나가는 시간보다 늦게 들어오면
        if(temp < routes[i][0]) {
            //카메라 설치
            answer++;
            //나가는 부분 수정
            temp = routes[i][1];
        }
        //다음차가 지금차보다 먼저 나가면
        if(routes[i][1] <= temp){
            //나가는 부분을 뒷차로 수정
            temp = routes[i][1];            
        }
    }
    
    return answer;
}