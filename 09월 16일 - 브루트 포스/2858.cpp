#include <iostream>

using namespace std;

//기숙사 바닥의 l(높이), w(너비) 구해서 리턴하는 함수
pair<int, int> length(int r, int b) 
{
    int area = r + b; //기숙사 바닥의 넓이 = 타일의 개수의 총합
    for (int i = area; i > 0; i--) //i = l(높이)의 값
    {
        if (area % i != 0) //w가 정수가 아니라면 넘어감
        {
            continue;
        }
        int w = area / i; //w = 넓이를 높이로 나눈 값
        if (r == ((i + w) * 2 - 4)) //빨간색 타일의 개수(테두리)가 높이와 너비 합의 두배 보다 4(모서리 4개)가 작다면
        {
            return make_pair(i, w); //높이와 너비의 쌍을 만든다
        }
    }
}

/**
 * 기숙사 바닥의 넓이는 타일의 개수의 총합인 r + b
 * l(높이)이 r + b인 사각형부터 검사 (w = (r + b) / l) -> 테두리 타일 개수가 r개와 같다면 정답
 * 테두리 개수 = (l + w) * 2 - 4(겹치는 부분)
 * 입력 범위는 최대 r + b = 2,005,000 이므로 접근 가능!
 */

int main()
{
    int r, b; //r: 빨간 타일 개수, b: 갈색 타일 개수

    //입력
    cin >> r >> b;

    //연산
    pair<int, int> result = length(r, b);

    //출력
    cout << result.first << ' ' << result.second << '\n'; //l 과 w 출력
    return 0;
}
