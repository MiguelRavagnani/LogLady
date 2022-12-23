#ifndef _FORMATTER_
#define _FORMATTER_

#include <string>
#include <memory>

#include "levels.hpp"

namespace loglady {
namespace formatter {

/**
 * @brief Abstract component, holds the level type, and a setter
 */
struct AbstractFormatter
{
	AbstractFormatter(...) {}

	std::shared_ptr<levels::LevelConfig> m_level_config;

	void SetLevelConfig(std::shared_ptr<levels::LevelConfig> param_level_config) { m_level_config = param_level_config; }
};

/**
 * @brief Implements the abstract component
 */
class Formatter: public virtual AbstractFormatter{
public:

    /**
     * @brief Construct a new Formatter object
     */
    Formatter() : AbstractFormatter(){;}

    /**
     * @brief Formats a message
     * 
     * @param param_message string message
     */
    virtual void Format(std::string& param_message, const levels::LevelType& param_level = levels::LevelType::INFO) = 0;

};

/**
 * @brief Implements the default component
 */
class DefaultFormatter: public virtual Formatter{
public:

    /**
     * @brief Construct a new Formatter object
     */
    DefaultFormatter() : Formatter(){;}

    /**
     * @brief Formats a message
     * 
     * @param param_message string message
     */
    virtual void Format(std::string& param_message, const levels::LevelType& param_level = levels::LevelType::INFO);

};

} // namespace formatter
} // namespace loglady

#endif // _FORMATTER_