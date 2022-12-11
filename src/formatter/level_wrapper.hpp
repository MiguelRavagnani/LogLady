#ifndef _LEVEL_WRAPPER_
#define _LEVEL_WRAPPER_

#include <string>

#include "formatter_wrapper.hpp"

namespace loglady {
namespace formatter {

class InfoWrapper : public FormatterWrapper {
public:
    InfoWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds a INFO level to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};
    
class WarnWrapper : public FormatterWrapper {
public:
    WarnWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds a WARN level to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};
    
class ErrorWrapper : public FormatterWrapper {
public:
    ErrorWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds a ERROR level to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};
    
class FatalWrapper : public FormatterWrapper {
public:
    FatalWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds a FATAL level to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};
    
class TraceWrapper : public FormatterWrapper {
public:
    TraceWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds a TRACE level to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};
    
class DebugWrapper : public FormatterWrapper {
public:
    DebugWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds a DEBUG level to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};
    
class AllWrapper : public FormatterWrapper {
public:
    AllWrapper(std::shared_ptr<Formatter> param_formatter) : FormatterWrapper(param_formatter) {}

    /**
     * @brief Adds indicator of ALL levels
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};

} // namespace formatter
} // namespace loglady

#endif // _LEVEL_WRAPPER_