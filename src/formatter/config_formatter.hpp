#ifndef _CONFIG_FORMATTER_
#define _CONFIG_FORMATTER_

#include <string>

#include "formats.hpp"
#include "datetime_wrapper.hpp"
#include "level_wrapper.hpp"
#include "levels.hpp"

namespace loglady {
namespace formatter {

Format ConfigFormatter(std::string& param_configuration) {
    Format formatter_configuration = Format::NONE;

    if (param_configuration.find("[dd/mm/yy]") != std::string::npos) {
        formatter_configuration += Format::DATE;
    }

    if (param_configuration.find("[hh:mm:ss]") != std::string::npos) {
        formatter_configuration += Format::TIME;
    }

    if (param_configuration.find("[l]") != std::string::npos) {
        formatter_configuration += Format::LEVEL;
    }

    if (param_configuration.find("[level]") != std::string::npos) {
        formatter_configuration += Format::LEVEL;
        formatter_configuration += Format::VERBOSE;
    }

    return formatter_configuration;
}

/**
 * @brief Abstracts the building of the formatter
 * 
 * @param param_format Plug in the defautl formatter
 * @param param_level Sink level
 * @return std::shared_ptr<Formatter> Built formatter
 */
std::shared_ptr<Formatter> BuildFormatter(Format param_format, loglady::levels::LevelType param_level = loglady::levels::LevelType::INFO) {
    auto default_formatter = std::shared_ptr<loglady::formatter::Formatter>(new loglady::formatter::DefaultFormatter);
    bool verbose = false;

    if ((param_format & Format::TIME) != Format::NONE) {
        default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::TimeWrapper(default_formatter));    
    }

    if ((param_format & Format::DATE) != Format::NONE) {
        default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::DateWrapper(default_formatter));    
    }

    verbose = ((param_format & Format::VERBOSE) != Format::NONE) ? true : false;

    if ((param_format & Format::LEVEL) != Format::NONE) {
        default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::LevelWrapper(default_formatter, param_level, verbose));
    }

    return default_formatter;
}

} // namespace formatter
} // namespace loglady

#endif // _CONFIG_FORMATTER_