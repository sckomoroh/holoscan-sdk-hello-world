#include "RandomGeneratorOp.h"

#include <random>

float generateRandomFloat(float min, float max) {
    // Create a random device and seed the generator
    std::random_device rd;
    std::mt19937 generator(rd());

    // Define a distribution in the given range
    std::uniform_real_distribution<float> distribution(min, max);

    // Generate and return a random float in the range
    return distribution(generator);
}

void RandomGeneratorOp::setup(holoscan::OperatorSpec& spec) {
    HOLOSCAN_LOG_INFO("[RandomGeneratorOp::setup] Setting up...");
    spec.output<float>("out");
    spec.param(_minRange, "minRange", "Parameter 1", "A parameter for the custom bin", 1.0f);
    spec.param(_maxRange, "maxRange", "Parameter 1", "A parameter for the custom bin", 1.0f);
}

void RandomGeneratorOp::compute(holoscan::InputContext& in_output,
                                holoscan::OutputContext& out_output,
                                holoscan::ExecutionContext& context) {
    HOLOSCAN_LOG_INFO("[RandomGeneratorOp::compute] Computing...");

    // Example processing (adding a fixed value to the input data)
    float processed_data = generateRandomFloat(_minRange.get(), _maxRange.get());
    HOLOSCAN_LOG_DEBUG("[RandomGeneratorOp::compute] Processed data: {}", processed_data);

    // Send the processed data to the next operator in the pipeline
    out_output.emit(processed_data);
    HOLOSCAN_LOG_INFO("[RandomGeneratorOp::compute] Emitting processed data: {}", processed_data);
}
