#ifndef _LEVEL_WRAPPER_
#define _LEVEL_WRAPPER_

#include <string>
#include "formatter.hpp"
#include "levels.hpp"

namespace loglady {
namespace formatter {

class LevelWrapperCompact : public DefaultFormatter {
public:
    template <levels::LevelType Level>
    static inline void Format(std::string& param_message) {
        switch (Level)
        {
        case levels::LevelType::INFO :
            param_message = "[I] " + param_message;
            break;
        case levels::LevelType::WARN :
            param_message = "[W] " + param_message;
            break;
        case levels::LevelType::ERROR :
            param_message = "[E] " + param_message;
            break;
        case levels::LevelType::FATAL :
            param_message = "[F] " + param_message;
            break;
        case levels::LevelType::TRACE :
            param_message = "[T] " + param_message;
            break;
        case levels::LevelType::DEBUG :
            param_message = "[D] " + param_message;
            break;
        case levels::LevelType::ALL :
            param_message = "[A] " + param_message;
            break;
        default:
            break;
        }
    }
};

class LevelWrapperVerbose : public DefaultFormatter {
public:
    template <levels::LevelType Level>
    static inline void Format(std::string& param_message) {
        switch (Level)
        {
        case levels::LevelType::INFO :
            param_message = "[INFO] " + param_message;
            break;
        case levels::LevelType::WARN :
            param_message = "[WARN] " + param_message;
            break;
        case levels::LevelType::ERROR :
            param_message = "[ERROR] " + param_message;
            break;
        case levels::LevelType::FATAL :
            param_message = "[FATAL] " + param_message;
            break;
        case levels::LevelType::TRACE :
            param_message = "[TRACE] " + param_message;
            break;
        case levels::LevelType::DEBUG :
            param_message = "[DEBUG] " + param_message;
            break;
        case levels::LevelType::ALL :
            param_message = "[ALL] " + param_message;
            break;
        default:
            break;
        }
    }
};

} // namespace formatter
} // namespace loglady

#endif // _LEVEL_WRAPPER_