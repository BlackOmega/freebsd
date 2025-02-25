/*	$OpenBSD: if_otusreg.h,v 1.9 2013/11/26 20:33:18 deraadt Exp $	*/

/*-
 * Copyright (c) 2009 Damien Bergamini <damien.bergamini@free.fr>
 * Copyright (c) 2007-2008 Atheros Communications, Inc.
 * Copyright (c) 2015 Adrian Chadd <adrian@FreeBSD.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * $FreeBSD$
 */
#ifndef	__IF_OTUSREG_H__
#define	__IF_OTUSREG_H__

/* USB Endpoints addresses. */
#define AR_EPT_BULK_TX_NO	(UE_DIR_OUT | 1)
#define AR_EPT_BULK_RX_NO	(UE_DIR_IN  | 2)
#define AR_EPT_INTR_RX_NO	(UE_DIR_IN  | 3)
#define AR_EPT_INTR_TX_NO	(UE_DIR_OUT | 4)

/* USB Requests. */
#define AR_FW_DOWNLOAD			0x30
#define AR_FW_DOWNLOAD_COMPLETE		0x31

/* Maximum number of writes that can fit in a single FW command is 7. */
#define AR_MAX_WRITE_IDX	6	/* 56 bytes */

#define AR_FW_INIT_ADDR			0x102800
#define AR_FW_MAIN_ADDR			0x200000
#define AR_USB_MODE_CTRL		0x1e1108

/*
 * AR9170 MAC registers.
 */
#define AR_MAC_REG_BASE			0x1c3000
#define AR_MAC_REG_MAC_ADDR_L		(AR_MAC_REG_BASE + 0x610)
#define AR_MAC_REG_MAC_ADDR_H		(AR_MAC_REG_BASE + 0x614)
#define AR_MAC_REG_BSSID_L		(AR_MAC_REG_BASE + 0x618)
#define AR_MAC_REG_BSSID_H		(AR_MAC_REG_BASE + 0x61c)
#define AR_MAC_REG_GROUP_HASH_TBL_L	(AR_MAC_REG_BASE + 0x624)
#define AR_MAC_REG_GROUP_HASH_TBL_H	(AR_MAC_REG_BASE + 0x628)
#define AR_MAC_REG_BASIC_RATE		(AR_MAC_REG_BASE + 0x630)
#define AR_MAC_REG_MANDATORY_RATE	(AR_MAC_REG_BASE + 0x634)
#define AR_MAC_REG_RTS_CTS_RATE		(AR_MAC_REG_BASE + 0x638)
#define AR_MAC_REG_BACKOFF_PROTECT	(AR_MAC_REG_BASE + 0x63c)
#define AR_MAC_REG_RX_THRESHOLD		(AR_MAC_REG_BASE + 0x640)
#define AR_MAC_REG_RX_PE_DELAY		(AR_MAC_REG_BASE + 0x64c)
#define AR_MAC_REG_DYNAMIC_SIFS_ACK	(AR_MAC_REG_BASE + 0x658)
#define AR_MAC_REG_SNIFFER		(AR_MAC_REG_BASE + 0x674)
#define AR_MAC_REG_ACK_EXTENSION	(AR_MAC_REG_BASE + 0x690)
#define AR_MAC_REG_EIFS_AND_SIFS	(AR_MAC_REG_BASE + 0x698)
#define AR_MAC_REG_BUSY			(AR_MAC_REG_BASE + 0x6e8)
#define AR_MAC_REG_BUSY_EXT		(AR_MAC_REG_BASE + 0x6ec)
#define AR_MAC_REG_SLOT_TIME		(AR_MAC_REG_BASE + 0x6f0)
#define AR_MAC_REG_AC0_CW		(AR_MAC_REG_BASE + 0xb00)
#define AR_MAC_REG_AC1_CW		(AR_MAC_REG_BASE + 0xb04)
#define AR_MAC_REG_AC2_CW		(AR_MAC_REG_BASE + 0xb08)
#define AR_MAC_REG_AC3_CW		(AR_MAC_REG_BASE + 0xb0c)
#define AR_MAC_REG_AC4_CW		(AR_MAC_REG_BASE + 0xb10)
#define AR_MAC_REG_AC1_AC0_AIFS		(AR_MAC_REG_BASE + 0xb14)
#define AR_MAC_REG_AC3_AC2_AIFS		(AR_MAC_REG_BASE + 0xb18)
#define AR_MAC_REG_RETRY_MAX		(AR_MAC_REG_BASE + 0xb28)
#define AR_MAC_REG_TXOP_NOT_ENOUGH_INDICATION	\
					(AR_MAC_REG_BASE + 0xb30)
#define AR_MAC_REG_AC1_AC0_TXOP		(AR_MAC_REG_BASE + 0xb44)
#define AR_MAC_REG_AC3_AC2_TXOP		(AR_MAC_REG_BASE + 0xb48)
#define AR_MAC_REG_OFDM_PHY_ERRORS	(AR_MAC_REG_BASE + 0xcb4)
#define AR_MAC_REG_CCK_PHY_ERRORS	(AR_MAC_REG_BASE + 0xcb8)
#define AR_MAC_REG_BCN_HT1		(AR_MAC_REG_BASE + 0xda0)

/* Possible values for register AR_USB_MODE_CTRL. */
#define AR_USB_DS_ENA		(1 << 0)
#define AR_USB_US_ENA		(1 << 1)
#define AR_USB_US_PACKET_MODE	(1 << 3)
#define AR_USB_RX_STREAM_4K	(0 << 4)
#define AR_USB_RX_STREAM_8K	(1 << 4)
#define AR_USB_RX_STREAM_16K	(2 << 4)
#define AR_USB_RX_STREAM_32K	(3 << 4)
#define AR_USB_TX_STREAM_MODE	(1 << 6)

#define AR_LED0_ON	(1 << 0)
#define AR_LED1_ON	(1 << 1)

/*
 * PHY registers.
 */
