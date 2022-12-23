#ifndef _FORMATTER_WRAPPER_
#define _FORMATTER_WRAPPER_

#include <string>

#include "formatter.hpp"

namespace loglady {
namespace formatter {

/**
 * @brief A format decorator
 * 
 * @tparam Format A format to be decorated
 */
template <typename Format>
class Wrapper: public virtual Formatter{
protected:
    Format m_formatter;
public:
    /**
     * @brief Construct a new Wrapper object
     * 
     * @param m_formatter A formater to recieve the wrapper format
     */
    Wrapper(Format m_formatter): Formatter(), m_formatter(m_formatter){;}

    virtual ~Wrapper(){}

    /**
     * @brief Set the Level object
     * 
     * @param param_level_config Level of an object
     */
    virtual void SetLevelConfig(){
        m_formatter.SetLevelConfig(param_level_config);
    }
};

template <typename Format>
class DefaultWrapper: public virtual Wrapper<Format> {
public:
    /**
     * @brief Construct a new Wrapper object
     * 
     * @param m_formatter A formater to recieve the wrapper format
     */
    DefaultWrapper(Format m_formatter) : Wrapper<Format>(m_formatter) {}

    virtual ~DateWrapper(){}
    
    virtual void Format(std::string& param_message, const levels::LevelType& param_level = levels::LevelType::INFO) {e;
        this->m_formatter.Format(param_message, param_level);
    }
};

template <typename S>
using result = typename std::result_of<S>::type;

template <template <typename> class E, template <typename> class... D>
struct wrapper_implementation
{
    template <typename A, typename N = result<wrapper_implementation<D...>(A)>>
	E<N> operator()(A&& a) const {
		return E<N>(wrapper_implementation<D...>()(std::forward<A>(a)));
	}
};

template <template <typename> class E>
struct wrapper_implementation <E> {
	template <typename A, typename N = typename std::decay<A>::type>
	E<N> operator()(A&& a) const { return E<N>(std::forward<A>(a)); }
};

template <template <typename> class E, template <typename> class... D, typename A>
std::shared_ptr <E<result<wrapper_implementation<D...>(A)>>>
 wrap(A& a) {
	return std::make_shared <E<result<wrapper_implementation<D...>(A)>>>
		(wrapper_implementation<D...>()(std::forward<A>(a)));
}

template <template <typename> class E, typename A>
std::shared_ptr <result<wrapper_implementation<E>(A)>>
 wrap(A& a)
{
	return std::make_shared <result<wrapper_implementation<E>(A)>>
		(wrapper_implementation<E>()(std::forward<A>(a)));
}

} // namespace formatter
} // namespace loglady

#endif // _FORMATTER_WRAPPER_