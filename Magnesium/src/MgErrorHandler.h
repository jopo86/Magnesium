#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Magnesium.h"
#include "MgObject.h"

/*
 * @brief A class to handle internal errors and relay them back to the user.
 * Magnesium recognizes errors that occur in the backend, but the user can decide what to do with them using this class.
 * All functions that have the potential to cause an error have an overloaded version that takes an MgErrorHandler object as the last paremeter.
 * When an error occurs, the error handler decides what to do with it, based on the logging/throwing settings set by the user.
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
	 * @param logging Whether to log all errors.
	 * @param throwing Whether to throw all errors.
	 */
	MgErrorHandler(bool logging, bool throwing);

	/*
	 * @brief Passes an error to the error handler.
	 * The error handler decides what to do with the error based on the logging/throwing settings.
	 * This function should not really by called by the user, it is just used by the library when appropriate.
	 * @param error The error to pass.
	 */
	void err(std::string error);

	/*
	 * @brief Sets whether to log all errors.
	 * @param enabled The desired logging setting.
	 */
	void setLogging(bool enabled);

	/*
	 * @brief Sets whether to throw all errors.
	 * @param enabled The desired throwing setting.
	 */
	void setThrowing(bool enabled);

	/*
	 * @brief Returns all errors.
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
	bool isLogging();

	/*
	 * @brief Returns whether the handler throws all errors.
	 * @return Whether the handler throws all errors.
	 */
	bool isThrowing();

	/*
	 * @brief Cleans up any memory and/or resources used by the error handler.
	 * This function should be called when the object is no longer needed, such as when the program exits or the object goes out of scope.
	 */
	void cleanup();

private:
	std::vector<std::string> errors;

	bool logging;
	bool throwing;
};
