#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Magnesium.h"
#include "MgObject.h"

class MgErrorHandler : public MgObject
{
public:
	MgErrorHandler();
	MgErrorHandler(bool logging, bool throwing);

	void err(std::string error);

	void setLogging(bool enabled);
	void setThrowing(bool enabled);

	std::vector<std::string> getErrors();
	std::string getLastError();
	bool isLogging();
	bool isThrowing();

	void dispose() override;

private:
	std::vector<std::string> errors;

	bool logging;
	bool throwing;
};
