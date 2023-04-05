#include <ctime>
#include <iostream>
#include <limits.h>

using namespace std;

const int MatrixSize{16};
void createMatrix(int (&matrix)[MatrixSize][MatrixSize]);
void printMatrix(int (&matrix)[MatrixSize][MatrixSize]);
void fillMaximalIndexes(int (&matrix)[MatrixSize][MatrixSize],
                        int (&maxIndexElements)[MatrixSize]);
void calculateSumInRow(int (&matrix)[MatrixSize][MatrixSize],
                       int (&maxIndexElements)[MatrixSize],
                       int (&sumOfRows)[MatrixSize]);
void productOfElementsAfterMaxElement(int (&sumOfRows)[16]);
bool checkingStringsForSymmetry(int matrix[][MatrixSize], const int MatrixSize);
int calculateSumOfBlackMatrixElements(int matrix[][MatrixSize],
                                      const int MatrixSize);
int main() {
  int matrix[MatrixSize][MatrixSize]{
      {100, 100, 100, 1}, {100, 100, 1, 1}, {100, 1, 1, 1}, {1, 1, 1, 1}};
  setlocale(LC_ALL, "ru");
  // а

  srand(time(NULL));
  createMatrix(matrix);
  printMatrix(matrix);
  cout << '\n';
  int maxIndexElements[MatrixSize] = {0};
  fillMaximalIndexes(matrix, maxIndexElements);
  int sumOfRows[MatrixSize] = {0};
  calculateSumInRow(matrix, maxIndexElements, sumOfRows);
  productOfElementsAfterMaxElement(sumOfRows);
  cout << '\n';
  // б
  bool stringsAreSymmetrical = checkingStringsForSymmetry(matrix, MatrixSize);
  if (stringsAreSymmetrical) {
    cout << "Все строки симметричны относительно среднего элемента.";
  } else {
    cout << "Cтроки не симметричны относительно среднего элемента.";
  }
  cout << '\n';
  // в
  cout << "Сумма элементов матрицы, выделенных чёрным цветом равна "
       << сalculateSumOfBlackMatrixElements(matrix, MatrixSize) << ".\n"
       << endl;
  return 0;
}
void createMatrix(int (&matrix)[MatrixSize][MatrixSize]) {
  for (int i = 0; i < MatrixSize; i++) {
    for (int j = 0; j < MatrixSize; j++) {
      matrix[i][j] = rand() % 19 + (-9);
      ;
    }
  }
}
void printMatrix(int (&matrix)[MatrixSize][MatrixSize]) {
  for (int i = 0; i < MatrixSize; i++) {
    for (int j = 0; j < MatrixSize; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
void fillMaximalIndexes(int (&matrix)[MatrixSize][MatrixSize],
                        int (&maxIndexElements)[MatrixSize]) {
  for (int i = 0; i < MatrixSize; i++) {
    int localMaximal = INT_MIN;
    int localIndex = 0;
    for (int j = 0; j < MatrixSize; j++) {
      if (matrix[i][j] > localMaximal) {
        localMaximal = matrix[i][j];
        localIndex = j;
      }
    }
    maxIndexElements[i] = localIndex;
  }
}
void calculateSumInRow(int (&matrix)[MatrixSize][MatrixSize],
                       int (&maxIndexElements)[MatrixSize],
                       int (&sumOfRows)[MatrixSize]) {
  for (int i = 0; i < MatrixSize; i++) {
    int localSum = 1;
    for (int j = maxIndexElements[i]; j < 16; j++) {
      if (j == maxIndexElements[i]) {
        continue;
      }
      localSum *= matrix[i][j];
    }
    sumOfRows[i] = localSum;
  }
}
void productOfElementsAfterMaxElement(int (&sumOfRows)[MatrixSize]) {
  for (int i = 0; i < MatrixSize; i++) {
    cout << "Row index: " << i << " Row mult: " << sumOfRows[i] << endl;
  }
}
bool checkingStringsForSymmetry(int matrix[][MatrixSize],
                                const int MatrixSize) {
  bool isStringsSymmetrical = true;
  for (size_t i = 0; i < MatrixSize / 2; i++) {
    for (size_t j = 0; j < MatrixSize; j++) {
      if (matrix[i][j] != matrix[MatrixSize - 1 - i][j]) {
        isStringsSymmetrical = false;
        break;
      }
    }
    if (!isStringsSymmetrical) {
      break;
    }
  }
  return isStringsSymmetrical;
}
int calculateSumOfBlackMatrixElements(int matrix[][MatrixSize],
                                      const int MatrixSize) {
  int sumOfBlackMatrixElements{};
  for (size_t i = 0; i < MatrixSize; i++) {
    for (size_t j = i; j < MatrixSize; j++) {
      sumOfBlackMatrixElements += matrix[MatrixSize - 1 - i][j];
    }
  }
  return sumOfBlackMatrixElements;
}
