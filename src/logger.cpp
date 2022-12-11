#include <iostream>

#include "levels.hpp"
#include "threading.hpp"
#include "config_formatter.hpp"

int main() {

    /* testing formatter */
    std::string format = "[dd/mm/yy] [hh:mm:ss] [I]";

    auto formatter = loglady::formatter::BuildFormatter(
        loglady::formatter::ConfigFormatter(format),
        loglady::levels::LevelType::ALL
    );

    std::string message = "My log has a message for you...";

    loglady::formatter::FormatterAdapter(formatter, message);

    std::cout << message << std::endl;

return 0;
}