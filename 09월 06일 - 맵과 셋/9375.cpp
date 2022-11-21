#include <iostream>
#include <map> //맵 사용

using namespace std;

/**
 * 의상의 종류만 알면 된다.
 */

int main()
{
    int t, n; //t: 테스트 케이스의 수, n: 해빈이가 가진 의상의 수
    string clothes, kind; //clothes: 의상의 이름, kind: 의상의 종류
    
    cin >> t;
    while(t--)
    {
        map<string, int> m; //같은 종류의 의상의 수를 확인하기 위한 맵
        
        //입력
        cin >> n;
        while(n--)
        {
            cin >> clothes >> kind;
            m[kind]++; //입력된 종류의 의상의 수 1 증가
        }
        
        int result = 1; //결과의 초기값을 1로 선언
        for(auto iter = m.begin(); iter != m.end(); iter++)
        {
            result *= iter->second + 1; //다른 종류의 의상의 수를 모두 곱해준다
        }
        
        //출력
        cout << result - 1 << '\n'; //알몸인 경우 제외
    }
}
