/* [풀이]
1. 이름->인덱스 형식의 map 활용, Union Find 알고리즘 사용
2. 새로운 사람이 나타날 때마다 parent와 size를 합쳐주기
3. SetUnion을 하면 두 집단의 size를 합쳐주기
*/

#include <bits/stdc++.h>
using namespace std;

int T, F;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while (T--) {
		int idx = 0;
		map<string, int> nameIdx;

		cin >> F;
		vector<int> parent, size; // 부모, 현재의 크기
		// 부모 찾기 함수
		function<int(int)> FindParent = [&](int a) -> int {
			if (a == parent[a]) return a;
			return parent[a] = FindParent(parent[a]);
			};

		// 유니온 설정
		function<void(int, int)> SetUnion = [&](int x, int y) -> void {
			int rootX = FindParent(x);
			int rootY = FindParent(y);

			if (rootX != rootY) {
				if (size[rootX] < size[rootY]) {
					swap(rootX, rootY);
				}
				parent[rootY] = rootX;
				size[rootX] += size[rootY]; // 크기 통합
			}};

		while (F--) {
			string name1, name2;
			cin >> name1 >> name2;
			if (nameIdx.find(name1) == nameIdx.end()) { // 인덱스가 없다면
				parent.push_back(idx); // 부모 : 인덱스에 맞게 추가
				size.push_back(1); // 크기 1 추가
				nameIdx[name1] = idx++; // 인덱스 등록
			}
			if (nameIdx.find(name2) == nameIdx.end()) {
				parent.push_back(idx);
				size.push_back(1);
				nameIdx[name2] = idx++;
			}

			int idx1 = nameIdx[name1], idx2 = nameIdx[name2];
			SetUnion(idx1, idx2); // 두 인덱스를 하나의 유니온으로 합치기
			cout << size[FindParent(idx1)] << "\n";
		}
	}
}