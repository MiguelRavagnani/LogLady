#include "config_formatter.hpp"

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

std::shared_ptr<Formatter> BuildFormatter(Format param_format, loglady::levels::LevelType param_level) {
    auto default_formatter = std::shared_ptr<loglady::formatter::Formatter>(new loglady::formatter::DefaultFormatter);
    bool verbose = false;

    if ((param_format & (Format::DATE + Format::TIME)) != Format::NONE) {
        default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::DatetimeWrapper(default_formatter));    
    }

    verbose = ((param_format & Format::VERBOSE) != Format::NONE) ? true : false;

    if ((param_format & Format::LEVEL) != Format::NONE) {
        default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::LevelWrapper(default_formatter, param_level, verbose));
    }

    return default_formatter;
}

} // namespace formatter
} // namespace loglady