#include "CustomProcessingBin.h"

#include <holoscan/logger/logger.hpp>

void CustomProcessingBin::setup(holoscan::OperatorSpec& spec) {
    HOLOSCAN_LOG_INFO("[CustomProcessingBin::compute] Setting up...");
    spec.input<float>("in");
    spec.output<float>("out");
    spec.param(param1_, "param1", "Parameter 1", "A parameter for the custom bin", 1.0f);
}

void CustomProcessingBin::compute(holoscan::InputContext& in_output,
                                  holoscan::OutputContext& out_output,
                                  holoscan::ExecutionContext& context) {
    HOLOSCAN_LOG_INFO("[CustomProcessingBin::compute] Computing...");

    // Retrieve the input message
    auto in_message = in_output.receive<float>("in").value();
    HOLOSCAN_LOG_DEBUG("[CustomProcessingBin::compute] Received input: {}", in_message);

    // Example processing (adding a fixed value to the input data)
    float processed_data = in_message + param1_.get();
    HOLOSCAN_LOG_DEBUG("[CustomProcessingBin::compute] Processed data: {}", processed_data);

    // Send the processed data to the next operator in the pipeline
    out_output.emit(processed_data);
    HOLOSCAN_LOG_INFO("[CustomProcessingBin::compute] Emitting processed data: {}", processed_data);
}
