#include "Math.h"

#include <cassert>
#include <cmath>

float Math::Sigmoid(float input)
{
	return 1.0f / (1.0f + std::exp(-input));
}

Matrix Math::Sigmoid(Matrix input)
{
	Matrix newMat(input.GetRowCount(), input.GetColCount());
	for (int i = 0; i < input.GetRowCount(); i++)
		for (int j = 0; j < input.GetColCount(); j++)
			newMat(i, j) = Sigmoid(input(i, j));

	return newMat;
}
