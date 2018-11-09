/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <misc/printk.h>

#include <logging/log.h>

#include <device.h>
#include <sensor.h>

struct sensor_value press;

LOG_MODULE_REGISTER(main);

void main(void)
{
	LOG_INF("Hello World! %s\n", CONFIG_ARCH);
	LOG_WRN("Foo");

	struct device *dev = device_get_binding("BME280");
	if (dev == NULL)
	{
		LOG_ERR("Could not get BME280 device\n");
		return;
	}
	while (true)
	{
		if (sensor_sample_fetch(dev) < 0)
		{
			LOG_ERR("Sensor sample update error\n");
			return;
		}

		sensor_sample_fetch(dev);
		sensor_channel_get(dev, SENSOR_CHAN_PRESS, &press);

		LOG_INF("press: %d.%06d\n",
					press.val1, press.val2);

		k_sleep(1000);
	}
}
