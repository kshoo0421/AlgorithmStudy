/* [풀이]
1. 모든 글자를 1로 가정했을 때의 값 더하기
2. 내림차순 정렬
3. 앞에서부터 9~0 할당
4. 해당 값들 모두 곱하여 누적 값에 더하기
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, digit = 9, total = 0;
    // N : 단어 수 
    // digit : 현재 한 글자에 배치할 수 있는 최대 숫자(9 -> 0)
    // total : 전체 누적값(결과값)

    map<char, int> weight;
    // 1. [글자 -> 현재까지 누적값] 연결하는 해시 ex) weight['c'] = 10010
    // 2. [글자 -> 가중치] ex) weight['c'] = 9
    vector<pair<int, char>> weightV;
    // <값, 글자> 순서대로 배열(순서 : 9 -> 0)

    cin >> N;    // 단어 갯수
    
    while(N--) { // 단어 갯수만큼 반복
        string word;
        cin >> word; // 단어 입력
        for (int i = 0; i < word.size(); i++) { 
            // 단어 길이만큼 반복
            char c = word[i];
            // c : 단어의 j번째 글자
            weight[c] += pow(10, word.size() - i - 1);
            // pow(a, b) = a^b
            // 10의 자릿수만큼 weight에 추가
        }
    }

    // 정렬 위해 vector로 변환
    // mci : Map<Char, Int> / first = char , second = int
    for (auto mci : weight) weightV.push_back({ mci.second, mci.first });

    // 모든 글자 1 기준, 가중치가 큰 순서대로 정렬
    sort(weightV.rbegin(), weightV.rend());

    // pic : Pair<Int, Char> 
    for(auto& pic : weightV) { // 전체 가중치
        total += (pic.first * digit--); 
        // 전체값 += ((1 기준 가중치) * (9 -> 0 (줄어감)))
    }
    cout << total;
}