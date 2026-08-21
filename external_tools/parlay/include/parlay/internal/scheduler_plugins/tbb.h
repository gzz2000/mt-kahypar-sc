#ifndef PARLAY_INTERNAL_SCHEDULER_PLUGINS_TBB_H_
#define PARLAY_INTERNAL_SCHEDULER_PLUGINS_TBB_H_

#include <cstddef>

#include <type_traits>

#include <tbb_kahypar/blocked_range.h>
#include <tbb_kahypar/parallel_for.h>
#include <tbb_kahypar/parallel_invoke.h>
#include <tbb_kahypar/task_arena.h>

namespace parlay {

// IWYU pragma: private, include "../../parallel.h"

inline size_t num_workers() { return tbb_kahypar::this_task_arena::max_concurrency(); }

inline size_t worker_id() {
  auto id = tbb_kahypar::this_task_arena::current_thread_index();
  return id == tbb_kahypar::task_arena::not_initialized ? 0 : id;
}

template <typename F>
inline void parallel_for(size_t start, size_t end, F&& f, long granularity, bool) {
  static_assert(std::is_invocable_v<F&, size_t>);
  // Use TBB's automatic granularity partitioner (tbb_kahypar::auto_partitioner)
  if (granularity == 0) {
    tbb_kahypar::parallel_for(tbb_kahypar::blocked_range<size_t>(start, end), [&](const tbb_kahypar::blocked_range<size_t>& r) {
      for (auto i = r.begin(); i != r.end(); ++i) {
        f(i);
      }
    }, tbb_kahypar::auto_partitioner{});
  }
  // Otherwise, use the granularity specified by the user (tbb_kahypar::simple_partitioner)
  else {
    tbb_kahypar::parallel_for(tbb_kahypar::blocked_range<size_t>(start, end, granularity), [&](const tbb_kahypar::blocked_range<size_t>& r) {
      for (auto i = r.begin(); i != r.end(); ++i) {
        f(i);
      }
    }, tbb_kahypar::simple_partitioner{});
  }
}

template <typename Lf, typename Rf>
inline void par_do(Lf&& left, Rf&& right, bool) {
  static_assert(std::is_invocable_v<Lf&&>);
  static_assert(std::is_invocable_v<Rf&&>);
  tbb_kahypar::parallel_invoke(std::forward<Lf>(left), std::forward<Rf>(right));
}

template <typename... Fs>
void execute_with_scheduler(Fs...) {
  struct Illegal {};
  static_assert((std::is_same_v<Illegal, Fs> && ...), "parlay::execute_with_scheduler is only available in the Parlay scheduler and is not compatible with TBB");
}

}  // namespace parlay

#endif  // PARLAY_INTERNAL_SCHEDULER_PLUGINS_TBB_H_

