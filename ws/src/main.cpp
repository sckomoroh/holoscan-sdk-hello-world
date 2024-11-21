#include "CustomBinApp.h"
#include "CustomProcessingBin.h"

// Run the application
int main(int argc, char** argv) {
    // holoscan::Logger::initialize(argc, argv);
    HOLOSCAN_LOG_INFO("Starting CustomBinApp...");
    CustomBinApp app;
    app.run();
    HOLOSCAN_LOG_INFO("CustomBinApp finished.");
    return 0;
}
