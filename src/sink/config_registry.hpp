#ifndef _CONFIG_REGISTRY_HPP_
#define _CONFIG_REGISTRY_HPP_

#include <vector>
#include <algorithm>

#include "registry.hpp"

namespace loglady {
namespace sink {

class ConfigRegistry : public Registry {
public:
    /**
     * @brief Subscribes a new sink to this registry. Once teh NotifySink method has been
     *        called, the sink registry will notify every registered sink
     * 
     * @param param_sink Sink
     */
    virtual void SubscribeSink(std::shared_ptr<Sink> param_sink) override {
        m_sinks.push_back(param_sink);
    }

    /**
     * @brief Unsubiscribe a sink from this registry
     * 
     * @param param_sink Sink
     */
    virtual void UnsubscribeSink(std::shared_ptr<Sink> param_sink) override {
        auto iterator = std::find(m_sinks.begin(), m_sinks.end(), param_sink);
    
        if (iterator != m_sinks.end()) {
            m_sinks.erase(iterator);
        }
    }

    /**
     * @brief Executes the every sink registered to this registry
     */
    virtual void NotifySink(const loglady::levels::LevelType& param_level) override {
        for (auto sink_iterator : m_sinks) {
            sink_iterator->ProcessRegistry(m_registry_buffer, param_level);
            m_registry_buffer.pop_back();
        }
    }

    /**
     * @brief Sink it!
     */
    virtual void SinkIt(std::string& param_message, const loglady::levels::LevelType& param_level) override {
        m_registry_buffer = param_message;
        this->NotifySink(param_level);
    }

private:
    
    std::vector<std::shared_ptr<Sink>> m_sinks;

    std::string m_registry_buffer;
};

} // sink
} // loglady

#endif // _CONFIG_REGISTRY_HPP_