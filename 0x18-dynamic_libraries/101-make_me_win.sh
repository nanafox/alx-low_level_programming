#!/bin/bash
wget -P /tmp https://github.com/nanafox/alx-low_level_programming/raw/main/0x18-dynamic_libraries/libinject.so
export LD_PRELOAD=/tmp/libinject.so
