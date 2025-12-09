# WacOff Project

## Name Choice
I choose that name because Wacom + Wack your stuff (damn this sounds weird ngl) = WacOff (Sheikh Assim Al Hakeem don't call me)

## Overview
WacOff is a Free and Open Source CLI app designed to pass through the Samsung Galaxy Note 9's S-Pen to your Linux machine using the network and show up as a drawing tablet.... and turns your Note 9 into a Wacom without you needing to work at McDonald's again (don't gotta put the fries in the bag)

## Installation Instructions

### For Linux based Systems:

- **Debian/Ubuntu/Ubuntu-based:** `sudo apt install gcc-aarch64-linux-gnu gcc-aarch64-linux-gnu libc6-dev-arm64-cross linux-headers-$(uname -r)-arm64-cross gcc make git xf86-input-wacom`

- **Fedora/Fedora-based:** `sudo dnf install @development-tools gcc-aarch64-linux-gnu binutils-aarch64-linux-gnu glibc-aarch64-linux-gnu glibc-devel-aarch64-linux-gnu linux-headers gcc make git xorg-x11-drv-wacom`

- **Arch/Arch-based:** `sudo pacman -S --noconfirm aarch64-linux-gnu-gcc aarch64-linux-gnu-binutils aarch64-linux-gnu-glibc aarch64-linux-gnu-linux-api-headers gcc make git xf86-input-wacom`

### For Windows users:
¯\_(ツ)_/¯

### READ THIS BEFORE CONTINUING

Make sure you have Developer Mode enabled and USB Debugging enabled before you actually use this and your little brother didn't break the S-Pen

### Configuring WacOff

Open src/config.h in your favorite text editor and comment out (using "//" at the start of the line) any line that doesn't look similar to the model of your Galaxy Note 9

### Compiling and Running WacOff

Compile WacOff by running this command

```bash
make all
```

To run WacOff firstly you will need to run the server as root on your PC using this command (you need to have the uinput module loaded)

```bash
sudo ./server
```

In this stage you will need to put the client in an app's data folder (in /data/data/<app directory name>) in the guide I will use com.android.shell (you can change it to your heart's liking) because that's the most standard and exists in almost every Android install

Run this command on your PC to put the client on your phone

```bash
adb push build/client /data/data/com.android.shell/wacoff_client
```

If your Galaxy Note 9 told you to allow a debugger, just allow it so you can get a shell

If you want to test with a different Note 9 model other than the SM-N960F put this file too

```bash
adb push build/client_info /data/data/com.android.shell/wacoff_client_info
```

To get a shell on your Note 9 just run this command

```bash
adb shell
```

Run this command on your Galaxy Note 9's shell

```bash
/data/data/com.android.shell/wacoff_client
```

It will ask you for the server's (Your PC) IP just enter it and yippy you have a drawing tablet

If you want to test with the Note 9 and see how it behaves and make an issue and give me the output of the command and the model of your Note 9 in the issue

Run this command while you are in a shell on your Note 9

```bash
/data/data/com.android.shell/wacoff_client_info
```

If you want to use the tablet as a landscape tablet (instead of a portrait one) you can just run this command on your PC after the Note 9 is connected

```bash
xsetwacom set "Note9 S-Pen Tablet stylus" Rotate cw
```

### Features

  - Full X, Y and hover work as expected
  - Pressure-sensitivity works
  - Works as a standard Linux compatible drawing tablet
  - 280Hz works perfectly (lags sometimes if your link is bad)

### Stuff I found but I couldn't support

   - The button on the S-Pen (that's literally it and it registers as evdev KEY 331)

### Supported Galaxy Note 9 models

  - SM-N960F (This is my Note 9's model, others might work tho let me know if one did)

#### License

This project is licensed under the GNU GPL-3.0 license.

#### Contact

For support or questions, please contact me at [ahmed.retroflexos.dev@protonmail.com](mailto:ahmed.retroflexos.dev@protonmail.com)
