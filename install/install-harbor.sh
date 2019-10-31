#!/bin/bash


find ./ -type f |grep "Dockerfile$" |grep -v '\.D' |xargs sed -i "s#photon:2.0#arm64v8/photon:3.0-20191025#g"
make package_offline VERSIONTAG=dev-1.9.1 PKGVERSIONTAG=dev-1.9.1 UIVERSIONTAG=dev-1.9.1 COMPILETAG=compile_golangimage
