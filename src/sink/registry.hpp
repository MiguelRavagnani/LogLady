#ifndef _REGISTRY_HPP_
#define _REGISTRY_HPP_

#include <memory>

#include "sink.hpp"

namespace loglady {
namespace sink {

class Registry {
public:
    /**
     * @brief Subscribes a new sink to this registry. Once teh NotifySink method has been
     *        called, the sink registry will notify every registered sink
     * 
     * @param param_sink Sink
     */
    virtual void SubscribeSink(std::shared_ptr<Sink> param_sink) = 0;

    /**
     * @brief Unsubiscribe a sink from this registry
     * 
     * @param param_sink Sink
     */
    virtual void UnsubscribeSink(std::shared_ptr<Sink> param_sink) = 0;

    /**
     * @brief Executes the every sink registered to this registry
     */
    virtual void NotifySink(const loglady::levels::LevelType& param_level) = 0;

    /**
     * @brief Sink it!
     */
    virtual void SinkIt(std::string& param_message, const loglady::levels::LevelType& param_level) = 0;
};

} // sink
} // loglady

#endif // _REGISTRY_HPP_