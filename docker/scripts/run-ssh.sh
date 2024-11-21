#!/bin/bash

echo "Start SSH daemon"

/sbin/sshd -D -E /ws/sshd.log -p 2220
