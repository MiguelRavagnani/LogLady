#ifndef _LEVEL_WRAPPER_
#define _LEVEL_WRAPPER_

#include <string>
#include "formatter_wrapper.hpp"
#include "levels.hpp"

namespace loglady {
namespace formatter {

class LevelWrapper : public FormatterWrapper {
private:
    /* Defines if the level formatter should add the level indicator, such as I, or the complete name, such as INFO */
    bool m_verbose;
    loglady::levels::LevelType m_level;
public:
    LevelWrapper(
        std::shared_ptr<Formatter> param_formatter,
        loglady::levels::LevelType param_level = loglady::levels::LevelType::INFO,
        bool param_verbose = false) : FormatterWrapper(param_formatter), m_level (param_level), m_verbose (param_verbose) {}

    /**
     * @brief Adds a INFO level to the message
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override;
};

} // namespace formatter
} // namespace loglady

#endif // _LEVEL_WRAPPER_