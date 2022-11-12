#ifndef _LEVELS_
#define _LEVELS_

#include <stdint.h>
#include <type_traits>

namespace loglady::level {
    /**
     * @brief Level configuration
     */
    enum class LevelType : uint32_t {
        INFO  = 0x01, // Core information
        WARN  = 0x03, // Runtime warning
        ERROR = 0x07, // Function/method error
        FATAL = 0x0F, // Runtime error
        TRACE = 0x1F, // High level debug
        DEBUG = 0x3F, // Low level debug
        ALL   = 0xFF, // Complete combined information
    };

    /**
     * @brief Overides the | operator
     * 
     * @param param_first Prefix
     * @param param_second Sufix
     * @return constexpr LevelType operation result
     */
    constexpr inline LevelType operator| (LevelType param_first, LevelType param_second) {
        return static_cast<LevelType>(
            static_cast<std::underlying_type<LevelType>::type>(param_first) |
            static_cast<std::underlying_type<LevelType>::type>(param_second)
            );
    }

    /**
     * @brief Overides the & operator
     * 
     * @param param_first Prefix
     * @param param_second Sufix
     * @return constexpr LevelType operation result
     */
    constexpr inline LevelType operator& (LevelType param_first, LevelType param_second) {
        return static_cast<LevelType>(
            static_cast<std::underlying_type<LevelType>::type>(param_first) &
            static_cast<std::underlying_type<LevelType>::type>(param_second)
            );
    }

    /**
     * @brief Overides the |= operator
     * 
     * @param param_first Prefix
     * @param param_second Sufix
     * @return constexpr LevelType operation result
     */
    constexpr inline LevelType& operator|= (LevelType& param_first, LevelType param_second) {
        return reinterpret_cast<LevelType&>(
            reinterpret_cast<std::underlying_type<LevelType>::type&>(param_first) |=
            static_cast<std::underlying_type<LevelType>::type>(param_second)
            );
    }

    /**
     * @brief Overides the &= operator
     * 
     * @param param_first Prefix
     * @param param_second Sufix
     * @return constexpr LevelType operation result
     */
    constexpr inline LevelType& operator&= (LevelType& param_first, LevelType param_second) {
        return reinterpret_cast<LevelType&>(
            reinterpret_cast<std::underlying_type<LevelType>::type&>(param_first) &=
            static_cast<std::underlying_type<LevelType>::type>(param_second)
            );
    }

    /**
     * @brief Compares a log level to a level type
     * 
     * @param param_input_level Level bytestring 
     * @param param_target_level Level type to be compared to
     * @return true If the bytestring has the target level enabled
     * @return false If the bytestring does not have the target level enabled
     */
    constexpr bool HasLevelEnabled(
        LevelType param_input_level, 
        LevelType param_target_level) {
        return ((param_input_level & param_target_level) == param_target_level) ? true : false;
    }
} // loglady::level

#endif // _LEVELS_