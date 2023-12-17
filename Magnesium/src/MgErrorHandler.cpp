#include "MgErrorHandler.h"

MgErrorHandler::MgErrorHandler()
{
	errors = {};
	logAll = false;
	throwAll = false;
}

MgErrorHandler::MgErrorHandler(bool logAll, bool throwAll)
{
	errors = {};
	this->logAll = logAll;
	this->throwAll = throwAll;
}

void MgErrorHandler::err(std::string error)
{
	errors.push_back(error);
	if (logAll) std::cout << "Magnesium error: " << error << "\n";
	if (throwAll) throw std::runtime_error(error);
}

void MgErrorHandler::setLogAll(bool enabled)
{
	logAll = enabled;
}

void MgErrorHandler::setThrowAll(bool enabled)
{
	throwAll = enabled;
}

std::vector<std::string> MgErrorHandler::getErrors()
{
	return errors;
}

std::string MgErrorHandler::getLastError()
{
	return errors[errors.size() - 1];
}

bool MgErrorHandler::logsAll()
{
	return logAll;
}

bool MgErrorHandler::throwsAll()
{
	return throwAll;
}

void MgErrorHandler::cleanup()
{
	errors.clear();
	logAll = false;
	throwAll = false;
}
