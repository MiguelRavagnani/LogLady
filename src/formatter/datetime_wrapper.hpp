#ifndef _DATETIME_WRAPPER_
#define _DATETIME_WRAPPER_

#include <string>
#include <time.h>

#include "formatter_wrapper.hpp"

namespace loglady {
namespace formatter {

template <typename Format>
class DateWrapper: public virtual Wrapper<Format> {
public:
    /**
     * @brief Construct a new Wrapper object
     * 
     * @param m_formatter A formater to recieve the wrapper format
     */
    DateWrapper(Format m_formatter) : Wrapper<Format>(m_formatter) {}

    virtual ~DateWrapper(){}
    
    /**
     * @brief Formats a message with a date
     * 
     * @param param_message string message
     */
    virtual void Format(std::string& param_message, const levels::LevelType& param_level = levels::LevelType::INFO) {
        time_t now = time(NULL);
        struct tm tstruct;
        char date_buf[40];

        tstruct = *localtime(&now);

        strftime(date_buf, sizeof(date_buf), "%d/%m/%y", &tstruct);

        std::string date = date_buf;

        param_message.m_message = "["+date+"] " + param_message.m_message;
        this->m_formatter.Format(param_message, param_level);
    }
};

template <typename Format>
class TimeWrapper: public virtual Wrapper<Format> {
public:
    /**
     * @brief Construct a new Wrapper object
     * 
     * @param m_formatter A formater to recieve the wrapper format
     */
    TimeWrapper(Format m_formatter) : Wrapper<Format>(m_formatter) {}

    virtual ~TimeWrapper(){}

    /**
     * @brief Formats a message with a time
     * 
     * @param param_message string message
     */
    virtual void Format(std::string& param_message, const levels::LevelType& param_level = levels::LevelType::INFO) {
        time_t now = time(NULL);
        struct tm tstruct;
        char time_buf[40];

        tstruct = *localtime(&now);

        strftime(time_buf, sizeof(time_buf), "%X", &tstruct);

        std::string time = time_buf;

        param_message = "["+time+"] " + param_message;
        this->m_formatter.Format(param_message, param_level);
    }
};

} // namespace formatter
} // namespace loglady

#endif // _DATETIME_WRAPPER_