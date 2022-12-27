#include <iostream>

#include "console_sink.hpp"
#include "level_wrapper.hpp"
#include "datetime_wrapper.hpp"

int main() {

    auto console_sink = loglady::sink::ConsoleSinkBuilder{}
        .AddConfig<loglady::formatter::LevelWrapperCompact>()
        .AddConfig<loglady::formatter::TimeWrapper_X>()
        .AddConfig<loglady::formatter::DateWrapper_dd_mm_YY>()
        .Dispatch();

    std::string message_1 = "My log has a message for you...";
    std::string message_2 = "Come on then. My log does not judge.";
    std::string message_3 = "He met the devil. The devil took the form of fire.";
    std::string message_4 = "This cherry pie is a miracle.";

    console_sink.ProcessRegistry<loglady::levels::LevelType::DEBUG>(message_1, loglady::levels::LevelType::DEBUG);
    console_sink.ProcessRegistry<loglady::levels::LevelType::DEBUG>(message_2, loglady::levels::LevelType::DEBUG);
    console_sink.ProcessRegistry<loglady::levels::LevelType::DEBUG>(message_3, loglady::levels::LevelType::DEBUG);
    console_sink.ProcessRegistry<loglady::levels::LevelType::DEBUG>(message_4, loglady::levels::LevelType::DEBUG);

return 0;
}