/* [풀이]
1. 카드의 비교횟수를 값으로 꾸준히 오름차순으로 정렬한다.
2. 가장 낮은 두 값을 카드에서 빼고, 두 값의 합을 카드에 넣는다.
3. 값이 1개가 될 때 해당 값을 출력한다.
*/

#include <bits/stdc++.h>	// STL / gcc
using namespace std;		// STL


int main()
{
	ios::sync_with_stdio(0), cin.tie(0); // boj 입출력 속도 개선
	int n, sum = 0; // n : 몇 회 입력? / sum : 전체 비교 누적치
	cin >> n;
	
	// multiset<int> : 중복값 허용, 오름차순 정렬 유지
	multiset<int> card; 
	
	while(n--){ 	// n회 입력
		int input;
		cin >> input; // 입력값
		card.insert(input); // multiset에 삽입
	}

	while (card.size() > 1) { 		// 값이 1개 초과라면
		int cur = *(card.begin()); 	// 가장 앞의 값 추출
		card.erase(card.begin()); 	// 해당 값 제거
		cur += *(card.begin()); 	// 그 다음 값 추출 후 더하기
		card.erase(card.begin()); 	// 해당 값 제거
		sum += cur;					// 두 값의 합만큼 누적치에 더하기
		card.insert(cur);			// 두 값의 합을 card에 추가
	}
	cout << sum;	// 누적치 출력
}