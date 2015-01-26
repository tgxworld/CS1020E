class Matrix {
  private:
    void rotate(int degree);
    void reflectX();
    void reflectY();

  public:
    void operate(string operation, string type);
};
