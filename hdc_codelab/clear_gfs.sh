#!/usr/bin/bash


for node in host{1..3}; do
    echo "edit on $node..."
    ssh $node umount /glusterfs
done

gluster volume tier gv0 detach force
gluster volume stop gv0
gluster volume delete gv0

for node in host{1..3}; do
    echo "operating on $node..."
    ssh $node setfattr -x trusted.glusterfs.volume-id /data/brick1/gv0
    ssh $node setfattr -x trusted.glusterfs.gfid /data/brick1/gv0
    ssh $node setfattr -x trusted.glusterfs.volume-id /data/tier1/gv0
    ssh $node setfattr -x trusted.glusterfs.gfid /data/tier1/gv0
    ssh $node rm -rf /data/brick1/* 
    ssh $node rm -rf /data/tier1/*
    ssh $node cpupower frequency-set -g powersave
    ssh $node tuned-adm profile balanced
done

echo "done."
