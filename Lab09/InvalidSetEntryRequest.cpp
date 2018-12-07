#include "InvalidSetEntryRequest.h"

InvalidSetEntryRequest::InvalidSetEntryRequest(const std::string& message): logic_error("Invalid Set Entry Request: " + message)
{
}