#!/usr/bin/bash

rpm -ivh http://ovirt.repo.nfrance.com/yum-repo/ovirt-release43.rpm

rpm -ivh https://cbs.centos.org/kojifiles/packages/rh-postgresql10/3.1/1.bs1.el7/aarch64/rh-postgresql10-runtime-3.1-1.bs1.el7.aarch64.rpm
rpm -ivh http://mirror.centos.org/altarch/7/sclo/aarch64/rh/rh-postgresql10/rh-postgresql10-postgresql-libs-10.6-1.el7.aarch64.rpm
rpm -ivh http://mirror.centos.org/altarch/7/sclo/aarch64/rh/rh-postgresql10/rh-postgresql10-postgresql-10.6-1.el7.aarch64.rpm
rpm -ivh http://mirror.centos.org/altarch/7/sclo/aarch64/rh/rh-postgresql10/rh-postgresql10-postgresql-contrib-10.6-1.el7.aarch64.rpm
rpm -ivh http://mirror.centos.org/altarch/7/sclo/aarch64/rh/rh-postgresql10/rh-postgresql10-postgresql-server-10.6-1.el7.aarch64.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/openstack-java-keystone-model-3.2.7-1.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/ebay-cors-filter-1.0.1-3.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/json-smart-2.2-5.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/openstack-java-resteasy-connector-3.2.7-1.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/openstack-java-cinder-model-3.2.7-1.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/openstack-java-quantum-client-3.2.7-1.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/openstack-java-glance-client-3.2.7-1.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/openstack-java-cinder-client-3.2.7-1.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/openstack-java-keystone-client-3.2.7-1.el7.noarch.rpm
rpm -ivh http://mirror.centos.org/altarch/7/virt/aarch64/ovirt-4.3/openstack-java-glance-model-3.2.7-1.el7.noarch.rpm

# step 0 create repo
cat > /etc/yum.repos.d/ovirt.repo <<EOF
[ovirt]
name=ovirt
baseurl=http://mirror.centos.org/altarch/7.7.1908/virt/aarch64/kvm-common/
enabled=1
gpgcheck=0

[kvm-common]
name=kvm-common
baseurl=http://mirror.centos.org/altarch/7.7.1908/virt/aarch64/ovirt-4.3/
enabled=1
gpgcheck=0

[pgsql10]
name=postgresql
baseurl=http://mirror.centos.org/altarch/7/sclo/aarch64/rh/rh-postgresql10/
enabled=0
gpgcheck=0
EOF

# compiling postgresql10 with rpm, 
wget https://download.postgresql.org/pub/source/v10.6/postgresql-10.6.tar.bz2
# using rh-postgresql10
scl enable rh-postgresql10 bash
postgresql-setup --initdb
service rh-postgresql10-postgresql start

# for vdsm
pip install subprocess32
pip install enum
pip install python-dateutil

./autogen.sh --system
make rpm


# for ovirt-engine
# step 1 install third-party packages, postgresql>=10
yum -y install git java-devel maven openssl postgresql-server postgresql-contrib \
     m2crypto python-psycopg2 python-cheetah python-daemon libxml2-python \
     unzip pyflakes python-pep8 python-docker-py mailcap python-jinja2 \
     python-dateutil gdeploy 
# step 2 install application servers
# - WildFly
wget https://resources.ovirt.org/pub/ovirt-4.3/src/ovirt-engine-wildfly/wildfly-17.0.1.Final.zip -C /root/rpmbuild/SOURCE
git clone https://github.com/oVirt/ovirt-engine-wildfly.git
rpmbuild -bb ovirt-engine-wildfly.spec
rpmbuild -bb ovirt-engine-wildfly-overlay.spec
# - JBoss

# create database
su - postgres -c "source /opt/rh/rh-postgresql10/enable;psql -d template1 -c \"create user engine password 'engine';\""
su - postgres -c "source /opt/rh/rh-postgresql10/enable;psql -d template1 -c \"create database engine owner engine template template0 encoding 'UTF8' lc_collate 'en_US.UTF-8' lc_ctype 'en_US.UTF-8';\""
su - postgres -c "source /opt/rh/rh-postgresql10/enable;psql -d engine -c \"CREATE EXTENSION \\\"uuid-ossp\\\";\""

