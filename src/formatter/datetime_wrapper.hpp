#ifndef _DATETIME_WRAPPER_
#define _DATETIME_WRAPPER_

#include <string>

#include "formatter_wrapper.hpp"

namespace loglady {
namespace formatter {

class DatetimeWrapper : public FormatterWrapper {
public:
    DatetimeWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds date and/or time to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};

} // namespace formatter
} // namespace loglady

#endif // _DATETIME_WRAPPER_