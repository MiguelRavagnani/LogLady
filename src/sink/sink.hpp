#ifndef _SINK_HPP_
#define _SINK_HPP_

#include <string>

#include "levels.hpp"
#include "threading.hpp"
#include "config_formatter.hpp"

namespace loglady {
namespace sink {

class Sink {
public:
    Sink(const loglady::levels::LevelType& param_level = loglady::levels::LevelType::INFO) : m_level (param_level) {}

    /**
     * @brief Recieves a message and process it
     * 
     * @param param_message Message as a string
     * @param param_level Enum from a level
     */
    virtual void ProcessRegistry(std::string& param_message, const loglady::levels::LevelType& param_level) = 0;

    /**
     * @brief Set the level of a sink
     * 
     * @param param_level Enum from a level
     */
    virtual void SetLevel(const loglady::levels::LevelType& param_level) = 0;

    /**
     * @brief Set the fromat of a sink registry
     * 
     * @param param_format Currently supported string formats addons:  \n 
     *                     [dd/mm/yy] - Adds a date to the registry    \n 
     *                     [hh:mm:ss] - Adds timestamp to the registry \n 
     *                     [level]    - Adds verbose level tag         \n 
     *                     [l]        - Adds non verbose level tag      
     */
    virtual void SetFormat(std::string param_format) = 0;

protected:
    loglady::levels::LevelType m_level;

    std::shared_ptr<loglady::formatter::Formatter> m_formatter;
};

} // sink
} // loglady

#endif // _SINK_HPP_