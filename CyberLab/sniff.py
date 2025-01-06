from scapy.all import *

server_ip = '10.50.31.7'

def intercept_packet(packet):
    if IP in packet and packet[IP].src == server_ip:
        print(packet)

sniff(prn=intercept_packet, store=0, filter="ip")