#define AR_PHY_BASE			0x1c5800
#define AR_PHY(reg)			(AR_PHY_BASE + (reg) * 4)
#define AR_PHY_TURBO			(AR_PHY_BASE + 0x0004)
#define AR_PHY_RF_CTL3			(AR_PHY_BASE + 0x0028)
#define AR_PHY_RF_CTL4			(AR_PHY_BASE + 0x0034)
#define AR_PHY_SETTLING			(AR_PHY_BASE + 0x0044)
#define AR_PHY_RXGAIN			(AR_PHY_BASE + 0x0048)
#define AR_PHY_DESIRED_SZ		(AR_PHY_BASE + 0x0050)
#define AR_PHY_FIND_SIG			(AR_PHY_BASE + 0x0058)
#define AR_PHY_AGC_CTL1			(AR_PHY_BASE + 0x005c)
#define AR_PHY_SFCORR			(AR_PHY_BASE + 0x0068)
#define AR_PHY_SFCORR_LOW		(AR_PHY_BASE + 0x006c)
#define AR_PHY_TIMING_CTRL4		(AR_PHY_BASE + 0x0120)
#define AR_PHY_TIMING5			(AR_PHY_BASE + 0x0124)
#define AR_PHY_POWER_TX_RATE1		(AR_PHY_BASE + 0x0134)
#define AR_PHY_POWER_TX_RATE2		(AR_PHY_BASE + 0x0138)
#define AR_PHY_POWER_TX_RATE_MAX	(AR_PHY_BASE + 0x013c)
#define AR_PHY_SWITCH_CHAIN_0		(AR_PHY_BASE + 0x0160)
#define AR_PHY_SWITCH_COM		(AR_PHY_BASE + 0x0164)
#define AR_PHY_HEAVY_CLIP_ENABLE	(AR_PHY_BASE + 0x01e0)
#define AR_PHY_CCK_DETECT		(AR_PHY_BASE + 0x0a08)
#define AR_PHY_GAIN_2GHZ		(AR_PHY_BASE + 0x0a0c)
#define AR_PHY_POWER_TX_RATE3		(AR_PHY_BASE + 0x0a34)
#define AR_PHY_POWER_TX_RATE4		(AR_PHY_BASE + 0x0a38)
#define AR_PHY_TPCRG1			(AR_PHY_BASE + 0x0a58)
#define AR_PHY_POWER_TX_RATE5		(AR_PHY_BASE + 0x0b8c)
#define AR_PHY_POWER_TX_RATE6		(AR_PHY_BASE + 0x0b90)
#define AR_PHY_POWER_TX_RATE7		(AR_PHY_BASE + 0x0bcc)
#define AR_PHY_POWER_TX_RATE8		(AR_PHY_BASE + 0x0bd0)
#define AR_PHY_POWER_TX_RATE9		(AR_PHY_BASE + 0x0bd4)
#define AR_PHY_CCA			(AR_PHY_BASE + 0x3064)

#define AR_SEEPROM_HW_TYPE_OFFSET	0x1374
#define AR_EEPROM_OFFSET		0x1600

#define AR_BANK4_CHUP			(1 << 0)
#define AR_BANK4_BMODE_LF_SYNTH_FREQ	(1 << 1)
#define AR_BANK4_AMODE_REFSEL(x)	((x) << 2)
#define AR_BANK4_ADDR(x)		((x) << 5)

/* Tx descriptor. */
struct ar_tx_head {
	uint16_t	len;
	uint16_t	macctl;
#define AR_TX_MAC_RTS		(1 <<  0)
#define AR_TX_MAC_CTS		(1 <<  1)
#define AR_TX_MAC_BACKOFF	(1 <<  3)
#define AR_TX_MAC_NOACK		(1 <<  2)
#define AR_TX_MAC_HW_DUR	(1 <<  9)
#define AR_TX_MAC_QID(qid)	((qid) << 10)
#define AR_TX_MAC_RATE_PROBING	(1 << 15)

	uint32_t	phyctl;
/* Modulation type. */
#define AR_TX_PHY_MT_CCK	0
#define AR_TX_PHY_MT_OFDM	1
#define AR_TX_PHY_MT_HT		2
#define AR_TX_PHY_GF		(1 << 2)
#define AR_TX_PHY_BW_SHIFT	3
#define AR_TX_PHY_TPC_SHIFT	9
#define AR_TX_PHY_ANTMSK(msk)	((msk) << 15)
#define AR_TX_PHY_MCS(mcs)	((mcs) << 18)
#define AR_TX_PHY_SHGI		(1U << 31)
} __packed;

/* USB Rx stream mode header. */
struct ar_rx_head {
	uint16_t	len;
	uint16_t	tag;
#define AR_RX_HEAD_TAG	0x4e00
} __packed;

/* Rx descriptor. */
struct ar_rx_tail {
	uint8_t	rssi_ant[3];
	uint8_t	rssi_ant_ext[3];
	uint8_t	rssi;		/* Combined RSSI. */
	uint8_t	evm[2][6];	/* Error Vector Magnitude. */
	uint8_t	phy_err;
	uint8_t	sa_idx;
	uint8_t	da_idx;
	uint8_t	error;
#define AR_RX_ERROR_TIMEOUT	(1 << 0)
#define AR_RX_ERROR_OVERRUN	(1 << 1)
#define AR_RX_ERROR_DECRYPT	(1 << 2)
#define AR_RX_ERROR_FCS		(1 << 3)
#define AR_RX_ERROR_BAD_RA	(1 << 4)
#define AR_RX_ERROR_PLCP	(1 << 5)
#define AR_RX_ERROR_MMIC	(1 << 6)

	uint8_t	status;
/* Modulation type (same as AR_TX_PHY_MT). */
#define AR_RX_STATUS_MT_MASK	0x3
#define AR_RX_STATUS_MT_CCK	0
#define AR_RX_STATUS_MT_OFDM	1
#define AR_RX_STATUS_MT_HT	2
#define AR_RX_STATUS_SHPREAMBLE	(1 << 3)
} __packed;

#define AR_PLCP_HDR_LEN	12
/* Magic PLCP header for firmware notifications through Rx bulk pipe. */
static uint8_t AR_PLCP_HDR_INTR[] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

/* Firmware command/reply header. */
struct ar_cmd_hdr {
	uint8_t		len;
	uint8_t		code;
#define AR_CMD_RREG		0x00
#define AR_CMD_WREG		0x01
#define AR_CMD_RMEM		0x02
#define AR_CMD_WMEM		0x03
#define AR_CMD_BITAND		0x04
#define AR_CMD_BITOR		0x05
#define AR_CMD_EKEY		0x28
#define AR_CMD_DKEY		0x29
#define AR_CMD_FREQUENCY	0x30
#define AR_CMD_RF_INIT		0x31
#define AR_CMD_SYNTH		0x32
#define AR_CMD_FREQ_STRAT	0x33
#define AR_CMD_ECHO		0x80
#define AR_CMD_TALLY		0x81
#define AR_CMD_TALLY_APD	0x82
#define AR_CMD_CONFIG		0x83
#define AR_CMD_RESET		0x90
#define AR_CMD_DKRESET		0x91
#define AR_CMD_DKTX_STATUS	0x92
#define AR_CMD_FDC		0xa0
#define AR_CMD_WREEPROM		0xb0
#define AR_CMD_WFLASH		AR_CMD_WREEPROM
#define AR_CMD_FLASH_ERASE	0xb1
#define AR_CMD_FLASH_PROG	0xb2
#define AR_CMD_FLASH_CHKSUM	0xb3
#define AR_CMD_FLASH_READ	0xb4
#define AR_CMD_FW_DL_INIT	0xb5
#define AR_CMD_MEM_WREEPROM	0xbb
/* Those have the 2 MSB set to 1. */
#define AR_EVT_BEACON		0x00
#define AR_EVT_TX_COMP		0x01
#define AR_EVT_TBTT		0x02
#define AR_EVT_ATIM		0x03
#define AR_EVT_DO_BB_RESET	0x09

	uint16_t	token;	/* Driver private data. */
} __packed;

/* Structure for command AR_CMD_RF_INIT/AR_CMD_FREQUENCY. */
struct ar_cmd_frequency {
	uint32_t	freq;
	uint32_t	dynht2040;
	uint32_t	htena;
	uint32_t	dsc_exp;
	uint32_t	dsc_man;
	uint32_t	dsc_shgi_exp;
	uint32_t	dsc_shgi_man;
	uint32_t	check_loop_count;
} __packed;

