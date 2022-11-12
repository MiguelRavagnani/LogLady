#ifndef _THREADING_
#define _THREADING_

#include <mutex>

namespace loglady::config
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
} // namespace loglady::config

#endif // _THREADING_