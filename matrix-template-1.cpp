
#include <iostream>
#include <sstream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin(){
    string user_input = "";
    getline(cin, user_input);
    std::istringstream stream(user_input);
    int value = 0;
    int row = 0;
    int col = 0;
    while(stream >> value){
      data[row][col] = value;
      col++;
      if(col == SIZE){
        col = 0;
        row++;
      }
      if(row == SIZE){
        break;
      }
    }

  }

  // 2. Display a matrix
  void display() const{
    for(const auto& row : data){
      for(const auto& value : row){
        cout << value << " ";
      }
      cout << endl;
    }

  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const{
    Matrix new_matrix;
    for(int row = 0; row < 4; row++){
      for(int col = 0; col < 4; col++){
        new_matrix.data[row][col] = data[row][col] + other.data[row][col];
      }
    }
    return new_matrix;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const{
    Matrix new_matrix;
    for(int i = 0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
        for(int k = 0; k < SIZE; k++){
          new_matrix.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
    return new_matrix;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const{
    int sum = 0;
    for(int i = 0; i < SIZE; i++){
      sum += data[i][i];
    }
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2){
    int tempnum;

    for(int col = 0; col < SIZE; col++){
      tempnum = data[row1][col];
      data[row1][col] = data[row2][col];
      data[row2][col] = tempnum;
    }
  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter 16 space serperated values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter 16 space seperated values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
