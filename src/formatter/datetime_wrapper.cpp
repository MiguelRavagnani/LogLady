#include "datetime_wrapper.hpp"

namespace loglady {
namespace formatter {

void DatetimeWrapper::Format(std::string& param_message) const {
    
    time_t now = time(NULL);
    struct tm tstruct;
    char date_buf[40];
    char time_buf[40];

    tstruct = *localtime(&now);

    strftime(date_buf, sizeof(date_buf), "%d/%m/%y", &tstruct);
    strftime(time_buf, sizeof(time_buf), "%X", &tstruct);

    std::string date = date_buf;
    std::string time = time_buf;

    param_message = "["+date+"] ["+time+"] " + param_message;
    FormatterWrapper::Format(param_message);
    return; 
}

} // namespace formatter
} // namespace loglady