#pragma once

#include <holoscan/holoscan.hpp>

namespace holo::fragments::cutom::ops {

class SumOp : public holoscan::Operator
{
public:
  HOLOSCAN_OPERATOR_FORWARD_ARGS(SumOp)

  SumOp() = default;

  void setup(holoscan::OperatorSpec& spec) override;

  void compute(holoscan::InputContext& in_output,
               holoscan::OutputContext& out_output,
               holoscan::ExecutionContext& context) override;

private:
  holoscan::Parameter<float> param1_;
};

} // namespace holo::fragments::cutom::ops
