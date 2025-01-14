#pragma once

#include <initializer_list>
#include <vector>

class Matrix
{
public:
	Matrix(unsigned int rows, unsigned int cols);
	Matrix(const std::initializer_list<std::initializer_list<float>>& data);

	inline int GetRowCount() const { return mRowCount; }
	inline int GetColCount() const { return mColCount; }
	inline int ElementCount() const { return mRowCount * mColCount; }

	float& operator()(size_t row, size_t col) { return mData[(row * mColCount) + col]; }
	const float& operator()(size_t row, size_t col) const { return mData[(row * mColCount) + col]; }

	Matrix operator*(const Matrix& otherMat);
	Matrix operator+(const Matrix& otherMat);
	Matrix& operator+=(const Matrix& otherMat);

protected:
	unsigned int mRowCount, mColCount;
	std::vector<float> mData;
};

class TransposeView
{
public:
	TransposeView(const Matrix& matrix) : mMatrix(matrix) {}

	int GetRowCount() const { return mMatrix.GetColCount(); }
	int GetColCount() const { return mMatrix.GetRowCount(); }

	const float& operator()(size_t row, size_t col) { return mMatrix(col, row); }
private:
	const Matrix& mMatrix;
};

Matrix operator*(float number, const Matrix& mat);
Matrix operator+(float number, const Matrix& mat);
Matrix operator/(float number, const Matrix& mat);
Matrix operator-(float number, const Matrix& mat);
inline Matrix operator*(const Matrix& mat, float number) { return number * mat; }
inline Matrix operator+(const Matrix& mat, float number) { return number + mat; }
inline Matrix operator/(const Matrix& mat, float number) { return number / mat; }
inline Matrix operator-(const Matrix& mat, float number) { return number - mat; }
