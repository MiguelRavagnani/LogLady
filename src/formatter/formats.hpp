#ifndef _FORMATS_
#define _FORMATS_

#include <stdint.h>
#include <type_traits>

namespace loglady {
namespace formatter {

/**
 * @brief Level configuration
 */
enum class Format : uint16_t {
    NONE            = 0x000, 
    DATE_dd_mm_yy   = 0x001,
    DATE_dd_mm_YY   = 0x002,
    TIME_hh_mm_ss   = 0x004,
    LEVEL_compact   = 0x008,
    LEVEL_verbose   = 0x0010
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
constexpr bool HasEnabled(
    Format param_input_format, 
    Format param_target_format) {
    return ((param_input_format & param_target_format) == param_target_format) ? true : false;
}

} // namespace formatter
} // namespace loglady

#endif // _FORMATS_