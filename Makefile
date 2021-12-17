compile:
	arduino-cli compile --fqbn Seeeduino:samd:seeed_wio_terminal HelloWorld

upload:
	arduino-cli upload -p /dev/ttyACM0 --fqbn Seeeduino:samd:seeed_wio_terminal HelloWorld

build: compile upload
