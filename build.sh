#!/bin/bash

xmake g --theme=ninja -q
xmake f -c -p gcc --toolchain=gcc
if ! xmake; then
    echo "构建失败！" >&2
    read -rp "按回车键继续..."
    clear
    exit 1
fi

clear
