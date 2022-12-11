#include "formatter.hpp"

namespace loglady {
namespace formatter {

void FormatterAdapter(std::shared_ptr<Formatter> param_formatter, std::string& param_message) {
    param_formatter->Format(param_message);
    return;
}

} // namespace formatter
} // namespace loglady