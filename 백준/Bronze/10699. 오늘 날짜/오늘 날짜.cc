#include <iostream>  // 입출력을 위한 헤더 (cout 사용)
#include <ctime>     // 시간 관련 함수를 위한 헤더 (time, localtime 등)
using namespace std;

int main(void) {
    struct tm *t;         // time 구조체 포인터 선언 (시간 정보를 담는 구조체), localtime의 반환 타입이 포인터이다.
    time_t timer;         // time_t는 시간 값을 저장하는 타입 (초 단위)

    timer = time(NULL);   // 현재 시간을 초 단위로 얻음 (UNIX timestamp 반환)
    t = localtime(&timer); // timer 값을 지역 시간(local time)으로 변환하여 tm 구조체에 저장

    // 연도 출력 (tm_year는 1900년부터의 경과년이므로 보정 필요)
    cout << t->tm_year + 1900 << "-";

    // 월 출력 (tm_mon은 0~11로 저장되므로 1을 더해야 실제 월)
    cout.width(2);         // 출력 폭을 2로 설정 (예: 3 → '03')
    cout.fill('0');        // 빈 자리는 '0'으로 채움
    cout << t->tm_mon + 1 << "-";

    // 일 출력
    cout.width(2);         // 출력 폭을 2로 설정
    cout.fill('0');        // 빈 자리는 '0'으로 채움
    cout << t->tm_mday;

    return 0;
}
