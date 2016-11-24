
static unsigned char default_tcp_template[] =
        "\0\1\2\3\4\5"  /* Ethernet: destination */
                "\6\7\x8\x9\xa\xb"  /* Ethernet: source */
                "\x08\x00"      /* Ethernet type: IPv4 */
                "\x45"          /* IP type */
                "\x00"
                "\x00\x28"      /* total length = 40 bytes */
                "\x00\x00"      /* identification */
                "\x00\x00"      /* fragmentation flags */
                "\xFF\x06"      /* TTL=255, proto=TCP */
                "\xFF\xFF"      /* checksum */
                "\0\0\0\0"      /* source address */
                "\0\0\0\0"      /* destination address */

                "\0\0"          /* source port */
                "\0\0"          /* destination port */
                "\0\0\0\0"      /* sequence number */
                "\0\0\0\0"      /* ack number */
                "\x50"          /* header length */
                "\x02"          /* SYN */
                "\x04\x0"        /* window fixed to 1024 */
                "\xFF\xFF"      /* checksum */
                "\x00\x00"      /* urgent pointer */
                "\x02\x04\x05\xb4"  /* added options [mss 1460] */
;

static unsigned char default_udp_template[] =
        "\0\1\2\3\4\5"  /* Ethernet: destination */
                "\6\7\x8\x9\xa\xb"  /* Ethernet: source */
                "\x08\x00"      /* Ethernet type: IPv4 */
                "\x45"          /* IP type */
                "\x00"
                "\x00\x1c"      /* total length = 28 bytes */
                "\x00\x00"      /* identification */
                "\x00\x00"      /* fragmentation flags */
                "\xFF\x11"      /* TTL=255, proto=UDP */
                "\xFF\xFF"      /* checksum */
                "\0\0\0\0"      /* source address */
                "\0\0\0\0"      /* destination address */

                "\xfe\xdc"      /* source port */
                "\x00\x00"      /* destination port */
                "\x00\x08"      /* length */
                "\x00\x00"      /* checksum */
;

static unsigned char default_sctp_template[] =
        "\0\1\2\3\4\5"  /* Ethernet: destination */
                "\6\7\x8\x9\xa\xb"  /* Ethernet: source */
                "\x08\x00"      /* Ethernet type: IPv4 */
                "\x45"          /* IP type */
                "\x00"
                "\x00\x34"      /* total length = 52 bytes */
                "\x00\x00"      /* identification */
                "\x00\x00"      /* fragmentation flags */
                "\xFF\x84"      /* TTL=255, proto = SCTP */
                "\x00\x00"      /* checksum */
                "\0\0\0\0"      /* source address */
                "\0\0\0\0"      /* destination address */

                "\x00\x00"          /* source port */
                "\x00\x00"          /* destination port */
                "\x00\x00\x00\x00"  /* verification tag */
                "\x58\xe4\x5d\x36"  /* checksum */
                "\x01"              /* type = init */
                "\x00"              /* flags = none */
                "\x00\x14"          /* length = 20 */
                "\x9e\x8d\x52\x25"  /* initiate tag */
                "\x00\x00\x80\x00"  /* receiver window credit */
                "\x00\x0a"          /* outbound streams = 10 */
                "\x08\x00"          /* inbound streams = 2048 */
                "\x46\x1a\xdf\x3d"  /* initial TSN */
;


static unsigned char default_icmp_ping_template[] =
        "\0\1\2\3\4\5"  /* Ethernet: destination */
                "\6\7\x8\x9\xa\xb"  /* Ethernet: source */
                "\x08\x00"      /* Ethernet type: IPv4 */
                "\x45"          /* IP type */
                "\x00"
                "\x00\x4c"      /* total length = 76 bytes */
                "\x00\x00"      /* identification */
                "\x00\x00"      /* fragmentation flags */
                "\xFF\x01"      /* TTL=255, proto=ICMP */
                "\xFF\xFF"      /* checksum */
                "\0\0\0\0"      /* source address */
                "\0\0\0\0"      /* destination address */

                "\x08\x00"      /* Ping Request */
                "\x00\x00"      /* checksum */

                "\x00\x00\x00\x00" /* ID, seqno */

                "\x08\x09\x0a\x0b" /* payload */
                "\x0c\x0d\x0e\x0f"
                "\x10\x11\x12\x13"
                "\x14\x15\x16\x17"
                "\x18\x19\x1a\x1b"
                "\x1c\x1d\x1e\x1f"
                "\x20\x21\x22\x23"
                "\x24\x25\x26\x27"
                "\x28\x29\x2a\x2b"
                "\x2c\x2d\x2e\x2f"
                "\x30\x31\x32\x33"
                "\x34\x35\x36\x37"
