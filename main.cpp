#include <iostream>
#include "libRPN.h"
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        for (char &c : s) {
            if (c == '[' || c == '{')
                c = '(';
            if (c == ']' || c == '}')
                c = ')';
        }
        vector<string> IPE = transfer(s);
        double res = solution(IPE);
        cout << fixed << setprecision(0) << res << endl;
    }
    return 0;
}
