#ifndef _DATETIME_WRAPPER_
#define _DATETIME_WRAPPER_

#include <string>
#include <time.h>

#include "formatter_wrapper.hpp"

namespace loglady {
namespace formatter {

class DateWrapper : public FormatterWrapper {
public:
    DateWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds date and/or time to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override {
        time_t now = time(NULL);
        struct tm tstruct;
        char date_buf[40];

        tstruct = *localtime(&now);

        strftime(date_buf, sizeof(date_buf), "%d/%m/%y", &tstruct);

        std::string date = date_buf;

        param_message = "["+date+"] " + param_message;
        FormatterWrapper::Format(param_message);
        return; 
    }
};

class TimeWrapper : public FormatterWrapper {
public:
    TimeWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds date and/or time to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override {
        time_t now = time(NULL);
        struct tm tstruct;
        char time_buf[40];

        tstruct = *localtime(&now);

        strftime(time_buf, sizeof(time_buf), "%X", &tstruct);

        std::string time = time_buf;

        param_message = "["+time+"] " + param_message;
        FormatterWrapper::Format(param_message);
        return; 
    }
};

} // namespace formatter
} // namespace loglady

#endif // _DATETIME_WRAPPER_