#include <iostream>
#include <deque>

using namespace std;
deque<int> dodo;
deque<int> suyeon;
deque<int> doground;
deque<int> suground;

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        dodo.push_front(a);
        suyeon.push_front(b);
    }
    
    for(int i = 0; i < m; i++)
    {
        if(i % 2 == 0)
        {
            doground.push_front(dodo.front());
            dodo.pop_front();
            if(dodo.empty())
            {
                cout << "su";
                break;
            }
        }
        else
        {
            suground.push_front(suyeon.front());
            suyeon.pop_front();
            if(suyeon.empty())
            {
                cout << "do";
                break;
            }
        }
        
        //도도가 종을 친다
        if((doground.size() != 0 && doground.front() == 5) || (suground.size() != 0 && suground.front() == 5))
        {
            for(int j = 0; j < suground.size(); j++)
                {
                    dodo.push_back(suground.back());
                    suground.pop_back();
                }
                for(int j = 0; j < doground.size(); j++)
                {
                    dodo.push_back(doground.back());
                    doground.pop_back();
                }
        }
        
        //수연이가 종을 친다
        if(doground.size() != 0 && suground.size() != 0 && doground.front() + suground.front() == 5)
        {
            for(int j = 0; j < doground.size(); j++)
            {
                suyeon.push_back(doground.back());
                doground.pop_back();
            }
            for(int j = 0; j < suground.size(); j++)
            {
                suyeon.push_back(suground.back());
                suground.pop_back();
            }
        }
    }
    
    if(dodo.size() > suyeon.size())
    {
        cout << "do";
    }
    else if(dodo.size() < suyeon.size())
    {
        cout << "su";
    }
    else
    {
        cout << "dosu";
    }
    
    return 0;
}
