#pragma once

#include <holoscan/holoscan.hpp>

class CustomProcessingBin : public holoscan::Operator {
public:
    HOLOSCAN_OPERATOR_FORWARD_ARGS(CustomProcessingBin)

    CustomProcessingBin() = default;

    void setup(holoscan::OperatorSpec& spec) override;

    void compute(holoscan::InputContext& in_output,
                 holoscan::OutputContext& out_output,
                 holoscan::ExecutionContext& context) override;

private:
    holoscan::Parameter<float> param1_;
};
