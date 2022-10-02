#include <iostream>
#include <algorithm>

using namespace std;
int A[1000];
int dp[1000];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        
        for(int j = 0; j < i; j++)
        {
            if(A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans;

    return 0;
}
