#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

template<typename T>
bool isMatrix(T const& m) {
	if (empty(m)) return true;

	auto const cols = size(*begin(m));

	for (auto& row : m) {
		if (size(row) != cols) return false;

	}

	return true;
}

template<typename M>
bool isMatrixGankels(M const& v) {

	if (!isMatrix(v)) return false;

	size_t n = v.size();

	for (size_t i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i + j < n) {
				if (v[i][j] != v[i + j][0]) return false;
			}
			else {
				if (v[i][j] != v[i + j - n + 1][n - 1]) return false;
			}

		}
	}
	return true;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<vector<int>> vector = {
	{1,2,3,4,5},
	{2,3,4,5,6},
	{3,4,5,6,7},
	{4,5,6,7,8},
	{5,6,7,8,9}
	};


	if (isMatrixGankels(vector)) cout << "Матрица ганкелева";
	else {
		cout << "Матрица либо не матрица, либо не ганкелева";
	}
	return 0;
}