#include <iostream>

#include "config_registry.hpp"
#include "console_sink.hpp"

int main() {

    loglady::sink::ConfigRegistry config_registry;

    auto console_sink = std::shared_ptr<loglady::sink::Sink>(new loglady::sink::ConsoleSink(loglady::levels::LevelType::WARN));

    console_sink->SetLevel(loglady::levels::LevelType::WARN);
    console_sink->SetFormat("[dd/mm/yy] [hh:mm:ss] [l] ");

    config_registry.SubscribeSink(console_sink);

    std::string message_1 = "My log has a message for you...";
    std::string message_2 = "Come on then. My log does not judge.";
    std::string message_3 = "He met the devil. The devil took the form of fire.";
    std::string message_4 = "This cherry pie is a miracle.";

    config_registry.SinkIt(message_1, loglady::levels::LevelType::WARN);
    config_registry.SinkIt(message_2, loglady::levels::LevelType::WARN);
    config_registry.SinkIt(message_3, loglady::levels::LevelType::WARN);
    config_registry.SinkIt(message_4, loglady::levels::LevelType::DEBUG);

return 0;
}