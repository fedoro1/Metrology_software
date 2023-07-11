#include "Functions.h"

template <typename T>
void WritePointsToFile(const string& path, const string& fileName, const T& feature) {
	fstream fs;
	const vector<Element>& container = feature.GetContainer();
	int size = container.size();
	fs.open(path + fileName, fstream::app);
	for (size_t i = 0; i < size; i++) {
		fs << container.at(i);
	}
	fs.close();
}