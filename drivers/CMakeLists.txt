# @file    CMakeLists.txt
# @brief   CMake entry file for Drivers

add_subdirectory_ifdef(CONFIG_TEMPLATE_DRIVER template_driver)
