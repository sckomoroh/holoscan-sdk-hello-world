#include "OutputFragment.h"

#include "ops/ConsoleSinkOp.h"

namespace holo::fragments::output {

using ops::ConsoleSinkOp;

void OutputFragment::compose() {
    using namespace holoscan;

    HOLOSCAN_LOG_INFO("[OutputFragment::compose] Compose fragment");

    auto sink = make_operator<ConsoleSinkOp>("sink", make_condition<CountCondition>(2));

    add_operator(sink);
}

}  // namespace holo::fragments::output
