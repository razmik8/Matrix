#include "matrix.h"
Matrix::Matrix()
{
    rows_ = 0;
    cols_ = 0;
    data_ = nullptr;
}
Matrix::Matrix(size_t row, size_t col)
{
    rows_ = row;
    cols_ = col;
    data_ = new double*[row];
    for(int i = 0; i < row; i++)
    {
        data_[i] = new double[col];
    }
}
Matrix::~Matrix()
{   
    if(data_ == nullptr)
    {
        return;
    }
    for(int i = 0; i < rows_; i++)
    {
        delete[] data_[i];
    }
    delete[] data_;
    data_ = nullptr;
}
Matrix::Matrix(const Matrix& obj)
{
    rows_ = obj.rows_;
    cols_ = obj.cols_;
    data_ = new double*[rows_];
    for(int i = 0; i < rows_; i++)
    {
        data_[i] = new double[cols_];
    }
    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < cols_; j++)
        {
            data_[i][j] = obj.data_[i][j];
        } 
    }
}
Matrix::Matrix (Matrix&& obj)
{
    rows_ = obj.rows_;
    cols_ = obj.cols_;
    data_ = obj.data_;
    for(int i = 0; i < rows_; i++)
    {
        data_[i] = obj.data_[i];
    }
    obj.data_ = nullptr;
}
Matrix::Matrix& operator=(const Matrix& obj)
{
    if(this == &obj)
    {
        return *this;
    }
    for(int i = 0; i < rows_; i++)
    {
        delete[] data_[i]
    }
    rows_ = obj.rows_;
    cols_ = obj.cols_;
    delete[] data_;
    data_ = new double*[rows_];
    for(int i = 0; i < rows_; i++)
    {
        data_[i] = new double*[cols_];
        for(int j = 0; j < cols_; j++)
        {
            data_[i][j] = obj.data_[i][j];
        }
    }
}
Matrix::Matrix& operator=(Matrix&& obj)
{
    rows_ = obj.rows_;
    cols_ = obj.cols_;
    data_ = obj.data_;
    obj.data_ = nullptr;
    obj.rows_ = 0;
    obj.cols_ = 0;
}

void Matrix::set(size_t row, size_t col, double value)
{
    data_[row][col] = value;
}
double Matrix::get(size_t row, size_t col)const
{
    return data_[row][col];
}
size_t Matrix::getRows()const
{
    return rows_;
}
size_t Matrix::getCols()const
{
    return cols_;
}
void Matrix::print()const
{
    for(int i = 0; i < rows_; i++)
    {
        for(int j = 0; j < cols_; j++)
        {
            std::cout << data_[i][j];
        }
        std::cout << std::endl;
    }
}
void Matrix operator<<()
{
    
}
