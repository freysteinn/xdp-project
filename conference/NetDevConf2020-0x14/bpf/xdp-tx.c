/*
 * compile with:
 * clang -O3 -c xdp-tx.c -o - -emit-llvm |llc -march=bpf - -filetype=obj -o xdp-tx.o
 * run with:
 * ip link set eth0 xdp object xdp-tx.o
 */

#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/udp.h>

#define SEC(NAME) __attribute__((section(NAME), used))

SEC("prog")
int xdp_main(struct xdp_md *ctx)
{
	return XDP_TX;
}

char _license[] SEC("license") = "GPL";
