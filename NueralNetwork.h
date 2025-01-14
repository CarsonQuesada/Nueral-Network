#pragma once

#include "Math/Matrix.h"

class NueralNetwork
{
public:
	NueralNetwork(unsigned int inputNodes, unsigned int hiddenNodes, unsigned int outputNodes, float learningRate);

	void Train(const std::vector<float>& inputList, const std::vector<float>& targetList);
	std::vector<float> Query(const std::vector<float>& input);

private:
	unsigned int mInputNodes, mHiddenNodes, mOutputNodes;
	float mLearningRate;

	Matrix mWeightsI2H;
	Matrix mWeightsH2O;
};