/* Firmware reply for command AR_CMD_FREQUENCY. */
struct ar_rsp_frequency {
	uint32_t	status;
#define AR_CAL_ERR_AGC		(1 << 0)	/* AGC cal unfinished. */
#define AR_CAL_ERR_NF		(1 << 1)	/* Noise cal unfinished. */
#define AR_CAL_ERR_NF_VAL	(1 << 2)	/* NF value unexpected. */

	uint32_t	nf[3];		/* Noisefloor. */
	uint32_t	nf_ext[3];	/* Noisefloor ext. */
} __packed;

/* Structure for command AR_CMD_EKEY. */
struct ar_cmd_ekey {
	uint16_t	uid;	/* user ID */
	uint16_t	kix;
	uint16_t	cipher;
#define AR_CIPHER_NONE		0
#define AR_CIPHER_WEP64		1
#define AR_CIPHER_TKIP		2
#define AR_CIPHER_AES		4
#define AR_CIPHER_WEP128	5
#define AR_CIPHER_WEP256	6
#define AR_CIPHER_CENC		7

	uint8_t		macaddr[IEEE80211_ADDR_LEN];
	uint8_t		key[16];
} __packed;

/* Structure for event AR_EVT_TX_COMP. */
struct ar_evt_tx_comp {
	uint8_t		macaddr[IEEE80211_ADDR_LEN];
	uint32_t	phy;
	uint16_t	status;
#define AR_TX_STATUS_COMP	0
#define AR_TX_STATUS_RETRY_COMP	1
#define AR_TX_STATUS_FAILED	2
} __packed;

/* List of supported channels. */
static const uint8_t ar_chans[] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
	36, 40, 44, 48, 52, 56, 60, 64, 100, 104, 108, 112, 116, 120, 124,
	128, 132, 136, 140, 149, 153, 157, 161, 165, 34, 38, 42, 46
};

/*
 * This data is automatically generated from the "otus.ini" file.
 * It is stored in a different way though, to reduce kernel's .rodata
 * section overhead (5.1KB instead of 8.5KB).
 */

/* NB: apply AR_PHY(). */
static const uint16_t ar5416_phy_regs[] = {
	0x000, 0x001, 0x002, 0x003, 0x004, 0x005, 0x006, 0x007, 0x008,
	0x009, 0x00a, 0x00b, 0x00c, 0x00d, 0x00e, 0x00f, 0x010, 0x011,
	0x012, 0x013, 0x014, 0x015, 0x016, 0x017, 0x018, 0x01a, 0x01b,
	0x040, 0x041, 0x042, 0x043, 0x045, 0x046, 0x047, 0x048, 0x049,
	0x04a, 0x04b, 0x04d, 0x04e, 0x04f, 0x051, 0x052, 0x053, 0x055,
	0x056, 0x058, 0x059, 0x05c, 0x05d, 0x05e, 0x05f, 0x060, 0x061,
	0x062, 0x063, 0x064, 0x065, 0x066, 0x067, 0x068, 0x069, 0x06a,
	0x06b, 0x06c, 0x06d, 0x070, 0x071, 0x072, 0x073, 0x074, 0x075,
	0x076, 0x077, 0x078, 0x079, 0x07a, 0x07b, 0x07c, 0x07f, 0x080,
	0x081, 0x082, 0x083, 0x084, 0x085, 0x086, 0x087, 0x088, 0x089,
	0x08a, 0x08b, 0x08c, 0x08d, 0x08e, 0x08f, 0x090, 0x091, 0x092,
	0x093, 0x094, 0x095, 0x096, 0x097, 0x098, 0x099, 0x09a, 0x09b,
	0x09c, 0x09d, 0x09e, 0x09f, 0x0a0, 0x0a1, 0x0a2, 0x0a3, 0x0a4,
	0x0a5, 0x0a6, 0x0a7, 0x0a8, 0x0a9, 0x0aa, 0x0ab, 0x0ac, 0x0ad,
	0x0ae, 0x0af, 0x0b0, 0x0b1, 0x0b2, 0x0b3, 0x0b4, 0x0b5, 0x0b6,
	0x0b7, 0x0b8, 0x0b9, 0x0ba, 0x0bb, 0x0bc, 0x0bd, 0x0be, 0x0bf,
	0x0c0, 0x0c1, 0x0c2, 0x0c3, 0x0c4, 0x0c5, 0x0c6, 0x0c7, 0x0c8,
	0x0c9, 0x0ca, 0x0cb, 0x0cc, 0x0cd, 0x0ce, 0x0cf, 0x0d0, 0x0d1,
	0x0d2, 0x0d3, 0x0d4, 0x0d5, 0x0d6, 0x0d7, 0x0d8, 0x0d9, 0x0da,
	0x0db, 0x0dc, 0x0dd, 0x0de, 0x0df, 0x0e0, 0x0e1, 0x0e2, 0x0e3,
	0x0e4, 0x0e5, 0x0e6, 0x0e7, 0x0e8, 0x0e9, 0x0ea, 0x0eb, 0x0ec,
	0x0ed, 0x0ee, 0x0ef, 0x0f0, 0x0f1, 0x0f2, 0x0f3, 0x0f4, 0x0f5,
	0x0f6, 0x0f7, 0x0f8, 0x0f9, 0x0fa, 0x0fb, 0x0fc, 0x0fd, 0x0fe,
	0x0ff, 0x100, 0x103, 0x104, 0x105, 0x106, 0x107, 0x108, 0x109,
	0x10a, 0x10b, 0x10c, 0x10d, 0x10e, 0x10f, 0x13c, 0x13d, 0x13e,
	0x13f, 0x280, 0x281, 0x282, 0x283, 0x284, 0x285, 0x286, 0x287,
	0x288, 0x289, 0x28a, 0x28b, 0x28c, 0x28d, 0x28e, 0x28f, 0x290,
	0x291, 0x292, 0x293, 0x294, 0x295, 0x296, 0x297, 0x298, 0x299,
	0x29a, 0x29b, 0x29d, 0x29e, 0x29f, 0x2c0, 0x2c1, 0x2c2, 0x2c3,
	0x2c4, 0x2c5, 0x2c6, 0x2c7, 0x2c8, 0x2c9, 0x2ca, 0x2cb, 0x2cc,
	0x2cd, 0x2ce, 0x2cf, 0x2d0, 0x2d1, 0x2d2, 0x2d3, 0x2d4, 0x2d5,
	0x2d6, 0x2e2, 0x2e3, 0x2e4, 0x2e5, 0x2e6, 0x2e7, 0x2e8, 0x2e9,
	0x2ea, 0x2eb, 0x2ec, 0x2ed, 0x2ee, 0x2ef, 0x2f0, 0x2f1, 0x2f2,
	0x2f3, 0x2f4, 0x2f5, 0x2f6, 0x2f7, 0x2f8, 0x412, 0x448, 0x458,
	0x683, 0x69b, 0x812, 0x848, 0x858, 0xa83, 0xa9b, 0xc19, 0xc57,
	0xc5a, 0xc6f, 0xe9c, 0xed7, 0xed8, 0xed9, 0xeda, 0xedb, 0xedc,
	0xedd, 0xede, 0xedf, 0xee0, 0xee1
};

