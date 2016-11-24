import struct

cdef extern from"CPacketBuilder.h":
    extern unsigned char default_tcp_template
    
    extern enum TemplateProtocol:
        Proto_TCP,
        Proto_UDP,
        Proto_SCTP,
        Proto_ICMP_ping,
        Proto_ICMP_timestamp,
        Proto_ARP,
        Proto_Script,
        Proto_Count

    struct TemplatePacket:
        unsigned length
        unsigned offset_ip
        unsigned offset_tcp
        unsigned offset_app
        unsigned char *packet
        unsigned checksum_ip
        unsigned checksum_tcp
        unsigned ip_id
        TemplateProtocol proto

    extern size_t tcp_create_packet(TemplatePacket *tmpl,unsigned ip_them, unsigned port_them,unsigned ip_me, unsigned port_me,unsigned seqno, unsigned ackno,unsigned flags,const unsigned char *payload, size_t payload_length,unsigned char *px, size_t px_length)

    extern void template_init(TemplatePacket *tmpl,const unsigned char *mac_source,const unsigned char *mac_dest,const void *packet_bytes,size_t packet_size)
 
cdef class PacketBuilder:
    cdef TemplatePacket tmpl
        
    def __init__(self,char *smac="\x00\x00\x00\x00\x00\x00", char *dmac="\x00\x00\x00\x00\x00\x00"):
            template_init(&self.tmpl,<const unsigned char *>smac,<const unsigned char *>dmac,&default_tcp_template,sizeof(default_tcp_template)-1)

    def GetTcpPacket(self,unsigned dip,unsigned dport,unsigned sip,unsigned sport,unsigned seq,unsigned ack,unsigned flags,const unsigned char *payload, size_t payload_length=0):
        cdef char px[2048]
        length = tcp_create_packet(&self.tmpl,dip, dport,sip, sport,seq, ack,flags,<const unsigned char *>payload, payload_length,<unsigned char *>px, sizeof(px))
        return px[:length]