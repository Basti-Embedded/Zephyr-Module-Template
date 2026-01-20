/*
 * @file    template_api.h
 * @brief   API jeader file
 * @version 1.0
 * */

#ifndef TEMPLATE_API_H
#define TEMPLATE_API_H

/* INCLUDE */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>

#include <stdint.h>

/* DEFINES */

/* DATA TYPES */

/* FUNCTION DECLARATIONS */

typedef int (*get_data_t)(const struct device *dev);

/* API STRUCTURE */

__subsystem struct template_api {
    get_data_t get_data;
};

/* FUNCTIONS */

/*
 * @brief api function
 * @param[in] dev pointer to the device structure
 * @retval returns 0 on success, negative error code on failure
 * */
__syscall int TEMPLATE_get_data(const struct device *dev);
static inline int TEMPLATE_get_data(const struct device *dev)
{
    const struct template_api *api = (const struct template_api *)dev->api;
    return api->get_data(dev);
}

#endif // TEMPLATE_API_H
/* EOF */