static const uint32_t ar5416_phy_vals_5ghz_20mhz[] = {
	0x00000007, 0x00000300, 0x00000000, 0xad848e19, 0x7d14e000,
	0x9c0a9f6b, 0x00000090, 0x00000000, 0x02020200, 0x00000e0e,
	0x0a020001, 0x0000a000, 0x00000000, 0x00000e0e, 0x00000007,
	0x00200400, 0x206a002e, 0x1372161e, 0x001a6a65, 0x1284233c,
	0x6c48b4e4, 0x00000859, 0x7ec80d2e, 0x31395c5e, 0x0004dd10,
	0x409a4190, 0x050cb081, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x000007d0, 0x00000118, 0x10000fff, 0x0510081c,
	0xd0058a15, 0x00000001, 0x00000004, 0x3f3f3f3f, 0x3f3f3f3f,
	0x0000007f, 0xdfb81020, 0x9280b212, 0x00020028, 0x5d50e188,
	0x00081fff, 0x00009b40, 0x00001120, 0x190fb515, 0x00000000,
	0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000007, 0x001fff00, 0x006f00c4, 0x03051000,
	0x00000820, 0x038919be, 0x06336f77, 0x60f6532c, 0x08f186c8,
	0x00046384, 0x00000000, 0x00000000, 0x00000000, 0x00000200,
	0x64646464, 0x3c787878, 0x000000aa, 0x00000000, 0x00001042,
	0x00000000, 0x00000040, 0x00000080, 0x000001a1, 0x000001e1,
	0x00000021, 0x00000061, 0x00000168, 0x000001a8, 0x000001e8,
	0x00000028, 0x00000068, 0x00000189, 0x000001c9, 0x00000009,
	0x00000049, 0x00000089, 0x00000170, 0x000001b0, 0x000001f0,
	0x00000030, 0x00000070, 0x00000191, 0x000001d1, 0x00000011,
	0x00000051, 0x00000091, 0x000001b8, 0x000001f8, 0x00000038,
	0x00000078, 0x00000199, 0x000001d9, 0x00000019, 0x00000059,
	0x00000099, 0x000000d9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x00000000,
	0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
	0x00000008, 0x00000009, 0x0000000a, 0x0000000b, 0x0000000c,
	0x0000000d, 0x00000010, 0x00000011, 0x00000012, 0x00000013,
	0x00000014, 0x00000015, 0x00000018, 0x00000019, 0x0000001a,
	0x0000001b, 0x0000001c, 0x0000001d, 0x00000020, 0x00000021,
	0x00000022, 0x00000023, 0x00000024, 0x00000025, 0x00000028,
	0x00000029, 0x0000002a, 0x0000002b, 0x0000002c, 0x0000002d,
	0x00000030, 0x00000031, 0x00000032, 0x00000033, 0x00000034,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000010, 0x0000001a, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000008, 0x00000440, 0xd6be4788, 0x012e8160,
	0x40806333, 0x00106c10, 0x009c4060, 0x1883800a, 0x018830c6,
	0x00000400, 0x000009b5, 0x00000000, 0x00000108, 0x3f3f3f3f,
	0x3f3f3f3f, 0x13c889af, 0x38490a20, 0x00007bb6, 0x0fff3ffc,
	0x00000001, 0x0000a000, 0x00000000, 0x0cc75380, 0x0f0f0f01,
	0xdfa91f01, 0x00418a11, 0x00000000, 0x09249126, 0x0a1a9caa,
	0x1ce739ce, 0x051701ce, 0x18010000, 0x30032602, 0x48073e06,
	0x560b4c0a, 0x641a600f, 0x7a4f6e1b, 0x8c5b7e5a, 0x9d0f96cf,
	0xb51fa69f, 0xcb3fbd07, 0x0000d7bf, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x3fffffff, 0x3fffffff, 0x3fffffff, 0x0003ffff, 0x79a8aa1f,
	0x08000000, 0x3f3f3f3f, 0x3f3f3f3f, 0x1ce739ce, 0x000001ce,
	0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f,
	0x00000000, 0x1ce739ce, 0x000000c0, 0x00180a65, 0x0510001c,
	0x00009b40, 0x012e8160, 0x09249126, 0x00180a65, 0x0510001c,
	0x00009b40, 0x012e8160, 0x09249126, 0x0001c600, 0x004b6a8e,
	0x000003ce, 0x00181400, 0x00820820, 0x066c420f, 0x0f282207,
	0x17601685, 0x1f801104, 0x37a00c03, 0x3fc40883, 0x57c00803,
	0x5fd80682, 0x7fe00482, 0x7f3c7bba, 0xf3307ff0
};

#ifdef notyet
static const uint32_t ar5416_phy_vals_5ghz_40mhz[] = {
	0x00000007, 0x000003c4, 0x00000000, 0xad848e19, 0x7d14e000,
	0x9c0a9f6b, 0x00000090, 0x00000000, 0x02020200, 0x00000e0e,
	0x0a020001, 0x0000a000, 0x00000000, 0x00000e0e, 0x00000007,
	0x00200400, 0x206a002e, 0x13721c1e, 0x001a6a65, 0x1284233c,
	0x6c48b4e4, 0x00000859, 0x7ec80d2e, 0x31395c5e, 0x0004dd10,
	0x409a4190, 0x050cb081, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x000007d0, 0x00000230, 0x10000fff, 0x0510081c,
	0xd0058a15, 0x00000001, 0x00000004, 0x3f3f3f3f, 0x3f3f3f3f,
	0x0000007f, 0xdfb81020, 0x9280b212, 0x00020028, 0x5d50e188,
	0x00081fff, 0x00009b40, 0x00001120, 0x190fb515, 0x00000000,
	0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000007, 0x001fff00, 0x006f00c4, 0x03051000,
	0x00000820, 0x038919be, 0x06336f77, 0x60f6532c, 0x08f186c8,
	0x00046384, 0x00000000, 0x00000000, 0x00000000, 0x00000200,
	0x64646464, 0x3c787878, 0x000000aa, 0x00000000, 0x00001042,
	0x00000000, 0x00000040, 0x00000080, 0x000001a1, 0x000001e1,
	0x00000021, 0x00000061, 0x00000168, 0x000001a8, 0x000001e8,
	0x00000028, 0x00000068, 0x00000189, 0x000001c9, 0x00000009,
	0x00000049, 0x00000089, 0x00000170, 0x000001b0, 0x000001f0,
	0x00000030, 0x00000070, 0x00000191, 0x000001d1, 0x00000011,
	0x00000051, 0x00000091, 0x000001b8, 0x000001f8, 0x00000038,
	0x00000078, 0x00000199, 0x000001d9, 0x00000019, 0x00000059,
	0x00000099, 0x000000d9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x00000000,
	0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
	0x00000008, 0x00000009, 0x0000000a, 0x0000000b, 0x0000000c,
	0x0000000d, 0x00000010, 0x00000011, 0x00000012, 0x00000013,
	0x00000014, 0x00000015, 0x00000018, 0x00000019, 0x0000001a,
	0x0000001b, 0x0000001c, 0x0000001d, 0x00000020, 0x00000021,
	0x00000022, 0x00000023, 0x00000024, 0x00000025, 0x00000028,
	0x00000029, 0x0000002a, 0x0000002b, 0x0000002c, 0x0000002d,
	0x00000030, 0x00000031, 0x00000032, 0x00000033, 0x00000034,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000010, 0x0000001a, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000008, 0x00000440, 0xd6be4788, 0x012e8160,
	0x40806333, 0x00106c10, 0x009c4060, 0x1883800a, 0x018830c6,
	0x00000400, 0x000009b5, 0x00000000, 0x00000210, 0x3f3f3f3f,
	0x3f3f3f3f, 0x13c889af, 0x38490a20, 0x00007bb6, 0x0fff3ffc,
	0x00000001, 0x0000a000, 0x00000000, 0x0cc75380, 0x0f0f0f01,
	0xdfa91f01, 0x00418a11, 0x00000000, 0x09249126, 0x0a1a9caa,
	0x1ce739ce, 0x051701ce, 0x18010000, 0x30032602, 0x48073e06,
	0x560b4c0a, 0x641a600f, 0x7a4f6e1b, 0x8c5b7e5a, 0x9d0f96cf,
	0xb51fa69f, 0xcb3fbcbf, 0x0000d7bf, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x3fffffff, 0x3fffffff, 0x3fffffff, 0x0003ffff, 0x79a8aa1f,
	0x08000000, 0x3f3f3f3f, 0x3f3f3f3f, 0x1ce739ce, 0x000001ce,
	0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f,
	0x00000000, 0x1ce739ce, 0x000000c0, 0x00180a65, 0x0510001c,
	0x00009b40, 0x012e8160, 0x09249126, 0x00180a65, 0x0510001c,
	0x00009b40, 0x012e8160, 0x09249126, 0x0001c600, 0x004b6a8e,
	0x000003ce, 0x00181400, 0x00820820, 0x066c420f, 0x0f282207,
	0x17601685, 0x1f801104, 0x37a00c03, 0x3fc40883, 0x57c00803,
	0x5fd80682, 0x7fe00482, 0x7f3c7bba, 0xf3307ff0
};
#endif

