#include "datetime_wrapper.hpp"

namespace loglady {
namespace formatter {

void DatetimeWrapper::Format(std::string& param_message) const {
    
    param_message = "[dd/mm/yy] [hh:mm:ss] " + param_message;
    
    FormatterWrapper::Format(param_message);
    return; 
}

} // namespace formatter
} // namespace loglady