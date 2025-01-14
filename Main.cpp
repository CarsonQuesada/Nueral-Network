#include <iostream>
#include <string>

#include "DataSet.h"
#include "NueralNetwork.h"

#define TRAINING_SET_SIZE 100
#define TESTING_SET_SIZE 10

int main()
{
	NueralNetwork nueralNetwork(SAMPLE_DATA_SIZE, 100, TARGET_SIZE, 0.2f);
	std::string trainingDataLoc = "DataSets/TrainingData100.csv";
	std::string testingDataLoc = "DataSets/TestingData10.csv";

	DataSet trainingData(trainingDataLoc, TRAINING_SET_SIZE);

	// Train nueral network
	for (Sample sample : trainingData)
	{
		nueralNetwork.Train(std::vector<float>(sample.data.begin(), sample.data.end()), sample.TargetList());
	}

	DataSet testingData(testingDataLoc, TESTING_SET_SIZE);

	// Test nueral network
	int correctCount = 0;
	for (Sample sample : testingData)
	{
		std::vector<float> outputs = nueralNetwork.Query(std::vector<float>(sample.data.begin(), sample.data.end()));

		// Find index of highest output
		float prevHigh = -1.0f;
		int indexHigh = 0;
		for (int i = 0; i < outputs.size(); i++)
		{
			if (prevHigh < outputs[i])
			{
				prevHigh = outputs[i];
				indexHigh = i;
			}
		}

		// Tally and display result
		if (indexHigh == sample.label)
		{
			correctCount++;
			std::cout << "CORRECT!  ";
		}
		else
		{
			std::cout << "INCORRECT!";
		}
		std::cout << " | Target: " << sample.label << ", Evaluated to: " << indexHigh << std::endl;
	}

	// Display score
	std::cout << (float(correctCount) / float(testingData.SampleCount())) * 100.0f << "% correct" << std::endl;

	return 0;
}
