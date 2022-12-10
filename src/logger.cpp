#include <iostream>

#include "levels.hpp"
#include "threading.hpp"
#include "datetime_wrapper.hpp"

int main() {
#if CXX_VERSION == 17
    std::cout << "17" <<std::endl;
#endif

    /* testing formatter */

    // auto default_formatter = std::make_shared<loglady::formatter::DefaultFormatter>;
    // auto datetime_formatter = std::make_shared<loglady::formatter::DatetimeWrapper>;

    auto default_formatter = std::shared_ptr<loglady::formatter::Formatter>(new loglady::formatter::DefaultFormatter);
    auto datetime_formatter = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::DatetimeWrapper(default_formatter));
    auto datetime_formatter_2 = std::shared_ptr<loglady::formatter::FormatterWrapper>(new loglady::formatter::DatetimeWrapper(datetime_formatter));

    std::string message = "My log has a message for you...";
    std::string message_2 = "My log has a message for you...";

    loglady::formatter::FormatterAdapter(default_formatter, message);

    std::cout << message << std::endl;

    loglady::formatter::FormatterAdapter(datetime_formatter, message);
    
    std::cout << message << std::endl;

    loglady::formatter::FormatterAdapter(datetime_formatter_2, message_2);
    
    std::cout << message_2 << std::endl;

return 0;
}