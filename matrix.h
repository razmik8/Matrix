#ifndef Matrix_h
#define Matrix_h
class Matrix 
{
public:
    Matrix();
    Matrix(size_t,size_t,);
    ~Matrix();
    Matrix(const Matrix&);
    Matrix(Matrix&&);
    Matrix& operator=(const Matrix&);
    Matrix& operator=(Matrix&&);

    void set(size_t row, size_t col, double value);
    double get(size_t row, size_t col) const;
    size_t getRows() const;
    size_t getCols() const;
    void print() const;

    Matrix operator+(const Matrix&);
    void operator<<();
    Matrix operator*(const Matrix&);
pivate:
    size_t rows_;
    size_t cols_;
    double** data_;
}
#endif
