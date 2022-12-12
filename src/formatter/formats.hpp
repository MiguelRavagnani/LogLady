#ifndef _FORMATS_
#define _FORMATS_

#include <stdint.h>
#include <type_traits>

namespace loglady {
namespace formatter {

/**
 * @brief Level configuration
 */
enum class Format : uint32_t {
    NONE  = 0x00, 
    DATE  = 0x01, 
    TIME  = 0x02, 
    LEVEL = 0x04,
    VERBOSE = 0x08,
    ALL   = 0xFF 
};

/**
 * @brief Overides the | operator
 * 
 * @param param_first Prefix
 * @param param_second Sufix
 * @return constexpr Format operation result
 */
constexpr inline Format operator| (Format param_first, Format param_second) {
    return static_cast<Format>(
        static_cast<std::underlying_type<Format>::type>(param_first) |
        static_cast<std::underlying_type<Format>::type>(param_second)
        );
}

/**
 * @brief Overides the & operator
 * 
 * @param param_first Prefix
 * @param param_second Sufix
 * @return constexpr Format operation result
 */
constexpr inline Format operator& (Format param_first, Format param_second) {
    return static_cast<Format>(
        static_cast<std::underlying_type<Format>::type>(param_first) &
        static_cast<std::underlying_type<Format>::type>(param_second)
        );
}

/**
 * @brief Overides the + operator
 * 
 * @param param_first Prefix
 * @param param_second Sufix
 * @return constexpr Format operation result
 */
constexpr inline Format operator+ (Format param_first, Format param_second) {
    return static_cast<Format>(
        static_cast<std::underlying_type<Format>::type>(param_first) +
        static_cast<std::underlying_type<Format>::type>(param_second)
        );
}

/**
 * @brief Overides the += operator
 * 
 * @param param_first Prefix
 * @param param_second Sufix
 * @return constexpr Format operation result
 */
constexpr inline Format& operator+= (Format& param_first, Format param_second) {
    return reinterpret_cast<Format&>(
        reinterpret_cast<std::underlying_type<Format>::type&>(param_first) +=
        static_cast<std::underlying_type<Format>::type>(param_second)
        );
}

/**
 * @brief Overides the |= operator
 * 
 * @param param_first Prefix
 * @param param_second Sufix
 * @return constexpr Format operation result
 */
constexpr inline Format& operator|= (Format& param_first, Format param_second) {
    return reinterpret_cast<Format&>(
        reinterpret_cast<std::underlying_type<Format>::type&>(param_first) |=
        static_cast<std::underlying_type<Format>::type>(param_second)
        );
}

/**
 * @brief Overides the &= operator
 * 
 * @param param_first Prefix
 * @param param_second Sufix
 * @return constexpr Format operation result
 */
constexpr inline Format& operator&= (Format& param_first, Format param_second) {
    return reinterpret_cast<Format&>(
        reinterpret_cast<std::underlying_type<Format>::type&>(param_first) &=
        static_cast<std::underlying_type<Format>::type>(param_second)
        );
}

/**
 * @brief Compares a log format to a format type
 * 
 * @param param_input_format Level bytestring 
 * @param param_target_format Level type to be compared to
 * @return true If the bytestring has the target format enabled
 * @return false If the bytestring does not have the target format enabled
 */
constexpr bool HasLevelEnabled(
    Format param_input_format, 
    Format param_target_format) {
    return ((param_input_format & param_target_format) == param_target_format) ? true : false;
}

} // namespace formatter
} // namespace loglady

#endif // _FORMATS_