#include "level_wrapper.hpp"

namespace loglady {
namespace formatter {

void InfoWrapper::Format(std::string& param_message) const {

    param_message = "[I] " + param_message;
    FormatterWrapper::Format(param_message);
    return; 
}

void WarnWrapper::Format(std::string& param_message) const {

    param_message = "[W] " + param_message;
    FormatterWrapper::Format(param_message);
    return; 
}

void ErrorWrapper::Format(std::string& param_message) const {

    param_message = "[E] " + param_message;
    FormatterWrapper::Format(param_message);
    return; 
}

void FatalWrapper::Format(std::string& param_message) const {

    param_message = "[F] " + param_message;
    FormatterWrapper::Format(param_message);
    return; 
}

void TraceWrapper::Format(std::string& param_message) const {

    param_message = "[T] " + param_message;
    FormatterWrapper::Format(param_message);
    return; 
}

void DebugWrapper::Format(std::string& param_message) const {

    param_message = "[D] " + param_message;
    FormatterWrapper::Format(param_message);
    return; 
}

void AllWrapper::Format(std::string& param_message) const {

    param_message = "[A] " + param_message;
    FormatterWrapper::Format(param_message);
    return; 
}

} // namespace formatter
} // namespace loglady