#!/usr/bin/bash

# step 1
yum install vdsm vdsm-jsonrpc vdsm-python vdsm-python-zombiereaper vdsm-xmlrpc vdsm-yajsonrpc vdsm-hook-macspoof

# step 2
changed /etc/vdsm/vdsm.conf ssl = false

# step 3
vdsm-tool configure --force

# step 4
service vdsmd start
service supervdsm start

# vish username/password
vish list --all
> vdsm@ovirt    # /usr/lib/python2.7/site-packages/vdsm/common/libvirtconnection.py
> shibboleth    # /etc/pki/vdsm/keys/libvirt_password