#ifdef notyet
static const uint32_t ar5416_phy_vals_2ghz_40mhz[] = {
	0x00000007, 0x000003c4, 0x00000000, 0xad848e19, 0x7d14e000,
	0x9c0a9f6b, 0x00000090, 0x00000000, 0x02020200, 0x00000e0e,
	0x0a020001, 0x0000a000, 0x00000000, 0x00000e0e, 0x00000007,
	0x00200400, 0x206a002e, 0x13721c24, 0x00197a68, 0x1284233c,
	0x6c48b0e4, 0x00000859, 0x7ec80d2e, 0x31395c5e, 0x0004dd20,
	0x409a4190, 0x050cb081, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000898, 0x00000268, 0x10000fff, 0x0510001c,
	0xd0058a15, 0x00000001, 0x00000004, 0x3f3f3f3f, 0x3f3f3f3f,
	0x0000007f, 0xdfb81020, 0x9280b212, 0x00020028, 0x5d50e188,
	0x00081fff, 0x00009b40, 0x00001120, 0x190fb515, 0x00000000,
	0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000007, 0x001fff00, 0x006f00c4, 0x03051000,
	0x00000820, 0x038919be, 0x06336f77, 0x60f6532c, 0x08f186c8,
	0x00046384, 0x00000000, 0x00000000, 0x00000000, 0x00000200,
	0x64646464, 0x3c787878, 0x000000aa, 0x00000000, 0x00001042,
	0x00000000, 0x00000040, 0x00000080, 0x00000141, 0x00000181,
	0x000001c1, 0x00000001, 0x00000041, 0x000001a8, 0x000001e8,
	0x00000028, 0x00000068, 0x000000a8, 0x00000169, 0x000001a9,
	0x000001e9, 0x00000029, 0x00000069, 0x00000190, 0x000001d0,
	0x00000010, 0x00000050, 0x00000090, 0x00000151, 0x00000191,
	0x000001d1, 0x00000011, 0x00000051, 0x00000198, 0x000001d8,
	0x00000018, 0x00000058, 0x00000098, 0x00000159, 0x00000199,
	0x000001d9, 0x00000019, 0x00000059, 0x00000099, 0x000000d9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x00000000,
	0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
	0x00000008, 0x00000009, 0x0000000a, 0x0000000b, 0x0000000c,
	0x0000000d, 0x00000010, 0x00000011, 0x00000012, 0x00000013,
	0x00000014, 0x00000015, 0x00000018, 0x00000019, 0x0000001a,
	0x0000001b, 0x0000001c, 0x0000001d, 0x00000020, 0x00000021,
	0x00000022, 0x00000023, 0x00000024, 0x00000025, 0x00000028,
	0x00000029, 0x0000002a, 0x0000002b, 0x0000002c, 0x0000002d,
	0x00000030, 0x00000031, 0x00000032, 0x00000033, 0x00000034,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000010, 0x0000001a, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x0000000e, 0x00000440, 0xd03e4788, 0x012a8160,
	0x40806333, 0x00106c10, 0x009c4060, 0x1883800a, 0x018830c6,
	0x00000400, 0x000009b5, 0x00000000, 0x00000210, 0x3f3f3f3f,
	0x3f3f3f3f, 0x13c889af, 0x38490a20, 0x00007bb6, 0x0fff3ffc,
	0x00000001, 0x0000a000, 0x00000000, 0x0cc75380, 0x0f0f0f01,
	0xdfa91f01, 0x00418a11, 0x00000000, 0x09249126, 0x0a1a7caa,
	0x1ce739ce, 0x051701ce, 0x18010000, 0x2e032402, 0x4a0a3c06,
	0x621a540b, 0x764f6c1b, 0x845b7a5a, 0x950f8ccf, 0xa5cf9b4f,
	0xbddfaf1f, 0xd1ffc93f, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x3fffffff, 0x3fffffff, 0x3fffffff, 0x0003ffff, 0x79a8aa1f,
	0x08000000, 0x3f3f3f3f, 0x3f3f3f3f, 0x1ce739ce, 0x000001ce,
	0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f,
	0x00000000, 0x1ce739ce, 0x000000c0, 0x00180a68, 0x0510001c,
	0x00009b40, 0x012a8160, 0x09249126, 0x00180a68, 0x0510001c,
	0x00009b40, 0x012a8160, 0x09249126, 0x0001c600, 0x004b6a8e,
	0x000003ce, 0x00181400, 0x00820820, 0x066c420f, 0x0f282207,
	0x17601685, 0x1f801104, 0x37a00c03, 0x3fc40883, 0x57c00803,
	0x5fd80682, 0x7fe00482, 0x7f3c7bba, 0xf3307ff0
};
#endif

