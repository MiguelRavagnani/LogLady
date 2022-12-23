#ifndef _LEVEL_WRAPPER_
#define _LEVEL_WRAPPER_

#include <string>
#include "formatter_wrapper.hpp"
#include "levels.hpp"

namespace loglady {
namespace formatter {

template <typename Format>
class LevelWrapper: public virtual Wrapper<Format> {
public:
    /**
     * @brief Construct a new Wrapper object
     * 
     * @param m_formatter A formater to recieve the wrapper format
     */
    DateWrapper(Format m_formatter) : Wrapper<Format>(m_formatter) {}

    virtual ~DateWrapper(){}
    
    /**
     * @brief Formats a message with a date
     * 
     * @param param_message string message
     */
    virtual void Format(std::string& param_message, const levels::LevelType& param_level = levels::LevelType::INFO) {
        switch (param_level)
        {
        case levels::LevelType::INFO :
            param_message = ((m_level_config->m_verbose) ? "[INFO] " : "[I] ") + param_message;
            break;
        case levels::LevelType::WARN :
            param_message = ((m_level_config->m_verbose) ? "[WARN] " : "[W] ") + param_message;
            break;
        case levels::LevelType::ERROR :
            param_message = ((m_level_config->m_verbose) ? "[ERROR] " : "[E] ") + param_message;
            break;
        case levels::LevelType::FATAL :
            param_message = ((m_level_config->m_verbose) ? "[FATAL] " : "[F] ") + param_message;
            break;
        case levels::LevelType::TRACE :
            param_message = ((m_level_config->m_verbose) ? "[TRACE] " : "[T] ") + param_message;
            break;
        case levels::LevelType::DEBUG :
            param_message = ((m_level_config->m_verbose) ? "[DEBUG] " : "[D] ") + param_message;
            break;
        case levels::LevelType::ALL :
            param_message = ((m_level_config->m_verbose) ? "[ALL] " : "[A] ") + param_message;
            break;
        default:
            break;
        }

        this->m_formatter.Format(param_message);
    }
};

} // namespace formatter
} // namespace loglady

#endif // _LEVEL_WRAPPER_