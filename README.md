# Wio Terminal OS

## Prerequisites

Install [`arduino-cli`](https://github.com/arduino/arduino-cli).

## Setup

Update the local indexes:

```bash
$ arduino-cli core update-index
```

Connect the Wio Terminal and ensure it shows up:

```bash
$ arduino-cli board list
Port         Protocol Type              Board Name             FQBN                              Core
/dev/ttyACM0 serial   Serial Port (USB) Seeeduino Wio Terminal Seeeduino:samd:seeed_wio_terminal Seeeduino:samd
```

Compile the sketch:

```bash
$ arduino-cli compile --fqbn Seeeduino:samd:seeed_wio_terminal HelloWorld
```

Upload it:

```bash
$ arduino-cli upload -p /dev/ttyACM0 --fqbn Seeeduino:samd:seeed_wio_terminal HelloWorld
```
