#ifndef _CONFIG_REGISTRY_HPP_
#define _CONFIG_REGISTRY_HPP_

#include <vector>
#include <algorithm>
#include <memory>

#include "sink.hpp"

namespace loglady {
namespace sink {

namespace registry
{
    template <int... Is>
    struct Index { };

    template <int N, int... Is>
    struct GenerateSequency : GenerateSequency<N - 1, N - 1, Is...> { };

    template <int... Is>
    struct GenerateSequency<0, Is...> : Index<Is...> { };
}

template <typename...Args>
struct RegistrySubscription
{
    std::tuple<Args...> m_sinks;

    template <levels::LevelType SinkLevel, int... Is>
    void NotifySink(const char* param_message, const levels::LevelType& param_level, registry::Index<Is...>)
    {
        std::string message = param_message;
        auto l = { (std::get<Is>(m_sinks).template ProcessRegistry<SinkLevel>(message, param_level), 0) ... };
    }

    template <levels::LevelType SinkLevel>
    void NotifySink(const char* param_message, const levels::LevelType& param_level)
    {
        NotifySink<SinkLevel>(param_message, param_level, registry::GenerateSequency<sizeof...(Args)>());
    }
};

} // sink
} // loglady

#endif // _CONFIG_REGISTRY_HPP_