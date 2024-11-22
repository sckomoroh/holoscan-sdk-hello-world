cmake_minimum_required(VERSION 3.20)

project(holoscanApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(holoscan REQUIRED CONFIG
             PATHS "/opt/nvidia/holoscan" "/workspace/holoscan-sdk/install")

include_directories(
    src
    ${HOLOSCAN_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/app/CustomBinApp.cpp

    src/fragments/custom/CustomFragment.cpp
    src/fragments/custom/ops/RandomGeneratorOp.cpp
    src/fragments/custom/ops/SumOp.cpp
    
    src/fragments/output/OutputFragment.cpp
    src/fragments/output/ops/ConsoleSinkOp.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    holoscan::core)