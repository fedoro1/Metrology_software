#include "Functions.h"

template <typename T>
void WritePointsToFile(const std::string& path, const std::string& fileName, const T& feature) {
	std::fstream fs;
	const std::vector<Element>& container = feature.GetContainer();
	int size = container.size();
	fs.open(path + fileName, std::fstream::app);
	for (size_t i = 0; i < size; i++) {
		fs << container.at(i);
	}
	fs.close();
}