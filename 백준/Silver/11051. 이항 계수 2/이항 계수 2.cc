#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    int result = 0;
    cin >> N >> K;
    vector<vector<int>> bino(N + 1);
    /*
       1 1
      1 2 1
    1  3  3  1
    nCk = n-1Ck-1 + n-1Ck
    */
    // (0, 0) 초기값
    bino[0].push_back(1);
    // (1, 0) 부터
    for (int n = 1; n <= N; n++)
    {
        for (int k = 0; k <= n; k++)
        {
            int tmp;
            // nC0 == 1
            if (k == 0)
                tmp = 1;
            // nCn == 1
            else if (k == n)
                tmp = 1;
            else
            {
                tmp = (bino[n - 1][k - 1] + bino[n - 1][k]) % 10007;
            }
            bino[n].push_back(tmp);
        }
    }

    cout << bino[N][K] % 10007 << endl;

    return 0;
}