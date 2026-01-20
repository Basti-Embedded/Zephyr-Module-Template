/*
 * @file    template_device.c
 * @brief   source file for the tcth021be temp monitor driver
 * @version 1.0
 * */

#define DT_DRV_COMPAT manufacturer_device

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>

#include <sys/errno.h>

#include "template_api.h"

#if DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) == 0
#warning "temp driver enabled without any devices"
#endif

/* DEFINES */

/* DATA TYPES */

struct device_config_t {
};

struct device_data_t {
    const struct device *device_ptr;
};

/* VARIABLES */

/* FUNCTION DECLERATIONS */

static int _get_value(const struct device *dev);

/* FUNCTIONS */

/*
 * @brief get the state of the INT pin
 * @param[in] dev pointer to the device structure
 * @retval return pin state,
 * */
static int _get_value(const struct device *dev)
{
    return 0;
}

/* API FUNCTIONS */

/*
 * @brief init function for the device gets called before the application code
 * @param[in] dev pointer to the device structure
 * @retval return 0 if the device was successfully init
 *         otherwise a negative error code
 * */
int DEVICE_init(const struct device *dev)
{
    const struct device_config_t *config = dev->config;
    struct device_data_t *data = dev->data;
    data->device_ptr = dev; /* add device ptr for better access later on */

    LOG_INF("DEVICE initialising....");

    return 0;
}

/*
 * @brief get the state of the temp monitor
 * @param[in] dev pointer to the device structure of the temp monitor instance
 * @retval 0 on success or a negative error code
 * */
int DEVICE_get_value(const struct device *dev)
{
    struct device_data_t *dev_data = dev->data;
    return 0;
}

/* API DECLERATION */

static const struct driver_api device_api = {
    .get_value = DEVICE_get_value,
};

/* DEVICE TREE DRIVER DEFINITION */

#define TEMPLATE_DEVICE_DEFINE(inst)                               \
    static struct device_data_t template_data_##inst;              \
    static const struct device_config_t template_config_##inst = { \
    };                                                             \
    DEVICE_DT_INST_DEFINE(                                         \
        inst,                                                      \
        DEVICE_init,                                               \
        NULL,                                                      \
        &device_data_##inst,                                       \
        &device_config_##inst,                                     \
        POST_KERNEL,                                               \
        CONFIG_TEMPLATE_DRIVER_INIT_PRIORITY,                      \
        &device_api);

DT_INST_FOREACH_STATUS_OKAY(MANUFACTURER_DEVICE_DEFINE)
/* EOF */
