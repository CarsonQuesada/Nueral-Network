#pragma once
#include <string>
#include <vector>

#define TARGET_SIZE 10
#define SAMPLE_DATA_SIZE 784

struct Sample 
{
	Sample(const std::vector<int>& sampleData);

	std::vector<float> TargetList();

	int label;
	std::vector<float> data;
};

class DataSet
{
public:
	DataSet(const std::string& dataFilepath, int sampleCount);

	int SampleCount() const { return mSamples.size(); }

	std::vector<Sample>::iterator begin() { return mSamples.begin(); } // For range based for loop
	std::vector<Sample>::iterator end() { return mSamples.end(); }     // For range based for loop

private:
	std::vector<Sample> mSamples;
};

