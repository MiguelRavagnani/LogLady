#ifndef _CONSOLE_SINK_HPP_
#define _CONSOLE_SINK_HPP_

#include <string>
#include <iostream>

#include "sink.hpp"

namespace loglady {
namespace sink {

class ConsoleSink : public Sink {
public:
    ConsoleSink(const loglady::levels::LevelType& param_level) : Sink(param_level) {}

    /**
     * @brief Recieves a message and process it
     * 
     * @param param_message Message as a string
     * @param param_level Enum from a level
     */
    virtual void ProcessRegistry(std::string& param_message, const loglady::levels::LevelType& param_level) override {
        loglady::formatter::FormatterAdapter(m_formatter, param_message);
        if ((param_level & m_level) == m_level) {
            std::cout << param_message << std::endl;
        }
    }

    /**
     * @brief Set the level of a sink
     * 
     * @param param_level Enum from a level
     */
    virtual void SetLevel(const loglady::levels::LevelType& param_level) override {
        m_level = param_level;
    }

    /**
     * @brief Set the fromat of a sink registry
     * 
     * @param param_format Currently supported string formats addons:  \n 
     *                     [dd/mm/yy] - Adds a date to the registry    \n 
     *                     [hh:mm:ss] - Adds timestamp to the registry \n 
     *                     [level]    - Adds verbose level tag         \n 
     *                     [l]        - Adds non verbose level tag      
     */
    virtual void SetFormat(std::string param_format) override {
        m_formatter = loglady::formatter::BuildFormatter(
            loglady::formatter::ConfigFormatter(param_format),
            m_level
        );
    }

protected:
    loglady::levels::LevelType m_level;

    std::shared_ptr<loglady::formatter::Formatter> m_formatter;
};

} // sink
} // loglady

#endif // _CONSOLE_SINK_HPP_