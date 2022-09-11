#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

struct message
{
    int number = 0;
    int frequency = 0;
    int priority = C;
};

bool cmp(const message &a, const message &b)
{
    if(a.frequency != b.frequency)
    {
        return a.frequency >= b.frequency;
    }
    return a.priority >= b.priority;
}

int main()
{
    int N, C, n;
    cin >> N >> C;
    vector<message> arr(C);
    
    for(int i = 0; i < N; i++)
    {
        cin >> n;
        for(int j = 0; j <= i; j++)
        {
            if(arr[j].number == n)
            {
                arr[j].frequency++;
                break;
            }
            else
            {
                arr[i].number = n;
                arr[i].frequency++;
                arr[i].priority -= i;
                break;
            }
        }
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].frequency; j++)
        {
            cout << arr[i].number << " ";
        }
    }
}
