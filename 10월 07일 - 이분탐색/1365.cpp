#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    int pole[N];
    int dp[N];
    
    for(int i = 0; i < N; i++)
    {
        cin >> pole[i];
    }
    
    int ans = 0;
    
    for(int i = 0; i < N; i++)
    {
        dp[i] = 1;
        
        for(int j = 0; j < i; j++)
        {
            if(pole[i] > pole[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout << N - ans;

    return 0;
}
