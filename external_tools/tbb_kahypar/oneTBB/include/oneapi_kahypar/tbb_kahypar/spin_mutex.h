/*
    Copyright (c) 2005-2021 Intel Corporation

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef __TBB_spin_mutex_H
#define __TBB_spin_mutex_H

#include "detail/_namespace_injection.h"
#include "detail/_mutex_common.h"

#include "profiling.h"

#include "detail/_assert.h"
#include "detail/_utils.h"
#include "detail/_scoped_lock.h"

#include <atomic>

namespace tbb_kahypar {
namespace detail {
namespace d1 {

#if __TBB_TSX_INTRINSICS_PRESENT
class rtm_mutex;
#endif

/** A spin_mutex is a low-level synchronization primitive.
    While locked, it causes the waiting threads to spin in a loop until the lock is released.
    It should be used only for locking short critical sections
    (typically less than 20 instructions) when fairness is not an issue.
    If zero-initialized, the mutex is considered unheld.
    @ingroup synchronization */
class spin_mutex {
public:
    //! Constructors
    spin_mutex() noexcept : m_flag(false) {
        create_itt_sync(this, "tbb_kahypar::spin_mutex", "");
    };

    //! Destructor
    ~spin_mutex() = default;

    //! No Copy
    spin_mutex(const spin_mutex&) = delete;
    spin_mutex& operator=(const spin_mutex&) = delete;

    using scoped_lock = unique_scoped_lock<spin_mutex>;

    //! Mutex traits
    static constexpr bool is_rw_mutex = false;
    static constexpr bool is_recursive_mutex = false;
    static constexpr bool is_fair_mutex = false;

    //! Acquire lock
    /** Spin if the lock is taken */
    void lock() {
        atomic_backoff backoff;
        call_itt_notify(prepare, this);
        while (m_flag.exchange(true)) backoff.pause();
        call_itt_notify(acquired, this);
    }

    //! Try acquiring lock (non-blocking)
    /** Return true if lock acquired; false otherwise. */
    bool try_lock() {
        bool result = !m_flag.exchange(true);
        if (result) {
            call_itt_notify(acquired, this);
        }
        return result;
    }

    //! Release lock
    void unlock() {
        call_itt_notify(releasing, this);
        m_flag.store(false, std::memory_order_release);
    }

protected:
    std::atomic<bool> m_flag;
}; // class spin_mutex

#if TBB_USE_PROFILING_TOOLS
inline void set_name(spin_mutex& obj, const char* name) {
    itt_set_sync_name(&obj, name);
}
#if (_WIN32||_WIN64)
inline void set_name(spin_mutex& obj, const wchar_t* name) {
    itt_set_sync_name(&obj, name);
}
#endif //WIN
#else
inline void set_name(spin_mutex&, const char*) {}
#if (_WIN32||_WIN64)
inline void set_name(spin_mutex&, const wchar_t*) {}
#endif // WIN
#endif
} // namespace d1
} // namespace detail

inline namespace v1 {
using detail::d1::spin_mutex;
} // namespace v1
namespace profiling {
    using detail::d1::set_name;
}
} // namespace tbb

#include "detail/_rtm_mutex.h"

namespace tbb_kahypar {
inline namespace v1 {
#if __TBB_TSX_INTRINSICS_PRESENT
    using speculative_spin_mutex = detail::d1::rtm_mutex;
#else
    using speculative_spin_mutex = detail::d1::spin_mutex;
#endif
}
}

#endif /* __TBB_spin_mutex_H */

