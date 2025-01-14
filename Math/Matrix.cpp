#include "Matrix.h"

// create a zero matrix with specified number of rows and cols
Matrix::Matrix(unsigned int rows, unsigned int cols)
	: mRowCount(rows), mColCount(cols)
{
	mData = std::vector<float>(rows * cols, 0.0f);
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<float>>& data)
	:mRowCount(data.size()), mColCount(data.begin()->size())
{
	mData.reserve(mRowCount * mColCount);

	for (const auto& row : data)
		for (const auto& element : row)
			mData.emplace_back(element);
}

Matrix Matrix::operator*(const Matrix& otherMat)
{
	Matrix newMat(this->mRowCount, this->mColCount);
	for (int i = 0; i < this->mRowCount; i++)
		for (int j = 0; j < this->mColCount; j++)
			newMat(i, j) = (*this)(i, j) * otherMat(i, j);

	return newMat;
}

Matrix Matrix::operator+(const Matrix& otherMat)
{
	Matrix newMat(this->mRowCount, this->mColCount);
	for (int i = 0; i < this->mRowCount; i++)
		for (int j = 0; j < this->mColCount; j++)
			newMat(i, j) = (*this)(i, j) + otherMat(i, j);

	return newMat;
}

Matrix& Matrix::operator+=(const Matrix& otherMat)
{
	*this = *this + otherMat;
	return *this;
}

Matrix operator*(float number, const Matrix& mat)
{
	Matrix newMat(mat.GetRowCount(), mat.GetColCount());
	for (int i = 0; i < mat.GetRowCount(); i++)
		for (int j = 0; j < mat.GetColCount(); j++)
			newMat(i, j) = (mat)(i, j) * number;
	return newMat;
}

Matrix operator+(float number, const Matrix& mat)
{
	Matrix newMat(mat.GetRowCount(), mat.GetColCount());
	for (int i = 0; i < mat.GetRowCount(); i++)
		for (int j = 0; j < mat.GetColCount(); j++)
			newMat(i, j) = (mat)(i, j) + number;
	return newMat;
}

Matrix operator/(float number, const Matrix& mat)
{
	Matrix newMat(mat.GetRowCount(), mat.GetColCount());
	for (int i = 0; i < mat.GetRowCount(); i++)
		for (int j = 0; j < mat.GetColCount(); j++)
			newMat(i, j) = (mat)(i, j) / number;
	return newMat;
}

Matrix operator-(float number, const Matrix& mat)
{
	Matrix newMat(mat.GetRowCount(), mat.GetColCount());
	for (int i = 0; i < mat.GetRowCount(); i++)
		for (int j = 0; j < mat.GetColCount(); j++)
			newMat(i, j) = (mat)(i, j) - number;
	return newMat;
}
