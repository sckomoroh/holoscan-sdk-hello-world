#pragma once

#include <holoscan/holoscan.hpp>

namespace holo::fragments::cutom {

class CustomFragment : public holoscan::Fragment
{
public:
  void compose() override;
};

} // namespace holo::fragments::sutom