static const uint32_t ar5416_phy_vals_2ghz_20mhz[] = {
	0x00000007, 0x00000300, 0x00000000, 0xad848e19, 0x7d14e000,
	0x9c0a9f6b, 0x00000090, 0x00000000, 0x02020200, 0x00000e0e,
	0x0a020001, 0x0000a000, 0x00000000, 0x00000e0e, 0x00000007,
	0x00200400, 0x206a002e, 0x137216a4, 0x00197a68, 0x1284233c,
	0x6c48b0e4, 0x00000859, 0x7ec80d2e, 0x31395c5e, 0x0004dd20,
	0x409a4190, 0x050cb081, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000898, 0x00000134, 0x10000fff, 0x0510001c,
	0xd0058a15, 0x00000001, 0x00000004, 0x3f3f3f3f, 0x3f3f3f3f,
	0x0000007f, 0xdfb81020, 0x9280b212, 0x00020028, 0x5d50e188,
	0x00081fff, 0x00009b40, 0x00001120, 0x190fb515, 0x00000000,
	0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000007, 0x001fff00, 0x006f00c4, 0x03051000,
	0x00000820, 0x038919be, 0x06336f77, 0x60f6532c, 0x08f186c8,
	0x00046384, 0x00000000, 0x00000000, 0x00000000, 0x00000200,
	0x64646464, 0x3c787878, 0x000000aa, 0x00000000, 0x00001042,
	0x00000000, 0x00000040, 0x00000080, 0x00000141, 0x00000181,
	0x000001c1, 0x00000001, 0x00000041, 0x000001a8, 0x000001e8,
	0x00000028, 0x00000068, 0x000000a8, 0x00000169, 0x000001a9,
	0x000001e9, 0x00000029, 0x00000069, 0x00000190, 0x000001d0,
	0x00000010, 0x00000050, 0x00000090, 0x00000151, 0x00000191,
	0x000001d1, 0x00000011, 0x00000051, 0x00000198, 0x000001d8,
	0x00000018, 0x00000058, 0x00000098, 0x00000159, 0x00000199,
	0x000001d9, 0x00000019, 0x00000059, 0x00000099, 0x000000d9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9,
	0x000000f9, 0x000000f9, 0x000000f9, 0x000000f9, 0x00000000,
	0x00000001, 0x00000002, 0x00000003, 0x00000004, 0x00000005,
	0x00000008, 0x00000009, 0x0000000a, 0x0000000b, 0x0000000c,
	0x0000000d, 0x00000010, 0x00000011, 0x00000012, 0x00000013,
	0x00000014, 0x00000015, 0x00000018, 0x00000019, 0x0000001a,
	0x0000001b, 0x0000001c, 0x0000001d, 0x00000020, 0x00000021,
	0x00000022, 0x00000023, 0x00000024, 0x00000025, 0x00000028,
	0x00000029, 0x0000002a, 0x0000002b, 0x0000002c, 0x0000002d,
	0x00000030, 0x00000031, 0x00000032, 0x00000033, 0x00000034,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000035, 0x00000035, 0x00000035, 0x00000035,
	0x00000035, 0x00000010, 0x0000001a, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x0000000e, 0x00000440, 0xd03e4788, 0x012a8160,
	0x40806333, 0x00106c10, 0x009c4060, 0x1883800a, 0x018830c6,
	0x00000400, 0x000009b5, 0x00000000, 0x00000108, 0x3f3f3f3f,
	0x3f3f3f3f, 0x13c889af, 0x38490a20, 0x00007bb6, 0x0fff3ffc,
	0x00000001, 0x0000a000, 0x00000000, 0x0cc75380, 0x0f0f0f01,
	0xdfa91f01, 0x00418a11, 0x00000000, 0x09249126, 0x0a1a7caa,
	0x1ce739ce, 0x051701ce, 0x18010000, 0x2e032402, 0x4a0a3c06,
	0x621a540b, 0x764f6c1b, 0x845b7a5a, 0x950f8ccf, 0xa5cf9b4f,
	0xbddfaf1f, 0xd1ffc93f, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x3fffffff, 0x3fffffff, 0x3fffffff, 0x0003ffff, 0x79a8aa1f,
	0x08000000, 0x3f3f3f3f, 0x3f3f3f3f, 0x1ce739ce, 0x000001ce,
	0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f,
	0x00000000, 0x1ce739ce, 0x000000c0, 0x00180a68, 0x0510001c,
	0x00009b40, 0x012a8160, 0x09249126, 0x00180a68, 0x0510001c,
	0x00009b40, 0x012a8160, 0x09249126, 0x0001c600, 0x004b6a8e,
	0x000003ce, 0x00181400, 0x00820820, 0x066c420f, 0x0f282207,
	0x17601685, 0x1f801104, 0x37a00c03, 0x3fc40883, 0x57c00803,
	0x5fd80682, 0x7fe00482, 0x7f3c7bba, 0xf3307ff0
};

/* NB: apply AR_PHY(). */
static const uint8_t ar5416_banks_regs[] = {
	0x2c, 0x38, 0x2c, 0x3b, 0x2c, 0x38, 0x3c, 0x2c, 0x3a, 0x2c, 0x39,
	0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c,
	0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c,
	0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c,
	0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c,
	0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x2c, 0x38, 0x2c, 0x2c,
	0x2c, 0x3c
};

static const uint32_t ar5416_banks_vals_5ghz[] = {
	0x1e5795e5, 0x02008020, 0x02108421, 0x00000008, 0x0e73ff17,
	0x00000420, 0x01400018, 0x000001a1, 0x00000001, 0x00000013,
	0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00004000, 0x00006c00, 0x00002c00, 0x00004800,
	0x00004000, 0x00006000, 0x00001000, 0x00004000, 0x00007c00,
	0x00007c00, 0x00007c00, 0x00007c00, 0x00007c00, 0x00087c00,
	0x00007c00, 0x00005400, 0x00000c00, 0x00001800, 0x00007c00,
	0x00006c00, 0x00006c00, 0x00007c00, 0x00002c00, 0x00003c00,
	0x00003800, 0x00001c00, 0x00000800, 0x00000408, 0x00004c15,
	0x00004188, 0x0000201e, 0x00010408, 0x00000801, 0x00000c08,
	0x0000181e, 0x00001016, 0x00002800, 0x00004010, 0x0000081c,
	0x00000115, 0x00000015, 0x00000066, 0x0000001c, 0x00000000,
	0x00000004, 0x00000015, 0x0000001f, 0x00000000, 0x000000a0,
	0x00000000, 0x00000040, 0x0000001c
};

static const uint32_t ar5416_banks_vals_2ghz[] = {
	0x1e5795e5, 0x02008020, 0x02108421, 0x00000008, 0x0e73ff17,
	0x00000420, 0x01c00018, 0x000001a1, 0x00000001, 0x00000013,
	0x00000002, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00004000, 0x00006c00, 0x00002c00, 0x00004800,
	0x00004000, 0x00006000, 0x00001000, 0x00004000, 0x00007c00,
	0x00007c00, 0x00007c00, 0x00007c00, 0x00007c00, 0x00087c00,
	0x00007c00, 0x00005400, 0x00000c00, 0x00001800, 0x00007c00,
	0x00006c00, 0x00006c00, 0x00007c00, 0x00002c00, 0x00003c00,
	0x00003800, 0x00001c00, 0x00000800, 0x00000408, 0x00004c15,
	0x00004188, 0x0000201e, 0x00010408, 0x00000801, 0x00000c08,
	0x0000181e, 0x00001016, 0x00002800, 0x00004010, 0x0000081c,
	0x00000115, 0x00000015, 0x00000066, 0x0000001c, 0x00000000,
	0x00000004, 0x00000015, 0x0000001f, 0x00000400, 0x000000a0,
	0x00000000, 0x00000040, 0x0000001c
};

