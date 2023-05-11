#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	string s;
 
	while (1) {
		getline(cin, s);
		if (s == "END") {
			break;
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
 
	return 0;
}