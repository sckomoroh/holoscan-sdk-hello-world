#pragma once

#include <holoscan/holoscan.hpp>

class RandomGeneratorOp : public holoscan::Operator {
private:
    holoscan::Parameter<float> _minRange;
    holoscan::Parameter<float> _maxRange;

public:
    HOLOSCAN_OPERATOR_FORWARD_ARGS(RandomGeneratorOp)

    RandomGeneratorOp() = default;

    void setup(holoscan::OperatorSpec& spec) override;

    void compute(holoscan::InputContext& in_output,
                 holoscan::OutputContext& out_output,
                 holoscan::ExecutionContext& context) override;
};