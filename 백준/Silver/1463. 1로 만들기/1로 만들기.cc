#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int>DP(N+1, 0);
    
    for(int i = N; i>1 ; i--) {
        
        if(i%3 == 0) {
            
            if(DP[i/3] > DP[i]+1 || DP[i/3] == 0) {
                DP[i/3] = DP[i]+1;
            }
        }
        if(i%2 == 0) {
            
            if(DP[i/2] > DP[i]+1 || DP[i/2] == 0) {
                DP[i/2] = DP[i]+1;
            }
        }

        if(DP[i-1] > DP[i]+1 || DP[i-1] == 0) {
                DP[i-1] = DP[i]+1;
        }
    
    }
    cout << DP[1];

    return 0;
    
}
