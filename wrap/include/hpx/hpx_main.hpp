//  Copyright (c) 2020 ETH Zurich
//  Copyright (c) 2025 Hartmut Kaiser
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>

#include <hpx/wrap_main.hpp>

// Emit a compile-time diagnostic on Linux when dynamic main() wrapping is
// enabled but the -Wl,-wrap=main linker flag has not been configured.
// Users who link with HPX::wrap_main or HPX::hpx get the flag automatically;
// this catches direct linkage without the CMake wrapper targets.
#if defined(__linux__) && defined(HPX_HAVE_DYNAMIC_HPX_MAIN) &&                \
    !defined(HPX_HAVE_WRAP_MAIN_CONFIGURED)
#if defined(__GNUC__) || defined(__clang__)
#pragma message(                                                               \
    "HPX: main() wrapping is enabled but -Wl,-wrap=main was not detected. "    \
    "Link via HPX::wrap_main or add -Wl,-wrap=main manually.")
#endif
#endif

#if defined(HPX_HAVE_RUN_MAIN_EVERYWHERE)

namespace hpx_startup {

    void install_user_main_config();

    struct register_user_main_config
    {
        register_user_main_config()
        {
            install_user_main_config();
        }
    };

    inline register_user_main_config cfg;
}    // namespace hpx_startup

#endif
