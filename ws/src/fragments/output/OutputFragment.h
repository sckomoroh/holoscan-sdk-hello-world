#pragma once

#include <holoscan/holoscan.hpp>

namespace holo::fragments::output {

class OutputFragment : public holoscan::Fragment {
public:
    void compose() override;
};

}  // namespace holo::fragments::output
