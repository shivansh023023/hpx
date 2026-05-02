#include <hpx/config.hpp>
#if defined(HPX_HAVE_P2300)
#include <hpx/hpx_main.hpp>
#include <hpx/modules/execution.hpp>
#include <hpx/modules/executors.hpp>
#include <hpx/modules/testing.hpp>
#include <atomic>

int main() {
    namespace ex = hpx::execution::experimental;
    namespace tt = hpx::this_thread::experimental;
    hpx::execution::sequenced_executor exec;
    auto sched = ex::get_scheduler(exec);
    std::atomic<bool> called{false};
    auto s = ex::schedule(sched) | ex::then([&] {
        called = true;
        return 42;
    });
    auto result = tt::sync_wait(s);
    HPX_TEST(called);
    HPX_TEST_EQ(hpx::get<0>(*result), 42);
    return hpx::util::report_errors();
}
#endif
