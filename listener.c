/*
 * To compile: gcc listener.c -o listener -lpcap
 *
 */

#include "listener.h"

#define MAXBYTES2CAPTURE 2048

void processPacket(u_char *arg, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    int i=0;
//    for(i=0; i<pkthdr->len; i++) {
//        printf("%c", packet[i]);
//    }
    printf("%d",pkthdr->len);

    printf("\n\n\n");

}


int listener(char* device) {

    int count=0;
    pcap_t *descr=NULL;
    char errbuf[PCAP_ERRBUF_SIZE];
    memset(errbuf, 0, PCAP_ERRBUF_SIZE);

    if (device==NULL) {
        if ((device=pcap_lookupdev(errbuf))==NULL) {
            fprintf(stderr, "ERROR: %s\n", errbuf);
            exit(1);
        }
    }

    printf("Opening device %s\n", device);

    if ((descr=pcap_open_live(device, MAXBYTES2CAPTURE, 0, 512, errbuf))==NULL) {
        fprintf(stderr, "ERROR: %s\n", errbuf);
        exit(1);
    }

    if (pcap_loop(descr, -1, processPacket, (u_char *)&count)==-1) {
        fprintf(stderr, "ERROR: %s\n", pcap_geterr(descr));
        exit(1);
    }

    return 0;
}

int main(int argc, char* argv[]) {
    char* device=NULL;

    if (argc>1) {
        device=argv[1];
    }

    listener(device);

}
