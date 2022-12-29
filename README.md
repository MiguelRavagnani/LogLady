# LogLady
Custom logging library created for code reusability purposes

## Current status

This project is small, and will grow at a slow pace for the moment. It currenlty only implements a string formatter

It already does tome things, but not much, and the road ahead Is really long.

## Usage example (too verborragic, will implement macros in the near future)

```cpp

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

```

## Next steps

 - [x] Formatter structure
 - [x] Sink structure
 - [x] Registry structure
 - [x] Improving basic structures
 - [x] Integration
 - [X] Refactor formatter + sink
 - [x] Moving a lot of the run time to compile time
 - [x] Subscrition based registry
 - [ ] Add doxygen comments to the refactored code
 - [ ] Integrate threading policy
 - [ ] Add color to sinks
 - [ ] Implement a basic file sink
 - [ ] Simplify the log configuration syntax
 - [ ] TBD

 ## Building

 ```bash

# On the repository root dir

mkdir build

cd build/

cmake ..

make

 ```