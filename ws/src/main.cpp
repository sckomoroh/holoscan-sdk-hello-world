#include "app/CustomBinApp.h"

using holo::app::CustomBinApp;

int main(int argc, char **argv) {
  HOLOSCAN_LOG_INFO("[main] Starting CustomBinApp...");

  CustomBinApp app;
  app.run();

  HOLOSCAN_LOG_INFO("[main] CustomBinApp finished.");

  return 0;
}
