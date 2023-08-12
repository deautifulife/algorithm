#include <string>
#include <vector>
#include<unordered_set>

using namespace std;

int min = 99999;


int solution(int N, int number) {
    int answer = -1; //최솟값이 8이 넘어가면 -1 리턴.
    unordered_set<int> s[8]; //중복값을 제거해주고 저장
    
    int sum = 0;
    //각 항목에다가 N,NN,NNN 넣어주기 [ex)5, 55, 555]
    for(int i=0; i<8; i++){
        sum = 10*sum + N;
        s[i].insert(sum);
    }
    
    //사칙연산한 것들을 s[]에 넣기
    //s[3]은 N이 연달아 4개 있는 것과 s[0]과 s[2]의 조합, s[1]과 s[1]의 조합, s[2]와 s[0]의 조합의 합집합
    //여기서 이중for문을 사용할 때 s[j]와 s[N의 개수-j-1]을 사칙연산으로 조합한 것들을 s[i]에 넣어줘야함
    //N이 8개 초과면 -1리턴이므로 N을 8개까지쓰는 s[7]까지 구함
    for(int i=1; i<8; i++){
        for(int j=0; j<i; j++){
            for(int a : s[j]){
                for(int b : s[i-j-1]){
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(a*b);
                    if(b != 0)
                        s[i].insert(a/b);
                }
            }
        }
    }
    
    //set을 채웠으니 number이 set에 있는지 확인
    for(int i=0; i<8; i++){
        //find = set에 number에 해당하는 값이 없으면 set.end()를 반환함
        if(s[i].find(number) != s[i].end()){
            answer = i+1; //인덱스가 0부터 시작이므로 +1
            break;
        }
    }
    return answer;
}