#ifndef _SINK_HPP_
#define _SINK_HPP_

#include <string>

#include "levels.hpp"
#include "threading.hpp"

namespace loglady {
namespace sink {

template <typename... Formats>
class Sink {
public:
    template <typename SinkLevel>
    void ProcessRegistry(std::string& param_message, const loglady::levels::LevelType& param_level) {}
};

} // sink
} // loglady

#endif // _SINK_HPP_