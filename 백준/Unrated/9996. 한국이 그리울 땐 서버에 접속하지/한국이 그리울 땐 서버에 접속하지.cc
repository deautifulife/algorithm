#include <iostream>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin>> num;

    string pattern;
    cin>>pattern;
    int index = pattern.find('*'); //*을 기준으로 파트를 나누는데 *의 인덱스 번호를 반환한다.
    string part1 = pattern.substr(0, index); //문자열 0부터 index개만큼 추출 = 바로 앞 위치까지 생성한다.
    string part2 = pattern.substr(index+1); //*뒤부터 모두 part2


    int output[num];
    for(int i=0; i<num; i++) {
        output[i] = 0;
    }

    for(int i=0; i<num; i++) {
        string filename;
        cin>>filename;
        //예외 처리
        if(part1.size() + part2.size() > filename.size()) //패턴 앞뒤파트의 길이가 파일이름보다 크면 무조건 NE
            output[i] = 0; //NE
        else if(filename.find(part1) == 0) { // 만약 part1 문자열이 filename에 속하고 첫 부분이면
            string del = filename.substr(filename.size() - (part2.size())); // 문자열 del에 part2의 사이즈만큼 끝부분을 잘라서 저장
            if(del == part2) //잘라낸 문자열이 part2와 같다면
                output[i] = 1; //DA
            else
                output[i] = 0; //NE
        }
    }

    for(int i=0; i<num; i++) {
        if(output[i]==1)
            cout<<"DA"<<'\n';
        else
            cout<<"NE"<<'\n';
    }
    

    return 0;
}