#ifndef _LEVEL_WRAPPER_
#define _LEVEL_WRAPPER_

#include <string>
#include "formatter_wrapper.hpp"
#include "levels.hpp"

namespace loglady {
namespace formatter {

class LevelWrapper : public FormatterWrapper {
private:
    /* Defines if the level formatter should add the level indicator, such as I, or the complete name, such as INFO */
    bool m_verbose;
    loglady::levels::LevelType m_level;
public:
    LevelWrapper(
        std::shared_ptr<Formatter> param_formatter,
        loglady::levels::LevelType param_level = loglady::levels::LevelType::INFO,
        bool param_verbose = false) : FormatterWrapper(param_formatter), m_level (param_level), m_verbose (param_verbose) {}

    /**
     * @brief Adds a LEVEL level to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override {
        switch (m_level)
        {
        case loglady::levels::LevelType::INFO :
            param_message = ((m_verbose) ? "[INFO] " : "[I] ") + param_message;
            break;
        case loglady::levels::LevelType::WARN :
            param_message = ((m_verbose) ? "[WARN] " : "[W] ") + param_message;
            break;
        case loglady::levels::LevelType::ERROR :
            param_message = ((m_verbose) ? "[ERROR] " : "[E] ") + param_message;
            break;
        case loglady::levels::LevelType::FATAL :
            param_message = ((m_verbose) ? "[FATAL] " : "[F] ") + param_message;
            break;
        case loglady::levels::LevelType::TRACE :
            param_message = ((m_verbose) ? "[TRACE] " : "[T] ") + param_message;
            break;
        case loglady::levels::LevelType::DEBUG :
            param_message = ((m_verbose) ? "[DEBUG] " : "[D] ") + param_message;
            break;
        case loglady::levels::LevelType::ALL :
            param_message = ((m_verbose) ? "[ALL] " : "[A] ") + param_message;
            break;
        default:
            break;
        }

        FormatterWrapper::Format(param_message);
        return; 
    }
};

} // namespace formatter
} // namespace loglady

#endif // _LEVEL_WRAPPER_