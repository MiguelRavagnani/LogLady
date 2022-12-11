#include "config_formatter.hpp"

namespace loglady {
namespace formatter {

Format ConfigFormatter(std::string& param_configuration) {
    Format formatter_configuration = Format::NONE;

    if (param_configuration.find("[dd/mm/yy]")) {
        formatter_configuration += Format::DATE;
    }

    if (param_configuration.find("[hh:mm:ss]")) {
        formatter_configuration += Format::TIME;
    }

    if (param_configuration.find("[level]")) {
        formatter_configuration += Format::LEVEL;
    }

    return formatter_configuration;
}

std::shared_ptr<Formatter> BuildFormatter(Format param_format, loglady::levels::LevelType param_level) {
    auto default_formatter = std::shared_ptr<loglady::formatter::Formatter>(new loglady::formatter::DefaultFormatter);

    if ((param_format & (Format::DATE + Format::TIME)) != Format::NONE) {
        default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::DatetimeWrapper(default_formatter));    
    }

    if ((param_format & Format::LEVEL) != Format::NONE) {
        switch (param_level)
        {
        case loglady::levels::LevelType::INFO :
            default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::InfoWrapper(default_formatter));
            break;
        case loglady::levels::LevelType::WARN :
            default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::WarnWrapper(default_formatter));
            break;
        case loglady::levels::LevelType::ERROR :
            default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::ErrorWrapper(default_formatter));
            break;
        case loglady::levels::LevelType::FATAL :
            default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::FatalWrapper(default_formatter));
            break;
        case loglady::levels::LevelType::TRACE :
            default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::TraceWrapper(default_formatter));
            break;
        case loglady::levels::LevelType::DEBUG :
            default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::DebugWrapper(default_formatter));
            break;
        case loglady::levels::LevelType::ALL :
            default_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::AllWrapper(default_formatter));
            break;
        default:
            break;
        }

    }

    return default_formatter;
}

} // namespace formatter
} // namespace loglady