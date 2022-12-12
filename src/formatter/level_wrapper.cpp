#include "level_wrapper.hpp"
namespace loglady {
namespace formatter {

void LevelWrapper::Format(std::string& param_message) const {
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

} // namespace formatter
} // namespace loglady