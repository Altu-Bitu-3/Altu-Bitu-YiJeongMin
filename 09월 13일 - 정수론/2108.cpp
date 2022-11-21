#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int n;
vector<int> arr;
int freq[8001];

//산술평균 arithmetic mean
int mean()
{
    int sum = 0, mean = 0;
    
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    mean = round((double)sum / (double)n);
    
    return mean;
}

//중앙값 median
int median()
{
    return arr[(n - 1) / 2];
}

//최빈값 mode
int mode()
{
    int freqmax = 0;
    int mode;
    
    for(int i = 0; i < n; i++)
    {
        freq[arr[i] + 4000]++;
    }
    
    for(int i = 0; i < 8001; i++)
    {
        if(freqmax < freq[i])
        {
            freqmax = freq[i];
        }
    }
    
    int count = 0;
    for(int i = 0; i < 8001; i++)
    {
        if(freq[i] == freqmax)
        {
            count++;
            mode = i - 4000;
        }
        if(count > 1)
        {
            break;
        }
    }
    
    return mode;
}

//범위 range
int range()
{
    return arr[n - 1] - arr[0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    cout << mean() << '\n';
    cout << median() << '\n';
    cout << mode() << '\n';
    cout << range() << '\n';
}
