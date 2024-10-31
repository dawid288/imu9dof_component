#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <stdlib.h>
#include <driver/i2c_master.h>
#include "ak09918.h"
#include "icm20600.h"
#include "imu_9dof.h"
#include "adc.h"
#include "ekf_imu13states.h"

void app_main(void)
{
    icm20600_dev_t icm_dev1;
    ak09918_dev_t ak_dev1;

    imu_9dof_i2c_init(&icm_dev1, &ak_dev1);
    icm20600_init(&icm_dev1);
    ak09918_init(&ak_dev1);

    while (1)
    {
        imu_9dof_read(&icm_dev1, &ak_dev1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
