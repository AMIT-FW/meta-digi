# Copyright (C) 2013 Digi International.

SUMMARY = "DEY examples: Battery test application"
SECTION = "examples"
LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

PR = "${DISTRO}.r0"

RDEPENDS_${PN} = "kernel-module-pmic-battery"

SRC_URI = "file://battery_test"

S = "${WORKDIR}/battery_test"

do_compile() {
	${CC} -O2 -Wall battery_calc.c battery_test.c -o battery_test
}

do_install() {
	install -d ${D}${bindir}
	install -m 0755 battery_test ${D}${bindir}
}

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "(ccimx51)"
