# PixyCam

This is a Pixy2 driver for usage with PX4 Firmware (https://github.com/PX4/Firmware.git).

This driver includes I2C and SPI interfaces.

In the pixycam.cpp file is an example shown based on I2C communication. But the driver also can support SPI communication. The PixyCam repo is writen to use with the [PX4 Firmware](https://github.com/PX4/Firmware.git). You should be familiar with [PX4 Firmware](https://dev.px4.io/master/en/) and [QGroundControl](http://qgroundcontrol.com/).

To use the driver and run the example, please follow the next steps:

1. Download or clone the PX4 Firmware: https://github.com/PX4/Firmware.git
2. Navigate to the following folder: ~/src/examples
3. Copy or clone this repo into this folder
4. Open the file ~/boards/nxp/fmuk66-v3/default.cmake and go to EXAMPLES (end of file). Add "PixyCam" in the last row (without the quotation marks) and save the file
5. Now run `make nxp_fmuk66-v3_default` in the terminal to build the code
6. Run the code with `make nxp_fmuk66-v3_default upload`
7. Open the MAVLink console in QGroundControl and type `pixycam` into the command line.
8. Detected block are printed to the consol. If no blocks are detected there is no output.

This is a simple example to show the principle of the Pixy API. For more information about the Pixy 2 camera visit [Pixy 2 Wiki](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:start).

The Pixy 2 device has to be configured first. You can find how to set the right Interface [here](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:porting_guide). And the Pixy 2 has to be in the mode "Color connected components". The instructions can be found [here](https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:color_connected_components).
