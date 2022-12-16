# LogLady
Custom logging library created for code reusability purposes

## Current status

This project is small, and will grow at a slow pace for the moment. It currenlty only implements a string formatter

It already does tome things, but not much, and the road ahead Is really long.

## Usage example (too verborragic, will implement macros in the near future)

```cpp

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

```

## Next steps

 - [x] Formatter structure
 - [x] Sink structure
 - [x] Registry structure
 - [x] Improving basic structures
 - [x] Integration
 - [ ] Integrate threading policy
 - [ ] Add color to sinks
 - [ ] Implement a basic file sink
 - [ ] Refactor formatter + sink
 - [ ] TBD

 ## Building

 ```bash

# On the repository root dir

mkdir build

cd build/

cmake ..

make

 ```