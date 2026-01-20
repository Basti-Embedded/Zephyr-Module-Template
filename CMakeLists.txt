# @file    CmakeLists.txt
# @brief   CMake entry for Zephyr Build

# add API Header to build
zephyr_include_directories(include)

# add driver source files to build
add_subdirectory(drivers)
