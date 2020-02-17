#!/bin/bash

start tftp
start xinetd
start dhcpd
start nfs
export /centos
export /var/lib/tftpboot
