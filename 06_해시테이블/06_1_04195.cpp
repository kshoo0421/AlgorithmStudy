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
		vector<int> parent, size;
		function<int(int)> FindParent = [&](int a) -> int {
			if (a == parent[a]) return a;
			return parent[a] = FindParent(parent[a]);
			};

		function<void(int, int)> SetUnion = [&](int x, int y) -> void {
			int rootX = FindParent(x);
			int rootY = FindParent(y);
			if (rootX != rootY) {
				if (size[rootX] < size[rootY]) {
					swap(rootX, rootY);
				}
				parent[rootY] = rootX;
				size[rootX] += size[rootY];
			}};

		while (F--) {
			string name1, name2;
			cin >> name1 >> name2;
			if (nameIdx.find(name1) == nameIdx.end()) {
				parent.push_back(idx);
				size.push_back(1);
				nameIdx[name1] = idx++;
			}
			if (nameIdx.find(name2) == nameIdx.end()) {
				parent.push_back(idx);
				size.push_back(1);
				nameIdx[name2] = idx++;
			}

			int idx1 = nameIdx[name1], idx2 = nameIdx[name2];
			SetUnion(idx1, idx2);
			cout << size[FindParent(idx1)] << "\n";
		}
	}
}