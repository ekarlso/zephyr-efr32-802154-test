cmake -GNinja  -DBOARD=efr32mg_sltb004a -DCONF_FILE="prj.conf efr32mg-tb2.conf debug.conf" ../

# Debugging
ninja debug


JLinkGDBServer -device EFR32MG12PxxxF1024 -speed 1000

## Start debugger
```
arm-none-eabi-gdb zephyr/zephyr.elf
```

```
load 
b main
i b
mon reset 
c
```
# Evry Hackathon

## BT Notes
* GW Needs recent kernel and bluez
* BT5 same as BT Mesh

## Notes on EFR32 init process

CHIP_Init
hal_efr.c -> halInitChipSpecific
    - bsp_init.c -> BSP_initDevice
        - em_chip.h -> CHIP_Init
        - bsp_init.c -> BSP_initDcdc
        - bsp_init.c -> SP_initClocks
        - bsp_init.c BSP_initEmu
    - bsp_init.c BSP_initBoard (board stuff)
        - CMU_ClockEnable gpio
        - bsp_stk.c -> BSP_Init
        - ...
    - init clocks lfrco default lfxo if not
    - FEM enable
    - low power init (disable spi flash)


efr32RadioInit

# Notes on logging
https://github.com/zephyrproject-rtos/zephyr/blob/master/drivers/i2c/Kconfig#L38
https://github.com/zephyrproject-rtos/zephyr/blob/master/subsys/logging/Kconfig.template.log_config

https://github.com/zephyrproject-rtos/zephyr/pull/9042 - soc etc
https://github.com/zephyrproject-rtos/zephyr/pull/9945 - flash

https://github.com/zephyrproject-rtos/zephyr/pull/11212 - Enable DCDC
https://github.com/zephyrproject-rtos/zephyr/pull/11211 - Debugger

https://www.silabs.com/documents/public/data-sheets/efr32mg12-datasheet.pdf

# Notes on EFR RAIL
https://www.silabs.com/documents/public/application-notes/an1113-porting-rail-applications-to-rail-version2.pdf
https://github.com/openthread/openthread/blob/master/examples/platforms/efr32/radio.c
https://docs.silabs.com/rail/latest/api-index
https://docs.silabs.com/rail/latest/group-general
https://www.silabs.com/community/wireless/proprietary/forum.topic.html/rail_init_alwaysret-mijl
https://www.silabs.com/community/mcu/32-bit/knowledge-base.entry.html/2016/10/07/hfrco_frequency_and-1oL5

# Notes on power
Disable spi flash ? hal_efr.c -> static void boardDisableSpiFlash(void)

