#include "NeuralNetwork.h"

#include <random>

#include "Math/Math.h"

NeuralNetwork::NeuralNetwork(unsigned int inputNodes, unsigned int hiddenNodes, unsigned int outputNodes, float learningRate)
	:mInputNodes(inputNodes), mHiddenNodes(hiddenNodes), mOutputNodes(outputNodes), mLearningRate(learningRate), mWeightsI2H(Matrix(hiddenNodes, inputNodes)), mWeightsH2O(Matrix(outputNodes, hiddenNodes))
{
	std::random_device rd;  // Obtain a random number from hardware
	std::mt19937 gen(rd()); // Seed the generator
	std::uniform_real_distribution<float> dis(-0.5f, 0.5f);

	for (int i = 0; i < mWeightsI2H.GetRowCount(); i++)
		for (int j = 0; j < mWeightsI2H.GetColCount(); j++)
			mWeightsI2H(i, j) = dis(gen);

	for (int i = 0; i < mWeightsH2O.GetRowCount(); i++)
		for(int j = 0; j < mWeightsH2O.GetRowCount(); j++)
			mWeightsH2O(i, j) = dis(gen);
}

void NeuralNetwork::Train(const std::vector<float>& inputList, const std::vector<float>& targetList)
{
	// Basically Query function but needs to be written out becuase we need access to hiddenInput ///////
	// Turn input vector into a single column Matrix
	Matrix inputMatrix(inputList.size(), 1);
	for (int i = 0; i < inputList.size(); i++)
		inputMatrix(i, 0) = inputList[i];

	// Dot product with input to hidden Weights
	Matrix hiddenOutput = Math::Dot(mWeightsI2H, inputMatrix);

	// Use activation function on all the hidden inputs
	hiddenOutput = Math::Sigmoid(hiddenOutput);

	// Dot product with hidden to final Weights
	Matrix finalOutput = Math::Dot(mWeightsH2O, hiddenOutput);

	// Use activation function on all the final inputs
	finalOutput = Math::Sigmoid(finalOutput);
	//////////////////////////////////////////////////////////////////////////////////////////////////////

	// Find output error
	Matrix outputError(mOutputNodes, 1);
	for (int i = 0; i < mOutputNodes; i++)
		outputError(i, 0) = targetList[i] - finalOutput(i, 0);

	// calculate error of hidden nodes
	TransposeView weightsO2H(mWeightsH2O);
	Matrix hiddenError = Math::Dot(weightsO2H, outputError); // backpropogate

	// Update Weights
	Matrix WeightAdjustment = Math::Dot(outputError * finalOutput * ((-1.0 * finalOutput) + 1.0) * mLearningRate, TransposeView(hiddenOutput)); // Update Weights for mWeightsH2O
	mWeightsH2O += WeightAdjustment;

	WeightAdjustment = Math::Dot(hiddenError * hiddenOutput * ((-1.0 * hiddenOutput) + 1.0) * mLearningRate, TransposeView(inputMatrix)); // Update Weights for mWeightsH2O
	mWeightsI2H += WeightAdjustment;
}

std::vector<float> NeuralNetwork::Query(const std::vector<float>& input)
{
	// Turn input vector into a single column Matrix
	Matrix inputMatrix(input.size(), 1);
	for (int i = 0; i < input.size(); i++)
		inputMatrix(i, 0) = input[i];

	// Dot product with input to hidden Weights
	Matrix hiddenInput = Math::Dot(mWeightsI2H, inputMatrix);

	// Use activation function on all the hidden inputs
	hiddenInput = Math::Sigmoid(hiddenInput);

	// Dot product with hidden to final Weights
	Matrix finalInput = Math::Dot(mWeightsH2O, hiddenInput);

	// Use activation function on all the final inputs
	finalInput = Math::Sigmoid(finalInput);

	// Turn finalInput into a vector<float>
	std::vector<float> output;
	output.reserve(mOutputNodes);
	for (int i = 0; i < finalInput.GetRowCount(); i++)
		output.emplace_back(finalInput(i, 0));

	return output;
}
