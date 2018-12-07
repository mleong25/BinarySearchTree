#include "NotFoundException.h"

NotFoundException::NotFoundException(const std::string& message): logic_error("Not Found Exception: " + message)
{
}