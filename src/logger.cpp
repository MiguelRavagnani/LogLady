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

    subscription.NotifySink<levels::LevelType::DEBUG>("My log has a message for you...", levels::LevelType::DEBUG);
    subscription.NotifySink<levels::LevelType::INFO>("Come on then. My log does not judge.", levels::LevelType::DEBUG);
    subscription.NotifySink<levels::LevelType::INFO>("He met the devil. The devil took the form of fire.", levels::LevelType::DEBUG);
    subscription.NotifySink<levels::LevelType::DEBUG>("This cherry pie is a miracle.", levels::LevelType::DEBUG);

    return 0;
}
