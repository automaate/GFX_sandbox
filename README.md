---
title: Harmony 3 Graphics  Package
nav_order: 1
---

# MPLAB® Harmony 3 Graphics 

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating
embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller
and microprocessor devices.  Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony Graphics Suite. The suite supports a free fast to market, graphics software development environment for Microchip MPLAB® 32-bit SAM and PIC microprocessor devices. Refer to the following graphics links for release notes, home page, training materials, framework and application help.

- [Release Notes](release_notes.md)
- [MPLAB® Harmony License](mplab_harmony_license.md)
- [MPLAB® Harmony 3 Aerospace Wiki](https://github.com/Microchip-MPLAB-Harmony/gfx/wiki)
- [MPLAB® Harmony 3 Aerospace API Help](https://microchip-mplab-harmony.github.io/GFX_sandbox)

# Featres
The key features of the MPLAB® Harmony Graphics Suite are the following:

* Hardware optimized for use with Microchip 32-bit SAM and PIC devices
* Compatible component for use with Microchip Harmony 3 Configurator (MHC)
* Written in C with MISRA C (Mandatory) compliancy
* RTOS and non-RTOS support
* Configurable widget building blocks buttons, labels, lists, sliders, and images
* Rich tool set: Heap Estimator, Event Manager, Palette generator, Asset Manager, String and Font interface, DDR memory organizer
* Hardware integrated for Microchip GPU and display controller peripherals
* Support for single and double frame buffers
* Multi-language font support
* External input support for use with capacitive, resistive and other devices
* UI design editor for what-you-see-what-you-get (WYSWYG) graphics layouts
* Fluid-UI support for alpha-blending, animations, scaling
* Pixel format support for RGBA8888, RGB888, RGB565, RGB5551, RGB332, GS8
* Multi-image support for industry standard formats, compression choices, external memory accessibility
* Fully functional demonstrations and quick-starts to enable new development
* Low memory and low power configurable


# Contents Summary

| Folder     | Description                                               |
| ---        | ---                                                       |
| apps       | Example quickstart and utility applications    |
| display    | Supported displays                      |
| input      | Input System and its associated drivers and services                      |
| middleware | Supported User Interface (UI) libraries      |
| driver     | Display controller and graphics processor unit drivers      |

## Code Examples

The following applications are provided to demonstrate the typical or interesting usage models of one or more Peripheral libraries.

| MIL1553 Examples | Status |
| --- | :---: |
| [IP1553 Bus Controller operation blocking](apps/ip1553/ip1553_bc_operation_blocking/readme.md) | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |
| [IP1553 Bus Controller operation interrupt](apps/ip1553/ip1553_bc_operation_interrupt/readme.md) | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |
| [IP1553 Remote Terminal operation blocking](apps/ip1553/ip1553_rt_operation_blocking/readme.md) | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |
| [IP1553 Remote Terminal operation interrupt](apps/ip1553/ip1553_rt_operation_interrupt/readme.md) | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |

| ICM with ECC errors injections Example | Status |
| --- | :---: |
| [ICM with ECC errors injections](apps/icm_with_ecc_error_injection/readme.md) | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |

| SpaceWire Examples | Status |
| --- | :---: |
| [SpaceWire Loopback](apps/spw/spw_loopback/readme.md) | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |
| [SpaceWire RMAP Loopback](apps/spw/spw_rmap_loopback/readme.md) | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |

## Peripheral libraries

### SAMRH71

| PLIB | Status |
| --- | :---: |
| [IP1553](peripheral/ip1553_44127/docs/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [ICM](peripheral/icm_11105/docs/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [FLEXRAMECC](peripheral/flexramecc_44124/docs/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [TCMECC](peripheral/tcmecc_44125/docs/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [SpaceWire](peripheral/spw_44126/docs/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/aerospace/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/aerospace.svg)](https://github.com/Microchip-MPLAB-Harmony/aerospace/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/aerospace.svg)](https://github.com/Microchip-MPLAB-Harmony/aerospace/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/aerospace.svg)](https://github.com/Microchip-MPLAB-Harmony/aerospace/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/aerospace.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/aerospace.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/aerospace.svg?style=social)]()
