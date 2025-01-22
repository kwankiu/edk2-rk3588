/** @file

  Copyright (c) 2025, Mario Bălănică <mariobalanica02@gmail.com>
  Copyright (c) 2022 Jared McNeill <jmcneill@invisible.ca>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef DWC_EQOS_HW_H_
#define DWC_EQOS_HW_H_

#define LOWEST_SET_BIT(__mask)  ((((__mask) - 1) & (__mask)) ^ (__mask))
#define SHIFTOUT(__x, __mask)   (((__x) & (__mask)) / LOWEST_SET_BIT (__mask))
#define SHIFTIN(__x, __mask)    ((__x) * LOWEST_SET_BIT (__mask))
#define BITS(hi, lo)            ((~((~0) << ((hi) + 1))) & ((~0) << (lo)))

#define GMAC_MAC_CONFIGURATION                      0x0000
#define GMAC_MAC_CONFIGURATION_CST                  (1U << 21)
#define GMAC_MAC_CONFIGURATION_ACS                  (1U << 20)
#define GMAC_MAC_CONFIGURATION_BE                   (1U << 18)
#define GMAC_MAC_CONFIGURATION_JD                   (1U << 17)
#define GMAC_MAC_CONFIGURATION_JE                   (1U << 16)
#define GMAC_MAC_CONFIGURATION_PS                   (1U << 15)
#define GMAC_MAC_CONFIGURATION_FES                  (1U << 14)
#define GMAC_MAC_CONFIGURATION_DM                   (1U << 13)
#define GMAC_MAC_CONFIGURATION_DCRS                 (1U << 9)
#define GMAC_MAC_CONFIGURATION_TE                   (1U << 1)
#define GMAC_MAC_CONFIGURATION_RE                   (1U << 0)
#define GMAC_MAC_EXT_CONFIGURATION                  0x0004
#define GMAC_MAC_PACKET_FILTER                      0x0008
#define GMAC_MAC_PACKET_FILTER_HPF                  (1U << 10)
#define GMAC_MAC_PACKET_FILTER_PCF_MASK             (3U << 6)
#define GMAC_MAC_PACKET_FILTER_PCF_ALL              (2U << 6)
#define GMAC_MAC_PACKET_FILTER_DBF                  (1U << 5)
#define GMAC_MAC_PACKET_FILTER_PM                   (1U << 4)
#define GMAC_MAC_PACKET_FILTER_HMC                  (1U << 2)
#define GMAC_MAC_PACKET_FILTER_HUC                  (1U << 1)
#define GMAC_MAC_PACKET_FILTER_PR                   (1U << 0)
#define GMAC_MAC_WATCHDOG_TIMEOUT                   0x000C
#define GMAC_MAC_HASH_TABLE_REG_BASE                0x0010
#define GMAC_MAC_HASH_TABLE_COUNT                   2
#define GMAC_MAC_VLAN_TAG                           0x0050
#define GMAC_MAC_Q0_TX_FLOW_CTRL                    0x0070
#define GMAC_MAC_Q0_TX_FLOW_CTRL_PT_SHIFT           16
#define GMAC_MAC_Q0_TX_FLOW_CTRL_TFE                (1U << 1)
#define GMAC_MAC_RX_FLOW_CTRL                       0x0090
#define GMAC_MAC_RX_FLOW_CTRL_RFE                   (1U << 0)
#define GMAC_RXQ_CTRL0                              0x00A0
#define GMAC_RXQ_CTRL0_EN_MASK                      0x3
#define GMAC_RXQ_CTRL0_EN_AVB                       0x1
#define GMAC_RXQ_CTRL0_EN_DCB                       0x2
#define GMAC_RXQ_CTRL1                              0x00A4
#define GMAC_RXQ_CTRL2                              0x00A8
#define GMAC_MAC_INTERRUPT_STATUS                   0x00B0
#define GMAC_MAC_INTERRUPT_ENABLE                   0x00B4
#define GMAC_MAC_RX_TX_STATUS                       0x00B8
#define GMAC_MAC_RX_TX_STATUS_RWT                   (1U << 8)
#define GMAC_MAC_RX_TX_STATUS_EXCOL                 (1U << 5)
#define GMAC_MAC_RX_TX_STATUS_LCOL                  (1U << 4)
#define GMAC_MAC_RX_TX_STATUS_EXDEF                 (1U << 3)
#define GMAC_MAC_RX_TX_STATUS_LCARR                 (1U << 2)
#define GMAC_MAC_RX_TX_STATUS_NCARR                 (1U << 1)
#define GMAC_MAC_RX_TX_STATUS_TJT                   (1U << 0)
#define GMAC_MAC_PMT_CONTROL_STATUS                 0x00C0
#define GMAC_MAC_RWK_PACKET_FILTER                  0x00C4
#define GMAC_MAC_LPI_CONTROL_STATUS                 0x00D0
#define GMAC_MAC_LPI_TIMERS_CONTROL                 0x00D4
#define GMAC_MAC_LPI_ENTRY_TIMER                    0x00D8
#define GMAC_MAC_1US_TIC_COUNTER                    0x00DC
#define GMAC_MAC_PHYIF_CONTROL_STATUS               0x00F8
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSTS        (1U << 19)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED      BITS(18, 17)
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_2_5  0x0
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_25   0x1
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKSPEED_125  0x2
#define GMAC_MAC_PHYIF_CONTROL_STATUS_LNKMOD        (1U << 16)
#define GMAC_MAC_VERSION                            0x0110
#define GMAC_MAC_VERSION_USERVER_SHIFT              8
#define GMAC_MAC_VERSION_USERVER_MASK               (0xFFU << GMAC_MAC_VERSION_USERVER_SHIFT)
#define GMAC_MAC_VERSION_SNPSVER_MASK               0xFFU
#define GMAC_MAC_DEBUG                              0x0114
#define GMAC_MAC_HW_FEATURE_BASE                    0x011C
#define GMAC_MAC_HW_FEATURE1_TXFIFOSIZE             BITS(10,6)
#define GMAC_MAC_HW_FEATURE1_RXFIFOSIZE             BITS(4,0)
#define GMAC_MAC_HW_FEATURE1_ADDR64_SHIFT           14
#define GMAC_MAC_HW_FEATURE1_ADDR64_MASK            (0x3U << GMAC_MAC_HW_FEATURE1_ADDR64_SHIFT)
#define GMAC_MAC_HW_FEATURE1_ADDR64_32BIT           (0x0U << GMAC_MAC_HW_FEATURE1_ADDR64_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS                       0x0200
#define GMAC_MAC_MDIO_ADDRESS_PA_SHIFT              21
#define GMAC_MAC_MDIO_ADDRESS_RDA_SHIFT             16
#define GMAC_MAC_MDIO_ADDRESS_CR_SHIFT              8
#define GMAC_MAC_MDIO_ADDRESS_CR_MASK               (0x7U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_CR_60_100             (0U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_CR_100_150            (1U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_CR_20_35              (2U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_CR_35_60              (3U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_CR_150_250            (4U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_CR_250_300            (5U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_CR_300_500            (6U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_CR_500_800            (7U << GMAC_MAC_MDIO_ADDRESS_CR_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_SKAP                  (1U << 4)
#define GMAC_MAC_MDIO_ADDRESS_GOC_SHIFT             2
#define GMAC_MAC_MDIO_ADDRESS_GOC_READ              (3U << GMAC_MAC_MDIO_ADDRESS_GOC_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_GOC_WRITE             (1U << GMAC_MAC_MDIO_ADDRESS_GOC_SHIFT)
#define GMAC_MAC_MDIO_ADDRESS_C45E                  (1U << 1)
#define GMAC_MAC_MDIO_ADDRESS_GB                    (1U << 0)
#define GMAC_MAC_MDIO_DATA                          0x0204
#define GMAC_MAC_CSR_SW_CTRL                        0x0230
#define GMAC_MAC_ADDRESS0_HIGH                      0x0300
#define GMAC_MAC_ADDRESS0_HIGH_AE                   (1U << 31)
#define GMAC_MAC_ADDRESS0_LOW                       0x0304
#define GMAC_MMC_CONTROL                            0x0700
#define GMAC_MMC_CONTROL_UCDBC                      (1U << 8)
#define GMAC_MMC_CONTROL_CNTPRSTLVL                 (1U << 5)
#define GMAC_MMC_CONTROL_CNTPRST                    (1U << 4)
#define GMAC_MMC_CONTROL_CNTFREEZ                   (1U << 3)
#define GMAC_MMC_CONTROL_RSTONRD                    (1U << 2)
#define GMAC_MMC_CONTROL_CNTSTOPRO                  (1U << 1)
#define GMAC_MMC_CONTROL_CNTRST                     (1U << 0)
#define GMAC_MMC_RX_INTERRUPT                       0x0704
#define GMAC_MMC_RX_INTERRUPT_RXFOVPIS              (1U << 21)
#define GMAC_MMC_RX_INTERRUPT_RXLENERPIS            (1U << 18)
#define GMAC_MMC_RX_INTERRUPT_RXCRCERPIS            (1U << 5)
#define GMAC_MMC_RX_INTERRUPT_RXMCGPIS              (1U << 4)
#define GMAC_MMC_RX_INTERRUPT_RXGOCTIS              (1U << 2)
#define GMAC_MMC_RX_INTERRUPT_RXGBOCTIS             (1U << 1)
#define GMAC_MMC_RX_INTERRUPT_RXGBPKTIS             (1U << 0)
#define GMAC_MMC_TX_INTERRUPT                       0x0708
#define GMAC_MMC_TX_INTERRUPT_TXGPKTIS              (1U << 21)
#define GMAC_MMC_TX_INTERRUPT_TXGOCTIS              (1U << 20)
#define GMAC_MMC_TX_INTERRUPT_TXCARERPIS            (1U << 19)
#define GMAC_MMC_TX_INTERRUPT_TXFLOWERPIS           (1U << 13)
#define GMAC_MMC_TX_INTERRUPT_TXGBPKTIS             (1U << 1)
#define GMAC_MMC_TX_INTERRUPT_TXGBOCTIS             (1U << 0)
#define GMAC_MMC_RX_INTERRUPT_MASK                  0x070C
#define GMAC_MMC_TX_INTERRUPT_MASK                  0x0710
#define GMAC_TX_OCTET_COUNT_GOOD_BAD                0x0714
#define GMAC_TX_PACKET_COUNT_GOOD_BAD               0x0718
#define GMAC_TX_UNDERFLOW_ERROR_PACKETS             0x0748
#define GMAC_TX_CARRIER_ERROR_PACKETS               0x0760
#define GMAC_TX_OCTET_COUNT_GOOD                    0x0764
#define GMAC_TX_PACKET_COUNT_GOOD                   0x0768
#define GMAC_RX_PACKETS_COUNT_GOOD_BAD              0x0780
#define GMAC_RX_OCTET_COUNT_GOOD_BAD                0x0784
#define GMAC_RX_OCTET_COUNT_GOOD                    0x0788
#define GMAC_RX_MULTICAST_PACKETS_GOOD              0x0790
#define GMAC_RX_CRC_ERROR_PACKETS                   0x0794
#define GMAC_RX_LENGTH_ERROR_PACKETS                0x07C8
#define GMAC_RX_FIFO_OVERFLOW_PACKETS               0x07D4
#define GMAC_MMC_IPC_RX_INTERRUPT_MASK              0x0800
#define GMAC_MMC_IPC_RX_INTERRUPT                   0x0808
#define GMAC_RXIPV4_GOOD_PACKETS                    0x0810
#define GMAC_RXIPV4_HEADER_ERROR_PACKETS            0x0814
#define GMAC_RXIPV6_GOOD_PACKETS                    0x0824
#define GMAC_RXIPV6_HEADER_ERROR_PACKETS            0x0828
#define GMAC_RXUDP_ERROR_PACKETS                    0x0834
#define GMAC_RXTCP_ERROR_PACKETS                    0x083C
#define GMAC_RXICMP_ERROR_PACKETS                   0x0844
#define GMAC_RXIPV4_HEADER_ERROR_OCTETS             0x0854
#define GMAC_RXIPV6_HEADER_ERROR_OCTETS             0x0868
#define GMAC_RXUDP_ERROR_OCTETS                     0x0874
#define GMAC_RXTCP_ERROR_OCTETS                     0x087C
#define GMAC_RXICMP_ERROR_OCTETS                    0x0884
#define GMAC_MAC_TIMESTAMP_CONTROL                  0x0B00
#define GMAC_MAC_SUB_SECOND_INCREMENT               0x0B04
#define GMAC_MAC_SYSTEM_TIME_SECS                   0x0B08
#define GMAC_MAC_SYSTEM_TIME_NS                     0x0B0C
#define GMAC_MAC_SYS_TIME_SECS_UPDATE               0x0B10
#define GMAC_MAC_SYS_TIME_NS_UPDATE                 0x0B14
#define GMAC_MAC_TIMESTAMP_ADDEND                   0x0B18
#define GMAC_MAC_TIMESTAMP_STATUS                   0x0B20
#define GMAC_MAC_TX_TS_STATUS_NS                    0x0B30
#define GMAC_MAC_TX_TS_STATUS_SECS                  0x0B34
#define GMAC_MAC_AUXILIARY_CONTROL                  0x0B40
#define GMAC_MAC_AUXILIARY_TS_NS                    0x0B48
#define GMAC_MAC_AUXILIARY_TS_SECS                  0x0B4C
#define GMAC_MAC_TS_INGRESS_CORR_NS                 0x0B58
#define GMAC_MAC_TS_EGRESS_CORR_NS                  0x0B5C
#define GMAC_MAC_TS_INGRESS_LATENCY                 0x0B68
#define GMAC_MAC_TS_EGRESS_LATENCY                  0x0B6C
#define GMAC_MAC_PPS_CONTROL                        0x0B70
#define GMAC_MTL_DBG_CTL                            0x0C08
#define GMAC_MTL_DBG_STS                            0x0C0C
#define GMAC_MTL_FIFO_DEBUG_DATA                    0x0C10
#define GMAC_MTL_INTERRUPT_STATUS                   0x0C20
#define GMAC_MTL_INTERRUPT_STATUS_DBGIS             (1U << 17)
#define GMAC_MTL_INTERRUPT_STATUS_Q0IS              (1U << 0)
#define GMAC_MTL_TXQ0_OPERATION_MODE                0x0D00
#define GMAC_MTL_TXQ0_OPERATION_MODE_TQS            BITS(24,16)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TTC            BITS(6,4)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_SHIFT    2
#define GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_MASK     (0x3U << GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_SHIFT)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_EN       (2U << GMAC_MTL_TXQ0_OPERATION_MODE_TXQEN_SHIFT)
#define GMAC_MTL_TXQ0_OPERATION_MODE_TSF            (1U << 1)
#define GMAC_MTL_TXQ0_OPERATION_MODE_FTQ            (1U << 0)
#define GMAC_MTL_TXQ0_UNDERFLOW                     0x0D04
#define GMAC_MTL_TXQ0_DEBUG                         0x0D08
#define GMAC_MTL_Q0_INTERRUPT_CTRL_STATUS           0x0D2C
#define GMAC_MTL_Q0_INTERRUPT_CTRL_STATUS_RXOIE     (1U << 24)
#define GMAC_MTL_Q0_INTERRUPT_CTRL_STATUS_RXOVFIS   (1U << 16)
#define GMAC_MTL_Q0_INTERRUPT_CTRL_STATUS_TXUIE     (1U << 8)
#define GMAC_MTL_Q0_INTERRUPT_CTRL_STATUS_TXUNFIS   (1U << 0)
#define GMAC_MTL_RXQ0_OPERATION_MODE                0x0D30
#define GMAC_MTL_RXQ0_OPERATION_MODE_RQS            BITS(29,20)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RFD            BITS(19,14)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RFA            BITS(13,8)
#define GMAC_MTL_RXQ0_OPERATION_MODE_EHFC           (1U << 7)
#define GMAC_MTL_RXQ0_OPERATION_MODE_RSF            (1U << 5)
#define GMAC_MTL_RXQ0_OPERATION_MODE_FEP            (1U << 4)
#define GMAC_MTL_RXQ0_OPERATION_MODE_FUP            (1U << 3)
#define GMAC_MTL_RXQ0_MISS_PKT_OVF_CNT              0x0D34
#define GMAC_MTL_RXQ0_DEBUG                         0x0D38
#define GMAC_DMA_MODE                               0x1000
#define GMAC_DMA_MODE_SWR                           (1U << 0)
#define GMAC_DMA_SYSBUS_MODE                        0x1004
#define GMAC_DMA_SYSBUS_MODE_WR_OSR_LMT_SHIFT       24
#define GMAC_DMA_SYSBUS_MODE_WR_OSR_LMT_MASK        (0xfU << GMAC_DMA_SYSBUS_MODE_WR_OSR_LMT_SHIFT)
#define GMAC_DMA_SYSBUS_MODE_RD_OSR_LMT_SHIFT       16
#define GMAC_DMA_SYSBUS_MODE_RD_OSR_LMT_MASK        (0xfU << GMAC_DMA_SYSBUS_MODE_RD_OSR_LMT_SHIFT)
#define GMAC_DMA_SYSBUS_MODE_MB                     (1U << 14)
#define GMAC_DMA_SYSBUS_MODE_EAME                   (1U << 11)
#define GMAC_DMA_SYSBUS_MODE_BLEN16                 (1U << 3)
#define GMAC_DMA_SYSBUS_MODE_BLEN8                  (1U << 2)
#define GMAC_DMA_SYSBUS_MODE_BLEN4                  (1U << 1)
#define GMAC_DMA_SYSBUS_MODE_FB                     (1U << 0)
#define GMAC_DMA_INTERRUPT_STATUS                   0x1008
#define GMAC_DMA_DEBUG_STATUS0                      0x100C
#define GMAC_AXI_LPI_ENTRY_INTERVAL                 0x1040
#define GMAC_RWK_FILTER_BYTE_MASK_BASE              0x10C0
#define GMAC_RWK_FILTER01_CRC                       0x10D0
#define GMAC_RWK_FILTER23_CRC                       0x10D4
#define GMAC_RWK_FILTER_OFFSET                      0x10D8
#define GMAC_RWK_FILTER_COMMAND                     0x10DC
#define GMAC_DMA_CHAN0_CONTROL                      0x1100
#define GMAC_DMA_CHAN0_CONTROL_DSL_SHIFT            18
#define GMAC_DMA_CHAN0_CONTROL_DSL_MASK             (0x7U << GMAC_DMA_CHAN0_CONTROL_DSL_SHIFT)
#define GMAC_DMA_CHAN0_CONTROL_PBLX8                (1U << 16)
#define GMAC_DMA_CHAN0_TX_CONTROL                   0x1104
#define GMAC_DMA_CHAN0_TX_CONTROL_TXPBL_SHIFT       16
#define GMAC_DMA_CHAN0_TX_CONTROL_TXPBL_MASK        (0x3FU << GMAC_DMA_CHAN0_TX_CONTROL_TXPBL_SHIFT)
#define GMAC_DMA_CHAN0_TX_CONTROL_OSP               (1U << 4)
#define GMAC_DMA_CHAN0_TX_CONTROL_START             (1U << 0)
#define GMAC_DMA_CHAN0_RX_CONTROL                   0x1108
#define GMAC_DMA_CHAN0_RX_CONTROL_RXPBL_SHIFT       16
#define GMAC_DMA_CHAN0_RX_CONTROL_RXPBL_MASK        (0x3FU << GMAC_DMA_CHAN0_RX_CONTROL_RXPBL_SHIFT)
#define GMAC_DMA_CHAN0_RX_CONTROL_RBSZ_SHIFT        1
#define GMAC_DMA_CHAN0_RX_CONTROL_RBSZ_MASK         (0x3FFFU << GMAC_DMA_CHAN0_RX_CONTROL_RBSZ_SHIFT)
#define GMAC_DMA_CHAN0_RX_CONTROL_START             (1U << 0)
#define GMAC_DMA_CHAN0_TX_BASE_ADDR_HI              0x1110
#define GMAC_DMA_CHAN0_TX_BASE_ADDR                 0x1114
#define GMAC_DMA_CHAN0_RX_BASE_ADDR_HI              0x1118
#define GMAC_DMA_CHAN0_RX_BASE_ADDR                 0x111C
#define GMAC_DMA_CHAN0_TX_END_ADDR                  0x1120
#define GMAC_DMA_CHAN0_RX_END_ADDR                  0x1128
#define GMAC_DMA_CHAN0_TX_RING_LEN                  0x112C
#define GMAC_DMA_CHAN0_RX_RING_LEN                  0x1130
#define GMAC_DMA_CHAN0_INTR_ENABLE                  0x1134
#define GMAC_DMA_CHAN0_RX_WATCHDOG                  0x1138
#define GMAC_DMA_CHAN0_SLOT_CTRL_STATUS             0x113C
#define GMAC_DMA_CHAN0_CUR_TX_DESC                  0x1144
#define GMAC_DMA_CHAN0_CUR_RX_DESC                  0x114C
#define GMAC_DMA_CHAN0_CUR_TX_BUF_ADDR              0x1154
#define GMAC_DMA_CHAN0_CUR_RX_BUF_ADDR              0x115C
#define GMAC_DMA_CHAN0_STATUS                       0x1160
#define GMAC_DMA_CHAN0_STATUS_REB_DATA_TRANS        (1U << 21)
#define GMAC_DMA_CHAN0_STATUS_REB_DESC_ACC          (1U << 20)
#define GMAC_DMA_CHAN0_STATUS_REB_READ_TRANS        (1U << 19)
#define GMAC_DMA_CHAN0_STATUS_TEB_DATA_TRANS        (1U << 18)
#define GMAC_DMA_CHAN0_STATUS_TEB_DESC_ACC          (1U << 17)
#define GMAC_DMA_CHAN0_STATUS_TEB_READ_TRANS        (1U << 16)
#define GMAC_DMA_CHAN0_STATUS_NIS                   (1U << 15)
#define GMAC_DMA_CHAN0_STATUS_AIS                   (1U << 14)
#define GMAC_DMA_CHAN0_STATUS_CDE                   (1U << 13)
#define GMAC_DMA_CHAN0_STATUS_FBE                   (1U << 12)
#define GMAC_DMA_CHAN0_STATUS_RWT                   (1U << 9)
#define GMAC_DMA_CHAN0_STATUS_RPS                   (1U << 8)
#define GMAC_DMA_CHAN0_STATUS_RBU                   (1U << 7)
#define GMAC_DMA_CHAN0_STATUS_RI                    (1U << 6)
#define GMAC_DMA_CHAN0_STATUS_TBU                   (1U << 2)
#define GMAC_DMA_CHAN0_STATUS_TPS                   (1U << 1)
#define GMAC_DMA_CHAN0_STATUS_TI                    (1U << 0)

#define GMAC_MAC_HASH_TABLE_REG(n)    (GMAC_MAC_HASH_TABLE_REG_BASE + 0x4 * (n))
#define GMAC_MAC_HW_FEATURE(n)        (GMAC_MAC_HW_FEATURE_BASE + 0x4 * (n))
#define GMAC_RWK_FILTER_BYTE_MASK(n)  (GMAC_RWK_FILTER_BYTE_MASK_BASE + 0x4 * (n))

#pragma pack(1)
typedef struct EQOS_DMA_DESCRIPTOR {
  UINT32    Tdes0;
  UINT32    Tdes1;
  UINT32    Tdes2;
  #define EQOS_TDES2_TX_IOC  (1U << 31)                       /* TX */
  #define EQOS_TDES2_RX_DAF  (1U << 17)                       /* RX (WB) */
  #define EQOS_TDES2_RX_SAF  (1U << 16)                       /* RX (WB) */
  UINT32    Tdes3;
  #define EQOS_TDES3_TX_OWN          (1U << 31)               /* TX */
  #define EQOS_TDES3_TX_FD           (1U << 29)               /* TX */
  #define EQOS_TDES3_TX_LD           (1U << 28)               /* TX */
  #define EQOS_TDES3_TX_DE           (1U << 23)               /* TX (WB) */
  #define EQOS_TDES3_TX_EUE          (1U << 16)               /* TX (WB) */
  #define EQOS_TDES3_TX_ES           (1U << 15)               /* TX (WB) */
  #define EQOS_TDES3_TX_JT           (1U << 14)               /* TX (WB) */
  #define EQOS_TDES3_TX_PF           (1U << 13)               /* TX (WB) */
  #define EQOS_TDES3_TX_PCE          (1U << 12)               /* TX (WB) */
  #define EQOS_TDES3_TX_LOC          (1U << 11)               /* TX (WB) */
  #define EQOS_TDES3_TX_NC           (1U << 10)               /* TX (WB) */
  #define EQOS_TDES3_TX_LC           (1U << 9)                /* TX (WB) */
  #define EQOS_TDES3_TX_EC           (1U << 8)                /* TX (WB) */
  #define EQOS_TDES3_TX_ED           (1U << 3)                /* TX (WB) */
  #define EQOS_TDES3_TX_UF           (1U << 2)                /* TX (WB) */
  #define EQOS_TDES3_TX_IHE          (1U << 0)                /* TX (WB) */
  #define EQOS_TDES3_RX_OWN          (1U << 31)               /* RX */
  #define EQOS_TDES3_RX_IOC          (1U << 30)               /* RX */
  #define EQOS_TDES3_RX_BUF1V        (1U << 24)               /* RX */
  #define EQOS_TDES3_RX_CTXT         (1U << 30)               /* RX (WB) */
  #define EQOS_TDES3_RX_FD           (1U << 29)               /* RX (WB) */
  #define EQOS_TDES3_RX_LD           (1U << 28)               /* RX (WB) */
  #define EQOS_TDES3_RX_CE           (1U << 24)               /* RX (WB) */
  #define EQOS_TDES3_RX_GP           (1U << 23)               /* RX (WB) */
  #define EQOS_TDES3_RX_RWT          (1U << 22)               /* RX (WB) */
  #define EQOS_TDES3_RX_OE           (1U << 21)               /* RX (WB) */
  #define EQOS_TDES3_RX_RE           (1U << 20)               /* RX (WB) */
  #define EQOS_TDES3_RX_DE           (1U << 19)               /* RX (WB) */
  #define EQOS_TDES3_RX_ES           (1U << 15)               /* RX (WB) */
  #define EQOS_TDES3_RX_LENGTH_MASK  0x7FFFU                  /* RX */
} EQOS_DMA_DESCRIPTOR;
#pragma pack()

#endif
