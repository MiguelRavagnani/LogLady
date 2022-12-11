#include "formatter_wrapper.hpp"

namespace loglady {
namespace formatter {

void FormatterWrapper::Format(std::string& param_message) const {
    this->m_wrapper->Format(param_message);
    return; 
}

} // namespace formatter
} // namespace loglady