#include <iostream>
#include <set>

using namespace std;
set<int> S;
set<int> Set = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

void add(int x)
{
    if(S.find(x) != S.end())
    {
        S.insert(x);
    }
}

void remove(int x)
{
    if(S.find(x) != S.end())
    {
        S.erase(x);
    }
}

void check(int x)
{
    if(S.find(x) != S.end())
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
}

void toggle(int x)
{
    if(S.find(x) != S.end())
    {
        S.erase(x);
    }
    else
    {
        S.insert(x);
    }
}

void all()
{
    S = Set;
}

void empty()
{
    S.clear();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x;
    string cmd;
    
    cin >> n;
    while(n--)
    {
        cin >> cmd;
        if(cmd == "add")
        {
            cin >> x;
            add(x);
            continue;
        }
        if(cmd == "remove")
        {
            cin >> x;
            remove(x);
            continue;
        }
        if(cmd == "check")
        {
            cin >> x;
            check(x);
            continue;
        }
        if(cmd == "toggle")
        {
            cin >> x;
            toggle(x);
            continue;
        }
        if(cmd == "all")
        {
            all();
            continue;
        }
        if(cmd == "empty")
        {
            empty();
        }
    }
    return 0;
}
