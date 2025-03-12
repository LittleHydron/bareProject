#!/bin/bash

startingDirectory=$(pwd)

cd /home/hydra/bareProject

st-flash --reset write build/bin/main.bin 0x08000000

cd $startingDirectory