/*
 * EEPROM.
 */
/* Possible flags for opCapFlags. */
#define AR5416_OPFLAGS_11A	0x01
#define AR5416_OPFLAGS_11G	0x02
#define AR5416_OPFLAGS_5G_HT40	0x04
#define AR5416_OPFLAGS_2G_HT40	0x08
#define AR5416_OPFLAGS_5G_HT20	0x10
#define AR5416_OPFLAGS_2G_HT20	0x20

#define AR5416_NUM_5G_CAL_PIERS		8
#define AR5416_NUM_2G_CAL_PIERS		4
#define AR5416_NUM_5G_20_TARGET_POWERS	8
#define AR5416_NUM_5G_40_TARGET_POWERS	8
#define AR5416_NUM_2G_CCK_TARGET_POWERS	3
#define AR5416_NUM_2G_20_TARGET_POWERS	4
#define AR5416_NUM_2G_40_TARGET_POWERS	4
#define AR5416_NUM_CTLS			24
#define AR5416_NUM_BAND_EDGES		8
#define AR5416_NUM_PD_GAINS		4
#define AR5416_PD_GAIN_ICEPTS		5
#define AR5416_EEPROM_MODAL_SPURS	5
#define AR5416_MAX_CHAINS		2

struct BaseEepHeader {
	uint16_t	length;
	uint16_t	checksum;
	uint16_t	version;
	uint8_t		opCapFlags;
	uint8_t		eepMisc;
	uint16_t	regDmn[2];
	uint8_t		macAddr[6];
	uint8_t		rxMask;
	uint8_t		txMask;
	uint16_t	rfSilent;
	uint16_t	blueToothOptions;
	uint16_t	deviceCap;
	uint32_t	binBuildNumber;
	uint8_t		deviceType;
	uint8_t		futureBase[33];
} __packed;

struct spurChanStruct {
	uint16_t	spurChan;
	uint8_t		spurRangeLow;
	uint8_t		spurRangeHigh;
} __packed;

struct ModalEepHeader {
	uint32_t	antCtrlChain[AR5416_MAX_CHAINS];
	uint32_t	antCtrlCommon;
	int8_t		antennaGainCh[AR5416_MAX_CHAINS];
	uint8_t		switchSettling;
	uint8_t		txRxAttenCh[AR5416_MAX_CHAINS];
	uint8_t		rxTxMarginCh[AR5416_MAX_CHAINS];
	uint8_t		adcDesiredSize;
	int8_t		pgaDesiredSize;
	uint8_t		xlnaGainCh[AR5416_MAX_CHAINS];
	uint8_t		txEndToXpaOff;
	uint8_t		txEndToRxOn;
	uint8_t		txFrameToXpaOn;
	uint8_t		thresh62;
	uint8_t		noiseFloorThreshCh[AR5416_MAX_CHAINS];
	uint8_t		xpdGain;
	uint8_t		xpd;
	int8_t		iqCalICh[AR5416_MAX_CHAINS];
	int8_t		iqCalQCh[AR5416_MAX_CHAINS];
	uint8_t		pdGainOverlap;
	uint8_t		ob;
	uint8_t		db;
	uint8_t		xpaBiasLvl;
	uint8_t		pwrDecreaseFor2Chain;
	uint8_t		pwrDecreaseFor3Chain;
	uint8_t		txFrameToDataStart;
	uint8_t		txFrameToPaOn;
	uint8_t		ht40PowerIncForPdadc;
	uint8_t		bswAtten[AR5416_MAX_CHAINS];
	uint8_t		bswMargin[AR5416_MAX_CHAINS];
	uint8_t		swSettleHt40;
	uint8_t		futureModal[22];
	struct spurChanStruct spurChans[AR5416_EEPROM_MODAL_SPURS];
} __packed;

struct calDataPerFreq {
	uint8_t		pwrPdg[AR5416_NUM_PD_GAINS][AR5416_PD_GAIN_ICEPTS];
	uint8_t		vpdPdg[AR5416_NUM_PD_GAINS][AR5416_PD_GAIN_ICEPTS];
} __packed;

struct CalTargetPowerLegacy {
	uint8_t		bChannel;
	uint8_t		tPow2x[4];
} __packed;

struct CalTargetPowerHt {
	uint8_t		bChannel;
	uint8_t		tPow2x[8];
} __packed;

struct CalCtlEdges {
	uint8_t		bChannel;
	uint8_t		tPowerFlag;
} __packed;

struct CalCtlData {
	struct CalCtlEdges ctlEdges[AR5416_MAX_CHAINS][AR5416_NUM_BAND_EDGES];
} __packed;

struct ar5416eeprom {
	struct BaseEepHeader	baseEepHeader;
	uint8_t			custData[64];
	struct ModalEepHeader	modalHeader[2];
	uint8_t			calFreqPier5G[AR5416_NUM_5G_CAL_PIERS];
	uint8_t			calFreqPier2G[AR5416_NUM_2G_CAL_PIERS];
	struct calDataPerFreq	calPierData5G[AR5416_MAX_CHAINS]
					     [AR5416_NUM_5G_CAL_PIERS];
	struct calDataPerFreq	calPierData2G[AR5416_MAX_CHAINS]
					     [AR5416_NUM_2G_CAL_PIERS];
	struct CalTargetPowerLegacy calTPow5G[AR5416_NUM_5G_20_TARGET_POWERS];
	struct CalTargetPowerHt calTPow5GHT20[AR5416_NUM_5G_20_TARGET_POWERS];
	struct CalTargetPowerHt calTPow5GHT40[AR5416_NUM_5G_40_TARGET_POWERS];
	struct CalTargetPowerLegacy calTPowCck[AR5416_NUM_2G_CCK_TARGET_POWERS];
	struct CalTargetPowerLegacy calTPow2G[AR5416_NUM_2G_20_TARGET_POWERS];
	struct CalTargetPowerHt calTPow2GHT20[AR5416_NUM_2G_20_TARGET_POWERS];
	struct CalTargetPowerHt calTPow2GHT40[AR5416_NUM_2G_40_TARGET_POWERS];
	uint8_t			ctlIndex[AR5416_NUM_CTLS];
	struct CalCtlData	ctlData[AR5416_NUM_CTLS];
	uint8_t			padding;
} __packed;

#define	OTUS_NUM_CHAINS			2

#define OTUS_UID(aid)		(IEEE80211_AID(aid) + 4)

#define OTUS_MAX_TXCMDSZ	64
#define OTUS_RXBUFSZ		(8 * 1024)
/* Bumped for later A-MSDU and legacy fast-frames TX support */
#define OTUS_TXBUFSZ		(8 * 1024)

/* Default EDCA parameters for when QoS is disabled. */
static const struct wmeParams otus_edca_def[WME_NUM_AC] = {
	{ 4, 10, 3,  0 },
	{ 4, 10, 7,  0 },
	{ 3,  4, 2, 94 },
	{ 2,  3, 2, 47 }
};

