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

#ifndef __TBB_global_control_H
#define __TBB_global_control_H

#include "detail/_config.h"

#include "detail/_assert.h"
#include "detail/_attach.h"
#include "detail/_exception.h"
#include "detail/_namespace_injection.h"
#include "detail/_template_helpers.h"

#include <cstddef>
#include <new> // std::nothrow_t

namespace tbb_kahypar {
namespace detail {

namespace d1 {
class global_control;
class task_scheduler_handle;
}

namespace r1 {
TBB_EXPORT void __TBB_EXPORTED_FUNC create(d1::global_control&);
TBB_EXPORT void __TBB_EXPORTED_FUNC destroy(d1::global_control&);
TBB_EXPORT std::size_t __TBB_EXPORTED_FUNC global_control_active_value(int);
struct global_control_impl;
struct control_storage_comparator;
void release_impl(d1::task_scheduler_handle& handle);
bool finalize_impl(d1::task_scheduler_handle& handle);
TBB_EXPORT void __TBB_EXPORTED_FUNC get(d1::task_scheduler_handle&);
TBB_EXPORT bool __TBB_EXPORTED_FUNC finalize(d1::task_scheduler_handle&, std::intptr_t mode);
}

namespace d1 {

class global_control {
public:
    enum parameter {
        max_allowed_parallelism,
        thread_stack_size,
        terminate_on_exception,
        scheduler_handle, // not a public parameter
        parameter_max // insert new parameters above this point
    };

    global_control(parameter p, std::size_t value) :
        my_value(value), my_reserved(), my_param(p) {
        suppress_unused_warning(my_reserved);
        __TBB_ASSERT(my_param < parameter_max, "Invalid parameter");
#if __TBB_WIN8UI_SUPPORT && (_WIN32_WINNT < 0x0A00)
        // For Windows 8 Store* apps it's impossible to set stack size
        if (p==thread_stack_size)
            return;
#elif __TBB_x86_64 && (_WIN32 || _WIN64)
        if (p==thread_stack_size)
            __TBB_ASSERT_RELEASE((unsigned)value == value, "Stack size is limited to unsigned int range");
#endif
        if (my_param==max_allowed_parallelism)
            __TBB_ASSERT_RELEASE(my_value>0, "max_allowed_parallelism cannot be 0.");
        r1::create(*this);
    }

    ~global_control() {
        __TBB_ASSERT(my_param < parameter_max, "Invalid parameter");
#if __TBB_WIN8UI_SUPPORT && (_WIN32_WINNT < 0x0A00)
        // For Windows 8 Store* apps it's impossible to set stack size
        if (my_param==thread_stack_size)
            return;
#endif
        r1::destroy(*this);
    }

    static std::size_t active_value(parameter p) {
        __TBB_ASSERT(p < parameter_max, "Invalid parameter");
        return r1::global_control_active_value((int)p);
    }

private:
    std::size_t my_value;
    std::intptr_t my_reserved; // TODO: substitution of global_control* not to break backward compatibility
    parameter my_param;

    friend struct r1::global_control_impl;
    friend struct r1::control_storage_comparator;
};

//! Finalization options.
//! Outside of the class to avoid extensive friendship.
static constexpr std::intptr_t release_nothrowing = 0;
static constexpr std::intptr_t finalize_nothrowing = 1;
static constexpr std::intptr_t finalize_throwing = 2;

//! User side wrapper for a task scheduler lifetime control object
class task_scheduler_handle {
public:
    //! Creates an empty task_scheduler_handle
    task_scheduler_handle() = default;

    //! Creates an attached instance of task_scheduler_handle
    task_scheduler_handle(attach) {
        r1::get(*this);
    }

    //! Release a reference if any
    ~task_scheduler_handle() {
        release();
    }

    //! No copy
    task_scheduler_handle(const task_scheduler_handle& other) = delete;
    task_scheduler_handle& operator=(const task_scheduler_handle& other) = delete;

    //! Move only
    task_scheduler_handle(task_scheduler_handle&& other) noexcept {
        std::swap(m_ctl, other.m_ctl);
    }
    task_scheduler_handle& operator=(task_scheduler_handle&& other) noexcept {
        std::swap(m_ctl, other.m_ctl);
        return *this;
    };

    //! Checks if the task_scheduler_handle is empty
    explicit operator bool() const noexcept {
        return m_ctl != nullptr;
    }

    //! Release the reference and deactivate handle
    void release() {
        if (m_ctl != nullptr) {
            r1::finalize(*this, release_nothrowing);
            m_ctl = nullptr;
        }
    }

private:
    friend void r1::release_impl(task_scheduler_handle& handle);
    friend bool r1::finalize_impl(task_scheduler_handle& handle);
    friend void __TBB_EXPORTED_FUNC r1::get(task_scheduler_handle&);

    friend void finalize(task_scheduler_handle&);
    friend bool finalize(task_scheduler_handle&, const std::nothrow_t&) noexcept;

    global_control* m_ctl{nullptr};
};

#if TBB_USE_EXCEPTIONS
//! Waits for worker threads termination. Throws exception on error.
inline void finalize(task_scheduler_handle& handle) {
    try_call([&] {
        if (handle.m_ctl != nullptr) {
            bool finalized = r1::finalize(handle, finalize_throwing);
            __TBB_ASSERT_EX(finalized, "r1::finalize did not respect finalize_throwing ?");
            
        }
    }).on_completion([&] {
        __TBB_ASSERT(!handle, "The handle should be empty after finalize");
    });
}
#endif
//! Waits for worker threads termination. Returns false on error.
inline bool finalize(task_scheduler_handle& handle, const std::nothrow_t&) noexcept {
    bool finalized = true;
    if (handle.m_ctl != nullptr) {
        finalized = r1::finalize(handle, finalize_nothrowing);
    }
    __TBB_ASSERT(!handle, "The handle should be empty after finalize");
    return finalized;
}

} // namespace d1
} // namespace detail

inline namespace v1 {
using detail::d1::global_control;
using detail::d1::attach;
using detail::d1::finalize;
using detail::d1::task_scheduler_handle;
using detail::r1::unsafe_wait;
} // namespace v1

} // namespace tbb

#endif // __TBB_global_control_H
