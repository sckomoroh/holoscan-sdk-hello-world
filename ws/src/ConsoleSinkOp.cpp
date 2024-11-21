#include "ConsoleSinkOp.h"

void ConsoleSinkOp::setup(holoscan::OperatorSpec& spec) {
    HOLOSCAN_LOG_INFO("[ConsoleSinkOp::compute] Setting up...");
    spec.input<float>("in");
}

void ConsoleSinkOp::compute(holoscan::InputContext& in_output,
                            holoscan::OutputContext& out_output,
                            holoscan::ExecutionContext& context) {
    HOLOSCAN_LOG_INFO("[ConsoleSinkOp::compute] Computing...");

    auto in_message = in_output.receive<float>("in").value();

    HOLOSCAN_LOG_DEBUG("[ConsoleSinkOp::compute] Received input: {}", in_message);
}
