#@TYPE: Machine
#@NAME: ConnectCore for MX53 module.
#@DESCRIPTION: Machine configuration for Digi's ConnectCore for MX53 module.

include conf/machine/include/imx-digi-base.inc
include conf/machine/include/tune-cortexa8.inc

DIGI_FAMILY = "ccimx5:ccimx53"
SOC_FAMILY  = "mx5:mx53:${DIGI_FAMILY}"

# Platform u-boot settings
UBOOT_ENTRYPOINT = "0x70008000"
UBOOT_SUFFIX = "bin"

# Firmware
MACHINE_FIRMWARE = "firmware-imx-vpu-imx53 firmware-imx-sdma-imx53"

MACHINE_EXTRA_RDEPENDS    += "mtd-utils-ubifs nvram ubootenv update-flash"
MACHINE_EXTRA_RRECOMMENDS += "${MACHINE_FIRMWARE}"
MACHINE_EXTRA_RRECOMMENDS += "kernel-module-mma7455l"
MACHINE_EXTRA_RRECOMMENDS += "kernel-module-smsc911x"
MACHINE_EXTRA_RRECOMMENDS += "kernel-module-scc2-driver"
MACHINE_EXTRA_RRECOMMENDS += "kernel-module-sahara"
MACHINE_EXTRA_RRECOMMENDS += "kernel-module-mt9v111-camera"

module_autoload_mma7455l = "mma7455l"
module_autoload_smsc911x = "smsc911x"
module_autoload_scc2_driver = "scc2_driver"
module_autoload_sahara = "sahara"
module_autoload_mt9v111_camera = "mt9v111_camera"

# Flash image types
IMAGE_FSTYPES ?= "jffs2.sum tar.bz2 ubifs"

#
# Supported variants
#
# Maintain in sync with the same table in platform local.conf template.
#
# Name          WiFi    Eth2    RAM     NAND
# ------------------------------------------
# -             N       N       512     512     (empty MACHINE_VARIANT="")
# 128           N       N       128     128
# 4k            N       N       512     1024
# e             N       Y       1024    512
# e4k           N       Y       512     1024
# w             Y       N       512     512
# w128          Y       N       128     128
# we            Y       Y       512     512

# All variants support
MACHINE_FEATURES += "accelerometer accel-graphics accel-video"

# Per-variant machine features
MACHINE_FEATURES_append_e = " ext-eth"
MACHINE_FEATURES_append_e4k = " ext-eth"
MACHINE_FEATURES_append_w = " wifi"
MACHINE_FEATURES_append_w128 = " wifi"
MACHINE_FEATURES_append_we = " wifi ext-eth"

# Per-variant u-boot configuration
UBOOT_CONFIG_VARIANT_128 = "128sdram"
UBOOT_CONFIG_VARIANT_4k = "4Kpage"
UBOOT_CONFIG_VARIANT_e = "ext_eth"
UBOOT_CONFIG_VARIANT_e4k = "4Kpage"
UBOOT_CONFIG_VARIANT_w128 = "128sdram"
UBOOT_CONFIG_VARIANT_we = "ext_eth"
