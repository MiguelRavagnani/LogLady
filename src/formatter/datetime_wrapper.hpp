#ifndef _DATETIME_WRAPPER_
#define _DATETIME_WRAPPER_

#include <string>
#include <time.h>

#include "formatter.hpp"

namespace loglady {
namespace formatter {

class DateWrapper_dd_mm_yy : public DefaultFormatter {
public:
    template <levels::LevelType Level>
    static inline void Format(std::string& param_message) {
        time_t now = time(NULL);
        struct tm tstruct;
        char date_buf[40];

        tstruct = *localtime(&now);

        strftime(date_buf, sizeof(date_buf), "%d/%m/%y", &tstruct);

        std::string date = date_buf;

        param_message = "["+date+"] " + param_message;
    }
};

class DateWrapper_dd_mm_YY : public DefaultFormatter {
public:
    template <levels::LevelType Level>
    static inline void Format(std::string& param_message) {
       time_t now = time(NULL);
        struct tm tstruct;
        char date_buf[40];

        tstruct = *localtime(&now);

        strftime(date_buf, sizeof(date_buf), "%d/%m/%Y", &tstruct);

        std::string date = date_buf;

        param_message = "["+date+"] " + param_message;
    }
};

class TimeWrapper_X : public DefaultFormatter {
public:
    template <levels::LevelType Level>
    static inline void Format(std::string& param_message) {
        time_t now = time(NULL);
        struct tm tstruct;
        char time_buf[40];

        tstruct = *localtime(&now);

        strftime(time_buf, sizeof(time_buf), "%X", &tstruct);

        std::string time = time_buf;

        param_message = "["+time+"] "  + param_message;
    }
};

} // namespace formatter
} // namespace loglady

#endif // _DATETIME_WRAPPER_