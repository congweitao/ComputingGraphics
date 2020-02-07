for i in {1..3}
do
  ssh host$i 'cpupower frequency-set --governor performance'
  ssh host$i 'tuned-adm profile throughput-performance'
  ssh host$i 'echo "always" > /sys/kernel/mm/transparent_hugepage/enabled'
done

gluster volume set gv0 client.event-threads 4
gluster volume set gv0 server.event-threads 2
gluster volume set gv0 group metadata-cache
gluster volume set gv0 nfs.mem-factor 150
gluster volume set gv0 cluster.read-hash-mode 2
gluster volume set gv0 performance.read-ahead-page-count 16
gluster volume set gv0 network.tcp-window-size 1048576
gluster volume set gv0 performance.client-io-threads on
gluster volume set gv0 server.outstanding-rpc-limit 128
gluster volume set gv0 performance.nfs.quick-read on
gluster volume set gv0 performance.nfs.io-threads on
gluster volume set gv0 features.cache-invalidation on
gluster volume set gv0 features.cache-invalidation-timeout 600
gluster volume set gv0 performance.stat-prefetch on
gluster volume set gv0 performance.cache-invalidation on

