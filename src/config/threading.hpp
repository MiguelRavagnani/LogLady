#ifndef _THREADING_
#define _THREADING_

#include <mutex>

#if CXX_VERSION == 17
#define MUTEX_LOCK std::scoped_lock
#else
#define MUTEX_LOCK std::lock_guard
#endif

namespace loglady
{
namespace config
{
    /**
     * @brief Provides a null mutex configuration for single threading
     */
	struct null_mutex 
	{
		void lock() {}
		void unlock() {}
        bool try_lock() const
        {
            return true;
        }
	};

    template<typename Mutex>
	struct threading
	{
		using mutex_t = Mutex;

		using lock = MUTEX_LOCK<Mutex>;
	};
} // namespace config
} // namespace loglady

#endif // _THREADING_