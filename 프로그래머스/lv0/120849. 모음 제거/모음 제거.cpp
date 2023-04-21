#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i=0; i<my_string.length(); i++){
        if(!(my_string[i] == v[0] || my_string[i] == v[1] || my_string[i] == v[2] || my_string[i] == v[3] || my_string[i] == v[4]))
            answer.push_back(my_string[i]);
    }
    return answer;
}