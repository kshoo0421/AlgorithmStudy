# C++ 알고리즘 스터디 깃허브 이용 가이드
## 개요
기업 코딩테스트 대비 문제 및 풀이 모음입니다.<br>
개인 공부 및 스터디 자료 공유용으로 제작되었으며,<br>
개인이 제작하고 풀이한 자료이니만큼 오타나 틀린 부분이 있을 수 있습니다.<br>

또, 문제는 직접 풀고, 주석도 직접 달았으나<br>
STL 등의 추가 설명에는 gpt를 활용했습니다.<br>

종종 제가 특이하게 푸는 경우가 있어서 gpt에 문제 물어보고<br>
그 풀이와 비교해보는 것도 공부하는 데에 도움이 됩니다.<br>
풀이는 많이 보면 볼수록 좋거든요.<br>

- 문제 출처 : [백준(BOJ)](https://www.acmicpc.net/)
- 풀이 언어 : C++17
- 작성자 백준 계정 : shmd02 [BOJ](https://www.acmicpc.net/user/shmd02), [solved.ac](https://solved.ac/profile/shmd02)

## 문제 목록
| DAY | 주제                   | 필수 문제        | 2          | 3          | 4          | 5          |
|:---:|:----------------------:|:----------------:|:----------:|:----------:|:----------:|:----------:|
| 1   | 그리디                 | 01715<br>G4      | 01339<br>G4| 01202<br>G2| 01744<br>G2| 11000<br>G5|
| 2   | DFS                    | 10026<br>G5      | 01987<br>G4| 01520<br>G4| 01707<br>G4| 02573<br>G4|
| 3   | BFS                    | 07576<br>G5      | 14502<br>G4| 07569<br>G5| 02206<br>G3| 16236<br>G3|
| 4   | 브루트 포스           | 14500<br>G4      | 01107<br>G5| 12100<br>G1| 15683<br>G3| 02589<br>G5|
| 5   | 백트래킹              | 09663<br>G4      | 15686<br>G5| 01759<br>G5| 02580<br>G5| 13023<br>G5|
| 6   | 해시 테이블           | 04195<br>G2      | 02143<br>G3| 01525<br>G3| 01351<br>G5| 02295<br>G4|
| 7   | 이분 탐색             | 02110<br>G4      | 02470<br>G5| 01300<br>G4| 02467<br>G5| 01253<br>G3|
| 8   | 위상정렬              | 02252<br>G3      | 01005<br>G3| 01766<br>G2| 01516<br>G3| 02623<br>G3|
| 9   | DP                    | 12865<br>G5      | 09251<br>G5| 02293<br>G5| 11054<br>G3| 02294<br>G3|
| 10  | MST (프림/크루스칼)   | 01197<br>G4      | 01922<br>G4| 01647<br>G4| 04386<br>G1| 17472<br>G1|
| 11  | 최단 경로 (플루이드)  | 11404<br>G4      | 02458<br>G4| 01956<br>G4| 14938<br>G4| 02660<br>G5|
| 12  | 최단 경로 (다익스트라)| 01753<br>G4      | 01916<br>G5| 13549<br>G5| 01238<br>G3| 01504<br>G4|
| 13  | 최단 경로 (벨만포드)  | 11657<br>G4      | 01865<br>G3| 01738<br>G3| 10360<br>G2| 07142<br>G4|
| 14  | LIS                   | 12015<br>G2      | 12738<br>G2| 02352<br>G2| 01365<br>G4| 03745<br>G5|
| 15  | 구현                  | 05430<br>G5      | 14503<br>G5| 03190<br>G4| 16234<br>G4| 14499<br>G5|

기업 코딩테스트에 많이 나오는 주제를 선정했고,<br>
순서는 제가 진행하는데 문제가 없게끔 임의로 정했습니다.<br>
문제는 `solved.ac` 기준 많이 푼 순으로 정렬한 후,<br>
골드 이상의 5문제를 선정했습니다.<br>
`pdf` 파일이 편하싣다면 이 폴더의 `pdf` 파일을 활용하시면 됩니다.<br>

+) solved.ac의 문제 난도는 종종 변경됩니다.<br>
문제를 선정한 시기와 현재의 문제 난이도가 다를 수 있습니다.

## 추천 공부법
문제를 많이 풀 수 있는 여유가 있다면 모든 문제를 푸는 게 좋습니다.<br>
해당 주제를 잘 모른다면 주제를 찾아보고,<br>
그래도 모르겠다면 풀이를 보고 따라치며 문제 풀이를 이해하는 것도 좋습니다.<br>
단, 보고 푸는 것은 주제별로 최대 1문제 푸는 것을 추천드리며<br>
가능한 모든 문제를 직접 푸는 것을 추천드립니다.

---

### 알고리즘이나 C++이 거의 처음인 경우
개인적으로 [코드업 C++ 기초 100제](https://codeup.kr/problemsetsol.php?psid=23)으로 시작하는 것을 추천합니다.<br>

---

### 알고리즘 강의가 필요한 분들
유튜브에 [바킹독의 실전 알고리즘 강의](https://youtube.com/playlist?list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY&si=YKVx-CvHWw_6Y8nv)를 추천합니다.<br>
이 강의에서 설명도 잘 되어있고, 예제 문제도 보통 실버 수준이기에 처음 도전하기에 좋습니다.<br>
여기서 개념 설명만 듣고 바로 문제를 푸는 것도 좋다고 생각합니다.<br>
어차피 요즘 코딩테스트에서는 골드 이상의 문제들만 출제되기에<br>
각 주제별로 골드 문제를 어느 정도는 푸는 것을 추천합니다.

## 코드 해석

저는 짧고 일관적인 코드를 선호해서 변수명이 짧고,<br>
특정한 코드를 추가하기도 하며,<br>
종종 `Modern C++`과 `STL`을 활용합니다.<br>
처음 보는 분들은 이게 무슨 뜻인지 해석하지 못할 가능성이 높습니다.<br>
우선 설명드리고, 코드에서 특이성이 있다면 해설에 추가하겠습니다.<br>

---
### 고정 코드
저는 C++ 알고리즘 문제를 풀 때 고정으로 쓰는 코드가 있습니다.<br>
```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
}
```
간단하게 말씀드리면<br>
- `#include <bits/stdc++.h>` : 필요한 헤더 파일을 한 번에 포함(gcc 포함 헤더)<br>
- `using namespace std;` : STL 앞에 std namespace를 생략<br>
- `ios::sync_with_stdio(0), cin.tie(0);` : 입출력을 빠르게 하는 코드입니다.<br>

헤더파일은 처음에는 `bits~`를 사용하지 않고 일일이 넣는 것을 추천드리며,<br>
모든 함수가 어떤 헤더파일에 있는지 알겠으면 그때부터 `bits~`를 사용하는 것을 추천드립니다.<br>

`ios::sync_with_stdio(0), cin.tie(0);`는 주로 백준에서 많이 필요한 코드인데,<br>
일반적으로 코테에서는 신경쓰지 않아도 됩니다.<br>
다만 백준 문제 중에 종종 입출력으로 시간초과 내는 문제들이 있기에<br>
귀찮음 방지용으로 넣어주시면 좋습니다.<br>

저 문구를 쓰면 c의 입출력인 `printf`, `scanf` 함수를 사용하지 않아야 하며<br>
추가로 줄바꿈에서 `endl` 대신 `'\n'`을 사용하시는 것이 좋습니다.<br>
이유는 버퍼 관련된 내용을 알아야하는데, 궁금하시면 개인적으로 찾아보시는 걸 추천드립니다.<br>

### STL(Standard Template Library)

C++ 알고리즘 플이의 핵심입니다.<br>
많은 자료구조와 알고리즘 함수가 구현되어 있으며,<br>
이를 얼마나 잘 활용하느냐가 C++ 알고리즘 풀이의 핵심이라고 볼 수 있습니다.

---

#### 주요 컨테이너(Container)
- `vector`, `deque`, `stack`, `queue`, `priority_queue`, `set` / `unordered_set`, `map` / `unordered_map`

컨테이너는 주제별 알고리즘을 풀며 사용법을 익히는 것을 추천드립니다.<br>
다만, `vector`의 경우 가장 많이 사용되기도 하고<br>
제가 독특하게 사용하는 측면도 있어서 이 부분은 설명드리겠습니다.<br>

`vector`는 동적 할당 가능한 배열입니다.<br>
맨 뒤의 값을 추가하거나 빼는 것이 가능하며,<br>
알고리즘에서 활용할 수 있는 여러 함수가 제공됩니다.<br>

```cpp
#include <vector> // <vector> 헤더에 포함 
using namespace std; // std::vector로 사용해야 함
```
헤더는 `<vector>`이며, std namespace에 포함되어 있습니다.<br>

```cpp
vector<int> v;          // int형 빈 벡터 생성
vector<int> v(5);         // 크기 5, 모든 값이 0 (int의 기본값)
vector<int> v2(5, -1);    // 크기 5, 모든 값이 -1
vector<int> v = {1, 2, 3, 4}; // 초기 리스트 사용, C++ 11 이상

/* 벡터 복사 */
vector<int> a = {1, 2, 3};
vector<int> b(a);         // b는 a의 복사본
vector<int> c = a;        // 동일한 복사

/* 2차원 벡터 초기화 */
vector<vector<int>> matrix(3, vector<int>(4, 0)); 
// 3행 4열, 모든 값이 0으로 초기화된 2차원 벡터

/* 선언 후 초기화 방법 */
vector<int> A;
A.assign(size, 0); // 길이와 값 명시
A.resize(size); // 길이만 변경하고 싶으면 resize() 사용

```
`vector`의 초기화 방법입니다.<br>
예시는 모두 int로 들었지만, `string`, `bool` 등 다른 자료형도 모두 가능합니다.<br>

```cpp
vector<int> v;          // int형 빈 벡터 생성
v.push_back(10);        // 원소 추가
v.emplace_back(20);     // 비슷한 함수
cout << v[0] << "\n";   // 10
cout << v.at(1) << "\n";// 20
```
`vector`에 값을 추가하는 방법과, 접근하는 방법입니다.<br>
`push_back`과 `emplace_back`은 미묘한 차이가 있는데<br>
그냥 `push_back` 쓰시고, `emplace_back`이 있으면 비슷한 함수라고 이해하고 넘어가면 됩니다.<br>
+) `emplace_back`이 일반적으로 조금 더 좋은 함수인데,<br>
다른 자료구조와의 함수 일관성(`stack`, `queue` 등에는 `emplace_back`이 없음)을 위해<br>
처음에는 `push_back`으로 통일하는 것을 추천합니다.<br>

접근도 보통 `[]`을 많이 사용하고, `at`이 비슷한 함수구나 하시면 됩니다.<br>
다차원도 일반 배열과 마찬가지로 `[0][2]`처럼 사용하면 됩니다.<br>

아래는 주요 함수입니다.<br>

| 기능 | 설명 | 예시 |
|------|------|------|
| `push_back(x)` | 맨 뒤에 x 추가 | `v.push_back(5);` |
| `pop_back()` | 마지막 원소 제거 | `v.pop_back();` |
| `size()` | 원소 개수 반환 | `v.size();` |
| `empty()` | 비었는지 확인 | `if (v.empty())` |
| `clear()` | 모든 원소 제거 | `v.clear();` |
| `resize(n)` | 크기 n으로 조정 | `v.resize(10);` |
| `front()` | 첫 번째 원소 반환 | `v.front();` |
| `back()` | 마지막 원소 반환 | `v.back();` |
| `begin()` | 시작 위치 반환(이터레이터(=포인터)) | `v.begin();` |
| `end()` | 끝 위치 반환(이터레이터(=포인터)) | `v.end();` |

참고로 end()는 마지막 원소 + 1의 위치값입니다.

---
#### 주요 알고리즘 함수(Algorithms) :

| 함수 | 용도 | 시간복잡도 |
|------|------|-------------|
| `sort(begin, end)` | 오름차순 정렬 | O(n log n) |
| `reverse(begin, end)` | 구간 뒤집기 | O(n) |
| `lower_bound`, `upper_bound` | 이분 탐색 위치 반환 | O(log n) |
| `max_element`, `min_element` | 최댓값/최솟값 찾기 | O(n) |
| `find(begin, end, val)` | 특정 값 찾기 | O(n) |

우선 알고리즘이 처음이라면 '이런 게 있구나'하고 넘긴 다음<br>
풀이를 하며 함수를 알아가는 것을 추천합니다.<br>

### Modern C++
#### 범위 기반 for문 (Range-based for loop) — C++11

```cpp
vector<int> v = {1, 2, 3, 4};
for (int x : v) {
    cout << x << " ";
}
```

- 반복자 사용 없이 **간결한 루프** 가능
- `&`를 붙이면 참조 (`for (int& x : v)`), 수정 가능

---

#### auto 키워드 — C++11

```cpp
map<int, string> m;
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " " << it->second;
}
```

- 반복자 타입 자동 추론
- 복잡한 STL 타입에서 코드 간결화

---

#### 람다 함수 (Lambda) — C++11

```cpp
vector<int> v = {3, 1, 4, 1};
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b; // 내림차순
});

function<int(int)> FindParent = [&](int a) {
		if (a == parent[a]) return a;
		return parent[a] = FindParent(parent[a]);
	};
```

- 함수 내에 함수를 선언하고 실행할 수 있음
- **정렬 기준 지정**, **DFS 내 커스텀 조건** 등에서 자주 활용
- 캡처 `[&]` 사용 시 외부 변수 참조 가능
- 필자는 함수 밖에 선언하고 왔다갔다하기 싫을 때 종종 사용함

---

#### tuple / pair — C++11 ~ C++17

```cpp
pair<int, int> xy = make_pair(2, 3);
int x1 = xy.first; // 2
int y1 = xy.second; // 3
auto& [x2, y2] = xy; // x2 : 2, y2 : 3

tuple<int, int, int> t = make_tuple(1, 2, 3);
auto [a, b, c] = t; // 구조적 바인딩 (C++17)

```

- 여러 값을 한 번에 반환하거나 정렬 키로 사용 가능
- `pair<int, int>`는 좌표, 우선순위 큐 등에 자주 사용

### 많이 사용하는 줄임 표현
이 부분은 저만 사용하는 표현입니다.<br>
본인의 스타일에 맞다면 사용하는 것도 좋습니다.<br>
저는 특정 조건문 안에서 사용되는 변수는 앞 글자를 딴 변수를 사용합니다.<br>
```cpp
vector<int> A(3);
for(int& i : A) cin >> i // Int 이므로 i

vector<bool> A = {1, 2, 3};
for(bool b : A) ~ // Bool 이므로 b

vector<string> A = {1, 2, 3};
for(string s : A) ~ // String 이므로 s
```

vector<int>와 같은 컨테이너의 경우 컨테이너 명도 같이 붙여 줄입니다.

```cpp
vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
for(auto& vi : A) ~ // Vector<Int> 이므로 vi

vector<pair<int, bool>> A = ~;
for(auto& pib : A) ~ //  Pair<Int, Bool>이므로 pib

vector<vector<pair<int, bool>>> A = ~;
for(auto& vpib : A) ~ // Vector<Pair<Int, Bool>>이므로 vpib
```
이는 제가 지역 변수 이름 짓는게 귀찮기도 하고,<br>
짧은 걸 선호하기도 하고<br>
변수명에 어떤 형식인지 표시하면 여러모로 편해서 이렇게 하고 있습니다.<br>
이렇게 하는 사람 저 말고는 못봤는데, 저는 편해서 사용하고 있습니다.<br>

이를 활용해서 입력을 받으면
```cpp
/* 1차원 입력 */
vector<int> A(3);
for(int& i : A) cin >> i;

/* 2차원 입력 */
vector<vector<int>> A(3, vector<int>(2));
for(auto& vi : A) {
    for(int& i : vi) cin >> i;
}
```
일반적인 입력보다 훨씬 짧고 직관적으로 받을 수 있습니다.<br>
물론 이렇게 입력 받을 때 참조자 `&`를 빼먹으시면 안됩니다.<br>
참조자는 많이 쓰이니 잘 모르겠다면 C++ 개념을 복습하는 것도 좋습니다<br>


그리고 주로 2차원 좌표에서 pair<int, int> 자료형을 많이 사용하는데
```cpp
#define Y first
#define X second
pair<int, int> yx = make_pair(3, 2);
int y = yx.Y;
int x = yx.X;
```
등의 방식으로 사용합니다.<br>
코드가 더 직관적이게 된다는 장점이 있습니다.<br>

그리고 문제에서 제시되는 변수는 가능하면 대문자로 표시합니다.<br>
이건 그냥 제 습관인데, 이게 더 좋더라구요.<br>
```cpp
int N, M, answer = 0; // N, M은 문제 제시, answer은 직접 만든 변수
cin >> N >> M;
vector<vector<int>> A(N, vector<int>(M, 0));
for(auto& vi : A) {
    for(int& i : vi) cin >> i;
}
```

---
일단 이 정도면 일반적인 내용은 모두 작성한 것 같고,<br>
필요하다면 해설해서 추가로 설명하겠습니다.
