#ifndef _FORMATTER_WRAPPER_
#define _FORMATTER_WRAPPER_

#include <string>

#include "formatter.hpp"

namespace loglady {
namespace formatter {

class FormatterWrapper : public Formatter {
protected:
    std::shared_ptr<Formatter> m_wrapper;

public:
    FormatterWrapper(std::shared_ptr<Formatter> param_formatter) : m_wrapper(param_formatter) {}

    /**
     * @brief Base formatter wrapper
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};

} // namespace formatter
} // namespace loglady

#endif // _FORMATTER_WRAPPER_