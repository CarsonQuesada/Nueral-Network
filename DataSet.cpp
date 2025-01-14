#include "DataSet.h"

#include <iostream>
#include <fstream>
#include <sstream>

DataSet::DataSet(const std::string& dataFilepath, int sampleCount = 0)
{
	mSamples.reserve(sampleCount);

	// Open file
	std::ifstream trainingData_f(dataFilepath);
	if (!trainingData_f.is_open())
	{
		std::cout << "Could not open file" << dataFilepath << std::endl;
		return;
	}

	// Parse csv file and create samples from it
	std::string sampleDataString;
	while (std::getline(trainingData_f, sampleDataString))
	{
		std::vector<int> sampleData;
		std::istringstream sampleData_ss(sampleDataString);
		std::string data;
		while (std::getline(sampleData_ss, data, ','))
			sampleData.emplace_back(std::stoi(data));

		Sample sample(sampleData);
		mSamples.emplace_back(sample);
	}
}

Sample::Sample(const std::vector<int>& sampleData)
	: label(sampleData[0])
{
	// Preprocess Image Data
	data.reserve(SAMPLE_DATA_SIZE);
	for (int i = 1; i < sampleData.size(); i++)
		data.emplace_back(((float(sampleData[i]) / 255.0f) * 0.99f) + 0.01f);
}

std::vector<float> Sample::TargetList()
{
	std::vector<float> targets(TARGET_SIZE, 0.01f);
	targets[label] = 0.99f;

	return targets;
}
