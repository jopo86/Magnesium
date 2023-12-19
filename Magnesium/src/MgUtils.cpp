#include "MgUtils.h"

std::string MgUtils::ReadFile(const char* filepath)
{
	std::string contents = "";
	std::string line = "";
	std::ifstream file(filepath);

	while (std::getline(file, line)) contents += line + "\n";

	file.close();

	return contents;
}

std::string MgUtils::ReadFile(const char* filepath, MgErrorHandler& errorHandler)
{
	std::string contents = "";
	std::string line = "";
	std::ifstream file(filepath);


	if (file.is_open()) while (std::getline(file, line)) contents += line + "\n";
	else
	{
		errorHandler.err("failed to locate file: \"" + std::string(filepath) + "\"");
		return "";
	}

	file.close();

	return contents;
}

void MgUtils::WriteFile(const char* filepath, const char* contents)
{
	std::ofstream file(filepath);
	file << contents;
	file.close();
}
