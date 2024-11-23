#pragma once

#include <holoscan/holoscan.hpp>

namespace holo::app {

class CustomBinApp : public holoscan::Application
{
public:
  void compose() override;
};

} // namespace holo::app
