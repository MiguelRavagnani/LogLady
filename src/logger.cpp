#include <iostream>

#include "levels.hpp"
#include "threading.hpp"
#include "config_formatter.hpp"

int main() {

    /* testing formatter */
    std::string format = "[dd/mm/yy] [hh:mm:ss] [l]";

    auto formatter = loglady::formatter::BuildFormatter(
        loglady::formatter::ConfigFormatter(format),
        loglady::levels::LevelType::TRACE
    );

    std::string message_1 = "My log has a message for you...";
    std::string message_2 = "Come on then. My log does not judge.";
    std::string message_3 = "He met the devil. The devil took the form of fire.";
    std::string message_4 = "This cherry pie is a miracle.";

    loglady::formatter::FormatterAdapter(formatter, message_1);
    loglady::formatter::FormatterAdapter(formatter, message_2);
    loglady::formatter::FormatterAdapter(formatter, message_3);
    loglady::formatter::FormatterAdapter(formatter, message_4);

    std::cout << message_1 << std::endl;
    std::cout << message_2 << std::endl;
    std::cout << message_3 << std::endl;
    std::cout << message_4 << std::endl;

return 0;
}