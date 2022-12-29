#ifndef _CONSOLE_SINK_HPP_
#define _CONSOLE_SINK_HPP_

#include <string>
#include <iostream>

#include "sink.hpp"

namespace loglady {
namespace sink {

template <typename... Formats>
class ConsoleSink : public Sink<Formats... > {
public:
    template <levels::LevelType SinkLevel>
    inline void ProcessRegistry(std::string& param_message, const loglady::levels::LevelType& param_level) {

        ((Formats::template Format<SinkLevel>(param_message)), ...);

        if ((param_level & SinkLevel) == SinkLevel) {
            std::clog << param_message << std::endl;
        } else {
            return;
        }
    }
};

template <typename... Formats>
struct ConsoleSinkBuilder {
    template <typename Format>
    inline auto AddConfig() {
        return ConsoleSinkBuilder<Formats..., Format>{};
    }
    inline auto Dispatch() {
        return ConsoleSink<Formats...>{};
    }
};

} // sink
} // loglady

#endif // _CONSOLE_SINK_HPP_