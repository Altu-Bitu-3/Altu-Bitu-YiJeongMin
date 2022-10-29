#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int arr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    int ans = 1;
    
    for(int i = 0; i < N; i++)
    {
        if(arr[i] > ans)
        {
            break;
        }
        ans += arr[i];
    }
    
    cout << ans;

    return 0;
}
