- 工程搭建：https://blog.csdn.net/whhcsdn233/article/details/132092077
- 代码裁剪：https://zhuanlan.zhihu.com/p/397742240
- 修改晶振：https://blog.csdn.net/Mark_md/article/details/100096505
- ucos移植：https://blog.csdn.net/qq_41671020/article/details/125137170

# 目录
- README.md
- Hardware
    - delay.c
    - delay.h
    - gy86.c
    - gy86.h
    - i2c.c
    - i2c.h
    - led.c
    - led.h
    - oled.c
    - oled.h
    - oled_font.h  
    - tim.c
    - tim.h
    - usart.c
    - usart.h
- Lib
    - inc
        - misc.h
        - stm32f4xx_adc.h
        - stm32f4xx_can.h
        - stm32f4xx_cec.h
        - stm32f4xx_crc.h
        - stm32f4xx_cryp.h
        - stm32f4xx_dac.h
        - stm32f4xx_dbgmcu.h
        - stm32f4xx_dcmi.h
        - stm32f4xx_dfsdm.h
        - stm32f4xx_dma.h
        - stm32f4xx_dma2d.h
        - stm32f4xx_dsi.h
        - stm32f4xx_exti.h
        - stm32f4xx_flash.h
        - stm32f4xx_flash_ramfunc.h
        - stm32f4xx_fmc.h
        - stm32f4xx_fmpi2c.h
        - stm32f4xx_fsmc.h
        - stm32f4xx_gpio.h
        - stm32f4xx_hash.h
        - stm32f4xx_i2c.h
        - stm32f4xx_iwdg.h
        - stm32f4xx_lptim.h
        - stm32f4xx_ltdc.h
        - stm32f4xx_pwr.h
        - stm32f4xx_qspi.h
        - stm32f4xx_rcc.h
        - stm32f4xx_rng.h
        - stm32f4xx_rtc.h
        - stm32f4xx_sai.h
        - stm32f4xx_sdio.h
        - stm32f4xx_spdifrx.h
        - stm32f4xx_spi.h
        - stm32f4xx_syscfg.h
        - stm32f4xx_tim.h
        - stm32f4xx_usart.h
        - stm32f4xx_wwdg.h
    - src
        - misc.c
        - stm32f4xx_adc.c
        - stm32f4xx_can.c
        - stm32f4xx_cec.c
        - stm32f4xx_crc.c
        - stm32f4xx_cryp.c
        - stm32f4xx_cryp_aes.c
        - stm32f4xx_cryp_des.c
        - stm32f4xx_cryp_tdes.c
        - stm32f4xx_dac.c
        - stm32f4xx_dbgmcu.c
        - stm32f4xx_dcmi.c
        - stm32f4xx_dfsdm.c
        - stm32f4xx_dma.c
        - stm32f4xx_dma2d.c
        - stm32f4xx_dsi.c
        - stm32f4xx_exti.c
        - stm32f4xx_flash.c
        - stm32f4xx_flash_ramfunc.c
        - stm32f4xx_fmc.c
        - stm32f4xx_fmpi2c.c
        - stm32f4xx_fsmc.c
        - stm32f4xx_gpio.c
        - stm32f4xx_hash.c
        - stm32f4xx_hash_md5.c
        - stm32f4xx_hash_sha1.c
        - stm32f4xx_i2c.c
        - stm32f4xx_iwdg.c
        - stm32f4xx_lptim.c
        - stm32f4xx_ltdc.c
        - stm32f4xx_pwr.c
        - stm32f4xx_qspi.c
        - stm32f4xx_rcc.c
        - stm32f4xx_rng.c
        - stm32f4xx_rtc.c
        - stm32f4xx_sai.c
        - stm32f4xx_sdio.c
        - stm32f4xx_spdifrx.c
        - stm32f4xx_spi.c
        - stm32f4xx_syscfg.c
        - stm32f4xx_tim.c
        - stm32f4xx_usart.c
        - stm32f4xx_wwdg.c
- Project
    - AF0Fly.uvoptx
    - AF0Fly.uvprojx
    - DebugConfig
    - Listings
    - Objects
    - RTE
