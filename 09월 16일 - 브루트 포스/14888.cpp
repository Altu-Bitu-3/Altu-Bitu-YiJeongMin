#include <iostream>
#include <algorithm>

using namespace std;
int n;
int A[11]; //A1, A2, ..., An 저장
int num[4]; //연산자의 개수 저장
int maxNum = - 1000000000, minNum = 1000000000;

void calc(int order, int ans)
{
    if(order == n)
    {
        maxNum = max(maxNum, ans);
        minNum = min(minNum, ans);
    }
    
    if(num[0] > 0)
    {
        num[0]--;
        calc(order + 1, ans + A[order]);
        num[0]++;
    }
    
    if(num[1] > 0)
    {
        num[1]--;
        calc(order + 1, ans - A[order]);
        num[1]++;
    }
    
    if(num[2] > 0)
    {
        num[2]--;
        calc(order + 1, ans * A[order]);
        num[2]++;
    }
    
    if(num[3] > 0)
    {
        num[3]--;
        calc(order + 1, ans / A[order]);
        num[3]++;
    }
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    for(int i = 0; i < 4; i++)
    {
        cin >> num[i];
    }
    
    calc(1, A[0]);
    
    cout << maxNum << "\n" << minNum;
}
