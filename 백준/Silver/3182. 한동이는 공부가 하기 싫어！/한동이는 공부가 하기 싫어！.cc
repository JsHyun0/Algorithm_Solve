#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    vector<int> visit(N, 0);
    int max = 0;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        fill(visit.begin(), visit.end(), 0);
        int len = 1;
        int cur = i;
        visit[i] = 1;
        int next = 0;
        while (true)
        {
            next = arr[cur] - 1;
            if (visit[next] == 1)
            {
                break;
            }
            else
            {
                visit[next] = 1;
                len++;
                cur = next;
            }
        }
        if (len > max)
        {
            max = len;
            result = i + 1;
        }
    }
    cout << result;
    return 0;
}