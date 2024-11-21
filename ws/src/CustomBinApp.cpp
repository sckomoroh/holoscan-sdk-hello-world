#include "CustomBinApp.h"

#include <holoscan/logger/logger.hpp>

#include "RandomGeneratorOp.h"
#include "ConsoleSinkOp.h"
#include "CustomProcessingBin.h"

void CustomBinApp::compose() {
    using namespace holoscan;

    HOLOSCAN_LOG_INFO("Composing CustomBinApp...");

    // Define the source operator
    auto source = make_operator<RandomGeneratorOp>("source", Arg("minRange") = -5.0f, Arg("maxRange") = 5.0f);

    // Define the custom processing bin
    auto custom_bin = make_operator<CustomProcessingBin>("custom_processing_bin",
                                                         Arg("param1") = 5.0f);  // Example parameter

    // Define a Sink Operator to see the output
    auto sink = make_operator<ConsoleSinkOp>("sink");

    // Link the operators together
    add_flow(source, custom_bin);
    add_flow(custom_bin, sink);
}
