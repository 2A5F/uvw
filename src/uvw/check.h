#ifndef UVW_CHECK_INCLUDE_H
#define UVW_CHECK_INCLUDE_H

#include <uv.h>
#include "handle.hpp"
#include "loop.h"

namespace uvw {

/*! @brief Check event. */
struct check_event {};

/**
 * @brief The check handle.
 *
 * Check handles will emit a check event once per loop iteration, right after
 * polling for I/O.
 *
 * To create a `check_handle` through a `loop`, no arguments are required.
 */
class check_handle final: public handle<check_handle, uv_check_t> {
    static void start_callback(uv_check_t *hndl);

public:
    using handle::handle;

    /**
     * @brief Initializes the handle.
     * @return Underlying code in case of errors, 0 otherwise.
     */
    int init() final;

    /**
     * @brief Starts the handle.
     *
     * A check event will be emitted once per loop iteration, right after
     * polling for I/O.
     */
    void start();

    /**
     * @brief Stops the handle.
     */
    void stop();
};

} // namespace uvw

#ifndef UVW_AS_LIB
#    include "check.cpp"
#endif

#endif // UVW_CHECK_INCLUDE_H
