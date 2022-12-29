#include <iostream>

#include "registry.hpp"
#include "console_sink.hpp"
#include "level_wrapper.hpp"
#include "datetime_wrapper.hpp"

using namespace loglady;

int main() {
    auto console_sink_1 = sink::ConsoleSinkBuilder{}
        .AddConfig<formatter::LevelWrapperCompact>()
        .AddConfig<formatter::TimeWrapper_X>()
        .Dispatch();

    auto console_sink_2 = sink::ConsoleSinkBuilder{}
        .AddConfig<formatter::LevelWrapperVerbose>()
        .AddConfig<formatter::TimeWrapper_X>()
        .AddConfig<formatter::DateWrapper_dd_mm_YY>()
        .Dispatch();
    
    sink::RegistrySubscription<decltype(console_sink_1), decltype(console_sink_2)> subscription;

    std::string message_1 = "My log has a message for you...";
    std::string message_2 = "Come on then. My log does not judge.";
    std::string message_3 = "He met the devil. The devil took the form of fire.";
    std::string message_4 = "This cherry pie is a miracle.";

    subscription.NotifySink<levels::LevelType::DEBUG>(message_1, levels::LevelType::DEBUG);
    subscription.NotifySink<levels::LevelType::DEBUG>(message_2, levels::LevelType::DEBUG);
    subscription.NotifySink<levels::LevelType::DEBUG>(message_3, levels::LevelType::DEBUG);
    subscription.NotifySink<levels::LevelType::DEBUG>(message_4, levels::LevelType::DEBUG);

    return 0;
}