#include <iostream>
#include <vector>

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

		for (size_t j = 0; j < n; j++) {

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

	vector<vector<int>> vector = {
	{1,2,3,4,5},
	{2,3,4,5,6},
	{3,4,5,6,7},
	{4,5,6,7,8},
	{5,6,7,8,9}
	};


	if (isMatrixGankels(vector)) cout << "Matrix is Hankel's";
	else {
		cout << "The matrix is either not a matrix or not a Hankel's matrix";
	}
	return 0;
}