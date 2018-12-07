#ifndef _INVALID_SET_ENTRY_REQUEST
#define _INVALID_SET_ENTRY_REQUEST

#include <stdexcept>
#include <string>

class InvalidSetEntryRequest : public std::logic_error
{
public:
  InvalidSetEntryRequest(const std::string& message = "");
};
#endif