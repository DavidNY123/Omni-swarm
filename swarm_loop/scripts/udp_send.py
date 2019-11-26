#!/usr/bin/python

import socket

MCAST_GRP = '239.255.76.67'
MCAST_PORT = 7667

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 2)
sock.sendto("Hello World", (MCAST_GRP, MCAST_PORT))