- Startup
    - startup_stm32f401xx.s
- Ucosii
    - Cfg
        - Template
            - app_cfg.h
            - app_hooks.c
            - os_cfg.h
    - LICENSE
    - NOTICE  
    - Ports
        - os_cpu.h
        - os_cpu_a.asm
        - os_cpu_c.c
    - README.rst
    - Source
        - os.h
        - os_core.c
        - os_dbg_r.c
        - os_flag.c
        - os_mbox.c
        - os_mem.c
        - os_mutex.c
        - os_q.c
        - os_sem.c
        - os_task.c
        - os_time.c
        - os_tmr.c
        - os_trace.h
        - ucos_ii.h
    - Trace
        - os_trace_events.c
        - os_trace_events.h
        - readme.txt
- User
    - main.c
    - stm32f4xx.h
    - stm32f4xx_conf.h
    - stm32f4xx_it.c
    - stm32f4xx_it.h
    - system_stm32f4xx.c
    - system_stm32f4xx.h
    - tasks.c
    - tasks.h

# F4系列宏定义对照表
- STM32F40_41xxx
>STM32F405RG, STM32F405VG, STM32F405ZG, STM32F415RG, STM32F415VG, STM32F415ZG, STM32F407VG, STM32F407VE, STM32F407ZG, STM32F407ZE, STM32F407IG, STM32F407IE, STM32F417VG, STM32F417VE, STM32F417ZG, STM32F417ZE, STM32F417IG, STM32F417IE
- STM32F427_437xx
>STM32F427VG, STM32F427VI, STM32F427ZG, STM32F427ZI, STM32F427IG, STM32F427II, STM32F437VG, STM32F437VI, STM32F437ZG, STM32F437ZI, STM32F437IG, STM32F437II
- STM32F429_439xx
>STM32F429VG, STM32F429VI, STM32F429ZG, STM32F429ZI, STM32F429BG, STM32F429BI, STM32F429NG, STM32F439NI, STM32F429IG, STM32F429II, STM32F439VG, STM32F439VI, STM32F439ZG, STM32F439ZI, STM32F439BG, STM32F439BI, STM32F439NG, STM32F439NI, STM32F439IG, STM32F439II
- STM32F401xx
>STM32F401CB, STM32F401CC,  STM32F401RB, STM32F401RC, STM32F401VB, STM32F401VC, STM32F401CD, STM32F401RD, STM32F401VD, STM32F401CExx, STM32F401RE, STM32F401VE
- STM32F410xx
>STM32F410Tx, STM32F410Cx, STM32F410Rx
- STM32F411xE
>STM32F411CC, STM32F411RC, STM32F411VC, STM32F411CE, STM32F411RE,
STM32F411VE
- STM32F412xG
>STM32F412CEU, STM32F412CGU, STM32F412ZET, STM32F412ZGT, STM32F412ZEJ, STM32F412ZGJ, STM32F412VET, STM32F412VGT, STM32F412VEH, STM32F412VGH, STM32F412RET, STM32F412RGT, STM32F412REY, STM32F412RGY
- STM32F413_423xx
>STM32F413CGU, STM32F413CHU, STM32F413MGY, STM32F413MHY, STM32F413RGT, STM32F413VGT, STM32F413ZGT, STM32F413RHT, STM32F413VHT, STM32F413ZHT, STM32F413VGH, STM32F413ZGJ, STM32F413VHH, STM32F413ZHJ, STM32F423CHU, STM32F423RHT, STM32F423VHT, STM32F423ZHT, STM32F423VHH, STM32F423ZHJ
- STM32F446xx
>STM32F446MC, STM32F446ME, STM32F446RC, STM32F446RE, STM32F446VC, STM32F446VE, STM32F446ZC, STM32F446ZE
- STM32F469_479xx
>STM32F479AI, STM32F479II, STM32F479BI, STM32F479NI, STM32F479AG, STM32F479IG, STM32F479BG, STM32F479NG, STM32F479AE, STM32F479IE, STM32F479BE, STM32F479NE