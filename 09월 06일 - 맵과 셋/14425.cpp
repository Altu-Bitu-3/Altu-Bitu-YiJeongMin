#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    string S1, S2;
    set<string> s;
    int ans = 0;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> S1;
        s.insert(S1);
    }
    for(int i = 0; i < M; i++)
    {
        cin >> S2;
        if(s.find(S2) != s.end())
        {
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}
