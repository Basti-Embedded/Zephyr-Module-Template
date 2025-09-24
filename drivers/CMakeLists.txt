# ******************************************************************************
# @file    CMakeLists.txt
# @brief   CMake File for Zephyr Driver
# @SPDX-License-Identifier: Apache-2.0
# ******************************************************************************

# add source file when CONFIG_TEMPLATE is defined
add_subdirectory_ifdef(CONFIG_API template)
