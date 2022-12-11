#ifndef _CONFIG_FORMATTER_
#define _CONFIG_FORMATTER_

#include <string>

#include "formats.hpp"
#include "datetime_wrapper.hpp"
#include "level_wrapper.hpp"
#include "levels.hpp"

namespace loglady {
namespace formatter {

Format ConfigFormatter(std::string& param_configuration);

std::shared_ptr<Formatter> BuildFormatter(Format param_format, loglady::levels::LevelType param_level = loglady::levels::LevelType::INFO);

} // namespace formatter
} // namespace loglady

#endif // _CONFIG_FORMATTER_