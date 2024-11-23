#pragma once

#include <holoscan/holoscan.hpp>

namespace holo::fragments::output::ops {

class ConsoleSinkOp : public holoscan::Operator {
public:
    HOLOSCAN_OPERATOR_FORWARD_ARGS(ConsoleSinkOp)

    ConsoleSinkOp() = default;

    void setup(holoscan::OperatorSpec& spec) override;

    void compute(holoscan::InputContext& in_output,
                 holoscan::OutputContext& out_output,
                 holoscan::ExecutionContext& context) override;
};

}  // namespace holo::fragments::output::ops
