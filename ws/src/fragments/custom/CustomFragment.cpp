#include "CustomFragment.h"

#include "ops/RandomGeneratorOp.h"
#include "ops/SumOp.h"

namespace holo::fragments::cutom {

using ops::RandomGeneratorOp;
using ops::SumOp;

void
CustomFragment::compose()
{
  using namespace holoscan;

  HOLOSCAN_LOG_INFO("[CustomFragment::compose] Compose fragment");

  config("config.yaml");

  auto rndMinRange = from_config("random_generator.minRange").as<float>();
  auto rndMaxRange = from_config("random_generator.maxRange").as<float>();
  auto count = from_config("random_generator.count").as<int>();
  auto param1 = from_config("custom_processing_bin.param1").as<float>();

  HOLOSCAN_LOG_INFO("[CustomFragment::compose] Min range = {} Max range = {} "
                    "Value = {} Counbt = {}",
                    rndMinRange,
                    rndMaxRange,
                    param1,
                    count);

  auto randomGenerator =
    make_operator<RandomGeneratorOp>("random",
                                     make_condition<CountCondition>(count),
                                     Arg("minRange") = rndMinRange,
                                     Arg("maxRange") = rndMaxRange);
  auto sum = make_operator<SumOp>("sum", Arg("param1") = param1);

  add_flow(randomGenerator, sum);
}

} // namespace holo::fragments::cutom
