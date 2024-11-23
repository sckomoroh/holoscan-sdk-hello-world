#include "CustomBinApp.h"

#include <holoscan/logger/logger.hpp>

#include "fragments/custom/CustomFragment.h"
#include "fragments/output/OutputFragment.h"

namespace holo::app {

using fragments::cutom::CustomFragment;
using fragments::output::OutputFragment;

void
CustomBinApp::compose()
{
  using namespace holoscan;

  HOLOSCAN_LOG_INFO("Composing CustomBinApp...");

  auto customFragment = make_fragment<CustomFragment>("customFragment");
  auto outputFragment = make_fragment<OutputFragment>("outputFragment");

  add_flow(customFragment, outputFragment, { { "sum", "sink" } });
}

} // namespace holo::app
