#include "MgErrorHandler.h"

MgErrorHandler::MgErrorHandler()
{
	errors = {};
	logging = false;
	throwing = false;
}

MgErrorHandler::MgErrorHandler(bool logging, bool throwing)
{
	errors = {};
	this->logging = logging;
	this->throwing = throwing;
}

void MgErrorHandler::err(std::string error)
{
	errors.push_back(error);
	if (logging) std::cout << "Magnesium error: " << error << "\n";
	if (throwing) throw std::runtime_error(error);
}

void MgErrorHandler::setLogging(bool enabled)
{
	logging = enabled;
}

void MgErrorHandler::setThrowing(bool enabled)
{
	throwing = enabled;
}

std::vector<std::string> MgErrorHandler::getErrors()
{
	return errors;
}

std::string MgErrorHandler::getLastError()
{
	return errors[errors.size() - 1];
}

bool MgErrorHandler::isLogging()
{
	return logging;
}

bool MgErrorHandler::isThrowing()
{
	return throwing;
}

void MgErrorHandler::dispose()
{
	errors.clear();
	logging = false;
	throwing = false;
}
