/******************************************************************************
* @file    Template_API.h
* @brief   API 
* @SPDX-License-Identifier: Apache-2.0
*******************************************************************************/

#ifndef template_H
#define template_H

//======================================================================
// ANCHOR - INCLUDES
//======================================================================

#include <zephyr/device.h>
#include <zephyr/devicetree.h>

//======================================================================
// ANCHOR - DEFINES
//======================================================================

//======================================================================
// ANCHOR - TYPEDEFS
//======================================================================

typedef enum 
{
    TEMPLATE_OK,
}template_t;

typedef void (*set_value_t)(const struct device *dev);

__subsystem struct template_api
{
    set_value_t set_value;
};

//======================================================================
// ANCHOR - API FUNCTION DECLARATIONS
//======================================================================

/**********************************************************
 * @brief 
 * @param[in] 
 * @retval 
 **********************************************************/
__syscall int template_set_value(const struct device *dev);
static inline void template_set_value(const struct device *dev)
{
	const struct template_api *api = (const struct template_api *)dev->api;
	return api->set_value(dev);
}

#endif // template_H
//======================================================================
//  EOF
//======================================================================