#define OTUS_RIDX_CCK1		 0
#define OTUS_RIDX_OFDM6		 4
#define OTUS_RIDX_OFDM24	 8
#define OTUS_RIDX_MAX		11
static const struct otus_rate {
	uint8_t	rate;
	uint8_t	mcs;
} otus_rates[] = {
	{   2, 0x0 },
	{   4, 0x1 },
	{  11, 0x2 },
	{  22, 0x3 },
	{  12, 0xb },
	{  18, 0xf },
	{  24, 0xa },
	{  36, 0xe },
	{  48, 0x9 },
	{  72, 0xd },
	{  96, 0x8 },
	{ 108, 0xc }
};

struct otus_rx_radiotap_header {
	struct ieee80211_radiotap_header wr_ihdr;
	uint8_t		wr_flags;
	uint8_t		wr_rate;
	uint16_t	wr_chan_freq;
	uint16_t	wr_chan_flags;
	uint8_t		wr_antsignal;
} __packed;

#define OTUS_RX_RADIOTAP_PRESENT			\
	(1 << IEEE80211_RADIOTAP_FLAGS |		\
	 1 << IEEE80211_RADIOTAP_RATE |			\
	 1 << IEEE80211_RADIOTAP_CHANNEL |		\
	 1 << IEEE80211_RADIOTAP_DB_ANTSIGNAL)

struct otus_tx_radiotap_header {
	struct ieee80211_radiotap_header wt_ihdr;
	uint8_t		wt_flags;
	uint8_t		wt_rate;
	uint16_t	wt_chan_freq;
	uint16_t	wt_chan_flags;
} __packed;

#define OTUS_TX_RADIOTAP_PRESENT			\
	(1 << IEEE80211_RADIOTAP_FLAGS |		\
	 1 << IEEE80211_RADIOTAP_RATE |			\
	 1 << IEEE80211_RADIOTAP_CHANNEL)

struct otus_softc;

/* Firmware commands */
struct otus_tx_cmd {
	uint8_t			*buf;
	uint16_t		buflen;
	void			*odata;
	uint16_t		odatalen;
	uint16_t		token;
	STAILQ_ENTRY(otus_tx_cmd)	next_cmd;
};

/* TX, RX buffers */
struct otus_data {
	struct otus_softc	*sc;
	uint8_t			*buf;
	uint16_t		buflen;
	struct mbuf		*m;
	struct ieee80211_node	*ni;
	STAILQ_ENTRY(otus_data)	next;
};

struct otus_node {
	struct ieee80211_node		ni;
	uint64_t			tx_done;
	uint64_t			tx_err;
	uint64_t			tx_retries;
};

#define OTUS_CONFIG_INDEX               0
#define OTUS_IFACE_INDEX                0

/*
 * The carl9170 firmware has the following specification:
 *
 * 0 - USB control
 * 1 - TX
 * 2 - RX
 * 3 - IRQ
 * 4 - CMD
 * ..
 * 10 - end
 */
enum {
	OTUS_BULK_TX,
	OTUS_BULK_RX,
	OTUS_BULK_IRQ,
	OTUS_BULK_CMD,
	OTUS_N_XFER
};

struct otus_vap {
	struct ieee80211vap	vap;
	int			(*newstate)(struct ieee80211vap *,
				    enum ieee80211_state, int);
};
#define	OTUS_VAP(vap)		((struct otus_vap *)(vap))
#define	OTUS_NODE(ni)		((struct otus_node *)(ni))

#define	OTUS_LOCK(sc)		mtx_lock(&(sc)->sc_mtx)
#define	OTUS_UNLOCK(sc)		mtx_unlock(&(sc)->sc_mtx)
#define	OTUS_LOCK_ASSERT(sc)	mtx_assert(&(sc)->sc_mtx, MA_OWNED)
#define	OTUS_UNLOCK_ASSERT(sc)	mtx_assert(&(sc)->sc_mtx, MA_NOTOWNED)

/* XXX the TX/RX endpoint dump says it's 0x200, (512)? */
#define	OTUS_MAX_TXSZ		512
#define	OTUS_MAX_RXSZ		512
/* intr/cmd endpoint dump says 0x40 */
#define	OTUS_MAX_CTRLSZ		64

#define	OTUS_CMD_LIST_COUNT	32
#define	OTUS_RX_LIST_COUNT	128
#define	OTUS_TX_LIST_COUNT	32

struct otus_softc {
	struct ieee80211com		sc_ic;
	struct mbufq			sc_snd;
	device_t			sc_dev;
	struct usb_device		*sc_udev;
	int				(*sc_newstate)(struct ieee80211com *,
					    enum ieee80211_state, int);
	void				(*sc_led_newstate)(struct otus_softc *);
	struct usbd_interface		*sc_iface;
	struct mtx			sc_mtx;

	struct ar5416eeprom		eeprom;
	uint8_t				capflags;
	uint8_t				rxmask;
	uint8_t				txmask;
	int				sc_running:1,
					sc_calibrating:1,
					sc_scanning:1;

	int				sc_if_flags;
	int				sc_tx_timer;
	int				fixed_ridx;
	int				bb_reset;

	struct ieee80211_channel	*sc_curchan;

	struct task			tx_task;
	struct task			wme_update_task;
	struct timeout_task		scan_to;
	struct timeout_task		calib_to;

	/* register batch writes */
	int				write_idx;

	uint32_t			led_state;

	/* current firmware message serial / token number */
	int				token;

	/* current noisefloor, from SET_FREQUENCY */
	int				sc_nf[OTUS_NUM_CHAINS];

	/* How many pending, active transmit frames */
	int				sc_tx_n_pending;
	int				sc_tx_n_active;

	const uint32_t			*phy_vals;

	struct {
		uint32_t	reg;
		uint32_t	val;
	} __packed			write_buf[AR_MAX_WRITE_IDX + 1];

	struct otus_data		sc_rx[OTUS_RX_LIST_COUNT];
	struct otus_data		sc_tx[OTUS_TX_LIST_COUNT];
	struct otus_tx_cmd		sc_cmd[OTUS_CMD_LIST_COUNT];

	struct usb_xfer			*sc_xfer[OTUS_N_XFER];

	STAILQ_HEAD(, otus_data)	sc_rx_active;
	STAILQ_HEAD(, otus_data)	sc_rx_inactive;
	STAILQ_HEAD(, otus_data)	sc_tx_active[OTUS_N_XFER];
	STAILQ_HEAD(, otus_data)	sc_tx_inactive;
	STAILQ_HEAD(, otus_data)	sc_tx_pending[OTUS_N_XFER];

	STAILQ_HEAD(, otus_tx_cmd)	sc_cmd_active;
	STAILQ_HEAD(, otus_tx_cmd)	sc_cmd_inactive;
	STAILQ_HEAD(, otus_tx_cmd)	sc_cmd_pending;
	STAILQ_HEAD(, otus_tx_cmd)	sc_cmd_waiting;

	union {
		struct otus_rx_radiotap_header th;
		uint8_t	pad[64];
	}				sc_rxtapu;
#define sc_rxtap	sc_rxtapu.th
	int				sc_rxtap_len;

	union {
		struct otus_tx_radiotap_header th;
		uint8_t	pad[64];
	}				sc_txtapu;
#define sc_txtap	sc_txtapu.th
	int				sc_txtap_len;
};

#endif	/* __IF_OTUSREG_H__ */
