MENDER_UBOOT_AUTO_CONFIGURE = "0"
MENDER_UBOOT_CONFIG_SYS_MMC_ENV_PART = "2"

TEGRA_MENDER_BOOTENV_SIZE_DEFAULT = "0x20000"
TEGRA_MENDER_BOOTENV_SIZE_DEFAULT_tegra210 = "${@'0x10000' if (d.getVar('TEGRA_SPIFLASH_BOOT') or '') == '1' else '0x20000'}"
BOOTENV_SIZE ?= "${TEGRA_MENDER_BOOTENV_SIZE_DEFAULT}"

# This offset must match the offset of the UBENV partition in the
# flash layout XML file for the target.
MENDER_UBOOT_ENV_STORAGE_DEVICE_OFFSET_tegra186 = "3911680"
MENDER_UBOOT_ENV_STORAGE_DEVICE_OFFSET_tegra210 = "${@'3866624' if (d.getVar('TEGRA_SPIFLASH_BOOT') or '') == '1' else '3801088'}"
MENDER_UBOOT_MMC_ENV_LINUX_DEVICE_PATH_tegra210 = "${@'/dev/mtd0' if (d.getVar('TEGRA_SPIFLASH_BOOT') or '') == '1' else mender_get_uboot_env_mmc_linux_device_path(d)}"

# Optionally use SDcard instead of SPI flash on Jetson Nano dev kits.
# Starting with meta-tegra zeus branch, Nano dev kits use the SPI flash
# for the U-Boot environment (as NVIDIA does with L4T R32.3.1 and
# later). Note that the u-boot environment will still live on SPI flash
# and relocating the environment also to SD may be possible but is not
# supported.
MENDER_UBOOT_STORAGE_DEVICE_tegra210 = "${@'1' if (d.getVar('TEGRA_SPIFLASH_BOOT') or '') == '1' else '0'}"
