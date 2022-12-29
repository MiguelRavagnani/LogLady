#ifndef _FORMATTER_
#define _FORMATTER_

#include <string>
#include <memory>

#include "levels.hpp"

namespace loglady {
namespace formatter {

/**
 * @brief Implements the abstract component
 */
class Formatter {
public:
    template <levels::LevelType Level>
    static inline void Format(std::stringstream& param_message) {}

};

/**
 * @brief Implements the default component
 */
class DefaultFormatter: public Formatter{
public:
    template <levels::LevelType Level>
    static inline void Format(std::stringstream& param_message) {}

};

} // namespace formatter
} // namespace loglady

#endif // _FORMATTER_