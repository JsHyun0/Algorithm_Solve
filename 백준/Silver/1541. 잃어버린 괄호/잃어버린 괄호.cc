#include <iostream>
#include <algorithm>

using namespace std;

int main () {

    int result = 0;
    int num = 0; 
    int mode = 1; // -1: minus, 1: plus, 2: number
    string s;
    cin >> s;
    for(auto c : s) {

        if(c == '+') {
            result += mode * num;
            num = 0;
        }
        else if(c == '-') {
            result += mode * num;
            num = 0;
            mode = -1;
        }

        else { // 입력이 number
            num *= 10;
            num += c - '0';
        }

    }

    cout << result + (mode * num); 

    return 0;
}