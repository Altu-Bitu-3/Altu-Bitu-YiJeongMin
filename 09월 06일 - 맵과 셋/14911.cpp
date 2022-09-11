#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main()
{
    vector<int> v;
    int n;
    while(cin >> n)
    {
        v.push_back(n);
    }
    
    int sum = v.back();
    v.pop_back();
    
    sort(v.begin(), v.end());
    
    int ans = 0;
    set<pair<int, int>> set;
    
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i + 1; j < v.size(); j++)
        {
            if(v[i] + v[j] == sum)
            {
                set.insert({v[i], v[j]});
                ans++;
            }
        }
    }
    
    for (auto &p:set)
    {
	cout << p.first << " " << p.second << "\n";
    }

    cout << ans << "\n";
    return 0;
}