;

static unsigned char default_icmp_timestamp_template[] =
        "\0\1\2\3\4\5"  /* Ethernet: destination */
                "\6\7\x8\x9\xa\xb"  /* Ethernet: source */
                "\x08\x00"      /* Ethernet type: IPv4 */
                "\x45"          /* IP type */
                "\x00"
                "\x00\x28"      /* total length = 84 bytes */
                "\x00\x00"      /* identification */
                "\x00\x00"      /* fragmentation flags */
                "\xFF\x01"      /* TTL=255, proto=UDP */
                "\xFF\xFF"      /* checksum */
                "\0\0\0\0"      /* source address */
                "\0\0\0\0"      /* destination address */

                "\x0d\x00"  /* timestamp request */
                "\x00\x00"  /* checksum */
                "\x00\x00"  /* identifier */
                "\x00\x00"  /* sequence number */
                "\x00\x00\x00\x00"
                "\x00\x00\x00\x00"
                "\x00\x00\x00\x00"
;


static unsigned char default_arp_template[] =
        "\xff\xff\xff\xff\xff\xff"  /* Ethernet: destination */
                "\x00\x00\x00\x00\x00\x00"  /* Ethernet: source */
                "\x08\x06"      /* Ethernet type: ARP */
                "\x00\x01" /* hardware = Ethernet */
                "\x08\x00" /* protocol = IPv4 */
                "\x06\x04" /* MAC length = 6, IPv4 length = 4 */
                "\x00\x01" /* opcode = request */

                "\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00"

                "\x00\x00\x00\x00\x00\x00"
                "\x00\x00\x00\x00"
;






enum TemplateProtocol {
    Proto_TCP,
    Proto_UDP,
    Proto_SCTP,
    Proto_ICMP_ping,
    Proto_ICMP_timestamp,
    Proto_ARP,
    Proto_Script,
    //Proto_IP,
    //Proto_Custom,
            Proto_Count
};
enum {
    Templ_TCP = 0,
    Templ_UDP = 65536,
    Templ_SCTP = 65536*2,
    Templ_ICMP_echo = 65536*3+0,
    Templ_ICMP_timestamp = 65536*3+1,
    Templ_ARP = 65536*3+2,
    Templ_Script = 65536*4,
};

typedef unsigned (*SET_COOKIE)(unsigned char *px, size_t length,
                               uint64_t seqno);
struct Payload {
    unsigned port;
    unsigned source_port; /* not used yet */
    unsigned length;
    unsigned xsum;
    SET_COOKIE set_cookie;
    unsigned char buf[1];
};

struct NmapPayloads {
    unsigned count;
    size_t max;
    struct Payload **list;
};

struct TemplatePacket {
    unsigned length;
    unsigned offset_ip;
    unsigned offset_tcp;
    unsigned offset_app;
    unsigned char *packet;
    unsigned checksum_ip;
    unsigned checksum_tcp;
    unsigned ip_id;
    enum TemplateProtocol proto;
    //struct NmapPayloads *payloads;
};

void
template_init(
        struct TemplatePacket *tmpl,
        const unsigned char *mac_source,
        const unsigned char *mac_dest,
        const void *packet_bytes,
        size_t packet_size
);

size_t
tcp_create_packet(
        struct TemplatePacket *tmpl,
        unsigned ip_them, unsigned port_them,
        unsigned ip_me, unsigned port_me,
        unsigned seqno, unsigned ackno,
        unsigned flags,
        const unsigned char *payload, size_t payload_length,
        unsigned char *px, size_t px_length);
        