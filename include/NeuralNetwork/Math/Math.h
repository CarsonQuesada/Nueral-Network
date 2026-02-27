#pragma once

#include "Matrix.h"

class Math
{
public:
	template<typename T1, typename T2>
	static Matrix Dot(T1 mat1, T2 mat2)
	{
		unsigned int rows = mat1.GetRowCount();
		unsigned int cols = mat2.GetColCount();
		Matrix resultMat(rows, cols);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				for (int k = 0; k < mat1.GetColCount(); k++)
				{
					resultMat(i, j) += mat1(i, k) * mat2(k, j);
				}
		}

		return resultMat;
	}

	static float Sigmoid(float input);
	static Matrix Sigmoid(Matrix input);
};

