# ******************************************************************************
# @file     CMakeLists.txt
# @brief    CMakeLists.txt file for s Zephyr Module, this is the starting point
#           to load the rest of the CMakeLists.txt files of the module
# SPDX-License-Identifier: Apache-2.0
# ******************************************************************************

# add API Header to build
zephyr_include_directories(include)

# add driver source files to build
add_subdirectory(drivers)
