#coding=utf-8
import PacketBuilder,time,socket,struct,dnet,dpkt
#a=PacketBuilder.PacketBuilder("\x5c\xf9\x38\xa6\x66\xfe","\x00\x00\x0c\x07\xac\x90")
a=PacketBuilder.PacketBuilder("\x5c\xf9\x38\xa6\x66\xfe","\x8c\xab\x8e\x6e\x56\xd8")

# a.A()
# t1=time.time()
# for i in range(1,10000000):
#     a.B()
# t2=time.time()
# print t2-t1
dip=struct.unpack(">I",socket.inet_aton("222.200.98.110"))[0]
dport=80
sip=struct.unpack(">I",socket.inet_aton("192.168.1.110"))[0]
sport=22222
seq=1
ack=0
flags=0x02
payload=''
payload_length=0
packet=a.GetTcpPacket(dip,dport,sip,sport,seq,ack,flags,payload,payload_length)
print len(packet)
print packet.encode('hex')

e=dnet.eth("en0")
e.send(packet)

t1=time.time()
for i in range(1,10000000):
    packet=a.GetTcpPacket(dip,dport,sip,sport,seq,ack,flags,payload,payload_length)
    e.send(packet)
    dip+=1
t2=time.time()
print t2-t1


# t1=dpkt.tcp.TCP(sport=sport,dport=dport,flags=0x02,seq=1,ack=0,win=1200)
# i1=dpkt.ip.IP(src=struct.pack('>I',sip),p=dpkt.ip.IP_PROTO_TCP,ttl=255,dst=struct.pack('>I',dip))
# e1=dpkt.ethernet.Ethernet(dst="\x8c\xab\x8e\x6e\x56\xd8",src="\x5c\xf9\x38\xa6\x66\xfe")
# i1.len=i1.__len__()
# i1.data=t1
# e1.data=i1
# p=e1.pack()
#e.send(p)