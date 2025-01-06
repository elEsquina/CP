import ping3
import ipaddress  # Import the ipaddress module

def icmp_ping(ip):
    ping = ping3.ping(ip)
    print(f"Pinging {ip}: {ping}")  # Debugging line
    return ping is not None and ping > 0  # Ensure only successful pings are counted

def scan_icmp(subnet):
    devices = []
    network = ipaddress.ip_network(subnet, strict=False)
    for ip in network.hosts():
        if icmp_ping(str(ip)):
            devices.append({'ip': str(ip), 'status': 'Up'})
    return devices

# Specify the IP range to scan
ip_range = '10.50.19.1/24'

# Perform the ICMP scan
devices = scan_icmp(ip_range)

# Display the results
for device in devices:
    print(f"IP: {device['ip']}, Status: {device['status']}")
