import socket
import time
import struct

with open("fpga_test_packets.bin", "rb") as f:
    data = f.read()

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
fpga_ip = '192.168.1.50'     # ← 你 FPGA 的 IP
fpga_port = 12345            # ← 你 FPGA 的 UDP Port

packet_size = 13
for i in range(0, len(data), packet_size):
    packet = data[i:i+packet_size]
    sock.sendto(packet, (fpga_ip, fpga_port))
    time.sleep(0.05)  # 模擬每 50ms 一筆（可調整）