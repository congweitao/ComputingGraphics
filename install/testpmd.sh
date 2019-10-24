#!/usr/bin/bash

./build/app/testpmd -c ffffff -n 3 -- -i --rxd=1024 --txd=1024 --burst=144 --txpt=32 --txht=0 --txfreet=0 --rxfreet=64 --mbcache=200 --portmask=0x3 --mbuf-size=2048 --max-pkt-len=9600
