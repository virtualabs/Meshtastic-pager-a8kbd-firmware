################################################################################
# MRS Version: 2.2.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/config.c \
../src/hal.c \
../src/main.c 

C_DEPS += \
./src/config.d \
./src/hal.d \
./src/main.d 

OBJS += \
./src/config.o \
./src/hal.o \
./src/main.o 


EXPANDS += \
./src/config.c.234r.expand \
./src/hal.c.234r.expand \
./src/main.c.234r.expand 



# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -g -DDEBUG=1 -I"/home/virtualabs/mounriver-studio-projects/CH582M/StdPeriphDriver/inc" -I"/home/virtualabs/mounriver-studio-projects/CH582M/RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

