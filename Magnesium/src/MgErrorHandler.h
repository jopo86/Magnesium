#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Magnesium.h"
#include "MgObject.h"

/*
 * @brief A class to handle internal errors and relay them back to the user.
 * When an error occurs, the error handler decides what to do with it,
 * based on the logging/throwing settings set by the user.
 */
class MgErrorHandler : public MgObject
{
public:
	/*
	 * @brief Creates a new MgErrorHandler object with logging and throwing disabled.
	 */
	MgErrorHandler();

	/*
	 * @brief Creates a new MgErrorHandler object with the specified logging and throwing settings.
	 * @param logAll Whether to log all errors.
	 * @param throwAll Whether to throw all errors.
	 */
	MgErrorHandler(bool logAll, bool throwAll);

	/*
	 * @brief Passes an error to the error handler.
	 * The error handler decides what to do with the error
	 * based on the logging/throwing settings.
	 * This function should not really by called by the user,
	 * it is just used by the library.
	 * @param error The error to pass.
	 */
	void err(std::string error);

	/*
	 * @brief Sets whether to log all errors.
	 * @param enabled Whether to log all errors.
	 */
	void setLogAll(bool enabled);

	/*
	 * @brief Sets whether to throw all errors.
	 * @param enabled Whether to throw all errors.
	 */
	void setThrowAll(bool enabled);

	/*
	 * @brief Gets all errors.
	 * @return A vector containing all errors.
	 */
	std::vector<std::string> getErrors();

	/*
	 * @brief Gets the last error passed to the handler.
	 * @return The last error.
	 */
	std::string getLastError();

	/*
	 * @brief Returns whether the handler logs all errors.
	 * @return Whether the handler logs all errors.
	 */
	bool logsAll();

	/*
	 * @brief Returns whether the handler throws all errors.
	 * @return Whether the handler throws all errors.
	 */
	bool throwsAll();

	/*
	 * @brief Cleans up any memory and/or resources used by the error handler.
	 * This function should be called when the object is no longer needed,
	 * such as when the program exits or the object goes out of scope.
	 */
	void cleanup();

private:
	std::vector<std::string> errors;

	bool logAll;
	bool throwAll;
};
