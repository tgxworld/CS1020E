class Matrix {
  private:
    int _matrix_size;
    void rotate(int degree, int matrix[100][100]);
    void reflectX(int matrix[100][100]);
    void reflectY(int matrix[100][100]);
    void swap_columns(int matrix[100][100]);
    void transpose(int matrix[100][100]);

  public:
    Matrix(int matrix_size);
    void operate(string operation, string type, int matrix[100][100]);
};
