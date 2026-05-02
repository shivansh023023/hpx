# Standard CMake with HPX wrapping
add_executable(executor_scheduler_test executor_scheduler.cpp)

# Link against HPX, the init library, AND the wrap library
target_link_libraries(executor_scheduler_test 
    PRIVATE 
    hpx
    hpx_init
    hpx_wrap
)

# Linker instruction to redirect the entry point
target_link_options(executor_scheduler_test PRIVATE "-Wl,-wrap,main")

# Essential definitions
target_compile_definitions(executor_scheduler_test PRIVATE HPX_APPLICATION_NAME=executor_scheduler_test)
