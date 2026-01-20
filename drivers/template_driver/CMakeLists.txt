# @file    CmakeLists.txt
# @brief   Cmake file for a Zephyr Driver

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_DT_HAS_TEMPLATE_DEVICE_ENABLED template_device/device.c)
