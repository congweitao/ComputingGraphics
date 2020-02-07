for i in {1..3}
do
  ssh host$i mkdir -p /data/brick1/gv0
done
gluster volume create gv0 host1:/data/brick1/gv0 host2:/data/brick1/gv0 host3:/data/brick1/gv0
gluster volume info gv0
gluster volume start gv0

for i in {1..3}
do 
  ssh host$i 'mkdir -p /glusterfs'
  ssh host$i 'mount -t glusterfs host1:/gv0 /glusterfs'
done

mkdir /glusterfs/test/
