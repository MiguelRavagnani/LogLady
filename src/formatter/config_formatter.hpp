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

/**
 * @brief Abstracts the building of the formatter
 * 
 * @param param_format Plug in the defautl formatter
 * @param param_level Sink level
 * @return std::shared_ptr<Formatter> Built formatter
 */
std::shared_ptr<Formatter> BuildFormatter(Format param_format, loglady::levels::LevelType param_level = loglady::levels::LevelType::INFO);

} // namespace formatter
} // namespace loglady

#endif // _CONFIG_FORMATTER_