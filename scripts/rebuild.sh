#!/bin/bash

startingDirectory=$(pwd)

cd /home/hydra/bareProject

rm -rf build

mkdir build
mkdir build/obj
mkdir build/bin

arm-none-eabi-as -o build/obj/startup.o service_files/startup.s && \
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -I includes -o build/obj/main.o src/main.c && \
arm-none-eabi-ld -T service_files/linker.ld build/obj/startup.o build/obj/main.o -o build/bin/main.elf && \
arm-none-eabi-objcopy -O binary build/bin/main.elf build/bin/main.bin

cd $startingDirectory

