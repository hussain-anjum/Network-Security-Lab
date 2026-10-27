#include <bits/stdc++.h>
#include <vector>
using namespace std;

void test(vector<vector<int>> matrix) {
  int r = matrix.size();
  int c = matrix[0].size();
  // cout << "The matrix is: " << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  int r, c;
  cout << "Enter the number of rows and columns: ";
  cin >> r >> c;
  vector<vector<int>> matrix(r, vector<int>(c)), matrix2(r, vector<int>(c));
  cout << "Enter the elements of the matrix: " << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> matrix[i][j];
    }
  }
  cout << "Enter the elements of the second matrix: " << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> matrix2[i][j];
    }
  }
  // test(matrix);
  vector<vector<int>> sum(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      sum[i][j] = matrix[i][j] + matrix2[i][j];
    }
  }

  cout << "The sum of the two matrices is: " << endl;
  test(sum);

  vector<vector<int>> subtract(r, vector<int>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      subtract[i][j] = matrix[i][j] - matrix2[i][j];
    }
  }

  cout << "The difference of the two matrices is: " << endl;
  test(subtract);
  
  return 0;
}
